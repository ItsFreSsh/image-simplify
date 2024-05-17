#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <Magick++.h>
#include <iostream>

class ImageProcessor {
public:
    ImageProcessor(const std::string& filePath);
    void replaceNonDistinctColors(const std::vector<Magick::Color>& distinctColors);
    void saveImage(const std::string& filePath) const;
    const Magick::Image& getImage() const;
    const Magick::Image getImageCopy() const;
private:
    Magick::Image image;
};

#endif // IMAGE_PROCESSOR_H