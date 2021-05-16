CC = gcc
CFLAGS = -W -Wall
TARGET = test
OBJECTS = test.o timetable.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -I./ -o $@
clean:
	rm *.o test
