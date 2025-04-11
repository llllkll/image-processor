#include "command_line.h"
#include "iostream"
#include "bmp.h"
#include "crop.h"
#include "negative.h"
#include "grayscale.h"

int main(int argc, char** argv) {
    try {
        Command parameters = Parser(argc, argv);
        Image image = ReadImage(parameters.input_file_path);
        for (size_t i = 0; i < parameters.filters.size(); ++i) {
            if (parameters.filters[i] == "-crop") {
                size_t width = std::stoi(parameters.filters[i + 1]);
                size_t height = std::stoi(parameters.filters[i + 2]);
                Crop crop(height, width);
                crop.ApplyFilter(image);
                ++i;
                ++i;
            }
            if (parameters.filters[i] == "-neg") {
                Negative negative;
                negative.ApplyFilter(image);
            }
            if (parameters.filters[i] == "-gs") {
                Grayscale grayscale;
                grayscale.ApplyFilter(image);
            }
        }
        WriteImage(image, parameters.output_file_path);

    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
