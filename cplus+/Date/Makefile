.PHONY : clean

DDM=Date.o\
	Date.o\
	main.o

GWC=-g -Wall -c

main : $(DDM)
	g++ -g $^ -o $@
%.o : %.c
	g++ $(GWC) $^ -o $@

clean:
	rm -rf *.o
