#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string substitui(string texto, string sub, string outra){
    int pos = texto.find(sub);
    
    if(pos == string::npos)return texto;
    
    return texto.replace(pos, sub.length(), outra);
}

int main(int argc, char * argv[]) {
    string dado;
    string arquivo = argv[1];

    fstream arq(arquivo);

    if(!arq.is_open()){
        throw -1;
    } else {
        for(int i = 2; i < argc; i++){
            dado = argv[i];
            int pos = dado.find("=");
            dado = dado.erase(0,pos+1);
            cout << dado << endl;
        }
    }
}