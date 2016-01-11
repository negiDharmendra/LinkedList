compile: 
	gcc -c linkListTest.c linkList.c
run: 
	gcc linkListTest.c linkList.c -o main
show: main
	./main
clean:
	rm main *.o
runTest:
	node runTest.js linkListTest.c linkList.c