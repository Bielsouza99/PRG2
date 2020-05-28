# Projeto 2 - Sistema de consulta de viagens
O projeto 2 tem como objetivo criar um programa que o usuário poderá reservar seu assento, consultar as viagens disponíveis e ver informações da sua viagem de uma empresa de viagens rodoviárias.

## Introdução ao projeto


## Algoritmo
Trabalharemos utilizando a memória do programa, criando uma tabela hash (unordered_map) como variável global, faremos todas as operações em cima dela, essa tabela hash possui como chave um float que será o número do veículo que realizará a viagem e como valor um tipo específico criado por nós programadores, essa que por sua vez possui um atributo também do tipo unordered_map com um outro tipo de dados definido por nós como valor e novamente uma variável do tipo int como chave.

Ao iniciar o programa o usuário irá se deparar com o menu, onde irá possuir 5 opções de seleção:

1 - Criar Viagem
    Chamará a função permitindo que o usuário crie uma viagem
2 - Reservar assento
    Permitirá que o usuário possa reservar seu assento no ônibus, desde que o mesmo não esteja ocupado por outro passageiro
3 - Informações da viagem
    Usuário poderia visualizar seu assento reservado e quantos lugares ainda há disponível no ônibus
4 - Viagens disponíveis
    Mostrará as viagens que estão disponíves no programa naquele momento
5 - Sair
    Encerra o programa


## Pseudocódigo

...

menu() {
    Pergunta qual opção o usuário deseja
    espera a entrada do usuário
    chama a função relacionada opção
}

## Novos tipos de dados

...

struct Passageiro
{
    string nome;
    int n_assento;
};

struct Viagem
{
    string nome_motorista;
    string hora_saida;
    string hora_chegada;
    string origem;
    string destino;
    unordered_map<int,Passageiro> passageiros;
    unordered_map<int, bool> lugares;
};

...

## Projeto final

## Estrutura do programa

Interface do usuário se dará pela CLI, os dados das viagens estarão armazenados em 1 ou mais arquivos de texto previamente criados e inseridos no repositório

## Representação de dados

As viagens são representadas pelo tipo de dados Viagem criado por nós programadores e amarzenadas em uma unordered_map<int,Viagem> que é global no escopo do programa, apenas armanezados dentro da memória do programa.

Os passageiros são representados por um tipo de dados chamado Passageiro e armazenados em uma unordered_map<int, Passageiro> dentro da struct Viagem

## Funcionalidades do programa


