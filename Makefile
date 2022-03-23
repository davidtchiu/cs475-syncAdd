all: 
	gcc -Wall -o spinSol spinSol.c -lpthread
	gcc -Wall -o blockingSol blockingSol.c -lpthread
	gcc -Wall -o noSync noSync.c

clean:
	rm -rf *.o spinSol blockingSol noSync
