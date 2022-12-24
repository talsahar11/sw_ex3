CC = gcc
CFLAGS = -Wall -g
OBJDIR = obj/
HDRDIR = hdrs/
CDIR = cfiles/
LIBDIR = libs/

all: makedirs isort txtfind

makedirs:
	mkdir libs
	mkdir obj

txtfind: $(LIBDIR)lib_txtfind.a $(OBJDIR)main_txtfind.o
	$(CC) $(CFLAGS) $(OBJDIR)main_txtfind.o $(LIBDIR)lib_txtfind.a -o txtfind

isort: $(LIBDIR)lib_isort.a $(OBJDIR)main_isort.o
	$(CC) $(CFLAGS) $(OBJDIR)main_isort.o $(LIBDIR)lib_isort.a -o isort

$(LIBDIR)lib_txtfind.a: $(OBJDIR)txtfind.o
	ar -rcs $(LIBDIR)lib_txtfind.a $(OBJDIR)txtfind.o

$(LIBDIR)lib_isort.a: $(OBJDIR)isort.o
	ar -rcs $(LIBDIR)lib_isort.a $(OBJDIR)isort.o

$(OBJDIR)main_txtfind.o: $(CDIR)main_txtfind.c $(HDRDIR)txtfind.h
	$(CC) $(CFLAGS) -c $(CDIR)main_txtfind.c -o $(OBJDIR)main_txtfind.o

$(OBJDIR)main_isort.o: $(CDIR)main_isort.c $(HDRDIR)isort.h
	$(CC) $(CFLAGS) -c $(CDIR)main_isort.c -o $(OBJDIR)main_isort.o

$(OBJDIR)isort.o: $(CDIR)isort.c
	$(CC) $(CFLAGS) -c $(CDIR)isort.c -o $(OBJDIR)isort.o

$(OBJDIR)txtfind.o: $(CDIR)txtfind.c
	$(CC) $(CFLAGS) -c $(CDIR)txtfind.c -o $(OBJDIR)txtfind.o


clean:
	rm -f $(OBJDIR)*.o $(LIBDIR)*.a *.gch isort txtfind
	rmdir libs obj
