TARGET_EXEC := parser.exe

build:
	bison -d -v -g parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c -o $(TARGET_EXEC) -g

clean:
	rm *.tab.* *.yy.c *.out *.exe *.dot

exec:
	./$(TARGET_EXEC)

setup-log-and-test-folders:
	ls ../algorithms-spp | awk '/\.spp$$/ { printf "mkdir -p ../logs/" } { sub(/\.spp$$/, "") } { print }' | sh
	ls ../algorithms-spp | awk '/\.spp$$/ { printf "mkdir -p ../tests/" } { sub(/\.spp$$/, "") } { print }' | sh

test-all: test-generico test-problema1 test-problema2 test-problema3 test-mergeSort test-switchCase

test-generico:
	./$(TARGET_EXEC) ../algorithms-spp/generico.spp

test-mergeSort:
	./$(TARGET_EXEC) ../algorithms-spp/mergeSort.spp

test-problema1:
	./$(TARGET_EXEC) ../algorithms-spp/problema1.spp

test-problema2:
	./$(TARGET_EXEC) ../algorithms-spp/problema2.spp

test-problema3:
	./$(TARGET_EXEC) ../algorithms-spp/problema3.spp

test-switchCase:
	./$(TARGET_EXEC) ../algorithms-spp/switchCase.spp

test-teste:
	./$(TARGET_EXEC) ../algorithms-spp/teste.spp

test-escopos:
	./$(TARGET_EXEC) ../algorithms-spp/escopos.spp --dump-symboltable ../logs/escopos/escopos-symboltable.dump --dump-stack ../logs/escopos/escopos-stack.dump
	sort ../logs/escopos/escopos-symboltable.dump > ../logs/escopos/escopos-symboltable.sorted.dump