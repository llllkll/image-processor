#pragma once

#include "filter.h"

class Crop : public Filter {
public:
    Crop(size_t height, size_t weight);
    void ApplyFilter(Image& image) const final;

private:
    size_t height_;
    size_t weight_;
};
