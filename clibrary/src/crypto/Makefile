CC := gcc
LD := $(CC)
RM := rm -rf

CXXFLAGS := -Wall -g -std=c99 -fPIC
LDFLAGS  :=
LIBS     :=

INCD :=
LIBD :=

TARGET := test
OBJS   := main.o md5.o sha1.o

.PHONY: all clean
all: $(TARGET)
$(TARGET): $(OBJS)
	$(strip $(LD) $(LIBD) $(LDFLAGS) -o $@ $^ $(LIBS))
%.o: %.c
	$(strip $(CC) $(INCD) $(CFLAGS) -c -o $@ $<)
clean:
	$(strip $(RM) $(TARGET) $(OBJS))
