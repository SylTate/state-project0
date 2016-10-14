all: shredder.c 
	gcc -g -Wall -o shredder shredder.c

clean: 
	 $(RM) shredder
