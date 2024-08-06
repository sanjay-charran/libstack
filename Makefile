INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib
BIN_DIR = ./bin
EGS_DIR = ./examples

CC = gcc
CFLAGS = -Wall -O3
LINKFLAGS = -lc -L $(LIB_DIR) -Wl,-Bstatic -l:libstack.a -Wl,-Bdynamic

_DEP = stack.h
DEP = $(patsubst %,$(INC_DIR)/%,$(_DEP))

_OBJS = stack_push.o \
	stack_pop.o \
	stack_isempty.o \
	stack_deallocate.o

OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

_EGS = example1

EGS = $(patsubst %,$(BIN_DIR)/%,$(_EGS))

$(LIB_DIR)/libstack.a: dirs $(OBJS)
	-ar rcs $@  $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP)
	$(CC) -c -o $@ $< $(CFLAGS) -I $(INC_DIR)
	
$(BIN_DIR)/%: $(EGS_DIR)/%.c $(DEP) $(LIB_DIR)/libstack.a
	$(CC) -o $@ $< $(LINKFLAGS) -I $(INC_DIR)

.PHONY: bin_dir
bin_dir:
	-mkdir -p $(BIN_DIR)
.PHONY: lib_dir
lib_dir:
	-mkdir -p $(LIB_DIR)
.PHONY: obj_dir
obj_dir:
	-mkdir -p $(OBJ_DIR)
.PHONY: dirs
dirs: obj_dir lib_dir bin_dir

.PHONY: clean_bin
clean_bin:
	-rm -rf $(BIN_DIR)
.PHONY: clean_obj
clean_obj:
	-rm -rf $(OBJ_DIR)
.PHONY: clean_lib
clean_lib:
	-rm -rf $(LIB_DIR)
.PHONY: clean
clean: clean_lib clean_obj clean_bin

.PHONY:	examples
examples: $(EGS)

.PHONY: all
all: $(LIB_DIR)/libstack.a $(EGS)
