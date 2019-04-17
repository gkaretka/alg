make:
	gcc -std=c11 main.c

t1:
	cat test1.file | ./a.out

t2:
	cat test2.file | ./a.out
