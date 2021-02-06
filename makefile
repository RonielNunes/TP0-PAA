all: main.c sources/funcoes.c sources/menu.c
	gcc main.c -o exec sources/funcoes.c sources/menu.c

run: exec
	./exec

rm: exec
	rm exec
