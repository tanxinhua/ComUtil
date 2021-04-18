project(ComUtil)

set(COM_UTIL_INCLUDE
    Singleton.hpp)
set(COM_UTIL_SOURCE
    Singleton.cpp)
	
source_group("include" FILES ${COM_UTIL_INCLUDE})
source_group("source" FILES ${COM_UTIL_SOURCE})

#add_library(ComUtil SHARED ${COM_UTIL_SOURCE} ${COM_UTIL_INCLUDE})
add_library(ComUtil STATIC ${COM_UTIL_SOURCE} ${COM_UTIL_INCLUDE})

