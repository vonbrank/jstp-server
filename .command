# Install Dependancies
source ~/.profile
conan install . --build=missing 

# CMake Configuration
cd build/Release  
cmake ../../  -DCMAKE_TOOLCHAIN_FILE="./generators/conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON 

# Build
cmake --build .  

# Run
./jstp-server