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

TAD(s):<br><br>
Optamos por manipular todas as filas usando listas encadeadas pela maior facilidade na alocação de memória e manipulação de dados, como em Paciente:
  
```C
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
Funcionamento: <br><br>
Dentro do main, após a inicialização de variáveis, basicamente duas funções controla os aspectos mais cruciais, verificaRaioX():
```
void verificaRaioX(RAIO **maquinas, QueueExame *filaExame, QueueLaudo *filaLaudo, int instante){
  srand(time(NULL));
  
  for(int i = 0; i < 5; i++){
    if(maquinas[i]->tempo == 0){              //verifica se a máquina está livre
      
      if(!qExame_is_empty(filaExame)){
        maquinas[i]->id = getIdExame(filaExame);
        retiraNo(filaExame);
        maquinas[i]->tempo = ((rand() % (5 + 1 - 10)) + 10) + instante; //adicionei o instante atual 
      }
    }  
    else{
      //printf("tempo maquina[%d]: %d, tempo atual: %d\n", i, maquinas[i]->tempo, instante);
      if(maquinas[i]->tempo >= instante){     //verifica se terminou o raio X
        registro *r = create_registro(filaLaudo, maquinas[i]->id, instante);
        qLaudo_enqueue(filaLaudo, r);

        //levando proximo paciente para fazer raio X
        if(!qExame_is_empty(filaExame)){
          maquinas[i]->id = getIdExame(filaExame);
          retiraNo(filaExame);
          maquinas[i]->tempo = (rand() % ((5 + 1 - 10)) + 10) + instante;
        }
        else{
          maquinas[i]->id = -1;
          maquinas[i]->tempo = 0;
        }
      }
    }
  }
}
```
Essa função é responsável por acessar a lista de maquinas e através dos seus campos internos designar ou retirar pacientes 
para a próxima fila. Assim como em verificaLaudo():
```
void verificaLaudo(MEDICO **medicos, QueueLaudo *filaLaudo, ListaPaciente *lista, int instante){
  srand(time(NULL));
  
  for(int i = 0; i < 3; i++){
    if (medicos[i]->tempo == 0){          //verifica se o médico está livre
      if(!qLaudo_is_empty(filaLaudo)){
        medicos[i]->id = getLaudoId(filaLaudo);
        retiraLaudo(filaLaudo);
        printf("sendo atendido\n");
        medicos[i]->tempo = instante + (rand() % (30 - 10 + 1) + 10);
      }
    }
    else{
      if(medicos[i]->tempo == instante){    //verifica se o laudo foi emitido  
        int idAlta = medicos[i]->id;
        paciente *p = getPaciente(lista, idAlta);
        //p->tempoLaudo = instante;                 - Devia funcionar
        //p->estado     = Sorteio_Patologias();     - Devia funcionar

        printf("paciente %d saiu do hospital\n", idAlta);

        //altaPaciente(lista, idAlta);


        if(!qLaudo_is_empty(filaLaudo)){    //chama próximo da lista
          medicos[i]->id = getLaudoId(filaLaudo);
          retiraLaudo(filaLaudo);
          printf("sendo atendido\n");
          medicos[i]->tempo = instante + (rand() % (30 - 10 + 1) + 10);
        }
        else{
          medicos[i]->id = -1;
          medicos[i]->tempo = 0;
        }
        
        //medirTempo( resultadoLaudo );

        
      }
      /*else{
        strcpy(medicos[i]->id, " ");
        medicos[i]->tempo = 0;
      }*/
    }
  }
}

```
