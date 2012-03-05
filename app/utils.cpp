#include "utils.h"
#include <iostream>
#include <stdexcept>

// The following code is taken from http://www.lazyfoo.net/SDL_tutorials/.
// I added the exception stuff.

using std::string;

/**
 * Given an image path from the project root, returns an SDL_Surface of the
 * image.
 *
 * @param filename The path
 * @return The surface
 */
SDL_Surface *load_image(string filename) {
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;

    loadedImage = IMG_Load(filename.c_str());

    if (loadedImage) {
        // Create an optimized surface (alpha so PNGs retain transparency)
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
        // Free the old surface
        SDL_FreeSurface( loadedImage );
    } else {
        throw new std::runtime_error(string("Unable to load image at ") +
                                            filename);
    }

    return optimizedImage;
}

/**
 * Given the x and y offsets, a source surface, and a destination surface,
 * blits the source surface to the destination at those offsets. Include the
 * optional clip rect to only apply the given dimensions of the source
 * surface.
 *
 * @param x The x offset
 * @param y The y offset
 * @param source The source surface
 * @param destination The destination surface
 * @param clip The clip rect
 */
void apply_surface(int x, int y, SDL_Surface* source,
                   SDL_Surface* destination, SDL_Rect* clip) {
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, clip, destination, &offset);
}
