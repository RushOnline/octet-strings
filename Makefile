run: octet_string
	./octet_string

all: octet_string

clean:
	rm -f octet_string

octet_string: octet_string.h octet_string.cpp
	g++ -Wall -Werror -o octet_string octet_string.cpp -lssl -lcrypto 

.PHONY: all clean run
