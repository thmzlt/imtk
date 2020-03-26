cmake_minimum_required(VERSION 3.16)

project(imtk VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE src_files src/*.cpp src/*.cpp)
file(GLOB_RECURSE include_files include/*.h)

set(include_files
    imconfig-SFML.h
    imconfig.h
    imconfig-SFML_export.h
    imgui.h
    imgui_internal.h
    imgui_plot.h
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h)

set(src_files src/imgui-SFML.cpp src/imgui.cpp src/imgui_draw.cpp
              src/imgui_plot.cpp src/imgui_widgets.cpp)

add_library(imtk ${src_files})
target_link_libraries(imtk GL sfml-graphics sfml-system sfml-window)
target_include_directories(imtk PUBLIC include/)

add_executable(imgui-demo src/imgui_demo.cpp src/imgui_demo_main.cpp
                          ${src_files})
target_link_libraries(imgui-demo imtk)
target_include_directories(imgui-demo PUBLIC include/)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS imtk DESTINATION lib)
install(TARGETS imgui-demo DESTINATION bin)
