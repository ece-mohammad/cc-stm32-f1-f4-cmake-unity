#include <unity.h>
#include <unity_fixture.h>
#include <platform.h>


void RunAllTests(void) {
  RUN_TEST_GROUP({{cookiecutter.project_name}});
}


int main(void) {
  const char* argv[] = {
    "test_{{cookiecutter.project_name}}",
    "-v"
  };
  platform_init();
  return UnityMain(sizeof(argv)/sizeof(argv[0]), argv, RunAllTests);
}
