#
# This file is part of the Everwar Project. See AUTHORS file for Copyright information
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#

set(LIBRARY_NAME mangosd_lib)

set(LIBRARY_SRCS
    CliRunnable.cpp
    CliRunnable.h
    MaNGOSsoap.cpp
    MaNGOSsoap.h
    Master.cpp
    Master.h
    RASocket.cpp
    RASocket.h
    WorldRunnable.cpp
    WorldRunnable.h
    soapC.cpp
    soapH.h
    soapServer.cpp
    soapStub.h
   )

if(WIN32)
  # add resource file to windows build
  set(LIBRARY_SRCS ${LIBRARY_SRCS} mangosd.rc)
endif()



if(POSTGRESQL)
  include_directories(${PGSQL_INCLUDE_DIR})
else()
  include_directories(${MYSQL_INCLUDE_DIR})
endif()

add_library(${LIBRARY_NAME}
  ${LIBRARY_SRCS}
)

target_include_directories(${LIBRARY_NAME}
        PUBLIC
            ${CMAKE_SOURCE_DIR}/src/shared
            ${CMAKE_SOURCE_DIR}/dep/include/gsoap
            ${CMAKE_SOURCE_DIR}/src/framework
            ${CMAKE_SOURCE_DIR}/src/game
            ${CMAKE_BINARY_DIR}
            ${CMAKE_BINARY_DIR}/src/shared
            ${OPENSSL_INCLUDE_DIR}
)
add_dependencies(${LIBRARY_NAME} revision.h)

target_link_libraries(${LIBRARY_NAME}
  game
  shared
  framework
  g3dlite
  gsoap
  boost_program_options
  boost_system
  boost_thread
)

if(WIN32)
  target_link_libraries(${LIBRARY_NAME}
    zlib
    optimized ${MYSQL_LIBRARY}
    optimized ${OPENSSL_LIBRARIES}
    debug ${MYSQL_DEBUG_LIBRARY}
    debug ${OPENSSL_DEBUG_LIBRARIES}
  )
  if(PLATFORM MATCHES X86)
    target_link_libraries(${LIBRARY_NAME})
  endif()
endif()

if(UNIX)
  target_link_libraries(${LIBRARY_NAME}
    ${MYSQL_LIBRARY}
    ${OPENSSL_LIBRARIES}
    ${OPENSSL_EXTRA_LIBRARIES}
    ${ZLIB_LIBRARIES}
  )
endif()

set(LIBRARY_LINK_FLAGS "")

if(UNIX)
  if (APPLE)
    set(LIBRARY_LINK_FLAGS "-pthread -framework Carbon")
  else()
    set(LIBRARY_LINK_FLAGS "-pthread -rdynamic")
  endif()
endif()

set_target_properties(${LIBRARY_NAME} PROPERTIES LINK_FLAGS
  "${LIBRARY_LINK_FLAGS}"
)

install(TARGETS ${LIBRARY_NAME} DESTINATION ${LIB_DIR})
install(FILES run-mangosd DESTINATION ${LIB_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mangosd.conf.dist.in ${CMAKE_CURRENT_BINARY_DIR}/mangosd.conf.dist)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/mangosd.conf.dist DESTINATION ${CONF_DIR})

if(WIN32 AND MSVC)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/\${BUILD_TYPE}/${LIBRARY_NAME}.pdb DESTINATION ${LIB_DIR} CONFIGURATIONS Debug)
endif()
