ifdef SYSTEMROOT
	OUTPUT = Tic-Tac-Toe.exe
else
	ifdef SystemRoot
	    OUTPUT = Tic-Tac-Toe.exe
	else
	    OUTPUT = Tic-Tac-Toe
	endif
endif

all:
	g++ src/*.cpp console/console.cpp -o $(OUTPUT) -std=gnu++11