#include <iostream>

using namespace std;

int main() {
    long double atual, anterior, fn;
    int N;
    cout << "Informe quantos números deseja mostrar dessa sequência: " << endl;
    cin >> N;
    cout << endl;

    long double seq [N] = {1};
     fn = 1;
    anterior = 0;
    seq[0] = 1;
    for(int j = 1; j < N; j++){
        seq[j] = fn + anterior;
        anterior = fn;
        fn = seq[j];
    }

    for(int i = 0; i < N; i++){
        cout << seq[i] << endl;
    }

    return 0;
}