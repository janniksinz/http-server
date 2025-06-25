CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
BIN_DIR = bin

TARGET = $(BIN_DIR)/myhttpd

SRC_FILES = $(wildcald $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
