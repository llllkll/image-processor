#pragma once

#include "image.h"
#include <string>

Image ReadImage(const std::string& file_path);

void WriteImage(const Image& img, const std::string& file_path);

const char ID1 = 'B';
const char ID2 = 'M';
const uint16_t UNUSED = 0;
const uint32_t OFFSET = 54;
const uint32_t HEADER_SIZE = 40;
const uint16_t NUMBER_OF_PLANES = 1;
const uint16_t PIXEL_SIZE = 24;
const uint32_t COMPRESSION = 0;
const uint32_t HORIZONTAL_RESOLUTION = 0;
const uint32_t VERTICAL_RESOLUTION = 0;
const uint32_t NUMBER_OF_COLORS = 0;
const uint32_t IMPORTANT_COLORS = 0;
const double MAX_VALUE = 255.0;
const int UNIMPORTANT_1 = 16;
const int UNIMPORTANT_2 = 28;