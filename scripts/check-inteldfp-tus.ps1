# Parallel compile check for IntelDFP translation units (ClangCL / extra-strict).
# Uses the configured vcxproj + MSBuild SelectedFiles (same flags as full build).
#
# Usage:
#   .\scripts\check-inteldfp-tus.ps1
#   .\scripts\check-inteldfp-tus.ps1 -Filter 'bid128_*'
#   .\scripts\check-inteldfp-tus.ps1 -Throttle 16 -FailFast

param(
    [string]$BuildDir = (Join-Path $PSScriptRoot "..\out\build\x64-Clang-Debug" | Resolve-Path),
    [string]$Config = "Debug",
    [string]$Filter = "*",
    [int]$Throttle = 8,
    [switch]$FailFast
)

$ErrorActionPreference = "Stop"
$proj = Join-Path $BuildDir "LIBRARY\IntelDFP.vcxproj"
if (-not (Test-Path $proj)) {
    Write-Error "Configure first: cmake --preset x64-Clang-Debug (missing $proj)"
}

$xml = Get-Content $proj -Raw
$sources = [regex]::Matches($xml, 'ClCompile Include="([^"]+\.c)"') |
    ForEach-Object { $_.Groups[1].Value } |
    Where-Object { [System.IO.Path]::GetFileName($_) -like $Filter } |
    Sort-Object -Unique

if (-not $sources) {
    Write-Error "No sources matched filter '$Filter'"
}

Write-Host "Checking $($sources.Count) file(s) with Throttle=$Throttle ..."

$failures = [System.Collections.Concurrent.ConcurrentBag[string]]::new()

$sources | ForEach-Object -Parallel {
    param($src, $BuildDir, $Config, $FailFast, $failures)
    $out = & cmake --build $BuildDir --target IntelDFP --config $Config -- `
        /t:ClCompile "/p:SelectedFiles=$src" /v:q /nologo 2>&1
    $text = ($out | Out-String)
    if ($LASTEXITCODE -ne 0 -or $text -match "error\s:") {
        $name = [System.IO.Path]::GetFileName($src)
        $failures.Add($name)
        $lines = $text -split "`n" | Where-Object { $_ -match "error\s:" }
        foreach ($line in $lines) {
            Write-Host "$name`: $($line.Trim())"
        }
        if ($FailFast) { throw "Failed on $name" }
    }
} -ThrottleLimit $Throttle -ArgumentList $BuildDir, $Config, $FailFast, $failures

$failed = @($failures | Sort-Object -Unique)
if ($failed.Count -gt 0) {
    Write-Host ""
    Write-Host "FAILED ($($failed.Count) file(s)):" -ForegroundColor Red
    $failed | ForEach-Object { Write-Host "  $_" }
    exit 1
}

Write-Host "OK: all $($sources.Count) translation unit(s) compile." -ForegroundColor Green
exit 0
