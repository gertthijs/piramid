cmake_minimum_required (VERSION 2.6) 

# Project
project(piramid)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)
find_package(OpenBabel2 REQUIRED)

# Version
set (${PROJECT_NAME}_VERSION_MAJOR 1)
set (${PROJECT_NAME}_VERSION_MINOR 0)
set (${PROJECT_NAME}_VERSION_PATCH 2)
configure_file ("${PROJECT_SOURCE_DIR}/piramidConfig.h.in" "${PROJECT_SOURCE_DIR}/include/piramidConfig.h")

# Release type
set (CMAKE_BUILD_TYPE Release)

# Sieve code
set (PiramidDir ${PROJECT_SOURCE_DIR}/src)
set (sources     ${PiramidDir}/main.cpp
                 ${PiramidDir}/alignmentInfo.cpp
                 ${PiramidDir}/atomGaussian.cpp
                 ${PiramidDir}/bestResults.cpp
                 ${PiramidDir}/coordinate.cpp
                 ${PiramidDir}/gaussianVolume.cpp
                 ${PiramidDir}/mainErr.cpp
                 ${PiramidDir}/moleculeRotation.cpp
                 ${PiramidDir}/options.cpp
                 ${PiramidDir}/parseCommandLine.cpp
                 ${PiramidDir}/printHeader.cpp
                 ${PiramidDir}/printUsage.cpp
                 ${PiramidDir}/shapeAlignment.cpp
                 ${PiramidDir}/siMath.cpp
                 ${PiramidDir}/solutionInfo.cpp
)

# Include files from piramid project
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${OPENBABEL2_INCLUDE_DIR})

# Executables
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} ${OPENBABEL2_LIBRARIES})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)


#-----------------------------------------
# packaging source tar.gz
#
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Shape-based alignment of molecules.")
set(CPACK_PACKAGE_VENDOR "Silicos NV")
set(CPACK_PACKAGE_VERSION_MAJOR @piramid_VERSION_MAJOR@)
set(CPACK_PACKAGE_VERSION_MINOR @piramid_VERSION_MINOR@)
set(CPACK_PACKAGE_VERSION_PATCH @piramid_VERSION_PATCH@)

set(CPACK_RESOURCE_FILE_LICENSE "COPYING")
set(CPACK_RESOURCE_FILE_README "README.TXT")

set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES 
	".svn;/CMakeFiles/;.DS_Store;/_CPack_Packages/;CMakeCache.txt;piramid.tmproj;Makefile"
)
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

include(CPack)


