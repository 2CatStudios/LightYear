cmake_minimum_required(VERSION 3.0)
project(LightYear C CXX)


#Set the directory which contains our "helper files" for finding external libraries
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${LightYear_SOURCE_DIR}/cmake")
set(BIN_DIR ${LightYear_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



#Find SDL2, our core window library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#Find SDL2_TTF, an extension for SDL2 that allows us to use TTF fonts
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

#Find SDL2_Image, another SDL2 extension; this one makes displaying images easier
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})



#Copy the resources folder into the binary directory
file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#Define KISS_SDL Preprocessor Macro (RESDIR found in kiss_sdl.h, used to locate KISS assets (font files, textures, etc.))
add_definitions(-DRESDIR=\"../resources/\")



#Include all files in the /include directory (our .h files)
include_directories(include/LightYear/)

#Define paths for our external libraries (for convenience)
set (KISSSDL_PATH lib/kiss_sdl-1.2.2/)
set (PUGIXML_PATH lib/pugixml/)

#Include our libraries from /lib (pugixml and kiss_sdl)
include_directories (${KISSSDL_PATH})
include_directories (${PUGIXML_PATH})



#Define SOURCES to simplify the add_executable step. This contains our source code, and the source files from included libraries.
<<<<<<< HEAD
set (SOURCES src/main.cpp src/CoreLoopDelegate.cpp src/InputManager.cpp src/RenderingManager.cpp src/UIManager.cpp src/LocalizationManager.cpp src/XMLManager.cpp ${PUGIXML_PATH}/pugixml.cpp ${KISSSDL_PATH}/kiss_draw.c ${KISSSDL_PATH}/kiss_general.c ${KISSSDL_PATH}/kiss_posix.c ${KISSSDL_PATH}/kiss_widgets.c)
=======
set (SOURCES src/main.cpp src/CoreLoopDelegate.cpp src/InputManager.cpp src/RenderingManager.cpp src/LocalizationManager.cpp src/XMLManager.cpp src/FileManager.cpp ${PUGIXML_PATH}/pugixml.cpp ${KISSSDL_PATH}/kiss_draw.c ${KISSSDL_PATH}/kiss_general.c ${KISSSDL_PATH}/kiss_posix.c ${KISSSDL_PATH}/kiss_widgets.c)
>>>>>>> dry-ui



#Add our code and loose libraries to the project
add_executable(LightYear ${SOURCES})

#Link the external libraries (SDL2)
target_link_libraries(LightYear ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY})

#Put the compiled application in the bin directory
install(TARGETS LightYear RUNTIME DESTINATION ${BIN_DIR})
