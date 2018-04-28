.PHONY : clean

OBJS = list.o\
	   main.o
main : $(OBJS)
	gcc -g $^ -o $@
%.o : %.c
	gcc -Wall -c $< -o $@

clean : 
	rm -rf *.o
