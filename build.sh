mkdir -p .out
clang -c ./external/glad/src/glad.c -I./external/glad/include
# clang -c src/*.c -I./external/glad/include -I./external/glfw/include
clang++ -c src/*.cpp -I./external/glad/include -I./external/glfw/include
clang++ -o ./.out/renderer.out ./*.o -L./external/glfw/src -lglfw3
rm ./*.o
