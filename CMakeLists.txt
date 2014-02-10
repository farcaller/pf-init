cmake_minimum_required(VERSION 2.6)
project(pf-init)

set(VERSION "0.0.1")

add_definitions(-Ofast -std=c99 -fPIC -W -Wall -pedantic -D_GNU_SOURCE)

add_executable(pf-init pf-init.c)

install(TARGETS pf-init DESTINATION bin)

set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "pf-init")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Oleksandr Natalenko <oleksandr@natalenko.name>")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
include(CPack)

