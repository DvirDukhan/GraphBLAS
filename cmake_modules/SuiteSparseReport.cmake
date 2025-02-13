#-------------------------------------------------------------------------------
# SuiteSparse/SuiteSparse_config/SuiteSparseReport.cmake
#-------------------------------------------------------------------------------

# Copyright (c) 2022, Timothy A. Davis.  All Rights Reserved.
# SPDX-License-Identifier: BSD-3-clause

#-------------------------------------------------------------------------------
# report status and compile flags
#-------------------------------------------------------------------------------

message ( STATUS "------------------------------------------------------------------------" )
message ( STATUS "SuiteSparse CMAKE report for: ${CMAKE_PROJECT_NAME}" )
message ( STATUS "------------------------------------------------------------------------" )
if ( GLOBAL_INSTALL )
    message ( STATUS "install in ${CMAKE_INSTALL_PREFIX}: true" )
else ( )
    message ( STATUS "install in ${CMAKE_INSTALL_PREFIX}: false" )
endif ( )
message ( STATUS "install in SuiteSparse/lib and SuiteSparse/include: ${INSIDE_SUITESPARSE}" )
message ( STATUS "build type:           ${CMAKE_BUILD_TYPE}" )
if ( NSTATIC )
    message ( STATUS "NSTATIC:              true (do not build static library)" )
else ( )
    message ( STATUS "NSTATIC:              false (build static library)" )
endif ( )
if ( OPENMP_FOUND )
    message ( STATUS "use OpenMP:           yes ")
else ( )
    message ( STATUS "use OpenMP:           no ")
endif ( )
message ( STATUS "C compiler:           ${CMAKE_C_COMPILER_ID} ")
message ( STATUS "C flags:              ${CMAKE_C_FLAGS}" )
message ( STATUS "C++ compiler:         ${CMAKE_CXX_COMPILER_ID}" )
message ( STATUS "C++ flags:            ${CMAKE_CXX_FLAGS}" )
if ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
    message ( STATUS "C Flags debug:        ${CMAKE_C_FLAGS_DEBUG} ")
    message ( STATUS "C++ Flags debug:      ${CMAKE_CXX_FLAGS_DEBUG} ")
else ( )
    message ( STATUS "C Flags release:      ${CMAKE_C_FLAGS_RELEASE} ")
    message ( STATUS "C++ Flags release:    ${CMAKE_CXX_FLAGS_RELEASE} ")
endif ( )
get_property ( CDEFN DIRECTORY PROPERTY COMPILE_DEFINITIONS )
message ( STATUS "compile definitions:  ${CDEFN}")
if ( DEFINED SuiteSparse_BLAS_integer )
    message ( STATUS "BLAS integer:         ${SuiteSparse_BLAS_integer}" )
endif ( )
if ( DEFINED CMAKE_CUDA_ARCHITECTURES )
    message ( STATUS "CUDA architectures:   ${CMAKE_CUDA_ARCHITECTURES}" )
endif ( )
if ( NPARTITION )
    message ( STATUS "NPARTITION:           do not use METIS" )
endif ( )
message ( STATUS "------------------------------------------------------------------------" )
