#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//tarefa = variavel do dado inserido
//addTarefa = variavel do arquivo que vai ser escrito e enviado
//listTarefa = variavel do arquivo que vai ser chamado e lido
// std::string tarefa;
// std::vector<std::string> task;
// std::string tarefa;

int main(){
    // std::cout << "escreva \n";
    // std::getline (std::cin >> std::ws, tarefa);//pega a linha inteira = espacos etc
    // std::ofstream addTarefa("dado.txt"); //cria a variavel do arq
    //     addTarefa << tarefa << "\n";//adiciona a variavel no arquivo como se fosse o cout
    //     addTarefa.close(); // fecha o arquivo

    // std::ifstream listTarefa("dado.txt"); //abre o arquivo para leitura
    // std::getline(listTarefa >> std::ws, tarefa); //pega a frase inteira c espacos etc
    // std::cout << tarefa << "\n"; //printa a variavel
    // listTarefa.close();//fecha o arquivo
    // return 0;

    // std::cout <<"Escreva um dado aqui: \n";
    // std::getline(std::cin >> std::ws, tarefa);
    // task.push_back(tarefa);
    // std::ofstream addTarefa("Task.txt");
    //     addTarefa << tarefa << "\n";
    //     addTarefa.close();

    std::ifstream listTarefa("tarefas.txt");
    if(!listTarefa.is_open()){
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 1;
    }
    std::string tarefa;
    std::cout << "escreva um dado" << std::endl;
    std::getline(std::cin >> std::ws, tarefa);
    std::ofstream addTarefa("tarefas.txt");

    while(std::getline(listTarefa, tarefa)){
        std::cout << tarefa << std::endl;
    }
    listTarefa.close();
    return 0;
}