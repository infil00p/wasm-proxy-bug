cmake_minimum_required(VERSION 3.4.1)


# C++ APIs are here
add_executable(
	proxying_api
	proxy_example.cpp
)

set(CMAKE_EXECUTABLE_SUFFIX ".html")

#set_target_properties(proxying_api PROPERTIES LINK_FLAGS "-o proxying_api.html -sEXPORTED_FUNCTIONS=_emscripten_proxy_finish,_main -sUSE_PTHREADS -pthread -s PROXY_TO_PTHREAD -s ALLOW_MEMORY_GROWTH=1 --js-library ../glue.js")
set_target_properties(proxying_api PROPERTIES LINK_FLAGS "-o proxying_api.html -sEXPORTED_FUNCTIONS=_wasmfs_create_opfs_backend,_emscripten_proxy_finish,_main -sUSE_PTHREADS -pthread -s PROXY_TO_PTHREAD -s WASMFS=1 -s ALLOW_MEMORY_GROWTH=1 --js-library ../glue.js")