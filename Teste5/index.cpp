#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

struct Aluno
{
    string nome;
    string matricula;

    bool operator<(const Aluno &novoAluno)
    {
        if (nome == novoAluno.nome)
        {
            return matricula < novoAluno.matricula;
        }
        return nome < novoAluno.nome;
    }
};

bool operator==(const Aluno &al1, const Aluno &al2)
{
    return (al1.matricula == al2.matricula) && (al1.nome == al2.nome);
}

void mostra_aluno(Aluno aluno)
{
    cout << "Nome: " << aluno.nome << endl;
    cout << "Matrícula: " << aluno.matricula << endl;
}

int main(int argc, char *argv[])
{
    string linha;
    list<Aluno> alunos;
    for (int i = 1; i < argc; i++)
    {
        fstream arq(argv[i]);
        while (getline(arq, linha))
        {
            Aluno al;
            int pos = linha.find(" ");
            al.matricula = linha.substr(0, pos);
            al.nome = linha.substr(pos + 1, string::npos);
            alunos.push_back(al);
        }
    }

    alunos.sort();

    cout << alunos.size() << endl;
    for (auto &students : alunos) {
        mostra_aluno(students);
    }

    cout << endl << endl << endl << endl;

    
    alunos.unique();
    for (auto &student : alunos)
    {
        mostra_aluno(student);
    }
    cout << alunos.size() << endl;
}