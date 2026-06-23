# задаем минимально требуемый стандарт сmake
cmake_minimum_required(VERSION 3.24)
# именуем проект и говорим что пишем на с++
project(TowerDefense VERSION 1.0 LANGUAGES CXX)

# задаем минимально требуемый стандарт с++
set(CMAKE_CXX_STANDARD 20)
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
	src/Core/main.cpp
	src/Core/Config.h
	src/Core/Game.h
	src/Core/Game.cpp
	src/Scenes/IScene.h
	src/Scenes/GameScene.h
	src/Scenes/GameScene.cpp
	src/Scenes/SceneType.h
	src/Scenes/MainMenuScene.h
	src/Scenes/MainMenuScene.cpp
	src/GameObjects/GameObject.h
	src/GameObjects/Monster.h
	src/GameObjects/Monster.cpp
	src/Managers/MonsterFactory.cpp
	src/Managers/MonsterFactory.h
	src/GameObjects/TownHall.h
	src/GameObjects/TownHall.cpp
	src/GameObjects/Tower.h
	src/GameObjects/Tower.cpp
	src/GameObjects/Projectile.h
	src/GameObjects/Projectile.cpp
	src/Managers/WaveManager.h
	src/Managers/WaveManager.cpp
	src/Managers/PlayerState.h
	src/Managers/PlayerState.cpp
)

# настройка рабочего каталога для Visual Studio
set_target_properties(TowerDefense PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

# линукем модули SFML
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SFML::Graphics
    SFML::Window
    SFML::System
)