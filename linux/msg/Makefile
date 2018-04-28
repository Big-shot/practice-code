.PHONY : clean all

OBJS = sev cli

all : $(OBJS)

sev : msgsev.o
	gcc $^ -o $@
cli : msgcli.o
	gcc $^ -o $@
%.o : %.c
	gcc -c $< -o $@

clean :
	rm -rf *.o $(OBJS)
