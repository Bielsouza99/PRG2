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
        if (matricula == novoAluno.matricula)
        {
            return nome < novoAluno.nome;
        }
        return matricula < novoAluno.matricula;
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

void verifica_repetidos(list<Aluno> alunos) {}

void normalizar_lista(list<Aluno> alunos) {}

int main(int argc, char *argv[])
{
    string linha;
    list<Aluno> alunos;
    fstream arq("alunos1.txt");
    while (getline(arq, linha))
    {
        Aluno al;
        int pos = linha.find(" ");
        al.matricula = linha.substr(0, pos);
        al.nome = linha.substr(pos + 1, string::npos);
        alunos.push_back(al);
    }
    cout << alunos.size() << endl;
    alunos.sort();
    alunos.unique();
    for (auto &student : alunos)
    {
        mostra_aluno(student);
    }
    cout << alunos.size() << endl;
}