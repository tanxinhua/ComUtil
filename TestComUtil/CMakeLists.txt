project(TestComUtil)

set(TEST_COM_UTIL_INCLUDE)
set(TEST_COM_UTIL_SOURCE
    main.cpp)

source_group(include FILES ${COM_UTIL_INCLUDE})
source_group(source FILES ${TEST_COM_UTIL_SOURCE})

include_directories(../ComUtil)

add_executable(TestComUtil ${TEST_COM_UTIL_SOURCE})

target_link_libraries(TestComUtil ComUtil)