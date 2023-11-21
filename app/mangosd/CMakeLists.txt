message("CMakeLists.txt load mangosd ...")

SET(MAIN_EXECUTE mangosd)

add_executable(${MAIN_EXECUTE} mangosd.cpp)   # Name of exec. and location of file.

include_directories(
        ${CMAKE_SOURCE_DIR}/src/mangosd
)

target_link_libraries(${MAIN_EXECUTE}
        PRIVATE
        mangosd_lib
        )

target_set_warnings(${MAIN_EXECUTE} ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).
target_enable_lto(${MAIN_EXECUTE} optimized)  # enable link-time-optimization if available for non-debug configurations

target_compile_definitions(${MAIN_EXECUTE} PRIVATE BOOST_STACKTRACE_USE_ADDR2LINE)
target_link_libraries(${MAIN_EXECUTE} PRIVATE dl)

## cmake 3.27 required
#target_link_options(${MAIN_EXECUTE} PRIVATE "-no-pie")

install(TARGETS ${MAIN_EXECUTE} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
