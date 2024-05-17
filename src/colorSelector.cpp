#include "colorSelector.h"

ColorSelector::ColorSelector(const Magick::Image img) : image(img) {}

std::vector<Magick::Color> ColorSelector::selectCommonColors(int numColors) {
    //const Magick::Image& image = this.image;
    // Get the color histogram
    std::map<Magick::Color, size_t> colorHistogram;
    for (size_t y = 0; y < image.rows(); ++y) {
        for (size_t x = 0; x < image.columns(); ++x) {
            Magick::Color pixelColor = image.pixelColor(x, y);
            colorHistogram[pixelColor]++;
        }
    }

    // Sort the colors by frequency
    std::vector<std::pair<Magick::Color, size_t>> colorCounts(colorHistogram.begin(), colorHistogram.end());
    std::sort(colorCounts.begin(), colorCounts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Sort in descending order of count
    });

    // Select the x most common colors
    std::vector<Magick::Color> commonColors;
    for (size_t i = 0; i < std::min(static_cast<size_t>(numColors), colorCounts.size()); ++i) {
        commonColors.push_back(colorCounts[i].first);
    }

    return commonColors;
}

Magick::Color ColorSelector::calculateAverageColor(size_t startX, size_t startY, size_t endX, size_t endY) const{
    size_t totalRed = 0, totalGreen = 0, totalBlue = 0;
    size_t pixelCount = 0;

    // Calculate the total color components within the region
    for (size_t y = startY; y < endY; ++y) {
        for (size_t x = startX; x < endX; ++x) {
            Magick::Color pixelColor = image.pixelColor(x, y);
            totalRed += pixelColor.redQuantum();
            totalGreen += pixelColor.greenQuantum();
            totalBlue += pixelColor.blueQuantum();
            pixelCount++;
        }
    }

    // Calculate the average color
    size_t averageRed = totalRed / pixelCount;
    size_t averageGreen = totalGreen / pixelCount;
    size_t averageBlue = totalBlue / pixelCount;

    // Create and return the average color
    return Magick::Color(averageRed, averageGreen, averageBlue);
}

std::vector<Magick::Color> ColorSelector::selectDominantColors(int numColors) const{
    // Define the number of regions and their size
    int numRegions = 5;
    size_t regionWidth = image.columns() / numRegions;
    size_t regionHeight = image.rows() / numRegions;

    // Calculate the average color of each region
    std::map<Magick::Color, size_t> colorHistogram;
    for (int y = 0; y < numRegions; ++y) {
        for (int x = 0; x < numRegions; ++x) {
            // Calculate the region boundaries
            size_t startX = x * regionWidth;
            size_t startY = y * regionHeight;
            size_t endX = (x + 1) * regionWidth;
            size_t endY = (y + 1) * regionHeight;

            // Calculate the average color of the region
            Magick::Color averageColor = calculateAverageColor(startX, startY, endX, endY);

            // Increment the count of the average color
            colorHistogram[averageColor]++;
        }
    }

    // Sort the average colors by dominance
    std::vector<std::pair<Magick::Color, size_t>> colorCounts(colorHistogram.begin(), colorHistogram.end());
    std::sort(colorCounts.begin(), colorCounts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Sort in descending order of count
    });

    // Select the x most dominant colors
    std::vector<Magick::Color> dominantColors;
    for (size_t i = 0; i < std::min(static_cast<size_t>(numColors), colorCounts.size()); ++i) {
        dominantColors.push_back(colorCounts[i].first);
    }

    return dominantColors;
}

void ColorSelector::selectDistinctColors(int numColors) {
    // Implement logic to select x most distinct colors from the image
}

const std::vector<Magick::Color>& ColorSelector::getDistinctColors() const {
    return distinctColors;
}