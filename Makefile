CC = gcc
CFLAGS = -Wall -Wextra -I.
LDFLAGS = -lSDL2 -lSDL2_ttf

SRCS = main.c engine.c app.c widget.c button.c menu.c menubar.c submenu.c
#SRCS = font_test.c font.c
OBJS = $(SRCS:.c=.o)
TARGET = sdl_app

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
