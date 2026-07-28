cmake_minimum_required(VERSION 3.10)
project(experimento_app)

set(CMAKE_CXX_STANDARD 23)

# Поиск SFML
find_package(
        SFML 3
        REQUIRED
        COMPONENTS
        Graphics
        Audio
        Network
        System
        Window
)


# Исходные файлы
set(SOURCES
        main.cc
        PhysicsWorld.cc
        PhysicsWorld.h
)

# Добавление исполняемого файла
add_executable(experimento_app ${SOURCES})

# Подключение SFML
target_link_libraries(
        experimento_app
        PRIVATE
        SFML::Graphics
        SFML::Audio
        SFML::Network
        SFML::System
        SFML::Window
)

