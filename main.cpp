#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

const string ch = "'.,:;/17+90*8&@$";

int main() {

    int width, height, bpp;
    uint8_t *rgb_image = stbi_load("image.jpg", &width, &height, &bpp, 3);

    uint8_t *ptr = rgb_image;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = (int)*ptr;
            ptr++;
            int g = (int)*ptr;
            ptr++;
            int b = (int)*ptr;
            ptr++;

            int avg = (double)0.3 * r + (double)0.5 * g + (double)0.2 * b;
            char curr = ch[(double)avg / 256 * ch.size()];
            cout << curr << curr << curr;
        }
        cout << '\n';
    }

    stbi_image_free(rgb_image);

    cin.get();

}