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
    string dado, linha, cidade, data, aluno, disciplina;
    string arquivo = argv[1];

    fstream arq(arquivo);

    if(!arq.is_open()){
        throw -1;
    } else {
        for(int i = 2; i < argc; i++){
            dado = argv[i];
            int pos = dado.find("=");
            auto formData = dado.substr(0,pos);
            //cout << formData << endl;
            if(formData == "cidade"){
                cidade = dado.erase(0,pos+1);
            }else if(formData == "data"){
                data = dado.erase(0,pos+1);
            } else if(formData == "aluno") {
                aluno = dado.erase(0,pos+1);
            } else if(formData == "disciplina"){
                disciplina = dado.erase(0,pos+1);
            }else {
                cout << "Não foi achado nenhum parâmetro correspondente" << endl;
            }
            // dado = dado.erase(0,pos+1);
        }

        cout << cidade << endl << data << endl << aluno << endl << disciplina << endl;
        // while(arq >> linha){
        //     if(linha.size() > 0){
        //         int pos = linha.find("$");
        //         auto var = linha.substr(pos+1,linha.size());
        //         auto newP = substitui(linha, var, "");
        //         cout << newP << endl;
        //     }
        // }
    }
}
