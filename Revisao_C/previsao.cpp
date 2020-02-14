#include <iostream>
#include <string>

using namespace std;

int main() {
    string barometro, termometro;

    cout << "Define como está o barômetro (S = subindo / E = Estacionário / B = Baixando)" << endl;
    getline(cin,barometro);

    cout << "Define como está o termômetro (S = subindo / E = Estacionário / B = Baixando)" << endl;
    getline(cin, termometro);

    if(barometro == "S"){
        if(termometro == "S"){
            cout << "Tempo bom, ventos quentes e secos"<< endl;
        } else if (termometro == "E"){
            cout << "Tempo bom, ventos de leste frescos"<< endl;
        } else {
            cout << "Tempo bom, ventos de sul a sudeste"<< endl;
        }
    } else if(barometro == "E"){
        if(termometro == "S"){
            cout << "Tempo mudando para bom, ventos de leste"<< endl;
        } else if (termometro == "E"){
            cout << "Tempo incerto, ventos variáveis"<< endl;
        } else {
            cout << "Chuva provável, ventos de sul a sudeste"<< endl;
        }
    } else {
        if(termometro == "S"){
            cout << "Tempo instável, aproximação de frente"<< endl;
        } else if (termometro == "E"){
            cout << "Frente quente com chuvas prováveis"<< endl;
        } else {
            cout << "Chuvas abundantes e ventos de sul a sudoeste fortes" << endl;
        }
    }
}