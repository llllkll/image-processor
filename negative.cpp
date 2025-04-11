#include "negative.h"

void Negative::ApplyFilter(Image& image) const {
    for (size_t i = 0; i < image.Height(); ++i) {
        for (size_t j = 0; j < image.Width(); ++j) {
            image[i][j].b = 1 - image[i][j].b;
            image[i][j].r = 1 - image[i][j].r;
            image[i][j].g = 1 - image[i][j].g;
        }
    }
}