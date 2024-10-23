PROJECT = asm02
CC = gcc
DEFS = -Wall
INCS =
INCDIR =
LIBS =
LIBDIR =
OBJS = \
	adddefine.o \
	addlabel.o \
	asm.o \
	asmconvertnumber.o \
	assemblefile.o \
	clear.o \
	compileop.o \
	defreplace.o \
	deldefine.o \
	evaluate.o \
	finddefine.o \
	findlabel.o \
	gethex.o \
	getlabel.o \
	isalpha.o \
	isexternal.o \
	isrreg.o \
	lineno.o \
	list.o \
	main.o \
	nextline.o \
	output.o \
	pass.o \
	processargs.o \
	processdb.o \
	processdf.o \
	processds.o \
	processoption.o \
	processorg.o \
	processram.o \
	processrom.o \
	setlabel.o \
	trim.o \
	writeoutput.o

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.c.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

clean:
	-rm *.o
	-rm $(PROJECT)

install:
	cp asm02 /usr/local/bin/
	chmod a+rx /usr/local/bin/asm02

adddefine.o:        header.h adddefine.c
addlabel.o:         header.h addlabel.c
asm.o:              header.h asm.c
asmconvertnumber.o: header.h asmconvertnumber.c
assemblefile.o:     header.h assemblefile.c
clear.o:            header.h clear.c
compileop.o:        header.h compileop.c
defreplace.o:       header.h defreplace.c
deldefine.o:        header.h deldefine.c
evaluate.o:         header.h evaluate.c
finddefine.o:       header.h finddefine.c
findlabel.o:        header.h findlabel.c
gethex.o:           header.h gethex.c
getlabel.o:         header.h getlabel.c
isalpha.o:          header.h isalpha.c
isexternal.o:       header.h isexternal.c
isrreg.o:           header.h isrreg.c
lineno.o:           header.h lineno.c
list.o:             header.h list.c
main.o:             header.h main.c
nextline.o:         header.h nextline.c
output.o:           header.h output.c
pass.o:             header.h pass.c
processargs.o:      header.h processargs.c
processdb.o:        header.h processdb.c
processdf.o:        header.h processdf.c
processds.o:        header.h processds.c
processoption.o:    header.h processoption.c
processorg.o:       header.h processorg.c
processram.o:       header.h processram.c
processrom.o:       header.h processrom.c
setlabel.o:         header.h setlabel.c
trim.o:             header.h trim.c
writeoutput.o:      header.h writeoutput.c

