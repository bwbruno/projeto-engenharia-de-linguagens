# Simple++ reference 
Essa é uma linguagem implementada como projeto da disciplina de Engenharia de Linguagens do Bacharelado em Tecnologia da Informação da UFRN. A ideia por trás do Simple++ é tentar tornar a sintaxe do uso de ponteiros mais amigável e de simples entendimento. 

## Como buildar o compilador simple++
No terminal, com o lex, yacc ou bison instalados, dentro da pasta ***src***:

**Windows**
```
$ flex lexer.l 
$ bison parser.y -d -v -g
$ gcc lex.yy.c parser.tab.c -o parser.exe
```

**Linux**
```
$ lex lexer.l 
$ yacc parser.y -d -v -g
$ gcc lex.yy.c parser.tab.c -o parser.out
```

Tambem existe a possibilidade de usar todos esses comandos via make
```
$ make build
```

## Como usar o compilador simple++
Com o executável do compilador passe a opção de --help e verá todas as opções disponíveis
```
$ ./parser.exe --help
```

## Tipos

| Tipo   | Descrição |
|---------|-------------------------------------|
| int  | Tipo inteiro                      |
| double   | double precision floating-point type |
| bool | true ou false |
| string | used to represent and manipulate a sequence of characters. |
| enum | is a distinct type whose value is restricted to a range of values (see below for details), which may include several explicitly named constants ("enumerators"). The values of the constants are values of an integral type known as the underlying type of the enumeration. |

## Ponteiros
Declara um tipo ponteiro que aponta para o endereco
```c++
Pointer<type> ptr;
```
Como apontar para uma variavel
```c++
int x = 20;
Pointer <int> ptr;
ptr.pointTo(x);
```
Metodos
| Tipo   | Descrição |
|---------|-------------------------------------|
| address()  | retorna o proprio endereco |
| value()  | retorna o endereco apontado|
| pointedValue()  | retorna o valor do endereco apontado|

Exemplo de utilizacao dos metodos
```c++
int x = 20;
Pointer <int> ptr;
ptr.pointTo(x); 
ptr.address() // retorna o proprio endereco
ptr.value() // retorna o endereco de x
ptr.pointedValue() // retorna 20
```
## Declaração de Arrays
Um array é uma coleção de elementos do mesmo tipo colocados continuamente em posições de memória e que
podem ser acessados individualmente e referenciados usando um index como identificador único.

### Estrutura de declaração
```c++
tipo nome [elementos];
```
### Como inserir elementos em um array de 5 posições
```c++
int[5] foo;

for(int i = 0 ; i < 5 ; i++){
  scan(foo[i]);
}

```
### Inicializando arrays
```c++
int[5] foo = {16, 2, 77, 40, 12071};
```

### Acessando itens do array
```c++
int x = foo[2];
print(x) //return 77
```

## Array Multidimensional
Array multidimensional pode ser descrito com um "array de array".

### Inicializando arrays multidimensionais
```c++
int[3][3] foo;
```
```c++
int[3][3] foo {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
```

### Acessando itens do array multidimensional
```c++
for (n=0; n<3; n++) {
    for (m=0; m<3; m++)
    {
      print( foo[n][m] );
    }
}
```


## Estruturas
| Tipo   | Descrição |
|---------|-------------------------------------|
| procedure  | É uma função que não possui retorno |
| function  | Classe que pode agrupar qualquer tipo de elemento chamável |


## Funções

### Declaração de funções
```c++
function main() : int
{
  return 2;
}
```
## I/O Streams

| Sintaxe   | Descrição |
|---------|-------------------------------------|
| print(string / item)  | imprime uma mensagem em tela |
| printArray(array)  | imprime um array em tela |
| printArray(scan)  | Lê um valor digitado |
              

## Controle de fluxo

### for
A instrução for cria um loop que consiste em três expressões opcionais, entre parênteses e separadas por ponto e vírgula, seguidas por uma instrução (geralmente uma instrução de bloco) a ser executada no loop.
```c++
string str = '';

for (int i = 0; i < 9; i++) {
  str = str + i;
}

print(str); // 012345678

```

### while
A instrução while cria um loop que executa uma instrução especificada desde que a condição de teste seja avaliada como verdadeira. A condição é avaliada antes de executar a instrução.
```c++
int n = 0;

while (n < 3) {
  n++;
}
print(n) // 3
``` 

### do...while
O do...while cria um loop que executa uma instrução especificada até que a condição de teste seja avaliada como falsa. A condição é avaliada após a execução da instrução, resultando na execução da instrução especificada pelo menos uma vez.
```c++
string result = '';
int i = 0;

do {
  i = i + 1;
  result = result + i;
} while (i < 5);

print(result); // expected result: "12345"
```

### if...else
A instrução if executa uma instrução se uma condição especificada for verdadeira. Se a condição for falsa, outra instrução na cláusula else opcional será executada.
```c++
function testNum(int a) {
  let result;
  if (a > 0) {
    result = 'positive';
  } else {
    result = 'NOT positive';
  }
  return result;
}

print(testNum(-5)); // expected output: "NOT positive"
```

### switch
A instrução switch avalia uma expressão, comparando o valor da expressão com uma série de cláusulas case e executa instruções após a primeira cláusula case com um valor correspondente, até que uma instrução break seja encontrada. A cláusula padrão de uma instrução switch será saltada se nenhum caso corresponder ao valor da expressão.
```javascript
string expr = 'Papayas';
switch (expr) {
  case 'Oranges':
    print('Oranges are $0.59 a pound.');
    break;
  case 'Mangoes':
  case 'Papayas':
    print('Mangoes and papayas are $2.79 a pound.');
    // expected output: "Mangoes and papayas are $2.79 a pound."
    break;
  default:
   print(`Sorry, we are out of` + expr + ".");
}
```

## Incremento & decremento
| Sintaxe   | Descrição |
|---------|-------------------------------------|
| ++  | Incrementa uma variável em 1 |
| --  | Decrementa uma variável em 1  |


## Operadores Unários
| Sintaxe   | Descrição |
|---------|-------------------------------------|
| & | AND |
| /|  OR  |
| ! | NOT |

## Operadores aritméticos
| Sintaxe   | Descrição | Exemplo |
|---------|-------------------------------------|-------------|
| + | soma duas variáveis | 1 + 1 = 2
| - |  subtração  | 2 - 1 = 1
| * | expressão de multiplicação | 10 * 2 = 20
| / | Divide dois operadores | 10 / 2 = 5
| % | Resto de uma divisão | 7 % 2 = 1


## Operadores relacionais
retorna TRUE se a condição for satisfeita o FALSE caso não seja.
| Sintaxe   | Descrição | Exemplo | Resultado
|---------|-------------------------------------|-------------|-----|
| == | copara se duas variáreis são iguais | 1 == 1 | TRUE
| != |  copara se duas variáreis são diferentes  | 2 != 1 | TRUE
| < | copara se uma variável é menor que outra | 10 > 5 | TRUE
| <= | copara se uma variável é menor ou igual a outra | 10 <= 2 | FALSE
| > |  copara se uma variável é maior que outra | 7 > 2 | TRUE
| >= | copara se uma variável é menor ou igual a outra | 10 >= 2 | TRUE

## Operadores de atribuição
| Sintaxe   | Descrição | Exemplo | resultado
|---------|----------------|--------|-------------|
| = | Variável = Expressão | int a = 1; | // a = 1
| += | Variável = Variável + Expressão | a += 11; | // a = 12 
| -= | Variável = Variável - Expressão | a -= 2; | // a = 10 
| *= | Variável = Variável * Expressão | a *= 2; | // a = 20 
| /= | Variável = Variável / Expressão | a /= 2; | // a = 10 
| %= | Variável = Variável % Expressão | a %= 2; | // a = 0 

## Verificações realizadas

### Multiplas declarações
```c++
  function main() : int
  {
      a = 2;
      int b = 1;
      int b = 2;    // Erro de declaração em duplicidade
  }
```
### Erro de tipo
```c++
function main() : int
{
    a = 1;
    int b = "brasil"; // Erro de atribuição a um tipo diferente do declarado
}
```
### Erro de tipo em uma expressão
```c++
function main() : int
{
    a = 1 + "brasil"; // Soma de int com string não é permitido
}
```
### Erro de tipo no retorno de funções
```c++
function iAmAFloat() : float
{
    return 10.5;
}

function main() : int
{
    int a = iAmAFloat(); // Erro: Retorno float sendo atribuído a um int
}
```

### Variável não declarada
```c++
function main() : int
{
    int a = 2;
    print(a);
    
    b = 0; // Erro: Variável não foi declarada
    print(b);
}
```

## License

MIT

**Free Software, Hell Yeah!**
