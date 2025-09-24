# Experimento 1: Criar Tarefa e Enviar para o Monitor

### 1.2) O que Você percebeu?
As duas tarefas executam alternadamente, independente da prioridade, por conta do delay, onde enquanto uma esta sendo executada, a outra esta esperando. Então a prioridade não esta sendo usada, por conta do tempo. 
Até que a tarefa 2 chegue em 10 e seja deletada, então fica apenas a 1.

### 1.3) Altere o código anterior para que a tarefa seja executada continuamente.
Parte alterada do codigo:

```bash
void TarefaDois(void*parametro) //não passa parâmetro nenhum (4º item da XTaskCreate())
{
  while(1)
  {
    for(int i = 0; i<10; i++)
    {
      Serial.print("Funcao 2: ");
      Serial.println(i);
      delay(1000);
    }
    
    Serial.println("Funcao 2 terminada");
  }

  // O comando vTaskDelete(NULL) foi removido
}

```

### 1.4) O que Você percebeu?
Agora a tarefa 2 para de ser deletada, então ficam indefinidamente se alternando.