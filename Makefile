CC = cl65
CFLAGS = -O -t cx16 -I/usr/local/share/cc65/include

SRC_DIR = src
BIN = MAIN.PRG

SRCS = $(wildcard $(SRC_DIR)/*.c)

all: $(BIN)

$(BIN):
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN)

run: $(BIN)
	../x16emu/x16emu -prg $(BIN) -run

clean:
	rm -f $(BIN)

.PHONY: all run clean
