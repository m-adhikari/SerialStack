# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -std=c11 -Iinclude

# Source files
UART_SRC := src/uart.c

# Executables
TARGETS := sender receiver

all: $(TARGETS)

sender: apps/sender.c $(UART_SRC)
	$(CC) $(CFLAGS) $^ -o $@

receiver: apps/receiver.c $(UART_SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGETS)

rebuild: clean all

.PHONY: all clean rebuild
