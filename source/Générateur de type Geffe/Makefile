CC=gcc
CFLAGS=-c -Wall -g


test:clean eval 
	./eval fonction

run:
	./eval fonction

eval: main.o exo1.o exo2.o liste.o
	$(CC) main.o exo1.o exo2.o liste.o -o eval
	

main.o: main.c exo1.h exo2.h 
	$(CC) $(CFLAGS) main.c 
	
exo1.o: exo1.c exo1.h liste.h 
	$(CC) $(CFLAGS) exo1.c 
	
exo2.o: exo2.c exo2.h 
	$(CC) $(CFLAGS) exo2.c 

liste.o: liste.c liste.h 
	$(CC) $(CFLAGS) liste.c 
	

# Lancer tous les fichiers 

editeur:
	subl Makefile *c *h  &
	
# indenter tous les fichiers

indent:
	indent -linux *c *h

clean:
	rm -f *.o
	rm -f main
