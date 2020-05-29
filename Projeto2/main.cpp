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

unordered_map<int, Viagem> viagens;

float criaIdPassageiro() {
    return (random() % 100) + 1;
}

float criaIdViagem() {
    return (random() % 10000) + 4000;
}

unordered_map<int,bool> criaLugares(unordered_map<int,bool> &lugares)
{
    int lug = 0;
    while (lug < 43)
    {
        lugares[lug] = true;
        lug++;
    }

    return lugares;
}

string criaNomeCompleto(string nome, string sobrenome) {
    string nomeCompleto = nome + " " + sobrenome;
    return nomeCompleto;
}

void mostrarViagens(Viagem bus)
{
    cout << "Partindo de " << bus.origem << " com destino " << bus.destino << " sai às " << bus.horaSaida << " e chega " << bus.horaChegada << endl;
}

void mostrarPassageiro(unordered_map<int, Passageiro> & passageiros, int id_passageiro) {
    for(auto &p: passageiros) {
        if(p.first == id_passageiro) {
            auto po = p.second;
            cout << "ID: " << p.first << endl;
            cout << "Nome completo: " << po.nomeCompleto << endl;
            cout << "N° do assento: " << po.nAssento << endl;
        }
    }
}

void mostrarPassageiros(Passageiro passageiro) {
    cout << passageiro.nomeCompleto << " ";
}

void mostrarAssentos(unordered_map<int,Passageiro> &passageiros) {
    for(auto &par: passageiros) {
        mostrarPassageiros(par.second);
        cout << endl;
    }
}

void mostrarLugares(unordered_map<int, bool> &lugares, unordered_map<int, Passageiro> &passageiros) {
    for(auto &par: lugares) {
        if(!par.second) {
            cout << par.first << ". ";
            mostrarAssentos(passageiros);
        } else {
            cout << par.first << ". LIVRE" << endl;
        }
    }
}

void criarViagem()
{
    Viagem bus;
    fstream arq("data/viagens1.txt");
    string linha;

    while(getline(arq, linha)) {
        int pos = 0, pos1;
        pos1 = linha.find(",");
        bus.nomeMotorista = linha.substr(pos, pos1);
        pos = pos1 + 1;
        pos1 = linha.find(",", pos);
        bus.origem = linha.substr(pos, (pos1 - pos));
        pos = pos1 + 1;
        pos1 = linha.find(",", pos);
        bus.destino = linha.substr(pos, (pos1 - pos));
        pos = pos1 + 1;
        pos1 = linha.find(",", pos);
        bus.horaSaida = linha.substr(pos, (pos1 - pos));
        pos = pos1 + 1;
        pos1 = linha.find(",", pos);
        bus.horaChegada = linha.substr(pos, (pos1 - pos));
        criaLugares(bus.lugares);

        viagens[criaIdViagem()] = bus;
    }

    for(auto &par: viagens) {
        cout << "Ônibus de número " << par.first << ": ";
        mostrarViagens(par.second);
        cout << endl;
    }
}

void reservar()
{
    Passageiro viajante;
    Viagem *trecho;
    int lugar;
    float n_onibus;

    cout << "Digite o número do ônibus que realizará sua viagem: ";
    cin >> n_onibus;

    for (auto & viagem: viagens) {
        if(n_onibus == viagem.first) {
            trecho = &viagem.second;
            break;
        }
    }

    cout << "Escolha seu assento de 0 a 42: ";
    cin >> lugar;

    if(lugar >= 42) {
        cout << "Nossos ônibus possuem apenas 43 lugares, favor escolher uma poltrona de 0 a 42" << endl;
    } else {
        if(trecho -> lugares[lugar]) {
            viajante.nAssento = lugar;
            trecho -> lugares[lugar] = false;
            cout << "Certo, agora preciso do seu nome e sobrenome para reservar seu assento na viagem." << endl;
            cout << "Nome: ";
            cin >> viajante.nome;
            cout << "Sobrenome: ";
            cin >> viajante.sobrenome;
            viajante.nomeCompleto = criaNomeCompleto(viajante.nome, viajante.sobrenome);
            int id_passageiro = criaIdPassageiro();
            trecho -> passageiros[id_passageiro] = viajante;
            cout << "Seu ID é: " << id_passageiro << ". Salve-o para consultar sua reserva quando quiser." << endl;
        } else {
            cout << "Esse lugar já está ocupado ou está indisponível nessa viagem." << endl;
        }
    }
}

void infoViagem()
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
    }

    mostrarViagens(trecho);
    cout << endl << endl << endl;
    mostrarLugares(trecho.lugares, trecho.passageiros);
    //mostrar_assentos(trecho.passageiros);
}

void infoReserva() {
    
    Viagem trecho;
    int id_passageiro;
    float n_onibus;

    cout << "Digite o número do ônibus que realizará sua viagem: ";
    cin >> n_onibus;
    cout << "Digite o seu ID de passageiro: ";
    cin >> id_passageiro;

    for (auto & viagem: viagens) {
        if(n_onibus == viagem.first) {
            trecho = viagem.second;
            break;
        }
    }

    mostrarPassageiro(trecho.passageiros, id_passageiro);

}

void viagensDisponiveis()
{
    
    cout << "Mostrando viagens disponíveis.." << endl;

    for(auto &par: viagens) {
        cout << "Ônibus de número " << par.first << ": ";
        mostrarViagens(par.second);
        cout << endl;
    }
}

void menu()
{
    while (true)
    {
        int escolha;
        cout << " \t\t\t 1. Criar viagem\n\t\t\t 2. Reservar assento\n\t\t\t 3. Informações de viagem\n\t\t\t 4. Viagens disponíveis\n\t\t\t 5. Informações da sua reserva\n\t\t\t 6. Sair\n\t\t\t" << endl;
        cout << "Escolha uma opção:\n>> ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            criarViagem();
            break;
        case 2:
            reservar();
            break;
        case 3:
            infoViagem();
            break;
        case 4:
            viagensDisponiveis();
            break;
        case 5:
            infoReserva();
            break;
        case 6:
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