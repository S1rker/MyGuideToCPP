# Makefile for building the C++ project only use for login.cpp
SRC_DIR = src
CC = clang++
SRC_FILES = login.cpp
OBJ_NAME = test
#Make sure to change the paths so that it match your mechines location
INCLUDE_PATHS = -I/opt/homebrew/cellar/mysql/9.4.0_3/include -I/opt/homebrew/cellar/mysql/9.4.0_3/include/mysql -I/opt/homebrew/cellar/mysql++/3.3.0_4/include
LIBRARY_PATHS = -L/opt/homebrew/cellar/mysql/9.4.0_3/lib -L/opt/homebrew/cellar/mysql++/3.3.0_4/lib

LINKER_FLAGS = -lmysqlservices -lmysqlpp.3.3.0

# If pkg-config is available, prefer its flags (libs come after sources in link)
all:
	$(CC) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(OBJ_NAME)