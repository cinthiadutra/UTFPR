CC ?= cc
RAYLIB_PREFIX ?= $(shell brew --prefix raylib 2>/dev/null || echo /opt/homebrew/opt/raylib)

CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -I$(RAYLIB_PREFIX)/include
LDFLAGS := -L$(RAYLIB_PREFIX)/lib -lraylib

TARGET := jogo
SOURCES := main.c sistema.c perguntas/perguntas.c view/view.c view/pergunta_view.c
OBJECTS := $(SOURCES:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	cd $(dir $(abspath $(TARGET))) && ./$(notdir $(TARGET))

clean:
	rm -f $(TARGET) $(OBJECTS)
