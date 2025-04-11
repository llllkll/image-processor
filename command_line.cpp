#include "command_line.h"

#include <iostream>

Command Parser(int argc, char** argv) {
    Command parsed_command;
    if (argc < 3) {
        throw std::invalid_argument("Enter program name, input file path and output file path");
    }
    parsed_command.program_name = argv[0];
    parsed_command.input_file_path = argv[1];
    parsed_command.output_file_path = argv[2];
    for (int i = 3; i < argc;) {
        if (argv[i][0] == '-') {
            std::string filter = argv[i];
            if (parsed_command.existing_filters.find(filter) == parsed_command.existing_filters.end()) {
                throw std::invalid_argument("Non-existent filter");
            }
            parsed_command.filters.push_back(filter);
            ++i;
            while (i < argc && argv[i][0] != '-') {
                parsed_command.filters.push_back(argv[i]);
                ++i;
            }
        } else {
            throw std::invalid_argument("Enter filter with -");
        }
    }
    return parsed_command;
}