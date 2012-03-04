#include "utils.h"
#include <iostream>

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if (loadedImage) {
        // Create an optimized surface (alpha so PNGs retain transparency)
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );
    } else {
        std::cerr << SDL_GetError() << std::endl;
    }

    //Return the optimized surface
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
