project_debug: user-interface.o
	g++ -o project_debug user-interface.o 
user-interface.o: user-interface.cpp
	g++ -ansi -pedantic-errors -Wall -DDEBUG -c user-interface.cpp
	g++ -ansi -pedantic-errors -Wall -DDEBUG -c llist.cpp
