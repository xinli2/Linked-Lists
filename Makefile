intSort:intSort_main.o intSort_funcs.o
	gcc -Wall -g -c intSort_main.c -o intSort_main.o
	gcc -Wall -g -c intSort_funcs.c -o intSort_funcs.o
	gcc intSort_main.o intSort_funcs.o -o intSort

strSort:strSort_main.o strSort_funcs.o
	gcc -Wall -g -c strSort_main.c -o strSort_main.o
	gcc -Wall -g -c strSort_funcs.c -o strSort_funcs.o
	gcc strSort_main.o strSort_funcs.o -o strSort
