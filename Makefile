CC = gcc

CFLAGS = -Wall -Wextra -std=c99

SRCS = program.c word_service.c ui_service.c game.c

OBJS = $(SRCS:.c=.o)

TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all