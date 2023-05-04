default: driver.c functions.c
	gcc -o main driver.c functions.c

run: default
	./main 


clean:
	rm -f main
	rm -rf bin
