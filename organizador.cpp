#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*O programa deve cumprir estes requisitos:
1. Exibir o título ORGANIZADOR CLI.
2. Mostrar três opções iniciais: 1. Adicionar tarefa, 2. Listar tarefas e 0. Sair.
3. Solicitar uma opção ao usuário usando cin.
4. Usar if/else ou switch para identificar a opção escolhida.
5. Mostrar uma mensagem diferente para cada opção.
6. Repetir o menu até que o usuário escolha 0.*/

// sem o "using namespace std;" é necessário utilizar o std:: antes de chamar qualquer variável, inclusive quando você for criar uma que seja string
int optionMenu;
std::string addTarefa;
// std::vector<std::string> tarefas; /*cria váriavel vetor especificando tipo (string) e da o nome*/

int main()
{
    // std::ifstream tarefas("tarefas.txt");
    do
    {
        std::cout << "\n\n============================";
        std::cout << "\nORGANIZADOR DE TAREFAS (CLI)\n";
        std::cout << "============================\n\n";
        std::cout << "1. Adicionar tarefa\n";
        std::cout << "2. Listar tarefa\n";
        std::cout << "3. Mostrar últimas 10 tarefas concluídas\n";
        std::cout << "0. Salvar e sair\n";
        std::cin >> optionMenu;
        std::cout << "\n";

        switch (optionMenu)
        {
        case 1:
        {
            std::cout << "Adicione uma tarefa: \n\n";
            std::getline(std::cin >> std::ws, addTarefa); //"getline" le a frase inteira e "ws" permite que voce escreva com espaços
            std::ofstream outTarefa("tarefas.txt", std::ios::app);
            outTarefa << addTarefa << "\n";
            outTarefa.close();
            std::cout << "\nTarefa adicionada com sucesso!\n";
            break;
        }
        case 2:
        {
            std::ifstream listTarefa("tarefas.txt");
            if (!listTarefa.is_open())
            {
                std::cerr << "Erro ao abrir arquivo, tente novamente!";
                return 1;
            }
            else
            {
                while (std::getline(listTarefa, addTarefa))
                {
                    std::cout << "@" << addTarefa << "\n";
                }
            }
            listTarefa.close();
            break;
        }
        case 3:
            std::cout << "Mostrando últimas tarefas concluídas: \n";
            break;
        case 0:
            std::cout << "Salvando e saindo . . .\n";
            break;
        default:
            std::cout << "Opção inválida, tente novamente.\n"; // não precisa do "return 0;" no default, o do-while faz a função de mostrar o menu novamente
            break;
        }
    } while (optionMenu != 0); // mostra o menu enquanto a resposta desejada não for zero
}
// OUTRA FORMA DE LISTAR
// if(tarefas.empty() == true){//se nao tem tarefas para fazer for true retorna que nao ha tarefas
//     std::cout << "Não há tarefas pendentes.\n";
// }else{
//     std::cout << "Listando todas as tarefas disponíveis . .\n";
//     std::cout << "Atualmente você tem " << tarefas.size() << " tarefas:\n\n"; // tarefas.size(); mostra a quantidade de itens no vetor
//     for (int i = 0; i < tarefas.size(); i++){                                                                //"for" enquanto "i" menor que a quantidade de tarefas
//         std::cout << char('A' + i) << ". " << tarefas.at(i) << "\n"; // printa CHAR (A B C) que o proprio C++ atualiza conforme char + i, tarefas.at(i) lista a tarefa do número i
// }    // recomendado utilizar at.(i) para entender melhor o código caso de erro
// OUTRA FORMA DE LISTAR
/*for (std::string lista : tarefas){ -> usa um "for" para mostrar itens dentro da TAREFAS, utilizando outro nome LISTA, como se fosse um nome externo
    std::cout << lista << "\n"; -> usa nome externo para poder printar
}*/