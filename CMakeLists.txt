cmake_minimum_required(VERSION 2.8)
project(grapsGen C)
add_executable(grapsGen grapsGen main.c loadingjsonfile.c drawgraph.c plotgraph.c)
##Proof of concept
##add_executable(grapsGen textRotation.c ./include/plottingutils.c)
target_link_libraries(grapsGen jansson)
target_link_libraries(grapsGen cairo)
 set(CMAKE_C_FLAGS "-std=c99")
file(GLOB FILE_IS_JSON
  "*.json"
)
file(COPY ${FILE_IS_JSON} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
install(TARGETS grapsGen DESTINATION build)
