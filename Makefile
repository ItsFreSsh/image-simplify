SRC_FILES := main.cpp

LDFLAGS := $(shell Magick++-config --ldflags)

CPPFLAGS := $(shell Magick++-config --cppflags)

TARGET := image-simplify

all: $(TARGET)

$(TARGET): $(SRC_FILES)
#	g++ -o $(TARGET) $(CPPFLAGS) $(SRC_FILES) $(LDFLAGS)
	g++ -o count_colors main.cpp `Magick++-config --cppflags --cxxflags --ldflags --libs`
clean:
	rm $(TARGET)

.PHONY: all clean
