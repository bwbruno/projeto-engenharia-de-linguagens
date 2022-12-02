TARGET_EXEC := parser.exe

build:
	bison -d -v -g parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c -o $(TARGET_EXEC) 

clean:
	rm *.tab.* *.yy.c *.out

exec:
	./$(TARGET_EXEC)

test-all: test-generico test-problema1 test-problema2 test-problema3 test-mergeSort test-switchCase

test-generico:
	./$(TARGET_EXEC) < ../algorithms-spp/generico.spp

test-mergeSort:
	./$(TARGET_EXEC) < ../algorithms-spp/mergeSort.spp

test-problema1:
	./$(TARGET_EXEC) < ../algorithms-spp/problema1.spp

test-problema2:
	./$(TARGET_EXEC) < ../algorithms-spp/problema2.spp

test-problema3:
	./$(TARGET_EXEC) < ../algorithms-spp/problema3.spp

test-switchCase:
	./$(TARGET_EXEC) < ../algorithms-spp/switchCase.spp

test-teste:
	./$(TARGET_EXEC) < ../algorithms-spp/teste.spp

test-escopos:
	./$(TARGET_EXEC) --dump-symboltable ../tests/escopos/symboltable-result < ../algorithms-spp/escopos.spp
	sort ../tests/escopos/symboltable-result > ../tests/escopos/symboltable-result-sorted