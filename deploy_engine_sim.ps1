Push-Location $PSScriptRoot

cp SDL2\lib\x64\SDL2.dll build\Release\
cp SDL2_image\lib\x64\SDL2_image.dll build\Release\

cp dependencies\submodules\delta-studio\dependencies\runtime\x64\d3dcompiler_47.dll build\Release\
cp dependencies\submodules\delta-studio\dependencies\runtime\x64\d3dcsx_47.dll build\Release\
cp dependencies\submodules\delta-studio\dependencies\runtime\x64\D3DX10d_43.dll build\Release\
cp dependencies\submodules\delta-studio\dependencies\runtime\x64\D3DX11d_43.dll build\Release\
cp dependencies\submodules\delta-studio\dependencies\runtime\x64\d3dx9d_33.dll build\Release\
cp dependencies\submodules\delta-studio\dependencies\runtime\x64\D3DX9d_43.dll build\Release\

Pop-Location
