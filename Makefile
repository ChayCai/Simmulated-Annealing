include ./rules.mk

.PHONY: bin

all: main bin

bin:
	$(MAKE) -C ./src

main: bin
	$(MAKE) -C ./script

clean:
	rm -r ./bin/*
