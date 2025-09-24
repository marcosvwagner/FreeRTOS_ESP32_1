#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);

   //criar tarefa 2
  xTaskCreate
  (
    TarefaDois,   //tarefa
    "TarefaDois", //nome da tarefa
    10000,        //tamanho da pilha
    // o comando uxTaskGetStackHighWaterMark() para ver quantos bytes de pilha permanecem não utilizados              
    NULL,         //parâmetro de entrada não passa nada
    2,            //prioridade 2
    NULL          //identificador da tarefa
  );

  //criar tarefa 1
  xTaskCreate(TarefaUm,"TarefaUm",10000,NULL,1,NULL);
  
 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("void loop"); //escreve se o loop está executando  delay(1000);
  delay(1000);
}

//função da tarefa 1: escrever "função 1" no terminal 10x com delay 1 seg
void TarefaUm(void*parametro)
{
  while(1)
  {
    for(int i = 0; i<10; i++)
    {
      Serial.print("Funcao 1: ");
      Serial.println(i);
      delay(999);
    }
    Serial.println("Funcao 1 terminada");
  }
   vTaskDelete(NULL); //quando terminar esta função a tarefa será deletada
}

//função da tarefa 2: escrever "função 2" no terminal 10x com delay 1 seg
// void TarefaDois(void*parametro) //não passa parâmetro nenhum (4º item da XTaskCreate())
// {
//   for(int i = 0; i<10; i++)
//   {
//     Serial.print("Funcao 2: ");
//     Serial.println(i);
//     delay(1000);
//   }
//     Serial.println("Funcao 2 terminada");
//      vTaskDelete(NULL); //quando terminar esta função a tarefa será deletada 
                       // e somente será executada novamente se reiniciar a tarefa.

//  *******  se quiser que a função seja executada continuamente altere o código acima digitando:
void TarefaDois(void*parametro) //não passa parâmetro nenhum (4º item da XTaskCreate())
{
  while(1){

    for(int i = 0; i<10; i++)
    {
      Serial.print("Funcao 2: ");
      Serial.println(i);
      delay(1000);
    }
    Serial.println("Funcao 2 terminada");
  }
}


// No terminal serial as vezes a tarefa 1 escreve primeiro.. as vezes a função 2.. pois elas
// ficam "brigando" pelo acesso ao processador