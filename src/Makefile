TARGET_EXEC := parser.exe

build:
	flex lexer.l
	bison parser.y -d -v -g
	gcc lex.yy.c parser.tab.c -o $(TARGET_EXEC)

exec:
	./$(TARGET_EXEC)

test-all: test-generico test-problema1 test-problema2 test-problema3 test-mergeSort test-switchCase

test-generico:
	./$(TARGET_EXEC) < ../algorithms-sample/generico.txt

test-mergeSort:
	./$(TARGET_EXEC) < ../algorithms-sample/mergeSort.txt

test-problema1:
	./$(TARGET_EXEC) < ../algorithms-sample/problema1.txt

test-problema2:
	./$(TARGET_EXEC) < ../algorithms-sample/problema2.txt

test-problema3:
	./$(TARGET_EXEC) < ../algorithms-sample/problema3.txt

test-switchCase:
	./$(TARGET_EXEC) < ../algorithms-sample/switchCase.txt

test-teste:
	./$(TARGET_EXEC) < ../algorithms-sample/teste.txt