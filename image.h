#pragma once

#include <cstdlib>
#include <cstdint>
#include <vector>

struct Pixel {
    double r;
    double g;
    double b;
};

class Image {
public:
    Image(size_t image_height, size_t image_width);

    void Resize(size_t new_height, size_t new_width);
    std::vector<Pixel>& operator[](size_t i);
    const std::vector<Pixel>& operator[](size_t i) const;

    size_t Height() const;
    size_t Width() const;

private:
    size_t height_;
    size_t width_;
    std::vector<std::vector<Pixel>> pixels_;
};