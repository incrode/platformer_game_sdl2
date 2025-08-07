CC = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -fPIC -Iinclude
WINDOWS_LDFLAGS = -lm -lmingw32 ./lib/libSDL2.a ./lib/libSDL2main.a ./bin/SDL2.dll


bin/game.exe: src/*
	$(CC) $(CXXFLAGS) $(WINDOWS_LDFLAGS) $^ -o $@