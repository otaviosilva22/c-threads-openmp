# Uso de threads em C com interface OpenMP

Este repositório faz referência ao uso de threads em linguagem C com interface OpenMP para manipulãção de arquivo de texto.

Nesse contexto, a tarefa em questão é utilizar threads para percorrer uma fila estática que contém as linhas do arquivo e identificar o número de ocorrência de determinada palavra.

<h2> Tecnologias Utilizadas </h2>

- [Linguagem C](https://docs.microsoft.com/pt-br/cpp/c-language/?view=msvc-160)
- [OpenMP](https://www.openmp.org/#)

<h2> Configuração do Ambiente</h2>

É necessário antes adicionar o seguinte comando ao compilador, referente ao OpenMP:

```
-fopenmp
```

<h2> Número de Núcleos </h2>

A quantidade de threads é definida a partir do número de núcleos disponíveis do processador.

```
#ifdef _WIN32
  #define WIN32_LEAN_AND_MEAN
  #include <windows.h>
#else
  #include <unistd.h>
#endif

int main(){
  #ifdef _WIN32 
    #ifndef _SC_NPROCESSORS_ONLN
      SYSTEM_INFO info;
      GetSystemInfo(&info);
      #define sysconf(a) info.dwNumberOfProcessors
      #define _SC_NPROCESSORS_ONLN
    #endif
  #endif

  //numero de nucleos disponíveis
  long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
  
  return 0;
}
 
```

<h2> Execução de Threads </h2>

A declaração de uma thread com OpenMP é relacionada à seguinte regra com parâmetro definido pelo número de threads:

```
#pragma omp parallel num_threads(nprocs-1)
{
  //executados por cada thread
}
```

<h2> Zona Crítica </h2>

A zona crítica serve para definir que as threads serão executadas uma por vez.

```
#pragma omp parallel num_threads(nprocs-1)
{
  #pragma omp critical
  {
    //executados por cada thread
  }
}
```

<h2> Contato </h2>

[![Linkedin Badge](https://img.shields.io/badge/-Otávio-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/otaviosilva22/)](https://www.linkedin.com/in/otaviosilva22/)
[![Gmail Badge](https://img.shields.io/badge/-otavio.ssilva22@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:otavio.ssilva22@gmail.com)](mailto:otavio.ssilva22@gmail.com)
