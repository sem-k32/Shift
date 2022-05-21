CC=g++
DEPS = sqlite3.h dbFuncs.h alg_funcs.h alg.h mapSch.h
OBJ =  main.o  sqlite3.o alg_funcs.o mySelect.o myNoSelect.o alg.o mapSch.o

LIBS = -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


result_file.c: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)	