project( QDigibib CXX )

set(CMAKE_VERBOSE_MAKEFILE ON)

cmake_minimum_required(VERSION 2.6.0)

find_package(Qt4 4.5.0 REQUIRED)

SET(QT_USE_QTTEST true)

include(${QT_USE_FILE})

add_subdirectory( src )
