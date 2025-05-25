all: atendimento

atendimento: main.o interface.o cardapio.o fila.o lista.o
	gcc -o atendimento main.o interface.o cardapio.o fila.o lista.o

main.o: main.c lista.h interface.h
	gcc -Wall -c main.c

interface.o: interface.c interface.h cardapio.h lista.h
	gcc -Wall -c interface.c

cardapio.o: cardapio.c cardapio.h
	gcc -Wall -c cardapio.c

fila.o: fila.c lista.h
	gcc -Wall -c fila.c

lista.o: lista.c lista.h
	gcc -Wall -c lista.c

teste: atendimento
	./atendimento

cleanl:
	rm -f atendimento *.o

cleanw:
	del /Q atendimento.exe *.o