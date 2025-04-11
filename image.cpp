#include "image.h"

Image::Image(size_t image_height, size_t image_width)
    : height_(image_height), width_(image_width), pixels_(height_, std::vector<Pixel>(width_)) {
}

size_t Image::Height() const {
    return height_;
}

size_t Image::Width() const {
    return width_;
}

std::vector<Pixel>& Image::operator[](size_t i) {
    return pixels_[i];
}

const std::vector<Pixel>& Image::operator[](size_t i) const {
    return pixels_[i];
}

void Image::Resize(size_t new_height, size_t new_width) {
    if (height_ > new_height) {
        pixels_.resize(new_height);
        height_ = new_height;
    }
    if (width_ > new_width) {
        for (auto& line : pixels_) {
            line.resize(new_width);
        }
        width_ = new_width;
    }
}