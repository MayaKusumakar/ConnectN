connectn.out: main.o setup.o win.o inputvalidation.o play.o
	gcc -g -Wall -Werror -o connectn.out main.o play.o setup.o win.o inputvalidation.o

main.o: main.c setup.h win.h inputvalidation.h play.h
	gcc -g -Wall -Werror -c main.c

play.o: play.c setup.h win.h inputvalidation.h
	gcc -g -Wall -Werror -c play.c

setup.o: setup.c setup.h
	gcc -g -Wall -Werror -c setup.c

win.o: win.c win.h
	gcc -g -Wall -Werror -c win.c

inputvalidation.o: inputvalidation.c inputvalidation.h
	gcc -g -Wall -Werror -c inputvalidation.c

clean:
	rm -f *.o *.out

run: connectn.out
	./connectn.out
