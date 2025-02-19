#ifndef ESTRUTURA_H_INCLUDED
#define ESTRUTURA_H_INCLUDED



#define MAX_CLIENTES 100
#define MAX_PIZZAS 50
#define MAX_PEDIDOS 100

typedef struct {
  int telefone;
  char nome[100];
  char endereco[100];
  char complemento[50];
  char cep[10];
} Cliente;

typedef struct {
  int codigo;
  char nome[50];
  float valor;
} Pizza;

typedef struct {
  int numeroPedido;
  int telefoneCliente;
  int codigoPizza;
  int codigoMotoqueiro;
  int situacao;
} Pedido;


#endif // ESTRUTURA_H_INCLUDED
