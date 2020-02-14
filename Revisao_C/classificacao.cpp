#include <iostream>
#include <string>

using namespace std;

int main(){

    float idade;
    string ps, taquicardia;

    cout << "A pressão sanguínea sistolica nas 24hs iniciais esteve acima de 91?" << endl;
    getline(cin, ps);

    if(ps == "não" || ps == "nao") {
        cout << "O paciente possui alto risco (G)" << endl;
    } else {
        cout << "Qual a idade do paciente?" << endl;
        cin >> idade;

        if(idade > 62.5){
            cout << "Existem sinais de taquicardia?" << endl;
            //getline(cin, taquicardia);
            cin >> taquicardia;
            if(taquicardia == "sim") {
                cout << "O paciente possui alto risco (G)" << endl;
            } else {
                cout << "O paciente possui baixo risco (F)" << endl;
            }
        } else {
            cout << "O paciente possui baixo risco (F)" << endl;
        }
    }
}