#ifndef OPTIONS_HANDLER_H
#define OPTIONS_HANDLER_H

#include <iostream>
#include "../includes/cxxopts/cxxopts.hpp"

class OptionsHandler {
public:
    OptionsHandler(int argc, char* argv[]);
    std::string getInputFile() const;
    std::string getOutputFile() const;
    int getNumColors() const;
    bool isHelp() const;
    void printHelp() const;
private:
    void setupOptions();
    cxxopts::Options options;
    cxxopts::ParseResult result;
    std::string inputFile;
    std::string outputFile;
    int numColors;
    bool help;
};

#endif // OPTIONS_HANDLER_H