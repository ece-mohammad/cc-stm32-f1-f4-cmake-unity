#include <{{cookiecutter.project_name}}.h>

#include <unity.h>
#include <unity_fixture.h>

TEST_GROUP({{cookiecutter.project_name}});

TEST_SETUP({{cookiecutter.project_name}}) {
}

TEST_TEAR_DOWN({{cookiecutter.project_name}}) {
}

TEST({{cookiecutter.project_name}}, first_test){
  TEST_FAIL_MESSAGE("Not implemented yet");
}


TEST_GROUP_RUNNER({{cookiecutter.project_name}}) {
    RUN_TEST_CASE({{cookiecutter.project_name}}, first_test);
}
