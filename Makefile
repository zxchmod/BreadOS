CC = gcc
CFLAGS = -ffreestanding -m32 -O2 -Wall
LDFLAGS = -Ttext 0x1000 --oformat=binary

SRC = src/boot.c src/kernel.c src/screen.c src/power.c src/input.c
OBJ = $(SRC:.c=.o)
BIN = breados.bin

all: $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ)
	ld $(OBJ) $(LDFLAGS) -o $(BIN)

clean:
	rm -f $(OBJ) $(BIN)
