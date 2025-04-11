#include "crop.h"

Crop::Crop(size_t height, size_t weight) : height_(height), weight_(weight) {
}

void Crop::ApplyFilter(Image& image) const {
    image.Resize(height_, weight_);
}