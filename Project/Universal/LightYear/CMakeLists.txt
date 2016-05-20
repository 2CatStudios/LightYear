cmake_minimum_required(VERSION 3.0)
project(LightYear C CXX)


#Set the directory which contains our "helper files" for finding external libraries
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${LightYear_SOURCE_DIR}/cmake")
set(BIN_DIR ${LightYear_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Define KISS_SDL Preprocessor Macro (RESDIR found in kiss_sdl.h, used to locat KISS assets (font files, textures, etc.))
add_definitions(-DRESDIR=\"../../resources/\")

#Find SDL2, our core window library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#Find SDL2_TTF, an extension for SDL2 that allows us to use TTF fonts
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

#Find SDL2_Image, another SDL2 extension; this one makes displaying images easier
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

#Include all files in the /include directory (our .h files)
include_directories(include)

#Add our code and loose libraries to the project
add_executable(LightYear src/main.cpp src/LoopController.cpp src/EventManager.cpp src/LogicDelegate.cpp src/RenderManager.cpp src/WindowManager.cpp lib/kiss_sdl-0.10.4/kiss_draw.c lib/kiss_sdl-0.10.4/kiss_general.c lib/kiss_sdl-0.10.4/kiss_posix.c lib/kiss_sdl-0.10.4/kiss_widgets.c lib/pugixml/pugixml.cpp)

#Link the found libraries
target_link_libraries(LightYear ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY})

#Put the compiled application in /bin
install(TARGETS LightYear RUNTIME DESTINATION ${BIN_DIR})
