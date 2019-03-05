mkdir build
cd build

@REM Generate a Visual Studio Sln
cmake .. -G "Visual Studio 15 2017 Win64"

@REM Build default config
cmake --build .

cd ..