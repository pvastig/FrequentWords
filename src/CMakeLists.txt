set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY} main.cpp)

target_link_libraries(${BINARY} PUBLIC ${BINARY}_lib)
