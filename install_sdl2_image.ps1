Push-Location $PSScriptRoot

Invoke-WebRequest https://github.com/libsdl-org/SDL_image/releases/download/release-2.8.2/SDL2_image-devel-2.8.2-VC.zip -OutFile SDL2_image.zip

Expand-Archive SDL2_image.zip -DestinationPath SDL2_image_raw
mv SDL2_image_raw/* SDL2_image

rm -r SDL2_image_raw
rm SDL2_image.zip

Pop-Location
