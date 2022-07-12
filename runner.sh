#!/bin/bash
cd bin
g++ -I../include/  -I../vendor/include/ -c ../src/*.cpp ../src/*.c
cd ..
echo "Compilation done"
g++ -o bin/openglCurrent -Lvendor/lib/ bin/*.o -lGL -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi 
echo "Linking done"
./bin/openglCurrent
