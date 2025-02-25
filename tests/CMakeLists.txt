# tests/CMakeLists.txt

# Create a test executable that tests the user library.
add_executable(test_user_library test_user_library.cpp)

# Link the test executable with the user_library
target_link_libraries(test_user_library PRIVATE user_library)

# Optionally, if using CTest, you could add:
# enable_testing()
# add_test(NAME UserLibraryTest COMMAND test_user_library)
