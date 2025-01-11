SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj
BIN_DIR=bin
LOG_DIR=log

CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c11 -I$(INC_DIR)
CFLAGS += -Wno-unused
CFLAGS += -DUSE_LOG_COLORS
LDFLAGS = -lSDL2 -lvulkan -lm

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BIN_DIR)/fern: $(OBJECTS) | $(BIN_DIR)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJ_DIR):
	mkdir -p $@
$(BIN_DIR):
	mkdir -p $@
$(LOG_DIR):
	mkdir -p $@

.PHONY: clean build test-neat test

build: $(BIN_DIR)/fern

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(LOG_DIR)

test: build
	./$(BIN_DIR)/fern

test-neat: build | $(LOG_DIR)
	./$(BIN_DIR)/fern 2> $(LOG_DIR)/stderr.log
