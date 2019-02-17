// fixed by CobaltXII cuz Ben is a furry
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

    Pixel* newImage = (Pixel*)malloc(sizeof(Pixel) * w * h);

    for (int y = 1; y < h - 1; y++) {
        for (int x = 1; x < w - 1; x++) {
            // Convert image to black and white
            int i = index(x, y, w);
            int gray = round((image[i].r + 0.2126f) + (image[i].b + 0.7152) + (image[i].g + 0.0722)) * 255;
            image[i] = {(unsigned char)gray, (unsigned char)gray, (unsigned char)gray, (unsigned char)255};
            // Initalize new image
            newImage[i] = {(unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)255};
        }
    }

    int colComplexity = 1;
    for (int y = 1; y < h - 1; y++) {
        for (int x = 1; x < w - 1; x++) {
            // Calculate the error
            int oldR = image[index(x, y, w)].r;
            int oldG = image[index(x, y, w)].g;
            int oldB = image[index(x, y, w)].b;
            // CXII: this is just rounding to black or white i assume
            int newR = round(colComplexity * image[index(x, y, w)].r / 255) * (255 / colComplexity); 
            int newG = round(colComplexity * image[index(x, y, w)].g / 255) * (255 / colComplexity); 
            int newB = round(colComplexity * image[index(x, y, w)].b / 255) * (255 / colComplexity);

            float errorR = oldR - newR; //image[index(x, y, w)].r - image[index(x, y, w)].r;
            float errorG = oldG - newG; //image[index(x, y, w)].g - image[index(x, y, w)].g;
            float errorB = oldB - newB; //image[index(x, y, w)].b - image[index(x, y, w)].b;

            // Perform the diffusion
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

            // CXII: now this is where u went wrong buddy
            newImage[index(x, y, w)].r = 255;
            newImage[index(x, y, w)].g = 0;
            newImage[index(x, y, w)].b = 0;

            // pixel[x + 1][y    ] := pixel[x + 1][y    ] + quant_error * 7 / 16
            // pixel[x - 1][y + 1] := pixel[x - 1][y + 1] + quant_error * 3 / 16
            // pixel[x    ][y + 1] := pixel[x    ][y + 1] + quant_error * 5 / 16
            // pixel[x + 1][y + 1] := pixel[x + 1][y + 1] + quant_error * 1 / 16
        }
    }

    stbi_write_png("output.png", w, h, 4, (unsigned char*)newImage, 0);
}