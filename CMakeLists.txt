cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(print_ip VERSION ${PROJECT_VESRION})

set(SOURCE_EXE main.cpp)

add_executable(print_ip_cli ${SOURCE_EXE})

set_target_properties(print_ip_cli PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(print_ip_cli PRIVATE
        /W4
    )
    #target_compile_options(print_ip PRIVATE
   #     /W4
    #)
else ()
    target_compile_options(print_ip_cli PRIVATE
        -Wall -Wextra -Wpedantic
    )
    #target_compile_options(print_ip_cli PRIVATE
    #    -Wall -Wextra -Wpedantic
    #)
    #target_compile_options(print_ip PRIVATE
   #     -Wall -Wextra -pedantic -Werror
    #)
   # target_compile_options(print_ip PRIVATE
    #-Wall -Wextra -Wpedantic
#)
endif()

install(TARGETS print_ip_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)