#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<stdbool.h>

// Funções
void limpaTela()
{
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void aguardaCmd()
{
  printf("\n\nPressione qualquer tecla para continuar...");
  getch();
}

void limpaArray(int *tamanhoArray, int *array)
{
  // limpa o array declarando 0 para todas posições
  for (int i = 0; i < *tamanhoArray; i++)
  {
    array[i] = 0;
  }
}

// CRIA FUNÇÃO PARA INSERIR VALORES NO ARRAY USANDO O PONTEIRO PARA O CONTADOR DE ARRAY E O PONTEIRO PARA O ARRAY EM SI (POIS O AMBOS SÃO PASSADOS POR REFERÊNCIA)
// tamanho array não usa referencia pois não será alterado, apenas lido.
// contadorArray é alterado, por isso usa referencia.
// array é alterado, por isso usa referencia.
void inserir(int *tamanhoArray, int *array, int *contadorArray)
{
  int valor;

  if (*contadorArray >= *tamanhoArray)
  {
    printf("\nO array está cheio. Remova algum valor para inserir um novo.");
    aguardaCmd();
    return;
  }

  while (valor != -1 && *contadorArray < *tamanhoArray)
  {
    limpaTela();
    printf("\nInsira o valor que deseja adicionar:\nDigite 0 para voltar ao menu anterior.\n");
    scanf(" %d", &valor);
    if (valor == 0)
    {
      valor = -1;
      break;
    }
    array[*contadorArray] = valor;
    (*contadorArray)++;
  }
  aguardaCmd();
}

void deletar(int *tamanhoArray, int *array, int *contadorArray)
{
  int valor;

  printf("\nInsira o valor que deseja remover:\n");
  scanf(" %d", &valor);
  // percorre todas posições do array
  for (int i = 0; i < *tamanhoArray; i++)
  {
    // se for igual valor do input
    if (array[i] == valor)
    {
      // percorre o array a partir da posição do valor e copia a posição seguinte
      for (int j = i; j < *tamanhoArray; j++)
      {
        array[j] = array[j + 1];
      }
      (*contadorArray)--;
    }
  }
  array[*tamanhoArray - 1] = 0;
  printf("\nO valor %d foi removido com sucesso.", valor);
  printf("\nO contador do Array atualmente é: %d", *contadorArray);
}

void debug (int *tamanhoArray, int *array, int *contadorArray) {
  printf("\nTamanho do array: %d", *tamanhoArray);
  printf("\nContador do array: %d", *contadorArray);

  for (int i = 0; i < *tamanhoArray; i++)
  {
    printf("\nArray [%d]: %d", i, array[i]);
  }
}

void exibir(int *array, int *contadorArray)
{
  // exibir(array, &contadorArray);
  // exibir(contadorArray, array);
  printf("\nContador do array: %d", *contadorArray);
  if (*contadorArray <= 0)
  {
    printf("\nArray está vazio.");
  }
  else if (*contadorArray > 0)
  {
    printf("\n| ");
    // lê todas as posições do array
    for (int i = 0; i < *contadorArray; i++)
    {
      printf("%i | ", array[i]);
    }
  }
}

void buscar(int *array, int *contadorArray) {
  int valor = 0;
  bool valorEncontrado = false;

  printf("\nInsira o valor que deseja buscar:\n");
  scanf(" %d", &valor);

  // percorre todas posições preenchidas do array
  for (int i = 0; i < *contadorArray; i++)
  {
    // se for igual valor do input
    if (array[i] == valor)
    {
      valorEncontrado = true;
      printf("\nO valor %d foi encontrado na posição %d do array.", valor, i);
    }
  }
    if (valorEncontrado == false) {
      printf("\nO valor %d não foi encontrado no array.", valor);
    }
}

void main()
{
  int tamanhoArray = 0;  // inicializa o contador em zero (0)
  int contadorArray = 0; // inicializa o contador em zero (0)
  int opcaoMenu;
  int valor;

  // recebe input do usuário para determinar o tamanho do array
  printf("\nInsira o tamanho desejado do Array: \n");
  scanf("\n %d", &tamanhoArray);
  int array[tamanhoArray];

  limpaArray(&tamanhoArray, array);

  while (opcaoMenu >= 0)
  {
    limpaTela();
    printf("\nDigite a opção desejada:");
    printf("\n1 - Inserir\n2 - Deletar\n3 - Buscar\n4 - Exibir\n5 - Debug Menu\n");
    scanf(" %d", &opcaoMenu);

    switch (opcaoMenu)
    {

    case 1:
      limpaTela();
      inserir(&tamanhoArray, array, &contadorArray);
      break;

    case 2:
      limpaTela();
      deletar(&tamanhoArray, array, &contadorArray);
      aguardaCmd();
      break;

    case 3:
      limpaTela();
      buscar(array, &contadorArray);
      aguardaCmd();
      break;

    case 4:
      limpaTela();
      exibir(array, &contadorArray);
      aguardaCmd();
      break;

    case 5:
      limpaTela();
      debug(&tamanhoArray, array, &contadorArray);
      aguardaCmd();
      break;

    default:
      printf("Opção inexistente. Tente novamente.");
      opcaoMenu = 0;
      break;
    }
  }
}
