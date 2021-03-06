cmake_minimum_required(VERSION 3.5)

project(editor VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(editor_cli main.cpp model.h model.cpp controller.h view.h gliph.h)

set_target_properties(editor_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

install(TARGETS editor_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT senyacherenkov@yandex.ru)

include (CPack)
