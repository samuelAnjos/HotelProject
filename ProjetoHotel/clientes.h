#include <iostream>
#include <locale.h>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <time.h> //Usada para receber a data atual do sistema do usuário

using namespace std;
//!Struct que recebe os dados do cliente com o CPF do tipo char para realizar a verificação
struct cliente
{
    char cpf[10];
    string senha;
    string nome;
    int idade;
    string profissao;
    string nacionalidade;
    string sexo;
    string endereco;
    int diaEntrada, mesEntrada, anoEntrada;
    float consumo;
};
//!Struct que recebe os dados do cliente com o CPF do tipo string para facilitar a manipulação dos arquivos
struct clienteStr
{
    string cpf;
    string senha;
    string nome;
    int idade;
    string profissao;
    string nacionalidade;
    string sexo;
    string endereco;
    int diaEntrada, mesEntrada, anoEntrada;
    float consumo;
    int quarto_aux; //! ************************* VARIÁVEL DESCONHECIDA DEVE TER SIDO ADICIONADA POR OUTRO GRUPO **********************
};

void imprimeCampoPadrao(int positionx, int positiony)
{   //Imprime um campo padrão para mostrar o perfil do cliente
    //Imprimeas barras e as sombras
    gotoxy(positionx - 4, positiony - 2);
    textbackground(CYAN);
    cout << "                                                                    ";
    gotoxy(positionx - 4, positiony + 10);
    textbackground(CYAN);
    cout << "                                                                    ";
    gotoxy(positionx - 3, positiony + 11);
    textbackground(LIGHTGRAY);
    cout << "                                                                    ";

    for (int i = positiony - 2; i <= positiony + 10; i++)
    {
        textbackground(CYAN);
        gotoxy(positionx - 4, i);
        cout << " ";
        gotoxy(positionx + 64, i);
        cout << " ";
        gotoxy(positionx + 65, i + 1);
        textbackground(LIGHTGRAY);
        cout << " ";
    }

    //!Imprime todos os campos
    textbackground(WHITE);
    gotoxy(positionx, positiony);
    cout << "NOME:   ";
    textbackground(LIGHTGRAY);
    cout << "                                                    ";

    textbackground(WHITE);
    gotoxy(positionx, positiony + 2);
    cout << "CPF:  ";
    textbackground(LIGHTGRAY);
    cout << "             ";

    textbackground(WHITE);
    gotoxy(positionx, positiony + 8);
    cout << "IDADE: ";
    textbackground(LIGHTGRAY);
    cout << "     ";

    textbackground(WHITE);
    gotoxy(positionx + 21, positiony + 2);
    cout << "NACIONALIDADE: ";
    textbackground(LIGHTGRAY);
    cout << "                        ";

    textbackground(WHITE);
    gotoxy(positionx + 42, positiony + 8);
    cout << "SEXO [M|F|O]:  ";
    textbackground(LIGHTGRAY);
    cout << "   ";

    textbackground(WHITE);
    gotoxy(positionx, positiony + 4);
    cout << "PROFISSAO: ";
    textbackground(LIGHTGRAY);
    cout << "                        ";

    textbackground(WHITE);
    gotoxy(positionx, positiony + 6);
    cout << "ENDERECO:   ";
    textbackground(LIGHTGRAY);
    cout << "                                               ";

    textbackground(WHITE);
    gotoxy(positionx + 46, positiony + 4);
    cout << "CONSUMO: ";
    textbackground(LIGHTGRAY);
    cout << "     ";
}

void separarValoresClientes(string &linha, clienteStr &retorno)
{ //Separa os valores por virgula dos arquivos

    string temp;
    int contadorCpf = 0;
    int cursorPosition = 0;
    //Percorre todas as letras da linha
    for (int i = 0; i < linha.size(); i++)
    {
        if (linha[i] == ',' || linha[i] == ';')
        { //Quando a letra é igual a , ou ; ele atribui o valor da variável temp para o seu devido lugar
            cursorPosition++;

            if (cursorPosition == 1)
                retorno.nome = temp;
            if (cursorPosition == 2)
            {
                retorno.cpf = temp;
            }
            if (cursorPosition == 3)
                retorno.senha = temp;
            if (cursorPosition == 4)
            {
                retorno.idade = stoi(temp);
            }
            if (cursorPosition == 5)
                retorno.profissao = temp;
            if (cursorPosition == 6)
                retorno.nacionalidade = temp;
            if (cursorPosition == 7)
                retorno.sexo = temp;
            if (cursorPosition == 8)
                retorno.endereco = temp;
            if (cursorPosition == 9)
                retorno.diaEntrada = stoi(temp);
            if (cursorPosition == 10)
                retorno.mesEntrada = stoi(temp);
            if (cursorPosition == 11)
                retorno.anoEntrada = stoi(temp);
            if (cursorPosition == 12)
                retorno.consumo = stoi(temp);

            temp = "";
        }
        else
        { //Sempre que o valor da letra da linha for diferente de , ou ; ele soma a letra com a letra anterior
            temp += linha[i];
        }
    }
}

void cadastrarCliente(cliente *cliente)
{ //armazena no final do arquivo o cliente recebido como ponteiro
    fstream clientesARQ;
    //pega o tempo no sistema
    time_t rawtime;
    struct tm *info;

    time(&rawtime); //tempo bruto
    info = gmtime(&rawtime);
    //coloca na struct
    cliente->diaEntrada = info->tm_mday;
    cliente->mesEntrada = info->tm_mon + 1;
    cliente->anoEntrada = 1900 + info->tm_year;
    //abre o arquivo e coloca o cursor no final do arquivo
    clientesARQ.open("clientes.dat", ios::app);
    //escreve o cliente todo no arquivo separando por ,
    clientesARQ << cliente->nome << ","
                << cliente->cpf << ","
                << cliente->senha << ","
                << cliente->idade << ","
                << cliente->profissao << ","
                << cliente->nacionalidade << ","
                << cliente->sexo << ","
                << cliente->endereco << ","
                << cliente->diaEntrada << ","
                << cliente->mesEntrada << ","
                << cliente->anoEntrada << ","
                << cliente->consumo << ";" << endl;
    //Fecha o arquiv
    clientesARQ.close();
}

clienteStr buscarCliente(string cpf)
{ //procura o usuário que tem o equivalente CPF e retorna toda a struct pra usar os dados no programa

    fstream clientesARQ;
    clienteStr retorno;
    string linha = "";
    //abre o arquivo
    clientesARQ.open("clientes.dat", ios::in);
    //pega cada linha do arquivo
    while (getline(clientesARQ, linha))
    {
        //usa a função para separar os dados em uma struct
        separarValoresClientes(linha, retorno);
        if (cpf == retorno.cpf)
        { //Se o cpf for o que o usuário está procurando ele retorna a struct com todos os dados do usuário
            clientesARQ.close();
            return retorno;
        }
    }

    clientesARQ.close();
    retorno.nome = "NULL";
    //caso não encontre nehum usuário ele define struct.nome como NULL e retorna para podermos tratar o erro
    return retorno;
}

void atualizarCliente(clienteStr *clienteEntrada)
{ //recebe um endereço de struct
    fstream clientesARQ;
    ofstream clientesARQSaida;
    clienteStr retorno;
    string linha;
    //abre um arquivo em formato de leitura
    clientesARQ.open("clientes.dat", ios::in);
    //cria um arquivo em formato de escrita
    clientesARQSaida.open("clientesCopia.dat", ios::out | ios::trunc);
    //enquanto o arquivo de leitura tiver linhas para ler
    while (getline(clientesARQ, linha))
    { //Ele separa todos os valores e armazena numa struct
        separarValoresClientes(linha, retorno);
        //Se o CPF que o usuário enviou for diferente do que está no arquivo ele simplesmente copia de um arquivo para o outro
        if (clienteEntrada->cpf != retorno.cpf)
        {
            clientesARQSaida << retorno.nome << ","
                             << retorno.cpf << ","
                             << retorno.senha << ","
                             << retorno.idade << ","
                             << retorno.profissao << ","
                             << retorno.nacionalidade << ","
                             << retorno.sexo << ","
                             << retorno.endereco << ","
                             << retorno.diaEntrada << ","
                             << retorno.mesEntrada << ","
                             << retorno.anoEntrada << ","
                             << retorno.consumo << ";" << endl;
        }
        if (clienteEntrada->cpf == retorno.cpf)
        {   // Se o cpf que o usuário enviou for o mesmo que enontrou na linha do arquivo significa que é exatamente o que ele quer alterar
            //então esvrevemos no arquivo os dados alteredos recebidos
            clientesARQSaida << clienteEntrada->nome << ","
                             << clienteEntrada->cpf << ","
                             << clienteEntrada->senha << ","
                             << clienteEntrada->idade << ","
                             << clienteEntrada->profissao << ","
                             << clienteEntrada->nacionalidade << ","
                             << clienteEntrada->sexo << ","
                             << clienteEntrada->endereco << ","
                             << clienteEntrada->diaEntrada << ","
                             << clienteEntrada->mesEntrada << ","
                             << clienteEntrada->anoEntrada << ","
                             << clienteEntrada->consumo << ";" << endl;
        }
    }

    clientesARQ.close();
    clientesARQSaida.close();
    //Renomeamos e substituimos o original pela cópia e assim temos um usuário alterado
    system("MOVE clientesCopia.dat clientes.dat");
}

void excluirCliente(string cpf)
{ //nLinha é o número da linha que vai ser deletada
    fstream clientesARQ;
    ofstream clientesARQSaida;
    clienteStr retorno;
    string linha;
    //abre um arquivo de leitura
    clientesARQ.open("clientes.dat", ios::in);
    //abre um arquivo de escrita
    clientesARQSaida.open("clientesCopia.dat", ios::out | ios::trunc);

    while (getline(clientesARQ, linha))
    {
        //separa os dados de cada linha do arquivo e armazena em uma struct
        separarValoresClientes(linha, retorno);
        if (cpf != retorno.cpf)
        { //copia para o outro arquivo apenas os dados do usuário que tem o CPF diferente do que foi recebido na função
            clientesARQSaida << retorno.nome << ","
                             << retorno.cpf << ","
                             << retorno.senha << ","
                             << retorno.idade << ","
                             << retorno.profissao << ","
                             << retorno.nacionalidade << ","
                             << retorno.sexo << ","
                             << retorno.endereco << ","
                             << retorno.diaEntrada << ","
                             << retorno.mesEntrada << ","
                             << retorno.anoEntrada << ","
                             << retorno.consumo << ";" << endl;
        }
    }

    clientesARQ.close();
    clientesARQSaida.close();
    //Substitui o arquivo antigo pelo que foi alterado
    system("MOVE clientesCopia.dat clientes.dat");
}

void listarClientes()
{ //Mostra na tela todos os clientes cadastrados no programa
    system("cls");
    fstream clientesARQ;
    clienteStr retorno;
    string linha = "";
    int verificacao, linhaMostrar = 2;

    clientesARQ.open("clientes.dat", ios::in);

    textcolor(WHITE);
    textbackground(DARKGRAY);
    gotoxy(1, 1);
    for (int i = 0; i < 240; i++)
    {
        cout << " ";
    }
    gotoxy(2, 1);
    cout << "NOME";
    gotoxy(22, 1);
    cout << "CPF";
    gotoxy(36, 1);
    cout << "IDADE";
    gotoxy(49, 1);
    cout << "PROFISSAO";
    gotoxy(65, 1);
    cout << "NACIONALIDADE";
    gotoxy(82, 1);
    cout << "SEXO";
    gotoxy(92, 1);
    cout << "DATA DE CADASTRO";
    /*gotoxy(113, 1);
    cout << "DEVENDO";*/
    //Pega linha por linha, separa os dados e imprime no lugar correto
    while (getline(clientesARQ, linha))
    {
        linhaMostrar++;
        separarValoresClientes(linha, retorno);
        if (linhaMostrar % 2 == 0)
        {
            textbackground(WHITE);
            textcolor(LIGHTBLUE);
        }
        else
        {
            textbackground(LIGHTBLUE);
            textcolor(WHITE);
        }
        gotoxy(1, linhaMostrar);
        for (int i = 0; i < 120; i++)
        {
            cout << " ";
        }

        gotoxy(1, linhaMostrar);
        cout << " " << retorno.nome;
        gotoxy(20, linhaMostrar);
        cout << " " << retorno.cpf;
        gotoxy(36, linhaMostrar);
        cout << " " << retorno.idade;
        gotoxy(51, linhaMostrar);
        cout << " " << retorno.profissao;
        gotoxy(65, linhaMostrar);
        cout << " " << retorno.nacionalidade;
        gotoxy(80, linhaMostrar);
        //substitui uma letra por uma palavre para ficar mais fácil a compreenção
        if (retorno.sexo == "m" || retorno.sexo == "M")
        {
            cout << " masculino";
        }
        else if (retorno.sexo == "f" || retorno.sexo == "F")
        {
            cout << " feminino";
        }
        else if (retorno.sexo == "o" || retorno.sexo == "O")
        {
            cout << " não definido";
        }
        else
        {
            cout << "-";
        }
        gotoxy(95, linhaMostrar);
        cout << " " << retorno.diaEntrada << "/" << retorno.mesEntrada << "/" << retorno.anoEntrada;
        gotoxy(113, linhaMostrar);
        cout << " " << retorno.consumo;
    }

    clientesARQ.close();
    gotoxy(30, 30);
    system("pause");
}

void adicionarConsumo(float valor, string cpf)
{ //Função criada para alterar o valor do consumo do usuário
    clienteStr cliente;
    //Procura o respectivo cliente e armazena os dados em uma struct
    cliente = buscarCliente(cpf);
    //Acrescenta o valor ao consumo do cliente
    cliente.consumo += valor;
    //atualiza o perfil do cliente com o novo valor
    atualizarCliente(&cliente);
}

//!  ******************************************** FEITO COM CARINHO PELO GRUPO DOS CLLIENTES S2 *************************************
