#include <iostream>
#include <locale.h>
#include <fstream>
#include <windows.h> //Usada para mostrar alertas e usar as teclas para navegação
#include <conio2.h>

#include "cpf.h"      //Usado para verificar a validade de um CPF
#include "clientes.h" //Usada para manipular os arquivos referentes aos funcionários

using namespace std;

void atualizarClienteController()
{                                           //controla o recebimento de dados do uduário e direciona eles para a atualização de um cliente
  string cpf;                               //variável que recebe o cpf
  clienteStr clienteAtualizar, novoCliente; //struct que recebe os dados já gravados do usuário e a que recebe os dados que vão ser gravados no usuário que foi substituido

  textbackground(WHITE); //PEGA O CPF DO CLIENTE
  textcolor(LIGHTBLUE);
  system("cls");
  gotoxy(45, 15);
  cout << "INFORME O CPF DO CLIENTE: ";
  textbackground(LIGHTGRAY);
  cout << "             ";
  textcolor(BLACK);
  gotoxy(72, 15);
  cin >> cpf;
  fflush(stdin);
  textbackground(WHITE);

  clienteAtualizar = buscarCliente(cpf); //Procura o respectivo cliente e coloca ele na struct clienteAtualizar
  system("cls");

  if (clienteAtualizar.nome != "NULL")
  {
    imprimeCampoPadrao(32, 4); // Imprime o capo padrão de perfil de cliente começando no respectivo X e Y
    imprimeCampoPadrao(32, 18);

    gotoxy(2, 2); //Mostra na tela a infomação de ajuda para o usuário de como proceder
    cout << "PARA MANTER O CONTEUDO";
    gotoxy(2, 3);
    cout << "ORIGINAL APENAS TECLE";
    gotoxy(10, 4);
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    cout << "ENTER";
    textbackground(LIGHTGRAY);
    textcolor(BLACK);

    int positionx = 32; // define uma posição inicial para posicionar o cursor
    int positiony = 4;
    //cada campo posiciona o cursor no lugar específico com base na posição padrão
    gotoxy(positionx + 9, positiony);
    cout << clienteAtualizar.nome;

    gotoxy(positionx + 7, positiony + 2);
    cout << clienteAtualizar.cpf;

    gotoxy(positionx + 37, positiony + 2);
    cout << clienteAtualizar.nacionalidade;

    gotoxy(positionx + 13, positiony + 4);
    cout << clienteAtualizar.profissao;

    gotoxy(positionx + 56, positiony + 4);
    cout << clienteAtualizar.consumo;

    gotoxy(positionx + 14, positiony + 6);
    cout << clienteAtualizar.endereco;

    gotoxy(positionx + 8, positiony + 8);
    cout << clienteAtualizar.idade;

    gotoxy(positionx + 58, positiony + 8);
    cout << clienteAtualizar.sexo;

    positiony = 18;

    gotoxy(positionx + 7, positiony + 2);
    cout << clienteAtualizar.cpf;

    gotoxy(positionx + 9, positiony);
    getline(cin, novoCliente.nome);
    clienteAtualizar.nome = (novoCliente.nome == "") ? clienteAtualizar.nome : novoCliente.nome;
    //As operações utilizam o operador ternário para verificar se aconteceu uma alteração no campo e se sim ela realiza essa alteração
    gotoxy(positionx + 37, positiony + 2);
    getline(cin, novoCliente.nacionalidade);
    clienteAtualizar.nacionalidade = (novoCliente.nacionalidade == "") ? clienteAtualizar.nacionalidade : novoCliente.nacionalidade;

    gotoxy(positionx + 13, positiony + 4);
    getline(cin, novoCliente.profissao);
    clienteAtualizar.profissao = (novoCliente.profissao == "") ? clienteAtualizar.profissao : novoCliente.profissao;

    //Mostra informações para o usuário
    gotoxy(2, 10);
    cout << "PARA MANTER O CONTEUDO";
    gotoxy(2, 11);
    cout << "ORIGINAL ESCREVA";
    gotoxy(10, 12);
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    cout << " 0 ";
    textbackground(WHITE);
    textcolor(BLACK);

    gotoxy(2, 2);
    cout << "                      ";
    gotoxy(2, 3);
    cout << "                      ";
    gotoxy(10, 4);
    textbackground(WHITE);
    textcolor(WHITE);
    cout << "     ";
    textbackground(LIGHTGRAY);
    textcolor(BLACK);

    gotoxy(positionx + 56, positiony + 4);
    cin >> novoCliente.consumo;
    fflush(stdin);
    clienteAtualizar.consumo = (novoCliente.consumo == 0) ? clienteAtualizar.consumo : novoCliente.consumo;

    gotoxy(2, 2);
    cout << "PARA MANTER O CONTEUDO";
    gotoxy(2, 3);
    cout << "ORIGINAL APENAS TECLE";
    gotoxy(10, 4);
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    cout << "ENTER";
    textbackground(WHITE);
    textcolor(BLACK);

    gotoxy(2, 10);
    cout << "                      ";
    gotoxy(2, 11);
    cout << "                ";
    gotoxy(10, 12);
    textbackground(WHITE);
    textcolor(WHITE);
    cout << "   ";
    textbackground(LIGHTGRAY);
    textcolor(BLACK);

    gotoxy(positionx + 14, positiony + 6);
    getline(cin, novoCliente.endereco);
    clienteAtualizar.endereco = (novoCliente.endereco == "") ? clienteAtualizar.endereco : novoCliente.endereco;

    gotoxy(2, 10);
    cout << "PARA MANTER O CONTEUDO";
    gotoxy(2, 11);
    cout << "ORIGINAL ESCREVA";
    gotoxy(10, 12);
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    cout << " 0 ";
    textbackground(WHITE);
    textcolor(BLACK);

    gotoxy(2, 2);
    cout << "                      ";
    gotoxy(2, 3);
    cout << "                      ";
    gotoxy(10, 4);
    textbackground(WHITE);
    textcolor(WHITE);
    cout << "     ";
    textbackground(LIGHTGRAY);
    textcolor(BLACK);

    gotoxy(positionx + 8, positiony + 8);
    cin >> novoCliente.idade;
    fflush(stdin);
    clienteAtualizar.idade = (novoCliente.idade == 0) ? clienteAtualizar.idade : novoCliente.idade;

    gotoxy(positionx + 58, positiony + 8);
    getline(cin, novoCliente.sexo);
    clienteAtualizar.sexo = (novoCliente.sexo == "") ? clienteAtualizar.sexo : novoCliente.sexo;

    atualizarCliente(&clienteAtualizar);

    textbackground(GREEN);
    system("cls");
    textbackground(WHITE);
    textcolor(GREEN);
    gotoxy(50, 14);
    cout << "                    ";
    gotoxy(50, 15);
    cout << " USUARIO ATUALIZADO ";
    gotoxy(50, 16);
    cout << "                    ";
    Sleep(1500);
  }
  else
  {
    //Mostra uma mensagem de erro informando que o cliente não foi encontrado
    MessageBox(
        NULL,
        "Cliente não encontrado.\nClique em \"OK\" para voltar ao menu.",
        "Exclus�o de usu�rio",
        MB_ICONSTOP | MB_OK);
  }
}

void excluirClienteController() //Controla toda a exclusão de um cliente
{
  string cpf;
  clienteStr clienteExcluir;

  textbackground(WHITE);
  textcolor(LIGHTBLUE);
  system("cls");
  gotoxy(45, 15);
  cout << "INFORME O CPF DO CLIENTE: ";
  textbackground(LIGHTGRAY);
  cout << "             ";
  textcolor(BLACK);
  gotoxy(72, 15);
  cin >> cpf; //recebe o CPF do cliente
  fflush(stdin);
  textbackground(WHITE);

  clienteExcluir = buscarCliente(cpf); //Pesquisa no arquivo o cliente com o respectivo CPF

  if (clienteExcluir.nome != "NULL") /*Verifica se o usuário existe*/
  {

    system("cls"); //Mostra ao usuário todos os dados do cliente que ele vai excluir
    imprimeCampoPadrao(32, 12);

    int positionx = 32;
    int positiony = 12;

    gotoxy(positionx + 9, positiony);
    cout << clienteExcluir.nome;

    gotoxy(positionx + 7, positiony + 2);
    cout << clienteExcluir.cpf;

    gotoxy(positionx + 37, positiony + 2);
    cout << clienteExcluir.nacionalidade;

    gotoxy(positionx + 13, positiony + 4);
    cout << clienteExcluir.profissao;

    gotoxy(positionx + 56, positiony + 4);
    cout << clienteExcluir.consumo;

    gotoxy(positionx + 14, positiony + 6);
    cout << clienteExcluir.endereco;

    gotoxy(positionx + 8, positiony + 8);
    cout << clienteExcluir.idade;

    gotoxy(positionx + 58, positiony + 8);
    cout << clienteExcluir.sexo;

    gotoxy(40, 30);
    system("pause"); //Espera o usuário verificar os dados

    //Mostrauma caixa que pergunta se realmente deseja exclluir o cliente
    int opc = MessageBox(
        NULL,
        "Deseja realmente continuar e excluir o cliente?\n(Essa acao nao podera ser desfeita)",
        "Exclusao de usuario",
        MB_ICONWARNING | MB_OKCANCEL | MB_DEFBUTTON2);

    //Verifica qual botãodacaixa de dialogo ele digitou
    if (opc == IDOK)
    {
      excluirCliente(cpf);
      textbackground(GREEN);
      system("cls");
      textbackground(WHITE);
      textcolor(GREEN);
      gotoxy(51, 14);
      cout << "                  ";
      gotoxy(51, 15);
      cout << " USUARIO EXCLUIDO ";
      gotoxy(51, 16);
      cout << "                  ";
      Sleep(1500);
    }
    else if (opc == IDCANCEL)
    {
      textbackground(RED);
      system("cls");
      textbackground(WHITE);
      textcolor(RED);
      gotoxy(49, 14);
      cout << "                      ";
      gotoxy(49, 15);
      cout << " OPERACAO CANCELADA ";
      gotoxy(49, 16);
      cout << "                      ";
      Sleep(1500);
    }
  }
  else
  {
    //Caso o cliente nao seja encontrado ele mostra uma caixa de diálogo avisando o erro e retornando ao menu principal
    MessageBox(
        NULL,
        "Cliente não encontrado.\nClique em \"OK\" para voltar ao menu.",
        "Exclusao de usuario",
        MB_ICONSTOP | MB_OK);
  }
}
//Mostra o menu principal da manipulação de clientes
void interfacepadraoClientes(int position)
{
  textbackground(WHITE);
  system("cls");
  textbackground(LIGHTBLUE);
  //imprime as linhas verticais
  for (int i = 1; i <= 120; i++)
  {
    gotoxy(i, 1);
    cout << " ";
    gotoxy(i, 30);
    cout << " ";
  }
  //imprime as linhas horizontais
  for (int i = 1; i <= 30; i++)
  {
    gotoxy(1, i);
    cout << " ";
    gotoxy(120, i);
    cout << " ";
  }
  //Imprime as informações de navegação
  textbackground(WHITE);
  textcolor(LIGHTBLUE);
  gotoxy(37, 5);
  cout << "USE AS SETAS DO TECLADO PARA NAVEGAR PELO MENU";
  gotoxy(55, 6);
  cout << "<--  -->";
  gotoxy(50, 8);
  cout << "OU \"ESC\" PARA SAIR";
  gotoxy(40, 25);
  cout << "PRESSIONE \"CTRL + ENTER\" PARA SELECIONAR";
  textbackground(LIGHTGRAY);
  textcolor(WHITE);
  //Imprime as opões do menu e suas respectivas cores
  gotoxy(5, 14);
  cout << "                   ";
  gotoxy(5, 15);
  cout << " CADASTRAR CLIENTE ";
  gotoxy(5, 16);
  cout << "                   ";
  //Se o valor recebido na variável position for igual a 1 significa que o usuário escolheu a primeira opção e assim em diante
  if (position == 1)
  {
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    gotoxy(5, 14);
    cout << "                   ";
    gotoxy(5, 15);
    cout << " CADASTRAR CLIENTE ";
    gotoxy(5, 16);
    cout << "                   ";
    textbackground(LIGHTGRAY);
    textcolor(WHITE);
  }
  gotoxy(33, 14);
  cout << "                 ";
  gotoxy(33, 15);
  cout << " LISTAR CLIENTES ";
  gotoxy(33, 16);
  cout << "                 ";

  if (position == 2)
  {
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    gotoxy(33, 14);
    cout << "                 ";
    gotoxy(33, 15);
    cout << " LISTAR CLIENTES ";
    gotoxy(33, 16);
    cout << "                 ";
    textbackground(LIGHTGRAY);
    textcolor(WHITE);
  }

  gotoxy(63, 14);
  cout << "                   ";
  gotoxy(63, 15);
  cout << " MODIFICAR CLIENTE ";
  gotoxy(63, 16);
  cout << "                   ";

  if (position == 3)
  {
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    gotoxy(63, 14);
    cout << "                   ";
    gotoxy(63, 15);
    cout << " MODIFICAR CLIENTE ";
    gotoxy(63, 16);
    cout << "                   ";
    textbackground(LIGHTGRAY);
    textcolor(WHITE);
  }

  gotoxy(96, 14);
  cout << "                 ";
  gotoxy(96, 15);
  cout << " EXCLUIR CLIENTE ";
  gotoxy(96, 16);
  cout << "                 ";

  if (position == 4)
  {
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    gotoxy(96, 14);
    cout << "                 ";
    gotoxy(96, 15);
    cout << " EXCLUIR CLIENTE ";
    gotoxy(96, 16);
    cout << "                 ";
    textbackground(LIGHTGRAY);
    textcolor(WHITE);
  }
}

void interfaceECadastroCliente()
{
  //Realiza todo o cadastro dos clientes
  textcolor(LIGHTBLUE);
  textbackground(WHITE);
  system("cls");
  //posi��es iniciais de escrita
  int positionx = 32;
  int positiony = 12;
  //Imprime o quadrado e a sombra
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

  //!RECEBE TODOS OS DADOS

  cliente novoCliente;           //struct que receberá os dados do usuário
  clienteStr clienteVerificador; //struct que receberá os dados do arquivo
  char enviarCpf[10];
  bool verificador = true;

  gotoxy(positionx + 9, positiony);
  getline(cin, novoCliente.nome);
  //!ÁREA DE VERIFICAÇÃO DE CPF
  do
  {

    if (verificador == false)
    {
      //Mostra mensagem na tela caso o CPF seja inválido
      textbackground(WHITE);
      gotoxy(positionx, positiony + 2);
      textcolor(LIGHTBLUE);
      cout << "CPF:  ";
      textbackground(RED);
      textcolor(WHITE);
      cout << "             ";
      gotoxy(50, 5);
      cout << "INFORME UM CPF VALIDO!!";
    }

    gotoxy(positionx + 7, positiony + 2); //recebe os dados d CPF
    cin >> novoCliente.cpf;
    fflush(stdin);
    //Verifica se o CPF é válido
    verificador = charCpf::verificarCpf(novoCliente.cpf);
    //Verifica se já existe um usuário com este CPF cadastrado
    clienteVerificador = buscarCliente(novoCliente.cpf);
    //se o usuário já existir ele mostra visualmente e definne o verificador como falso
    if (clienteVerificador.nome != "NULL")
    {
      verificador = false;
      gotoxy(48, 6);
      textbackground(RED);
      textcolor(WHITE);
      cout << "O CPF JA ESTA SENDO USADO";
      textbackground(WHITE);
      textcolor(LIGHTBLUE);
    }
    else
    {
      //Se ele não existir ele apaga a mensagem da tela do usuário
      textbackground(WHITE);
      textcolor(LIGHTBLUE);
      gotoxy(48, 6);
      cout << "                            ";
    }

  } while (verificador == false);

  textbackground(WHITE);
  textcolor(LIGHTBLUE);
  gotoxy(50, 5);
  cout << "                         ";
  gotoxy(48, 6);
  cout << "                            ";
  gotoxy(positionx, positiony + 2);
  cout << "CPF:  ";
  textbackground(LIGHTGRAY);

  cout << " " << novoCliente.cpf << " ";
  //Quando o usuáio informa o CPF válido ele limpa os campos com cores vibrantes

  gotoxy(positionx + 37, positiony + 2);
  getline(cin, novoCliente.nacionalidade);

  gotoxy(positionx + 13, positiony + 4);
  getline(cin, novoCliente.profissao);

  //gotoxy(positionx+56,positiony+4);
  //cin >> novoCliente.consumo;
  //fflush(stdin);

  gotoxy(positionx + 14, positiony + 6);
  getline(cin, novoCliente.endereco);

  gotoxy(positionx + 8, positiony + 8);
  cin >> novoCliente.idade;
  fflush(stdin);

  gotoxy(positionx + 58, positiony + 8);
  getline(cin, novoCliente.sexo);

  novoCliente.consumo = 0;
  //Envia para a função escrever no arquivo o novo usuário
  cadastrarCliente(&novoCliente);

  textbackground(GREEN);
  system("cls");
  textbackground(WHITE);
  textcolor(GREEN);
  gotoxy(50, 14);
  cout << "                    ";
  gotoxy(50, 15);
  cout << " USUARIO CADASTRADO ";
  gotoxy(50, 16);
  cout << "                    ";
  Sleep(1500);
  //Pergunta em uma caixa de diálogo se o usuário deseja cadastrar um novo cliente
  int opc = MessageBox(
      NULL,
      "Deseja cadastrar um outro usuario?",
      "Cadastrar outro usuario?",
      MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2);
  //Se a resposta for sim ele chama novamente a função
  if (opc == IDYES)
  {
    interfaceECadastroCliente();
  }
}

int main()
{
  //!INICIA A INTERFACE DOS CLIENTES
  int position = 1;
  setlocale(LC_ALL, ""); //Define a linguagem padr�o

  system("MODE con cols=120 lines=30 "); //Define o tamanho da CMD (S� uma garantia)

  //*Aqui funciona a navegação pelo teclado
  while (!GetAsyncKeyState(VK_ESCAPE))
  {
    interfacepadraoClientes(position);
    while (!(GetAsyncKeyState(VK_RETURN) && GetAsyncKeyState(VK_CONTROL)))
    {
//Sempre que o usuário aperta uma das teclas definidas a variável position é alterada para mudar a posição do menu
//E chama uma função que imprime a tela principal com base em sua posição
      if (GetAsyncKeyState(VK_LEFT) && position > 1)
      {
        position--;
        interfacepadraoClientes(position);
      }
      if (GetAsyncKeyState(VK_RIGHT) && position < 4)
      {
        position++;
        interfacepadraoClientes(position);
      }
      if (GetAsyncKeyState(VK_ESCAPE))
      {
        exit(1);
      }
      setbuf(stdin, NULL);
      Sleep(100);
    }//Quando a escolha da opção é feita a variável position é avaliada para direcionar o usuário para o seu respectivo código.
    if (position == 1)
    {//Cadastro de clientes
      interfaceECadastroCliente();
    }
    else if (position == 2)
    {
      //Listagem de clientes
      listarClientes();
    }
    else if (position == 3)
    {//Atualizar clientes
      atualizarClienteController();
    }
    else if (position == 4)
    {//Excluir clientes
      excluirClienteController();
    }
    else if (position == 5)
    {//Sair do programa
      break;
    }
    Sleep(500);
  }
}
