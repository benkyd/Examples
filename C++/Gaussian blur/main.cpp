#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

struct Pixel {
    unsigned char r, g, b, a;
};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::err << "Invalid usage" << std::endl;
        return 0;
    }


    Pixel* image = 

}
