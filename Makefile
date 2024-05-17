SRC_DIR := src/
INCLUDE_DIR := includes/
SRC_FILES := main.cpp imageProcessor.cpp colorSelector.cpp optionsHandler.cpp

# Add the source directory prefix to each source file
SRC_FILES := $(addprefix $(SRC_DIR), $(SRC_FILES))

LDFLAGS := $(shell Magick++-config --ldflags)

CPPFLAGS := $(shell Magick++-config --cppflags)
CPFLAGS := -I$(INCLUDE_DIR)cxxopts

LIBS := $(shell Magick++-config --libs)

TARGET := image-simplify

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	g++ -o $(TARGET) $(CPPFLAGS) $(SRC_FILES) $(LDFLAGS) $(LIBS)
#	g++ -o image-simplify main.cpp imageProcessor.h colorSelector.h `Magick++-config --cppflags --cxxflags --ldflags --libs`
clean:
	rm $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean
