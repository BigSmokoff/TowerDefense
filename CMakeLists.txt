# задаем минимально требуемый стандарт сmake
cmake_minimum_required(VERSION 3.24)
# именуем проект и говорим что пишем на с++
project(TowerDefense VERSION 1.0 LANGUAGES CXX)

# задаем минимально требуемый стандарт с++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_STANDARD_REQUIRED ON)

# отключаем сборку примеров и тестов
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TEST_SUITE OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/sfml/CMakeLists.txt")
    message(FATAL_ERROR "SFML submodule не найден! Запустите: git submodule update --init --recursive")
endif()

# интегрируем исходный код SMFL и задаем путь для файлов компиляции
add_subdirectory(external/sfml external/sfml/build_out)

# объявляем исполняемый файл и перечисляем исходники
add_executable(${PROJECT_NAME}
	src/main.cpp
    src/Game.cpp
    src/Game.h
	src/IScene.h
	src/GameScene.h
	src/GameScene.cpp
	src/SceneType.h
	src/MainMenuScene.h
	src/MainMenuScene.cpp
)

# линукем модули SFML
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SFML::Graphics
    SFML::Window
    SFML::System
)