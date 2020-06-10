# Projeto 2 - Sistema de consulta de viagens
O projeto 2 tem como objetivo criar um programa que o usuário poderá reservar seu assento, consultar as viagens disponíveis e ver informações da sua viagem de uma empresa de viagens rodoviárias.

## Introdução ao projeto
Diversas empresas de transporte de passageiros necessitam de um sistema para que os usuários possam consultar as viagens disponíveis,
reservar seu assento no veículo, consultar sua reserva e procurar por viagens. Dessa maneira pensamos num sistema que englobe todas esses requisitos, ao final o usuário poderá, reservar seu assento na viagem desejada, ver todas as viagens disponíveis, ver todas as viagens a partir de uma origem ou de um destino, bem como poderá consultar sua reserva.

Os dados estarão dispostos em um arquivo de texto da seguinte forma:
```
Sérgio,Florianópolis,Chapecó,10:00,23:00
Pedro,Blumenau,Florianópolis,12:30,16:10
Pablo,Balneário Camboriú,Brusque,14:30,15:40
André,Criciúma,Itapema,10:00,15:00
Roberto,Itapema,Xanxerê,07:00,17:00

```
O qual segue a ordem:
<ul>
    <li>Nome do motorista</li>
    <li>Cidade de origem</li>
    <li>Cidade de destino</li>
    <li>Horário de saída</li>
    <li>Horário de chegada</li>
</ul>

Cada viagem tem um ID único e aleatório gerado quando incluída na tabela hash que a representa, será utilizada uma tabela hash para facilitar a procura da viagem selecionada pelo usuário, tendo em vista que uma mesma empresa possui diversos itinerários.

## Algoritmo
Trabalharemos utilizando a memória do programa, criando uma tabela hash (unordered_map) como variável global, faremos todas as operações em cima dela, essa tabela hash possui como chave um float que será o número do veículo que realizará a viagem e como valor um tipo específico criado por nós programadores, essa que por sua vez possui um atributo também do tipo unordered_map com um outro tipo de dados definido por nós como valor e novamente uma variável do tipo int como chave.

Ao iniciar o programa as viagens serão carregadas para a memória do programa e o usuário irá se deparar com o menu, onde irá possuir as seguintes opções de seleção:


* 1 - Reservar assento <br>
    Permitirá que o usuário possa reservar seu assento no ônibus, desde que o mesmo não esteja ocupado por outro passageiro
* 2 - Informações da viagem <br>
    Usuário poderia visualizar seu assento reservado e quantos lugares ainda há disponível no ônibus
* 3 - Viagens disponíveis <br>
    Mostrará as viagens que estão disponíves no programa naquele momento
* 4 - Informações da reserva <br>
    Mostrará ao usuário o nome completo de quem reservou, seu ID e o número do seu assento
* 5 - Buscar viagens a partir de uma cidade de origem <br>
    Usuário poderá pesquisar todas as viagens disponíveis a partir da sua cidade de origem 
* 6 - Buscar viagens a partir de uma cidade de destino <br>
    Usuário poderá pesquisar todas as viagens disponíveis a partir da sua cidade de destino
* 7 - Sair <br>
    Encerra o programa


## Pseudocódigo

```
carrega as viagens pra memória

mostra o menu
{
    opção 1 - reservar assento
    opção 2 - informações da viagem
    opção 3 - viagens disponíveis
    opção 4 - informações da reserva
    opção 5 - buscar viagens de uma origem
    opção 6 - buscar viagens de um destino
    opção 7 - sair
}

opção 1 - Pergunta ao usuário o número do ônibus que irá realizar a viagem, se existir, pergunta o assento, caso exista e não esteja ocupado perguntará o nome e sobrenome, ao final irá exibir o ID do passageiro

opção 2 - Pergunta ao usuário o número do ônibus que irá realizar a viagem, se existir, retorna pro usuário na tela o itinerário e a relação dos assentos

opção 3 - Mostra todas as viagens com ID e intinerário

opção 4 - Pergunta ao usuário o número do ônibus que irá realizar a viagem, se existir, pergunta o ID de passageiro, se existir, mostra o nome completo e o assento do passageiro referente ao ID

opção 5 - Pergunta ao usuário o nome da cidade de origem, caso exista uma viagem com essa cidade como origem, adiciona a uma lista auxiliar e no final do loop printa todas as viagens com essa condição

opção 6 - Pergunta ao usuário o nome da cidade de destino, caso exista uma viagem com essa cidade como destino, adiciona a uma lista auxiliar e no final do loop printa todas as viagens com essa condição



```

## Novos tipos de dados

```
struct Passageiro
{
    string nome;
    string sobrenome;
    string nomeCompleto;
    int nAssento;
};

struct Viagem
{
    string nomeMotorista;
    string horaSaida;
    string horaChegada;
    string origem;
    string destino;
    unordered_map<int,Passageiro> passageiros;
    unordered_map<int, bool> lugares;
};

```

## Projeto final

## Estrutura do programa

Interface do usuário se dará pela CLI, os dados das viagens estarão armazenados em 1 ou mais arquivos de texto previamente criados e inseridos no repositório

## Representação de dados

As viagens são representadas pelo tipo de dados Viagem criado por nós programadores e amarzenadas em uma unordered_map<int,Viagem> que é global no escopo do programa, apenas armanezados dentro da memória do programa.

Os passageiros são representados por um tipo de dados chamado Passageiro e armazenados em uma unordered_map<int, Passageiro> dentro da struct Viagem

## Funcionalidades do programa
```

criaIdPassageiro() {
    retorna um inteiro aleatório entre 1 - 100
}

criaIdViagem() {
    retorna um float aleatório entre 4000 - 14000
}

criaLugares(unordered_map<int,bool> &lugares) {
    recebe a tabela hash da struct Viagem que representa os lugares
    inicialmente cria a chave com valores inteiros de 0 a 42 e o valor = true
}

criaNomeCompleto(string nome, string sobrenome) {
    retorna nome + " " + sobrenome;
}

mostrarViagens(Viagem bus) {
    printa as informações do ônibus passado como parâmetro de maneira previamente decidida
}

mostrarPassageiro(unordered_map<int, Passageiro> & passageiros, int id_passageiro) {
    printa as informações do passageiro com o ID correspondente ao passado no parâmetro da função de maneira previamente decidida
}

mostrarPassageiros(Passageiro passageiro) {
    printa o nome completo do passageiro
}

mostrarAssentos(unordered_map<int,Passageiro> &passageiros) {

}

criarViagem() {
    abre o arquivo de texto
    procura a vírgula a partir da posição da anterior+1
    criaLugares()
    e seta a chave da tabela hash global (viagens) chamando a  função criaIdViagem() e o valor como o onibus criado com os parametros lidos do arquivo de texto
}

reservar() {
    pergunta ao usuário o n° do ônibus
    o assento que ele deseja
    se ele tiver vazio (true), seta para falso
    se ele estiver ocupado, avisa o usuário que o lugar está ocupado e chama o menu novamente
    pergunta o nome e sobrenome do usuário
    chama criaNomeCompleto(nome, sobrenome)
    printa o ID para conhecimento do usuário

}

infoViagem() {
    printa as informações da viagem e a situação dos assentos
}

infoReserva() {
    pergunta ao usuário o n° do ônibus e seu ID para informar seu nome e seu assento
}

viagensDisponiveis() {
    printa todas as viagens com origem, destino, nome do motorista, hora de saída e previsão de chegada
}

```