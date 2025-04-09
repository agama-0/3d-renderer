cmake external/glfw -B glfw-build
cd glfw_build
make
cd ../
cp glfw-build/src/libglfw3.a ./external/glfw/src
