include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS IntelDFPF128 IntelDFP
    EXPORT IntelDFPTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    OBJECTS DESTINATION ${CMAKE_INSTALL_LIBDIR}/IntelDFP/objects
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/IntelDFP
    FILES_MATCHING PATTERN "*.h"
)

install(EXPORT IntelDFPTargets
    FILE IntelDFPTargets.cmake
    NAMESPACE IntelDFP::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/IntelDFP
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/IntelDFPConfigVersion.cmake"
    VERSION 2.0.0
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_SOURCE_DIR}/cmake/IntelDFPConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/IntelDFPConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/IntelDFP
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/IntelDFPConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/IntelDFPConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/IntelDFP
)
