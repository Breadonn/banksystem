project: user-interface.o
	g++ -o project user-interface.o
user-interface.o: user-interface.cpp
	g++ -ansi -pedantic-errors -Wall -c user-interface.cpp
	g++ -ansi -pedantic-errors -Wall -c llist.cpp
