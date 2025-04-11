#include "bmp.h"

#include <iostream>
#include <fstream>

template <typename T>
static T Read(std::ifstream& fstream) {
    T result;
    fstream.read(reinterpret_cast<char*>(&result), sizeof(T));
    return result;
}

Image ReadImage(const std::string& file_path) {
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw std::invalid_argument("File cannot be opened");
    }
    char id_1 = Read<char>(file);
    char id_2 = Read<char>(file);
    if (id_1 != 'B' || id_2 != 'M') {
        throw std::invalid_argument("Wrong file format");
    }
    file.ignore(UNIMPORTANT_1);
    size_t width = (Read<uint32_t>(file));
    size_t height = (Read<uint32_t>(file));
    file.ignore(UNIMPORTANT_2);
    size_t padding = (4 - (width * 3) % 4) % 4;
    Image image(height, width);
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            image[height - i - 1][j].b = Read<uint8_t>(file) / MAX_VALUE;
            image[height - i - 1][j].g = Read<uint8_t>(file) / MAX_VALUE;
            image[height - i - 1][j].r = Read<uint8_t>(file) / MAX_VALUE;
        }
        file.ignore(static_cast<std::streamsize>(padding));
    }
    return image;
}

template <typename T>
static void Write(std::ofstream& file, const T& object) {
    file.write(reinterpret_cast<const char*>(&object), sizeof(T));
}

void WriteImage(const Image& image, const std::string& file_path) {
    std::ofstream file(file_path, std::ios::binary);
    Write(file, ID1);
    Write(file, ID2);
    uint32_t width = image.Width();
    uint32_t height = image.Height();
    size_t padding = (4 - (width * 3) % 4) % 4;
    uint32_t raw_data = (width * 3 + padding) * height;
    uint32_t file_size = OFFSET + raw_data;
    Write(file, file_size);
    Write(file, UNUSED);
    Write(file, UNUSED);
    Write(file, OFFSET);
    Write(file, HEADER_SIZE);
    Write(file, width);
    Write(file, height);
    Write(file, NUMBER_OF_PLANES);
    Write(file, PIXEL_SIZE);
    Write(file, COMPRESSION);
    Write(file, raw_data);
    Write(file, HORIZONTAL_RESOLUTION);
    Write(file, VERTICAL_RESOLUTION);
    Write(file, NUMBER_OF_COLORS);
    Write(file, IMPORTANT_COLORS);
    for (size_t y = 0; y < image.Height(); ++y) {
        for (size_t x = 0; x < image.Width(); ++x) {
            Write(file, static_cast<uint8_t>((image[image.Height() - y - 1][x].b) * MAX_VALUE));
            Write(file, static_cast<uint8_t>((image[image.Height() - y - 1][x].g) * MAX_VALUE));
            Write(file, static_cast<uint8_t>((image[image.Height() - y - 1][x].r) * MAX_VALUE));
        }
        file.write("\0", static_cast<std::streamsize>(padding));
    }
}