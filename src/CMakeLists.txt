# Needs to link against mangos_worldd.lib
if(WIN32)
  link_directories(
    ${CMAKE_BINARY_DIR}/src/mangosd/${CMAKE_CFG_INTDIR}
  )
  include_directories(
    ${CMAKE_SOURCE_DIR}/dep/include # For Win32
  )
endif()

add_subdirectory(framework)
add_subdirectory(shared)
add_subdirectory(realmd)
add_subdirectory(game)
add_subdirectory(mangosd)
add_subdirectory(scriptdev2)
