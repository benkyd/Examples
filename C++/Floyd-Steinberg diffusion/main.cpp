#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

struct Pixel {
    unsigned char r, g, b, a;
};

int index(int x, int y, int w) {
    return x+y*w;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Incorrect usage, use like ./output.o <imagepath>" << std::endl;
        return 0;
    }

    int w, h, c;
    Pixel* image = (Pixel*)stbi_load(*(argv + 1), &w, &h, &c, 4);
    if (image == NULL){
        std::cout << "Invalid image: " << stbi_failure_reason() << std::endl;
        return 0;
    }

    // Pixel* image = (Pixel*)malloc(sizeof(Pixel) * w * h * 4);
    // Pixel* image = (Pixel*)stbi_load(*(argv + 1), &w, &h, &c, 4);
    // Pixel* image = new Pixel[w * h * 4];

    // for (int y = 0; y < h - 1; y++) {
    //     for (int x = 1; x < w - 1; x++) {
    //         image[x + y * w] = {255, 255, 255, 255};
    //     }
    // }
    int colComplexity = 3;

    for (int y = 1; y < h - 1; y++) {
        for (int x = 1; x < w - 1; x++) {
            image[x + y * w].r = round(colComplexity * image[x + y * w].r / 255) * (255 / colComplexity); 
            image[x + y * w].g = round(colComplexity * image[x + y * w].g / 255) * (255 / colComplexity); 
            image[x + y * w].b = round(colComplexity * image[x + y * w].b / 255) * (255 / colComplexity);
            
            float errorR = image[x + y * w].r - image[x + y * w].r;
            float errorG = image[x + y * w].g - image[x + y * w].g;
            float errorB = image[x + y * w].b - image[x + y * w].b;

            int i = index(x+1, y, w);
            image[i].r = (float)image[i].r + errorR * (7.0f / 16.0f);
            image[i].g = (float)image[i].g + errorG * (7.0f / 16.0f);
            image[i].b = (float)image[i].b + errorB * (7.0f / 16.0f);

            i = index(x-1, y+1, w);
            image[i].r = (float)image[i].r + errorR * (3.0f / 16.0f);
            image[i].g = (float)image[i].g + errorG * (3.0f / 16.0f);
            image[i].b = (float)image[i].b + errorB * (3.0f / 16.0f);

            i = index(x, y+1, w);
            image[i].r = (float)image[i].r + errorR * (5.0f / 16.0f);
            image[i].g = (float)image[i].g + errorG * (5.0f / 16.0f);
            image[i].b = (float)image[i].b + errorB * (5.0f / 16.0f);

            i = index(x+1, y+1, w);
            image[i].r = (float)image[i].r + errorR * (1.0f / 16.0f);
            image[i].g = (float)image[i].g + errorG * (1.0f / 16.0f);
            image[i].b = (float)image[i].b + errorB * (1.0f / 16.0f);

            // int i = index(x+1, y, w);
            // float r = image[i].r;
            // float g = image[i].g;
            // float b = image[i].b;
            // r = r + errorR * 7/16.0;
            // g = g + errorG * 7/16.0;
            // b = b + errorB * 7/16.0;
            // image[i] = {r, g, b, 255};

            // i = index(x-1, y+1, w);
            // r = image[i].r;
            // g = image[i].g;
            // b = image[i].b;
            // r = r + errorR * 3/16.0;
            // g = g + errorG * 3/16.0;
            // b = b + errorB * 3/16.0;
            // image[i] = {r, g, b, 255};

            // i = index(x, y+1, w);
            // r = image[i].r;
            // g = image[i].g;
            // b = image[i].b;
            // r = r + errorR * 5/16.0;
            // g = g + errorG * 5/16.0;
            // b = b + errorB * 5/16.0;
            // image[i] = {r, g, b, 255};

            // i = index(x+1, y+1, w);
            // r = image[i].r;
            // g = image[i].g;
            // b = image[i].b;
            // r = r + errorR * 1/16.0;
            // g = g + errorG * 1/16.0;
            // b = b + errorB * 1/16.0;
            // image[i] = {r, g, b, 255};

            // pixel[x + 1][y    ] := pixel[x + 1][y    ] + quant_error * 7 / 16
            // pixel[x - 1][y + 1] := pixel[x - 1][y + 1] + quant_error * 3 / 16
            // pixel[x    ][y + 1] := pixel[x    ][y + 1] + quant_error * 5 / 16
            // pixel[x + 1][y + 1] := pixel[x + 1][y + 1] + quant_error * 1 / 16
        }
    }

    stbi_write_png("output.png", w, h, 4, (unsigned char*)image, 0);
}
