#ifndef _IMAGE_PACK_H_
#define _IMAGE_PACK_H_

#include "SDL/SDL.h"
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

using std::string;

typedef std::map<string, SDL_Surface *> SurfaceMap;
typedef std::vector<string> StringVector;

/**
 * ImagePack loads and manages SDL image surfaces.
 */
class ImagePack {
private:
    SurfaceMap images;

    void add_image(string path);
public:
    ImagePack(StringVector paths);
    ~ImagePack();
    
    SDL_Surface *get_image(string path);
};

#endif

// Local Variables:
// mode: c++
// End:
