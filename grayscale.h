#pragma once

#include "filter.h"

class Grayscale : public Filter {
public:
    void ApplyFilter(Image& image) const final;
};