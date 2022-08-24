# --------------------
# import google test
# --------------------
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --------------------
# import unittest files
# --------------------
include(GoogleTest)
list(APPEND UNIT_TESTS
    unit_test
    hello_test)

foreach (UNIT_TEST IN LISTS UNIT_TESTS)
  add_executable(
      ${UNIT_TEST}
      ${UNIT_TEST}.cc
  )

  target_link_libraries(
      ${UNIT_TEST}
      GTest::gtest_main
      ${PROJECT_NAME}
  )
  gtest_discover_tests(${UNIT_TEST})
endforeach ()