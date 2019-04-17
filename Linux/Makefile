serverPath = ./server
serverLib = $(serverPath)/lib
serverSrc = $(serverPath)/src
serverBin = $(serverPath)/bin

all: server client

server: hserver

hserver:	server_error_handling.o $(serverLib)/error_handling.h
	gcc -I $(serverPath) $(serverSrc)/hello_server.c server_error_handling.o -o $(serverBin)/hserver
server_error_handling.o: $(serverLib)/error_handling.h
	gcc -I $(serverPath) -c $(serverLib)/error_handling.c -o

client:

.PHONY : clean
clean:
	rm server/bin/* client/bin/*
