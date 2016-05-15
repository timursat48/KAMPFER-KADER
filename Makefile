all: bin/CONVERT
	
bin/CONVERT:obj/main.o obj/USD_RUB.o obj/EUR_RUB.o
	gcc -o bin/CONVERT obj/main.o obj/USD_RUB.o obj/EUR_RUB.o
obj/main.o: scr/main/main.c
	gcc -c scr/main/main.c -o obj/main.o

obj/USD_RUB.o: scr/usd_in_to_rub/USD_RUB.c
	gcc -c scr/usd_in_to_rub/USD_RUB.c -o obj/USD_RUB.o

obj/EUR_RUB.o: scr/eur_in_to_rub/EUR_RUB.c
	gcc -c scr/eur_in_to_rub/EUR_RUB.c -o obj/EUR_RUB.o
.PHONY: clean
clean:
	rm -f obj/*.o CONVERT
