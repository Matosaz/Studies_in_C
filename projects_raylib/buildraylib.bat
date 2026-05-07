@echo off
setlocal

cd /d C:\Projects\Studies_in_C\projects_raylib

set "PATH=C:\msys64\ucrt64\bin;%PATH%"

gcc.exe main.c -o main.exe ^
-IC:\Projects\Studies_in_C\Raylib\raylib-6.0_win64_mingw-w64\include ^
-LC:\Projects\Studies_in_C\Raylib\raylib-6.0_win64_mingw-w64\lib ^
-lraylib -lopengl32 -lgdi32 -lwinmm

if errorlevel 1 (
    echo.
    echo ERRO NA COMPILACAO
    exit /b 1
)

echo.
echo COMPILADO COM SUCESSO
exit /b 0