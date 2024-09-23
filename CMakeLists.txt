# cmake_minimum_required(VERSION 3.24)
# project(cmake_sfml_1)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(SFML_STATIC_LIBRARIES TRUE) #только если статическая сборка библиотеки
# find_package(SFML 2.6.1 COMPONENTS graphics window system)

# add_executable(cmake_sfml rightnow.cpp)
# target_link_libraries(cmake_sfml sfml-graphics sfml-window sfml-system)

#### THIS CODE IS NOT MINE AND WAS TAKEN FROM A FORUM
cmake_minimum_required( VERSION 3.10 )

project( Kartinka VERSION 1.0 LANGUAGES CXX )
set( CMAKE_CXX_STANDARD 14 )


# set INC and SRC files
set( SRC 
    main.cpp 
)
set( INC 
    inc/
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -lncurses -lstdc++")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")


add_subdirectory(sorts)
add_subdirectory(tests)
add_subdirectory(random)
add_subdirectory(drawing)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})




add_executable( ${PROJECT_NAME} ${SRC} )
SET(CURSES_USE_NCURSES TRUE)
target_include_directories( ${PROJECT_NAME} PUBLIC ${INC} )
target_link_libraries( ${PROJECT_NAME} PUBLIC ${SFML_LIBS} ${OPEN_GL_LIBS} )
#### THIS CODE IS NOT MINE AND WAS TAKEN FROM A FORUM

