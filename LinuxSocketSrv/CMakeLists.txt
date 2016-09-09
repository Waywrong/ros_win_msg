project(iubotserver)

add_executable(iubotserver main.cpp)

install(TARGETS iubotserver RUNTIME DESTINATION bin)

target_link_libraries(iubotserver -lpthread)