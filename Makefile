PREFIX  := /usr/local
CC      := cc
CFLAGS  := -pedantic -Wall -Wno-deprecated-declarations -Os -I/usr/include/readline
LDFLAGS := -lreadline -L/usr/lib/aarch64-linux-gnu

all: options gitup

options:
	@echo gitup build options:
	@echo "CFLAGS  = ${CFLAGS}"
	@echo "LDFLAGS = ${LDFLAGS}"
	@echo "CC      = ${CC}"

gitup: gitup.c
	${CC} ${CFLAGS} gitup.c ${LDFLAGS} -o gitup

clean:
	rm -f *.o *.gch gitup

install: gitup
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f gitup ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/gitup

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/gitup

.PHONY: all options clean install uninstall
