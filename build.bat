g++ -g src\* -o build\main1.exe -DSFML_STATIC -I"dependencies\SFML\include" -L"dependencies\SFML\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -static-libgcc -static-libstdc++ -static