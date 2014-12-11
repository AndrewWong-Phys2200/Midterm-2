GRAPH = gnuplot

CC = clang
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lgsl -lm

dwarf: dwarf.o ODE.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

res1: dwarf
	./dwarf > res1

dwarf.png: dwarf.gpl res1
	$(GRAPH) dwarf.gpl

clean : 
	rm -f *~
	rm -f *.o
	rm -f dwarf

veryclean : clean
	rm -f res1 dwarf.png
