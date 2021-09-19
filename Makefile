IDIR=include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src
LDIR =/usr/local/lib

LIBS=-lm

_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o matrix.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
debug: CFLAGS += -DDEBUG -g
debug: hill-cipher

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hill-cipher: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 