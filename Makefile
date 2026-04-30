CC = gcc
CFLAGS = -shared -O2 -Wall -fPIC \
         -I claws-mail/src \
         -I claws-mail/src/common \
         $(shell pkg-config --cflags gtk+-3.0 glib-2.0)

LIBS = $(shell pkg-config --libs gtk+-3.0 glib-2.0) \
       -Wl,--enable-auto-import \
       /mingw64/bin/claws-mail.exe

DLL = html_sig.dll
SRC = html_sig.c

all: $(DLL)

$(DLL): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
