CC = gcc
CFLAGS = -Wall -Wextra -g $(shell pkg-config --cflags sdl2) -Iinclude
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image)

# CFLAGS = -Wall -Wextra -g -Iinclude
# LDFLAGS =

SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/plane-war

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean