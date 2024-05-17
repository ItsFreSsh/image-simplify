#include "imageProcessor.h"
#include "colorSelector.h"
#include <iomanip>
#include <cmath>
#include <Magick++.h>
#include "../includes/cxxopts/cxxopts.hpp"
#include "optionsHandler.h"

int main(int argc, char **argv)
{

    // Initialize option handler
    OptionsHandler optionsHandler(argc, argv);

    if (optionsHandler.isHelp())
    {
        optionsHandler.printHelp();
        return 0;
    }

    // Initialize ImageMagick
    Magick::InitializeMagick(nullptr);

    std::string inputFile = optionsHandler.getInputFile();
    std::string outputFile = optionsHandler.getOutputFile();
    int numColors = optionsHandler.getNumColors();

    // Read the input image
    ImageProcessor imageProcessor(inputFile);

    // Process image..

    return 0;
}