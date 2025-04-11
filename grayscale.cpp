#include "grayscale.h"

void Grayscale::ApplyFilter(Image& image) const {
    for (size_t i = 0; i < image.Height(); ++i) {
        for (size_t j = 0; j < image.Width(); ++j) {
            double new_color = 0.299 * image[i][j].r + 0.587 * image[i][j].g + 0.114 * image[i][j].b;
            image[i][j].b = new_color;
            image[i][j].r = new_color;
            image[i][j].g = new_color;
        }
    }
}