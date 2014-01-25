ifdef SystemRoot
    OUTPUT = Tic-Tac-Toe.exe
else
    OUTPUT = Tic-Tac-Toe
endif

all:
	g++ src/*.cpp console/console.cpp -o $(OUTPUT) -std=gnu++11