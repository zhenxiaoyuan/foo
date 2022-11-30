set scriptpath=%~dp0

cd vendor/SDL_image
cmake -H. -G Ninja -Bbuild -DCMAKE_C_COMPILER="C:/Program Files/LLVM/bin/clang.exe" -DCMAKE_CXX_COMPILER="C:/Program Files/LLVM/bin/clang.exe" -DCMAKE_LINKER="C:/Program Files/LLVM/bin/lld-link.exe" -DCMAKE_BUILD_TYPE=Release

cd build
ninja

