#include "image_pack.h"
#include "utils.h"
#include <algorithm>

ImagePack::ImagePack(StringVector paths) :
    images() {
    for_each(paths.begin(), paths.end(),
             std::bind1st(std::mem_fun(&ImagePack::add_image), this));
}

/**
 * Adds an image to the pack. As ImagePacks are supposed to load all images
 * before processing, this is NOT a public function, and should only be called
 * in the constructor. ImagePacks should be immutable.
 *
 * @param path The path to the image relative to the /res directory.
 */
void ImagePack::add_image(string path) {
    SDL_Surface *image = load_image(string("res/") + path);
    images.insert(SurfaceMap::value_type(path, image));
}

/**
 * Frees any memory being used by images in the pack
 */
ImagePack::~ImagePack() {
    SurfaceMap::iterator iter;

    for (iter = images.begin(); iter != images.end(); ++iter) {
        SDL_FreeSurface(iter->second);
    }
}

/**
 * Given the path to an image contained in the ImagePack from the /res directory,
 * returns the surface.
 *
 * @param path The path
 * @return The image
 */
SDL_Surface *ImagePack::get_image(string path) {
    SurfaceMap::iterator iter = images.find(path);

    if (iter == images.end()) {
        throw std::invalid_argument(string("ImagePack does not contain "
                                           "image at ") + path);
    }

    return iter->second;
}
