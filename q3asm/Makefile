# yeah, couldn't do more simple really

# Dean Netherton 2025

FADE:="\033[2m"
NORMAL:="\033[0m"

CC=gcc
CFLAGS=-g -Wall -Wextra -O2

default:	q3asm
	@echo $(FADE)q3asm: Compiled$(NORMAL)

q3asm:	q3asm.c cmdlib.c ../src/vm/target-support.c
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f q3asm *~ *.o

