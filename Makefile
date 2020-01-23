all: pentago.c 
	gcc -g -Wall -o pentago pentago.c

clean: 
	$(RM) pentago
