SHELL=/bin/bash

CC = gcc

H_PATH := $(shell pwd)/src/container
export CPATH=$(H_PATH)
PWD := `pwd`
LIB_PATH = $(PWD)/lib
OBJ := obj
SRC := src
LIB := lib
CONTAINER := src/container

c_files := $(wildcard $(CONTAINER)/*.c)
o_files := $(patsubst $(CONTAINER)/%.c, $(OBJ)/%.o, $(c_files))
lib_files := $(patsubst $(CONTAINER)/%.c, $(LIB)/lib%.so, $(c_files))
exe_file := $(patsubst $(CONTAINER)/%.c, $(SRC)/%.exe, $(c_files))
test_file := $(wildcard *_test)

all: $(o_files) $(lib_files) $(exe_file)

$(OBJ)/%.o: $(CONTAINER)/%.c
	@$(CC) -c -Wall -Werror -fpic $< -o $@

$(LIB)/lib%.so: $(OBJ)/%.o
	@$(CC) -shared -o $@ $<

$(SRC)/%.exe: $(SRC)/%.c
	@$(CC) -L$(LIB) -Wall -o $@ $< -$(patsubst $(SRC)/%.c,l%, $<)

test:
	@for a in $(exe_file); do \
		./$$a ; \
	done

#new_test:
#	@echo test

clean:
	@rm -rf lib/*
	@rm -rf obj/*
	@rm -rf src/*.exe
