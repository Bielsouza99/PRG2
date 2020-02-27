#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string substitui(string texto, string sub, string outra)
{
    int pos = texto.find(sub);

    if (pos == string::npos)
        return texto;

    return texto.replace(pos, sub.length(), outra);
}

int main(int argc, char *argv[])
{
    string dado, linha, cidade = "$cidade", data = "$data", aluno = "$aluno", disciplina = "$disciplina";
    string arquivo = argv[1];

    fstream arq(arquivo);

    if (!arq.is_open())
    {
        throw - 1;
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            dado = argv[i];
            int pos = dado.find("=");
            auto formData = dado.substr(0, pos);
            if (formData == "cidade")
            {
                cidade = dado.erase(0, pos + 1);
            }
            else if (formData == "data")
            {
                data = dado.erase(0, pos + 1);
            }
            else if (formData == "aluno")
            {
                aluno = dado.erase(0, pos + 1);
            }
            else if (formData == "disciplina")
            {
                disciplina = dado.erase(0, pos + 1);
            }
            else
            {
                break;
            }
        }

        string t, s, l, p;
        while (getline(arq, linha))
        {
            if (cidade != "$cidade")
            {
                t = substitui(linha, "$cidade", cidade);
                if (data != "$data")
                {
                    s = substitui(t, "$data", data);
                    if (aluno != "$aluno")
                    {
                        l = substitui(s, "$aluno", aluno);
                        if (disciplina != "$disciplina")
                        {
                            p = substitui(l, "$disciplina", disciplina);
                        }
                    }
                }
            }
            cout << p << endl;
        }
    }
}