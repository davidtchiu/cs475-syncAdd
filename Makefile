all: rtclock.o spinSol.c blockingSol.c noSync.c
	gcc -Wall -o spinSol spinSol.c rtclock.o -lpthread
	gcc -Wall -o blockingSol blockingSol.c rtclock.o  -lpthread
	gcc -Wall -o noSync noSync.c -lpthread

rtclock.o: rtclock.h rtclock.c
	gcc -Wall -c rtclock.c

clean:
	rm -rf *.o spinSol blockingSol noSync
