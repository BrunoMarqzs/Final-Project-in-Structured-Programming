#include "estrutura.h"
#include <stdio.h>

// Função para salvar os clientes
void salvarClientes(Cliente clientes[], int numClientes) {
  FILE *file = fopen("clientes.bin", "wb");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo para salvar clientes!\n");
    return;
  }
  fwrite(&numClientes, sizeof(int), 1, file);
  fwrite(clientes, sizeof(Cliente), numClientes, file);
  fclose(file);
}

// Função para salvar as pizzas
void salvarPizzas(Pizza pizzas[], int numPizzas) {
  FILE *file = fopen("pizzas.bin", "wb");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo para salvar pizzas!\n");
    return;
  }
  fwrite(&numPizzas, sizeof(int), 1, file);
  fwrite(pizzas, sizeof(Pizza), numPizzas, file);
  fclose(file);
}

// Função para salvar os pedidos
void salvarPedidos(Pedido pedidos[], int numPedidos) {
  FILE *file = fopen("pedidos.bin", "wb");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo para salvar pedidos!\n");
    return;
  }
  fwrite(&numPedidos, sizeof(int), 1, file);
  fwrite(pedidos, sizeof(Pedido), numPedidos, file);
  fclose(file);
}
