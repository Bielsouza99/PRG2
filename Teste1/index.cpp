#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <list>

using namespace std;

const int tamCartela = 8;
struct Jogador
{
    string nome;
    int cartela[tamCartela];
    int acertos = 0;
};

void printJogador(Jogador jogador)
{
    cout << "A cartela de " << jogador.nome << ": ";
    for (int i = 0; i < 8; i++)
    {
        cout << jogador.cartela[i] << " ";
    }

    cout << endl;
}

int generateRandomNumber()
{
    int randomN = rand() % 100 + 1;
    return randomN;
}

void init(Jogador *jogadores, int nJogadores)
{
    Jogador jog;

    for (int i = 0; i < nJogadores; i++)
    {
        cout << "Digite o nome do jogador " << i << ": ";
        cin >> jog.nome;

        for (int j = 0; j < tamCartela; j++)
        {
            int n = rand() % 100 + 1;
            for (int k = 0; k < tamCartela; k++)
            {
                if (jog.cartela[k] == n)
                {
                    int newN = generateRandomNumber();
                    jog.cartela[j] = newN;
                }
                else
                    jog.cartela[j] = n;
            }
        }

        jogadores[i] = jog;
    }

    for (int t = 0; t < nJogadores; t++)
    {
        printJogador(jogadores[t]);
    }

    bool ganhador = false;
    int ctrl = 0;
    int tam = 100;
    while (!ganhador)
    {
        int randomN = generateRandomNumber();
        int arrWin[tam];

        for (int index = 0; index < nJogadores; index++)
        {
            auto arr = jogadores[index].cartela;

            for (int aux = 0; aux < tamCartela; aux++)
            {
                if (arr[aux] == randomN)
                {
                    cout << "A cartela de " << jogadores[index].nome << " tem " << arr[aux] << " ";
                    cout << "- Acertos: "
                         << " ";
                    jogadores[index].acertos += 1;
                    cout << jogadores[index].acertos << endl;
                    arr[aux] = 0;
                    if (jogadores[index].acertos == 8)
                    {
                        ganhador = true;
                        cout << "O vencedor do jogo foi: " << jogadores[index].nome << endl;
                        break;
                    }
                }
            }
        }
        ctrl++;
    }
}

int main()
{
    int nJogadores;
    cout << "Digite o número de jogadores da partida: ";
    cin >> nJogadores;
    Jogador jogs[nJogadores];
    init(jogs, nJogadores);
}