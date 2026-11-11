CC ?= cc
raylibPrefix ?= $(shell brew --prefix raylib 2>/dev/null || echo /opt/homebrew/opt/raylib)

CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -I$(raylibPrefix)/include
LDFLAGS := -L$(raylibPrefix)/lib -lraylib

TARGET := jogo
SOURCES := main.c sistema.c perguntas/perguntas.c view/view.c view/perguntaView.c view/gerenciarView.c
OBJECTS := $(SOURCES:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJECTS): perguntas/perguntas.h sistema.h view/view.h view/perguntaView.h view/gerenciarView.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	cd $(dir $(abspath $(TARGET))) && ./$(notdir $(TARGET))

clean:
	rm -f $(TARGET) $(OBJECTS)
