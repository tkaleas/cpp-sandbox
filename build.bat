mkdir build
cd build

@REM Generate a Visual Studio Sln
cmake .. -G "Visual Studio 15 2017 Win64"

@REM Build default config
cmake --build .

@REM Copy Test File to Proper CMake Directory
copy ..\test_books.txt .\src\test_books.txt

cd ..