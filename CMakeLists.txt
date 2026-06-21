# задаем минимально требуемый стандарт сmake
cmake_minimum_required(VERSION 3.15)
# именуем проект и говорим что пишем на с++
project(TowerDefense LANGUAGES CXX)

# задаем минимально требуемый стандарт с++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_STANDARD_REQUIRED ON)
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/SFML-3.1.0/lib/cmake/SFML")

# находим пакет SFML и создаем умные ярлыки
find_package(SFML 3.1.0 COMPONENTS Graphics Window System REQUIRED)

# объявляем исполняемый файл
add_executable(TowerDefense main.cpp Game.cpp Game.h)

# линкуем пакет по ярлыкам к проекту 
target_link_libraries(TowerDefense PRIVATE SFML::Graphics SFML::Window SFML::System)