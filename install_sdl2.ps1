Push-Location $PSScriptRoot

Invoke-WebRequest https://github.com/libsdl-org/SDL/archive/refs/tags/release-2.30.6.zip -OutFile SDL2.zip

Expand-Archive SDL2.zip -DestinationPath SDL2_raw
mv SDL2_raw/* SDL2

rm -r SDL2_raw
rm SDL2.zip

Pop-Location
