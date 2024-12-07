ARCH=arm64
CROSS_COMPILE=aarch64-none-linux-gnu-

CC=$(CROSS_COMPILE)gcc
CFLAGS=-g -Wall

.PHONY: clean aesdsocket

all: aesdsocket
default: aesdsocket

aesdsocket: aesdsocket.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f aesdsocket
