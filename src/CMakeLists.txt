target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
)

target_sources(${PROJECT_NAME} PRIVATE 
    main.cpp
    pg/window.cpp
    pg/screen.cpp
    pg/screen_manager.cpp
    pg/engine.cpp
    pg/transition.cpp
)