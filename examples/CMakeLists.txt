


add_executable(oop_example oop.cc)
target_link_libraries(oop_example PRIVATE xcmixin)
add_executable(oop_test test.cc)
target_link_libraries(oop_test PRIVATE xcmixin)
