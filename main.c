#include "estrutura.h"
#include <stdio.h>

int main() {
  Cliente clientes[MAX_CLIENTES];
  Pizza pizzas[MAX_PIZZAS];
  Pedido pedidos[MAX_PEDIDOS];
  int numClientes = carregarClientes(clientes);
  int numPizzas = carregarPizzas(pizzas);
  int numPedidos = carregarPedidos(pedidos);
  int opcao;
  do {
    printf("\n----- Menu -----\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Cadastrar Pizza\n");
    printf("3. Cadastrar Pedido\n");
    printf("4. Despachar Pizza\n");
    printf("5. Receber Pizza\n");
    printf("6. Mostrar Pizzas Entregues\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      cadastrarCliente(clientes, &numClientes);
      break;
    case 2:
      cadastrarPizza(pizzas, &numPizzas);
      break;
    case 3:
      cadastrarPedido(pedidos, clientes, &numPedidos, numClientes);
      break;
    case 4:
      despacharPizza(pedidos, numPedidos);
      break;
    case 5:
      receberPizza(pedidos, numPedidos);
      break;
    case 6:
      mostrarPizzasEntregues(pedidos, numPedidos);
      break;
    case 7:
      printf("Salvando dados...\n");
      salvarClientes(clientes, numClientes);
      salvarPizzas(pizzas, numPizzas);
      salvarPedidos(pedidos, numPedidos);
      printf("Saindo...\n");
      break;

    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 7);
  return 0;
}
