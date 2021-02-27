//Importa��o de bibliotecas, variaveis globais e fun��es
#include "./Header/Bibliotecas.h"
#include "./Header/VariaveisGlobais.h"
#include "./Header/Funcoes.h"

//Fun��o main
int main(){
	
	//struct principal de fila
	struct Fila fila;
	
	//define nucleos do processador
	DefineNucleos();
		
	//transforma palavra a ser pesquisada em uppercase
	TransformaPalavra("Palmeiras");

	//Inicializa a struct fila
	IniciaFila(&fila);
	
	//Thread de produtor	
	#pragma omp parallel num_threads(1)
	{
		Enfileira(&fila);
		
	}	
	
	//thread de consumidores
	int verifica = 1;
	#pragma omp parallel num_threads(nprocs-1)
	{
		while (verifica == 1){
			verifica = Desenfileira(&fila);
		}
	}
	
	//Exibe ocorrencias
	ExibeOcorrencia();
	
	//libera mem�ria
	fflush(stdin);
	
	return 0;
}
