cmake_minimum_required(VERSION 2.8)
INCLUDE(CPack)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# the RPATH to be used when installing, but only if it's not a system directory
LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
IF("${isSystemDir}" STREQUAL "-1")
   SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
ENDIF("${isSystemDir}" STREQUAL "-1")

project(exru)
set (EXRU_VERSION_MAJOR 1)
set (EXRU_VERSION_MINOR 0)
set (EXRU_VERSION_PATCH 0)
set (EXRU_VERSION ${EXRU_VERSION_MAJOR}.${EXRU_VERSION_MINOR}.${EXRU_VERSION_PATCH})
include_directories(src) 
FIND_PACKAGE(OpenEXR REQUIRED)
add_subdirectory(config)

set(SOURCES)
set(SOURCES ${SOURCES} src/exru.cpp)
set(SOURCES ${SOURCES} src/exru.h)
source_group(exru FILES src/exru.cpp src/exru.h)
add_library(exru SHARED ${SOURCES})
include_directories(${OPENEXR_INCLUDE_DIRS})
target_link_libraries(exru ${OPENEXR_LIBRARIES})
set_target_properties(exru PROPERTIES VERSION ${EXRU_VERSION} 
                                      SOVERSION ${EXRU_VERSION_MAJOR})
install (TARGETS exru DESTINATION lib)
install (FILES src/exru.h DESTINATION include/exru)

