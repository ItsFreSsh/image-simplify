#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <Magick++.h>
#include <vector>

class ColorSelector {
public:
    ColorSelector(const Magick::Image image);
    std::vector<Magick::Color> selectCommonColors(int numColors);
    std::vector<Magick::Color> selectDominantColors(int numColors) const;
    void selectDistinctColors(int numColors);
    const std::vector<Magick::Color>& getDistinctColors() const;

private:
    Magick::Image image;
    Magick::Color calculateAverageColor(size_t startX, size_t startY, size_t endX, size_t endY) const;
    std::vector<Magick::Color> distinctColors;
};

#endif // COLOR_SELECTOR_H