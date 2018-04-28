.PHONY : clean

SSM=String.o\
	String.o\
	main.o
GCW=-g -c -Wall

main : $(SSM)
	g++ -g $^ -o $@
%.o : %.c
	g++ $(GCW) $< -o $@



clean:
	rm -rf *.o
