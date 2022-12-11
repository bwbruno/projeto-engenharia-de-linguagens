# Reference: 
# https://bytes.usc.edu/cs104/wiki/makefile/
# https://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Text-Functions.html

COMPILER=parser.exe

DIR_SOURCE=../algorithms-spp
DIR_LOGS=../logs
DIR_TESTS=../tests
FILE_STACK=$(DIR_LOGS)/$(@:test-%=%)/$(@:test-%=%)-stack.dump
FILE_SYMBOLTABLE=$(DIR_LOGS)/$(@:test-%=%)/$(@:test-%=%)-symboltable.dump

OPTIONS=
# OPTIONS=--dump-stack=$(FILE_STACK) -t $(FILE_SYMBOLTABLE) -p

ALGORITHMS=test-generico test-problema1 test-problema2 test-problema3 test-mergeSort test-switchCase test-escopos

build:
	bison -d -v -g parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c -o $(COMPILER) -g

clean:
	rm *.tab.* *.yy.c *.out *.exe *.dot

exec:
	./$(COMPILER)

setup-log-and-test-folders:
	ls ../algorithms-spp | awk '/\.spp$$/ { printf "mkdir -p ../logs/" } { sub(/\.spp$$/, "") } { print }' | sh
	ls ../algorithms-spp | awk '/\.spp$$/ { printf "mkdir -p ../tests/" } { sub(/\.spp$$/, "") } { print }' | sh

test-all: $(ALGORITHMS)

$(ALGORITHMS):
	./$(COMPILER) $(OPTIONS) $(DIR_SOURCE)/$(@:test-%=%).spp
