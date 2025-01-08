# Kompilator
CC = gcc

# Kompilatorflaggor
CFLAGS =

# Länkningsflaggor
LDFLAGS = -lSDL2 -lSDL2_ttf

# Målet namn
TARGET = SDLApp

# Källkodsfil
SRC = main.c app_sdl.c engine_sdl.c font_sdl.c

# Skapa objektfiler
OBJ = $(SRC:.c=.o)

# Regler
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
