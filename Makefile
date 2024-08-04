INC_DIR = ./src
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib
OUT_DIR = ./bin

CC = gcc
CFLAGS = -Wall
LINKFLAGS = -lc

_DEP = stack.h
DEP = $(patsubst %,$(INC_DIR)/%,$(_DEP))

_OBJS = stack_push.o \
	stack_pop.o \
	stack_isempty.o \
	stack_deallocate.o

OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

$(LIB_DIR)/libstack.a: dirs $(OBJS)
	-ar rcs $@  $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: lib_dir
lib_dir:
	-mkdir -p $(LIB_DIR)
.PHONY: obj_dir
obj_dir:
	-mkdir -p $(OBJ_DIR)
.PHONY: dirs
dirs: obj_dir lib_dir

.PHONY: clean_obj
clean_obj:
	-rm -rf $(OBJ_DIR)
.PHONY: clean_lib
clean_lib:
	-rm -rf $(LIB_DIR)
.PHONY: clean
clean: clean_lib clean_obj
	
.PHONY: all
all: $(LIB_DIR)/libstack.a
