compileflags=''
if [ $# -eq 1 ]
  then
    compileflags=$1
fi
set -x
mkdir -p .out
clang -c ./external/glad/src/glad.c -I./external/glad/include -I./external/ $compileflags
clang++ -c src/*.cpp -I./external/glad/include -I./external/glfw/include -I./external/ $compileflags
clang++ -o ./.out/renderer.out ./*.o -L./external/glfw/src -lglfw3 $compileflags
rm ./*.o
