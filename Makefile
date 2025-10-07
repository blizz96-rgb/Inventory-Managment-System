# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -std=c99  # Enable C99 standard, warnings, and debugging

# Target program name
TARGET = inventory_manager

# Source and object files
SRCS = main.c inventory.c file_io.c
OBJS = main.o inventory.o file_io.o

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
