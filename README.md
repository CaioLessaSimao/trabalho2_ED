# trabalho2_ED
## Definição

O projeto se baseia na simulação de um ambiente hospitalar com objetivo de auxiliar na organização de uma fila de laudo do exame de raioX.

## Estrutura do Projeto

- `main.c`: O arquivo principal contendo as funções `main` e chamadas das funções.
- `pcnt.c`: O arquivo de implementação das funções relacionadas aos pacientes.
- `pcnt.h`: O arquivo de cabeçalho contendo assinaturas de funções relacionadas aos pacientes.
- `fila.c`: O arquivo de implementação das funções relacionadas a fila de raioX.
- `fila.h`: O arquivo de cabeçalho contendo assinaturas de funções relacionadas a fila de raioX.
- `filaLaudo.c`: O arquivo de implementação das funções relacionadas a fila de laudo.
- `filaLaudo.h`: O arquivo de cabeçalho contendo assinaturas de funções relacionadas a fila de laudo.
- `metric.c`: O arquivo de implementação das funções relacionadas as métricas.
- `metric.h`: O arquivo de cabeçalho contendo assinaturas de funções relacionadas as métricas.

## Estruturas utilizadas

- `QueueExame`: struct que define o nó da fila de raioX 
- `QueueNodeExame`: struct que define a fila de raioX
- `QueueLaudo`: struct que define o nó da fila de laudo
- `QueueNodeLaudo`: struct que define a fila de laudo
- `registro`: struct que define os registros que são adicionados na fila de laudo
- `patologia`: struct que define o nó da lista de patologias
- `ListaPatologias`: struct que define a lista de patologias
- `paciente`: struct que define os pacientes que são adicionados na lista de paciente
- `RAIO`: struct que define as maquinas de raioX que são usadas para os exames
- `MEDICO`: struct que define os radiologistas que fazem os laudos
- `NodePaciente`: struct que define o nó da lista de pacientes
- `ListaPaciente`: struct que define a lista de pacientes

## Principais Desisões

TAD(s):
Optamos por manipular todas as filas usando listas encadeadas pela maior facilidade na alocação de memória e manipulação de dados, como em Paciente:
  
```
struct listaPaciente_struct{
  NodePaciente *first;	
};

struct nodePaciente_struct{
  paciente *info;
  NodePaciente *next;
};
```
Como optamos por criar uma lista geral de pacientes, uma fila para raio X e uma fila para Laudos a estrutura se manteve. com funções auxiliares para adicionar e remover estruturas da lista. Exemplo:
  
```

ListaPaciente *ll_create(){
  ListaPaciente *l = (ListaPaciente *)malloc(sizeof(ListaPaciente));
    l->first = NULL; 
  return l;
}

void ll_append(ListaPaciente *lista, paciente *p){
  NodePaciente *n = (NodePaciente *)malloc(sizeof(NodePaciente));
  n->info = p;
  n->next = NULL;
  
  if(lista->first == NULL){
    lista->first = n;
  }
```
