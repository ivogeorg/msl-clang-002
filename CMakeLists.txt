cmake_minimum_required(VERSION 3.5)
project(msl-clang-002)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Werror")

set(SOURCE_FILES
    main.c rb_node.c test_suite.h test_suite.c)

#add_library(libcmocka SHARED IMPORTED)
#set_property(TARGET libcmocka PROPERTY IMPORTED_LOCATION /usr/local/lib/libcmocka.0.4.1.dylib) # For MacOS installation
## TODO: Try to use find_library() to make it work on all platforms following the prescribed platform-specific installation

add_executable(msl-clang-002 ${SOURCE_FILES})

#target_link_libraries(msl-clang-002 libcmocka)
