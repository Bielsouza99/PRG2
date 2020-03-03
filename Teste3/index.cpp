#include <string>
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(){
    string diretorio, arquivo, newArq, linha;
    queue<string> q;

    cout << "Digite para qual diretório você deseja copiar os arquivos: " << endl;
    getline(cin,diretorio);
    do
    {
        cout << "Digite o nome do arquivo a ser copiado: (Para sair, aperte ENTER apenas)" << endl;
        getline(cin, arquivo);
        q.push(arquivo);
    } while (!arquivo.empty());
    

    while(!q.empty()){
        string arquivoAtual = q.front();
        newArq = diretorio + "/" + arquivoAtual;

        ifstream arq(arquivoAtual);
        ofstream arq1(newArq);
        
        if(!arq.is_open()){
            return errno;
        } else {
            string linha;
            while(getline(arq,linha)){
                arq1 << linha << endl;
            }
        }        
        q.pop();
    }


}