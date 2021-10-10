cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME SFML_GAME0)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
src/main.cpp
src/Components/Renderable.cpp
src/Components/Updatable.cpp
src/Components/Eventable.cpp

src/Buffers/Buffer.cpp
src/Buffers/RenderBuffer.cpp
src/Buffers/UpdatableBuffer.cpp
src/Buffers/EventableBuffer.cpp

src/Global/Configuration.cpp

src/Entities/Player.cpp

src/World/World.cpp
)

add_subdirectory(external/sfml)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-system sfml-window sfml-network)