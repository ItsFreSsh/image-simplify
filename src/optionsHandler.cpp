#include "optionsHandler.h"
#include <iostream>

OptionsHandler::OptionsHandler(int argc, char* argv[]) : options("image-simplify", "Image simplification tool") {
    setupOptions();
    result = options.parse(argc, argv);

    if (result.count("help")) {
        help = true;
    } else {
        inputFile = result["input"].as<std::string>();
        outputFile = result["output"].as<std::string>();
        numColors = result["colors"].as<int>();
        help = false;
    }
}

void OptionsHandler::setupOptions() {
    options.add_options()
        ("i,input", "Input image file", cxxopts::value<std::string>())
        ("o,output", "Output image file", cxxopts::value<std::string>())
        ("c,colors", "Number of colors", cxxopts::value<int>()->default_value("10"))
        ("h,help", "Print help");
}

std::string OptionsHandler::getInputFile() const {
    return inputFile;
}

std::string OptionsHandler::getOutputFile() const {
    return outputFile;
}

int OptionsHandler::getNumColors() const {
    return numColors;
}

bool OptionsHandler::isHelp() const {
    return help;
}

void OptionsHandler::printHelp() const {
    std::cout << options.help() << std::endl;
}
