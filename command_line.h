#pragma once

#include <vector>
#include <map>
#include <string>
#include <set>

struct Command {
    std::string program_name;
    std::string input_file_path;
    std::string output_file_path;
    std::vector<std::string> filters;
    const std::set<std::string> existing_filters = {"-neg", "-crop", "-gs"};
};

Command Parser(int argc, char** argv);