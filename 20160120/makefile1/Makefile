SOURCES:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SOURCES))
ELF:=main
CFLAGS:= -Wall -g
CC:=gcc
$(ELF):$(OBJS)
	$(CC) -o $@ $^
.PHONY:clean
clean:	
	rm -f $(ELF) $(OBJS)
