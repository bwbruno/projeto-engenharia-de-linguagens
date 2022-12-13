# Reference: 
# https://bytes.usc.edu/cs104/wiki/makefile/
# https://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Text-Functions.html

COMPILER=parser.exe

DIR_SOURCE=../algorithms-spp
DIR_BROKEN_SOURCE=../algorithms-spp/errors
DIR_LOGS=../logs
DIR_TESTS=../tests
FILE_STACK=$(DIR_LOGS)/$(@:test-%=%)/$(@:test-%=%)-stack.dump
FILE_SYMBOLTABLE=$(DIR_LOGS)/$(@:test-%=%)/$(@:test-%=%)-symboltable.dump

#OPTIONS=-p
OPTIONS=--dump-stack=$(FILE_STACK) -t $(FILE_SYMBOLTABLE)

ALGORITHMS=test-generico test-problema1 test-problema2 test-problema3 test-mergeSort test-switchCase test-escopos test-cast
BROKEN_ALGORITHMS=test-broken-multipleDeclarations test-broken-undeclared test-broken-typeErrorOnExpression test-broken-typeErrorOnAssignment

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

test-broken-all: $(BROKEN_ALGORITHMS)

RESET=\x1B[0m
BOLD=\x1B[1m
CYAN=\x1B[36m

$(ALGORITHMS):
	@echo -e '\n$(CYAN)$(BOLD)make $@$(RESET)'
	./$(COMPILER) $(OPTIONS) $(DIR_SOURCE)/$(@:test-%=%).spp

$(BROKEN_ALGORITHMS):
	@echo -e '\n$(CYAN)$(BOLD)make $@$(RESET)'
	./$(COMPILER) $(DIR_BROKEN_SOURCE)/$(@:test-broken-%=%).spp