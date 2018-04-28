.PHONY : clean

OBJS=vector.o\
	main.o
WCG=-Wall -c -g

main : $(OBJS)
	g++ $(WCG) $^ -o $@

%.o : %.c %.h
	g++ $(WCG) $< -o $@

clean :
	rm -rf *.o
