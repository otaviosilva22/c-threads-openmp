/*--- Variáveis Globais e Structs ---*/

/*Tamanho stático máximo de linhas do arquivo txt*/
#define tam 50

/*Tamanho stático máximo de caracteres em cada linha*/
#define tamLinha 300

//quantidade de linhas
int qtdLinhas = 0;

//contador comparilhado
int contador = 0;

//quantidade de nucleos
long nprocs;

//palavra a ser pesquisada
char palavra[] = "";

/*Typedef para posições da fila*/
typedef int TipoApontador;

//Struct de linha
struct Linha{
	char conteudo[tamLinha];
};

/*Struct referente a fila, onde cada posição existe uma linha*/
struct Fila {
	struct Linha linha[tam];
	TipoApontador frente, tras;
};

