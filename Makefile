CPP_FILES := $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/*/*/*.cpp) $(wildcard src/*/*/*/*.cpp) $(wildcard src/*/*/*/*/*.cpp)

all:
	g++ -g $(CPP_FILES) -o build\main.exe -DSFML_STATIC -I"dependencies\SFML\include" -I"src" -L"dependencies\SFML\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -static-libgcc -static-libstdc++ -static