# It is not recommended to compile on the Windows platform
# we suggest you compile it on the Linux platform, for example CentOS 6.5, or CentOS 7.x

if ( MSVC )
  include("${ROOT_DIR}/cmake/compiler/msvc/settings.cmake")
endif()
