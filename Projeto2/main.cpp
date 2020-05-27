#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <list>
#include <time.h>

using namespace std;

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

unordered_map<int, Viagem> viagens;

float generate_id_passageiro() {
    return (random() % 100) + 1;
}

float generate_id_viagem() {
    return (random() % 10000) + 4000;
}

unordered_map<int,bool> cria_lugares(unordered_map<int,bool> &lugares)
{
    int lug = 0;
    while (lug < 43)
    {
        lugares[lug] = true;
        lug++;
    }

    return lugares;
}

void mostrar_viagens(Viagem bus)
{
    cout << "Partindo de " << bus.origem << " com destino " << bus.destino << " sai às " << bus.hora_saida << " e chega " << bus.hora_chegada << endl;
}

void mostrar_passageiros(Passageiro passageiro) {
    cout << "Nome: " << passageiro.nome << "\n Assento: " << passageiro.n_assento << " ";
}

void mostrar_assentos(unordered_map<int,Passageiro> &passageiros) {
    for(auto &par: passageiros) {
        mostrar_passageiros(par.second);
        cout << "(" << par.first << ")" << endl;
    }
}

void mostrar_lugares(unordered_map<int, bool> &lugares) {
    for(auto &par: lugares) {
        if(!par.second) {
            cout << par.first << ". OCUPADO" << endl;
        } else {
            cout << par.first << ". LIVRE" << endl;
        }
    }
}

void criar_viagem()
{
    Viagem bus;
    fstream arq("data/viagens1.txt");
    string linha;

    while(getline(arq, linha)) {
        int pos = 0, pos1;
        pos1 = linha.find(",");
        bus.nome_motorista = linha.substr(pos, pos1);
        pos = pos1 + 1;
        pos1 = linha.find(",", pos);
        bus.origem = linha.substr(pos, (pos1 - pos));
        pos = pos1 + 1;
        pos1 = linha.find(",", pos);
        bus.destino = linha.substr(pos, (pos1 - pos));
        pos = pos1 + 1;
        pos1 = linha.find(",", pos);
        bus.hora_saida = linha.substr(pos, (pos1 - pos));
        pos = pos1 + 1;
        pos1 = linha.find(",", pos);
        bus.hora_chegada = linha.substr(pos, (pos1 - pos));
        cria_lugares(bus.lugares);

        viagens[generate_id_viagem()] = bus;
    }

    for(auto &par: viagens) {
        cout << "Ônibus de número " << par.first << ": ";
        mostrar_viagens(par.second);
        cout << endl;
    }
}

void reservar()
{
    Passageiro viajante;
    Viagem trecho;
    int lugar;
    float n_onibus;

    cout << "Digite o número do ônibus que realizará sua viagem: ";
    cin >> n_onibus;

    for (auto & viagem: viagens) {
        if(n_onibus == viagem.first) {
            trecho = viagem.second;
            break;
        }
    }
    mostrar_viagens(trecho);

    cout << "Escolha seu assento de 0 a 42: ";
    cin >> lugar;

    if(lugar >= 42) {
        cout << "Nossos ônibus possuem apenas 43 lugares, favor escolher uma poltrona de 0 a 42" << endl;
    } else {
        if(trecho.lugares[lugar]) {
            viajante.n_assento = lugar;
            cout << trecho.lugares[lugar] << endl;
            trecho.lugares[lugar] = false;
            cout << trecho.lugares[lugar] << endl;
            cout << "Digite seu nome para reservar o assento: ";
            cin >> viajante.nome;

            trecho.passageiros[generate_id_passageiro()] = viajante;
        } else {
            cout << "Esse lugar já está ocupado ou está indisponível nessa viagem." << endl;
        }
    }
    // cout << trecho.lugares[lugar] << endl;
    mostrar_lugares(trecho.lugares);
    trecho.lugares = trecho.lugares;
}

void mostrar_reserva()
{
    Viagem trecho;
    int id_passageiro;
    float n_onibus;

    cout << "Digite o número do ônibus que realizará sua viagem: ";
    cin >> n_onibus;

    for (auto & viagem: viagens) {
        if(n_onibus == viagem.first) {
            trecho = viagem.second;
            break;
        }
        cout << "Desculpe não encontrei o ônibus com o número " << n_onibus << endl;
    }

    mostrar_lugares(trecho.lugares);
    mostrar_assentos(trecho.passageiros);
}

void viagens_disponiveis()
{
    
    cout << "Mostrando viagens disponíveis.." << endl;

    for(auto &par: viagens) {
        cout << "Ônibus de número " << par.first << ": ";
        mostrar_viagens(par.second);
        cout << endl;
    }
}

void menu()
{
    while (true)
    {
        int escolha;
        cout << " \t\t\t 1. Criar viagem\n\t\t\t 2. Reservar assento\n\t\t\t 3. Informações de viagem\n\t\t\t 4. Viagens disponíveis\n\t\t\t 5. Sair\n\t\t\t" << endl;
        cout << "Escolha uma opção:\n>> ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            criar_viagem();
            break;
        case 2:
            reservar();
            break;
        case 3:
            mostrar_reserva();
            break;
        case 4:
            viagens_disponiveis();
            break;
        case 5:
            break;
        default:
            cout << "Você não escolheu nenhuma das opções listadas" << endl;
            break;
        }
    }
}

int main()
{
    menu();
    return 0;
}