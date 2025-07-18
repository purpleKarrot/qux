# Copyright 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.

cmake_minimum_required(VERSION 3.31)
project(Qux
  VERSION 1.0.0
  LANGUAGES C
  )

if(Qux_IS_TOP_LEVEL)
  option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
endif()

add_library(qux)
add_library(Qux::qux ALIAS qux)

target_sources(qux
  PUBLIC FILE_SET HEADERS FILES
    qux.h
  PRIVATE
    qux.c
  )

get_target_property(qux_type qux TYPE)
if(qux_type STREQUAL "STATIC_LIBRARY")
  target_compile_definitions(qux PUBLIC qux_STATIC foo)
endif()

set_target_properties(qux PROPERTIES
  C_VISIBILITY_PRESET hidden
  VERSION ${Qux_VERSION}
  SOVERSION ${Qux_VERSION_MAJOR}
  DLL_NAME_WITH_SOVERSION ON
  )

include(GNUInstallDirs)
if(WIN32)
  set(cmake_package_config_dir "cmake")
else()
  set(cmake_package_config_dir "${CMAKE_INSTALL_LIBDIR}/cmake/Qux")
endif()

install(TARGETS qux EXPORT qux-targets
  ARCHIVE
    COMPONENT develop
  LIBRARY
    CONFIGURATIONS Debug
    COMPONENT develop
  LIBRARY
    CONFIGURATIONS Release
    COMPONENT runtime
    NAMELINK_COMPONENT develop
  RUNTIME
    CONFIGURATIONS Debug
    COMPONENT develop
  RUNTIME
    CONFIGURATIONS Release
    COMPONENT runtime
  FILE_SET HEADERS
    COMPONENT develop
  )

install(EXPORT qux-targets DESTINATION ${cmake_package_config_dir}
  FILE qux-config.cmake
  NAMESPACE Qux::
  COMPONENT develop
  )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(qux-config-version.cmake
  COMPATIBILITY SameMajorVersion
  )

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/qux-config-version.cmake
  DESTINATION ${cmake_package_config_dir}
  COMPONENT develop
  )

include(CPack)
