Push-Location $PSScriptRoot

git clone https://github.com/gre-42/engine-sim.git

cd engine-sim
mkdir build
cd build

$env:SDL2DIR=$(Resolve-Path "..\SDL2")
$env:SDL2IMAGEDIR=$(Resolve-Path "..\SDL2_image")

cmake ..
cmake --build . --config Release -j 8 --verbose

Pop-Location
