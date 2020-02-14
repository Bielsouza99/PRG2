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
    //srand(time(NULL));
    //int generateSeed = (rand() % 10 + 1);
    int randomN = rand() % 100;
    return randomN;
}

bool verifyOut(int *numeros, int num)
{
    bool saiu = false;

    for (int i = 0; i < 100; i++)
    {
        if (numeros[i] == num)
        {
            saiu = true;
        }
        else
        {
            saiu = false;
        }
    }

    return saiu;
}

void init(Jogador *jogadores, int nJogadores)
{
    Jogador jog;
    int cart[tamCartela];

    for (int i = 0; i < nJogadores; i++)
    {
        cout << "Digite o nome do jogador " << i << ": ";
        cin >> jog.nome;

        for (int j = 0; j < tamCartela; j++)
        {
            int n = rand() % 100;
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
    while (!ganhador)
    {
        
        int arrWin[100];

        int randomN;
        for(ctrl; ctrl < 100; ctrl++){
            int randomN = generateRandomNumber();
            for(int l = 0; l < 100; l++){
                if(randomN == arrWin[l]){
                    int newRandomN = generateRandomNumber();
                    arrWin[l] = newRandomN;
                }else {
                    arrWin[l] = randomN;
                }
            }
        }





        for (int index = 0; index < nJogadores; index++)
        {
            auto arr = jogadores[index].cartela;

            for (int aux = 0; aux < tamCartela; aux++)
            {
                if (arr[aux] == randomN)
                {
                    cout << "A cartela de " << jogadores[index].nome << " tem " << arr[aux] << "? ";
                    cout << "Sim"
                         << " ";
                    jogadores[index].acertos = jogadores[index].acertos + 1;
                    cout << jogadores[index].acertos << endl;

                    if (jogadores[index].acertos == 8)
                    {
                        ganhador = true;
                        cout << "O vencedor do jogo foi: " << jogadores[index].nome << endl;
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    int nJogadores;
    cout << "Digite o número de jogadores da partida: ";
    cin >> nJogadores;
    Jogador jogs[nJogadores];
    int cartela[tamCartela];
    init(jogs, nJogadores);
}