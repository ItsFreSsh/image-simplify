#include "imageProcessor.h"

ImageProcessor::ImageProcessor(const std::string& filePath) {
    image.read(filePath);
}

void ImageProcessor::replaceNonDistinctColors(const std::vector<Magick::Color>& distinctColors) {
    // Implement logic to replace non-distinct colors with closest distinct color
    // Loop over image pixels and replace colors
}

void ImageProcessor::saveImage(const std::string& filePath) const {
    // Make a copy of the image
    Magick::Image imageCopy = image;
    // Write the copy to the file
    imageCopy.write(filePath);
}

const Magick::Image ImageProcessor::getImageCopy() const {
    return image;
}

const Magick::Image& ImageProcessor::getImage() const {
    return image;
}