#include "estrutura.h"
#include <stdio.h>
#include <string.h>

void cadastrarCliente(Cliente clientes[], int *numClientes) {
  printf("Digite o numero de telefone do cliente: ");
  scanf("%d", &clientes[*numClientes].telefone);
  printf("Digite o nome do cliente: ");
  getchar(); // Consome o caractere de nova linha residual
  fgets(clientes[*numClientes].nome, sizeof(clientes[*numClientes].nome),
        stdin);
  clientes[*numClientes].nome[strcspn(clientes[*numClientes].nome, "\n")] =
      '\0'; // Remove o '\n' do final
  printf("Digite o endereco do cliente: ");
  fgets(clientes[*numClientes].endereco,
        sizeof(clientes[*numClientes].endereco), stdin);
  clientes[*numClientes]
      .endereco[strcspn(clientes[*numClientes].endereco, "\n")] = '\0';
  printf("Digite o complemento do cliente: ");
  fgets(clientes[*numClientes].complemento,
        sizeof(clientes[*numClientes].complemento), stdin);
  clientes[*numClientes]
      .complemento[strcspn(clientes[*numClientes].complemento, "\n")] = '\0';
  printf("Digite o CEP do cliente: ");
  scanf("%s", clientes[*numClientes].cep);
  (*numClientes)++;
  printf("Cliente cadastrado com sucesso!\n");
}

void cadastrarPizza(Pizza pizzas[], int *numPizzas) {
  printf("Digite o nome da pizza: ");
  scanf(" %[^\n]s", pizzas[*numPizzas].nome);
  printf("Digite o valor da pizza: ");
  scanf("%f", &pizzas[*numPizzas].valor);
  pizzas[*numPizzas].codigo = *numPizzas + 1;
  printf("Pizza cadastrada com sucesso! O codigo da pizza e: %d\n",
         pizzas[*numPizzas].codigo);
  (*numPizzas)++;
}

void cadastrarPedido(Pedido pedidos[], Cliente clientes[], int *numPedidos,
                     int numClientes) {
  int telefone, i, clienteEncontrado = -1;
  printf("Digite o numero de telefone do cliente: ");
  scanf("%d", &telefone);
  for (i = 0; i < numClientes; i++) {
    if (clientes[i].telefone == telefone) {
      clienteEncontrado = i;
      break;
    }
  }
  if (clienteEncontrado == -1) {
    printf("Cliente nao encontrado. Cadastro de pedido encerrado.\n");
    return;
  } else {
    printf("Cliente encontrado: %s\n", clientes[clienteEncontrado].nome);
  }
  pedidos[*numPedidos].telefoneCliente = telefone;
  printf("Digite o codigo da pizza: ");
  scanf("%d", &pedidos[*numPedidos].codigoPizza);
  pedidos[*numPedidos].situacao = 0;
  pedidos[*numPedidos].codigoMotoqueiro = -1;
  pedidos[*numPedidos].numeroPedido = *numPedidos + 1;
  (*numPedidos)++;
  printf("Pedido cadastrado com sucesso! A pizza esta em preparo.\n");
}

void despacharPizza(Pedido pedidos[], int numPedidos) {
  int numeroPedido, i, encontrado = 0;
  printf("Digite o numero do pedido a ser despachado: ");
  scanf("%d", &numeroPedido);
  for (i = 0; i < numPedidos; i++) {
    if (pedidos[i].numeroPedido == numeroPedido && pedidos[i].situacao == 0) {
      printf("Digite o codigo do motoqueiro: ");
      scanf("%d", &pedidos[i].codigoMotoqueiro);
      pedidos[i].situacao = 1;
      printf("Pedido %d despachado com sucesso!\n", numeroPedido);
      encontrado = 1;
      break;
    }
  }
  if (!encontrado) {
    printf("Pedido nao encontrado ou ja foi despachado.\n");
  }
}

void receberPizza(Pedido pedidos[], int numPedidos) {
  int numeroPedido, i, encontrado = 0;
  printf("Digite o numero do pedido a ser recebido: ");
  scanf("%d", &numeroPedido);
  for (i = 0; i < numPedidos; i++) {
    if (pedidos[i].numeroPedido == numeroPedido && pedidos[i].situacao == 1) {
      pedidos[i].situacao = 2;
      printf("Pedido %d entregue com sucesso!\n", numeroPedido);
      encontrado = 1;
      break;
    }
  }
  if (!encontrado) {
    printf("Pedido nao encontrado ou ainda nao foi despachado.\n");
  }
}

void mostrarPizzasEntregues(Pedido pedidos[], int numPedidos) {
  int i, encontrou = 0;
  printf("Pizzas ja entregues:\n");
  for (i = 0; i < numPedidos; i++) {
    if (pedidos[i].situacao == 2) {
      printf("Pedido %d - Pizza Codigo: %d\n", pedidos[i].numeroPedido,
             pedidos[i].codigoPizza);
      encontrou = 1;
    }
  }
  if (!encontrou) {
    printf("Nenhuma pizza foi entregue ainda.\n");
  }
}
