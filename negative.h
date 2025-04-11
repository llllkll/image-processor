#pragma once

#include "filter.h"

class Negative : public Filter {
public:
    void ApplyFilter(Image& image) const final;
};