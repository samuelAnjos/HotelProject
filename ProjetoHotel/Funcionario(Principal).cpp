#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio2.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <iomanip>
#include "funcionario.h"
#include "login.h"
#include "tela.h"
#include "Qblibioteca.h"

using namespace std;

void login_recepcao();
void cadastro_funcionario();
void login_gerencia();
void login_gerencia2();
void login_gerencia3();
void listar_funcionario();
void excluir_funcionario();
void CriarArquivo_funcionario(fstream &arquivo);
void mostrarlinha(ostream &output, const funcionario &funcionario);
void login_verificar(int acesso);
void verificar_clientes(int acesso);
void verificar_quartos(int acesso);
void checkout();
void adicionar_produto();
void adicionar_quartos();
void alterar_quartos();
void alterar_senha();
void criar_outCredito(fstream &outCredito);
void criar_QuartoArquivo(fstream &QuartoArquivo);
void alterar_produto();
void excluir_produto();
void excluir_quartos();

int op;

int main()
{
    string cpf_aux;
    int acesso = 3;
    setlocale(LC_ALL, "portuguese");
    system("cls");
    desenhaTela();
    cin >> op;
    switch(op)
    {
    case 1:
        system("cls");
        recepcao();
        cin >> op;
        if(op == 1)
        {
            verificar_clientes(acesso);
            main();
        }
        else if(op == 2)
        {
            verificar_quartos(acesso);
            main();
        }
        else if(op == 3)
        {
            main();
        }
        else
        {
            system("cls");
            tela_limpa();
            textcolor(RED);
            gotoxy(45,10);
            cout << "  NUMERO INVALIDO, VOLTANDO AO MENU";
            Sleep(1500);
            main();
        }
        break;
    case 2:
        system("cls");
        login_verificar(acesso);
        break;
    case 3:
        system("cls");
        tela_limpa();
        gotoxy(45,10);
        cout << "DIGITE O CPF DO CLIENTE:";
        gotoxy(45,11);
        cin >> cpf_aux;
        verificar_checkout(cpf_aux);
        break;
    case 4:
        system("cls");
        tela_fechar();
        exit(0);
    default:
        textcolor(RED);
        gotoxy(50,19);
        cout << "NUMERO INVALIDO" << endl;
        gotoxy(40,20);
        system("pause");
        main();
        break;
    }
    return 0;
}

void CriarArquivo_funcionario(fstream &arquivo)
{
    funcionario funcionarioVazio = {0, "","",""};
    arquivo.seekp(0);
    for(int i=0; i<100; i++)
    {
        arquivo.write((const char*)(&funcionarioVazio), sizeof(funcionario));
    }

    arquivo.close();
    arquivo.clear();
}

void login_gerencia()
{
    system("cls");
    fstream arquivo("funcionarios.txt", ios::in|ios::out);
    if(!arquivo)
    {
        fstream arquivo("funcionarios.txt", ios::out);
        CriarArquivo_funcionario(arquivo);
        login_gerencia();
    }
    adm_escolha();
    cin >> op;
    switch(op)
    {
    case 1:
        system("cls");
        cadastro_funcionario();
        break;
    case 2:
        system("cls");
        excluir_funcionario();
        break;
    case 3:
        system("cls");
        listar_funcionario();
        break;
    case 4:
        main();
        break;
    case 5:
        login_gerencia2();
        break;
    default:
        textcolor(RED);
        gotoxy(50,19);
        cout << "NUMERO INVALIDO" << endl;
        gotoxy(40,20);
        system("pause");
        login_gerencia();
        break;
    }
}

void cadastro_funcionario()
{
    fstream arquivo("funcionarios.txt", ios::in|ios::out);
    int codigo;
    funcionario funcionario;
    tela_cad();
    textcolor(BLACK);
    gotoxy(22,13);
    cin >> codigo;
    arquivo.seekp((codigo-1)*sizeof(funcionario));
    arquivo.read((char*)(&funcionario),sizeof(funcionario));
    if(funcionario.codigo == 0)
    {
        fflush(stdin);
        gotoxy(39,13);
        gets(funcionario.nome);
        fflush(stdin);
        gotoxy(62,13);
        cin >> funcionario.cpf;
        fflush(stdin);
        gotoxy(82,13);
        cin >> funcionario.cargo;

        funcionario.codigo = codigo;
        arquivo.seekp((codigo-1)*sizeof(funcionario));
        arquivo.write((const char*)(&funcionario),sizeof(funcionario));
        gotoxy(50,15);
        textcolor(BLACK);
        cout << "FUNCIONARIO CADASTRADO" << endl;
        gotoxy(40,20);
        textcolor(BLACK);
        arquivo.close();
        arquivo.clear();
        system("pause");
        login_gerencia();
    }
    else
        textcolor(RED);
    gotoxy(50,15);
    cout << "CODIGO " << codigo << " JA CADASTRADO" << endl;
    textcolor(BLACK);
    gotoxy(40,16);
    system("pause");
    arquivo.close();
    arquivo.clear();
    login_gerencia();
}

void listar_funcionario()
{
    tela_lista();
    int i=4;
    textcolor(BLACK);
    funcionario funcionario;
    fstream arquivo("funcionarios.txt", ios::in);
    arquivo.seekp(0);
    arquivo.read((char*)(&funcionario),sizeof(funcionario));
    while(arquivo && !arquivo.eof())
    {
        if(funcionario.codigo != 0)
        {
            i++;
            gotoxy(22,i);
            cout << funcionario.codigo;
            gotoxy(39,i);
            cout << funcionario.nome;
            gotoxy(62,i);
            cout << funcionario.cpf;
            gotoxy(82,i);
            cout << funcionario.cargo;
        }
        arquivo.read((char*)(&funcionario),sizeof(funcionario));
    }
    textcolor(RED);
    gotoxy(40,24);
    system("pause");
    login_gerencia();

}

void excluir_funcionario()
{
    tela_excluir();
    int codigo;
    fstream arquivo("funcionarios.txt", ios::in|ios::out);
    funcionario funcionario, funcionarioVazio = {0, "","",""};
    cin >> codigo;
    arquivo.seekp((codigo-1)*sizeof(funcionario));
    arquivo.read((char*)(&funcionario), sizeof(funcionario));
    if(funcionario.codigo != 0)
    {
        textcolor(BLUE);
        gotoxy(24,12);
        cout << "CODIGO: ";
        gotoxy(41,12);
        cout << "NOME: ";
        gotoxy(64,12);
        cout << "CPF: ";
        gotoxy(84,12);
        cout << "CARGO: ";
        textcolor(BLACK);
        gotoxy(24,13);
        cout << funcionario.codigo;
        gotoxy(41,13);
        cout << funcionario.nome;
        gotoxy(64,13);
        cout << funcionario.cpf;
        gotoxy(84,13);
        cout << funcionario.cargo;
        arquivo.seekp((codigo-1)*sizeof(funcionario));
        arquivo.write((const char*)(&funcionarioVazio),sizeof(funcionario));
        textcolor(RED);
        gotoxy(50,15);
        cout << "FUNCIONARIO EXCLUIDO" << endl;
        fflush(stdin);
        textcolor(BLACK);
        gotoxy(40,20);
        system("pause");
        arquivo.close();
        login_gerencia();

    }
    else
        textcolor(RED);
    gotoxy(40,13);
    cout << "FUNCIONARIO INEXISTENTE OU JA EXCLUIDO" << endl;
    textcolor(BLACK);
    gotoxy(40,15);
    system("pause");
    arquivo.close();
    login_gerencia();
}

void carregar_login(fstream &arquivo_login)
{
    int senha_aux;
    login_usuario login;
    adm_senha();
    textcolor(BLACK);
    gotoxy(40,12);
    cout << "  <PRIMEIRO ACESSO ADMINISTRATIVO>";
    gotoxy(40,13);
    cout << "POR FAVOR CADASTRE SUA SENHA DE ACESSO";
    gotoxy(40,14);
    cout << "SENHA: ";
    cin >> senha_aux;
    login.senha = senha_aux;
    arquivo_login.write((const char*)(&login),sizeof(login_usuario));
    system("cls");
    adm_senha();
    textcolor(GREEN);
    gotoxy(40,12);
    cout << "  <SENHA CADASTRADA COM SUCESSO>";
    textcolor(BLACK);
    gotoxy(40,13);
    system("pause");
    arquivo_login.close();
    login_gerencia();
}

void login_verificar(int acesso)
{
    int senha_aux;
    fstream arquivo_login("login.txt", ios::in|ios::out);
    if(!arquivo_login)
    {
        fstream arquivo_login("login.txt", ios::out);
        carregar_login(arquivo_login);
    }
    else
    {
        if(acesso>=0)
        {
            login_usuario login;
            system("cls");
            adm_senha();
            textcolor(BLACK);
            gotoxy(50,12);
            cout << "SENHA: ";
            cin >> senha_aux;
            arquivo_login.seekp(0);
            arquivo_login.read((char*)(&login), sizeof(login_usuario));
            if(senha_aux == login.senha)
            {
                system("cls");
                adm_senha();
                textcolor(GREEN);
                gotoxy(40,12);
                cout << "            SENHA CORRETA" << endl;
                textcolor(BLACK);
                gotoxy(40,13);
                system("pause");
                login_gerencia();
            }
            else
            {
                textcolor(RED);
                gotoxy(40,12);
                cout << "         SENHA INCORRETA " << endl;
                gotoxy(40,13);
                cout << " VOCE TEM + " << acesso << " TENTATIVAS RESTANTES" << endl;
                textcolor(BLACK);
                gotoxy(40,14);
                system("pause");
                login_verificar(acesso-1);
            }
        }
    }
}

void verificar_clientes(int acesso)
{
    tela_base();
    funcionario funcionario;
    fstream arquivo("funcionarios.txt", ios::in|ios::out);
    int codigo;
    if(acesso>=0)
    {
        system("cls");
        tela_base();
        textcolor(BLACK);
        gotoxy(40,12);
        cout << "DIGITE UM CODIGO DE UM FUNCIONARIO: ";
        gotoxy(55,13);
        cin >> codigo;
        arquivo.seekp((codigo-1)*sizeof(funcionario));
        arquivo.read((char*)(&funcionario),sizeof(funcionario));
        if(funcionario.codigo == codigo)
        {
            system("start Cliente.exe");
            main();
        }
        else
        {
            system("cls");
            tela_base();
            textcolor(RED);
            gotoxy(40,12);
            cout << " CODIGO INCORRETO OU INEXISTENTE " << endl;
            gotoxy(40,13);
            cout << " VOCE TEM + " << acesso << " TENTATIVAS RESTANTES" << endl;
            textcolor(BLACK);
            gotoxy(40,14);
            system("pause");
            verificar_clientes(acesso-1);
        }
    }
}

void verificar_quartos(int acesso)
{
    tela_base();
    funcionario funcionario;
    fstream arquivo("funcionarios.txt", ios::in|ios::out);
    int codigo;
    if(acesso>=0)
    {
        system("cls");
        tela_base();
        textcolor(BLACK);
        gotoxy(40,12);
        cout << "DIGITE UM CODIGO DE UM FUNCIONARIO: ";
        gotoxy(55,13);
        cin >> codigo;
        arquivo.seekp((codigo-1)*sizeof(funcionario));
        arquivo.read((char*)(&funcionario),sizeof(funcionario));
        if(funcionario.codigo == codigo)
        {
            menu();
            main();
        }
        else
        {
            system("cls");
            tela_base();
            textcolor(RED);
            gotoxy(40,12);
            cout << " CODIGO INCORRETO OU INEXISTENTE " << endl;
            gotoxy(40,13);
            cout << " VOCE TEM + " << acesso << " TENTATIVAS RESTANTES" << endl;
            textcolor(BLACK);
            gotoxy(40,14);
            system("pause");
            verificar_quartos(acesso-1);
        }
    }
}

void login_gerencia2()
{
    tela2();
    cin >> op;
    fstream outCredito("credito.dat",ios::in|ios::out);
    if(!outCredito)
    {
        fstream outCredito("credito.dat", ios::out);
        criar_outCredito(outCredito);
        login_gerencia2();
    }
    fstream QuartoArquivo("Quartos.txt",ios::in|ios::out);
    if(!QuartoArquivo)
    {
        fstream QuartoArquivo("Quartos.txt", ios::out);
        criar_QuartoArquivo(QuartoArquivo);
        login_gerencia2();
    }
    switch(op)
    {
    case 1:
        system("cls");
        tela_quartos();
        cin >> op;
        if(op == 1)
        {
            adicionar_quartos();
        }
        else if(op == 2)
        {
            alterar_quartos();
        }
        else if(op == 3)
        {
            excluir_quartos();
        }
        else if(op == 4)
        {
            login_gerencia2();
        }
        else
        {
            system("cls");
            tela_limpa();
            textcolor(RED);
            gotoxy(45,10);
            cout << "  NUMERO INVALIDO, VOLTANDO AO MENU";
            Sleep(1500);
            login_gerencia2();
        }
        break;
    case 2:
        system("cls");
        tela_produtos();
        cin >> op;
        if(op == 1)
        {
            adicionar_produto();
        }
        else if(op == 2)
        {
            alterar_produto();
        }
        else if(op == 3)
        {
            excluir_produto();
        }
        else if(op == 4)
        {
            login_gerencia2();
        }
        else
        {
            system("cls");
            tela_limpa();
            textcolor(RED);
            gotoxy(45,10);
            cout << "  NUMERO INVALIDO, VOLTANDO AO MENU";
            Sleep(1500);
            login_gerencia2();
        }
        break;
    case 3:
        system("cls");
        alterar_senha();
        break;
    case 4:
        login_gerencia();
        break;
    default:
        textcolor(RED);
        gotoxy(50,19);
        cout << "NUMERO INVALIDO" << endl;
        gotoxy(40,20);
        system("pause");
        login_gerencia();
        break;
    }
}

void adicionar_produto()
{
    produto c;
    fstream outCredito("credito.dat",ios::in|ios::out);
    int cont;
    tela_adicionar();
    gotoxy(40,13);
    cin >> cont;
    outCredito.seekp((cont-1)*sizeof(produto));
    outCredito.read((char*)(&c),sizeof(produto));
    if(c.numero == 0)
    {
        gotoxy(55,13);
        cin >> c.nome;
        gotoxy(70,13);
        cin >> c.preco;

        c.numero = cont;
        outCredito.seekp((cont-1)*sizeof(produto));
        outCredito.write((const char*)(&c),sizeof(produto));
        gotoxy(50,15);
        textcolor(GREEN);
        cout << "PRODUTO CADASTRADO" << endl;
        outCredito.close();
        textcolor(RED);
        gotoxy(40,16);
        system("pause");
        login_gerencia2();
    }
    else
    {
        textcolor(RED);
        gotoxy(45,15);
        cout << "NUMERO DE PRODUTO JA CADASTRADO";
        textcolor(BLACK);
        gotoxy(40,16);
        system("pause");
        outCredito.close();
        login_gerencia2();
    }
}

void criar_outCredito(fstream &outCredito)
{
    produto cVazio = {0, "", 0.0};
    outCredito.seekp(0);
    for(int i=0; i<100; i++)
    {
        outCredito.write((const char*)(&cVazio), sizeof(produto));
    }
    outCredito.close();
    outCredito.clear();
}

void alterar_produto()
{
    produto c;
    int cont;
    fstream outCredito("credito.dat",ios::in|ios::out);
    tela_limpa();
    textcolor(BLACK);
    gotoxy(40,7);
    cout << "NUMERO DO PRODUTO QUE DESEJA ALTERAR:";
    cin >> cont;
    outCredito.seekp((cont-1)*sizeof(produto));
    outCredito.read((char*)(&c),sizeof(produto));
    if(c.numero != 0)
    {
        textcolor(BLACK);
        gotoxy(45,10);
        cout << "PRODUTO A SER ALTERADO:";
        gotoxy(45,12);
        cout << "PRODUTO:";
        gotoxy(60,12);
        cout << "VALOR:";
        gotoxy(45,13);
        textcolor(RED);
        cout << c.nome;
        gotoxy(60,13);
        cout << c.preco << "$";
        textcolor(BLACK);
        gotoxy(45,14);
        cout << "NOVO PRODUTO:";
        gotoxy(60,14);
        cout << "NOVO VALOR:";
        textcolor(GREEN);
        gotoxy(45,15);
        cin >> c.nome;
        gotoxy(60,15);
        cin >> c.preco;
        c.numero = cont;
        outCredito.seekp((cont-1)*sizeof(produto));
        outCredito.write((const char*)(&c),sizeof(produto));
        outCredito.close();
        gotoxy(50,17);
        textcolor(GREEN);
        cout << "PRODUTO ALTERADO" << endl;
        gotoxy(40,18);
        system("pause");
        login_gerencia2();
    }
    else
    {
        textcolor(RED);
        gotoxy(50,15);
        cout << "NUMERO DE PRODUTO INEXISTENTE";
        textcolor(BLACK);
        gotoxy(40,16);
        system("pause");
        outCredito.close();
        login_gerencia2();
    }
}

void excluir_produto()
{
    int cont;
    tela_limpa();
    gotoxy(50,2);
    cout << "EXCLUIR PRODUTO";
    fstream outCredito("credito.dat",ios::in|ios::out);
    produto c, cVazio = {0, "", 0.0};
    gotoxy(40,7);
    cout << "NUMERO DO PRODUTO QUE DESEJA EXCLUIR: ";
    cin >> cont;
    outCredito.seekp((cont-1)*sizeof(produto));
    outCredito.read((char*)(&c), sizeof(produto));
    if(c.numero != 0)
    {
        gotoxy(45,12);
        cout << "PRODUTO:";
        gotoxy(60,12);
        cout << "VALOR:";
        gotoxy(45,13);
        textcolor(RED);
        cout << c.nome;
        gotoxy(60,13);
        cout << c.preco << "$";

        outCredito.seekp((cont-1)*sizeof(produto));
        outCredito.write((const char*)(&cVazio),sizeof(produto));
        outCredito.close();
        textcolor(RED);
        gotoxy(50,15);
        cout << "PRODUTO EXCLUIDO" << endl;
        textcolor(BLACK);
        gotoxy(40,16);
        system("pause");
        login_gerencia2();
    }
    else
    {
        textcolor(RED);
        gotoxy(40,13);
        cout << "  PRODUTO INEXISTENTE OU JA EXCLUIDO" << endl;
        textcolor(BLACK);
        gotoxy(40,15);
        system("pause");
        outCredito.close();
        login_gerencia2();
    }
}

void adicionar_quartos()
{
    system("cls");
    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);
    int NQuarto;
    Quartos Pousada;
    tela_limpa();
    textcolor(BLACK);
    gotoxy(50,02);
    cout << "CADASTRAR POUSADA" << endl;
    gotoxy(22,4);
    cout << "NUMERO";
    gotoxy(35,4);
    cout << "TIPO";
    gotoxy(48,4);
    cout << "OPCAO";
    gotoxy(61,4);
    cout << "VALOR";
    gotoxy(72,4);
    cout << "STATUS";
    gotoxy(88,4);
    cout << "CONSUMO";
    gotoxy(22,5);
    cin >> NQuarto;
    Pousada.numero = NQuarto;
    QuartoArquivo.seekp((NQuarto-1)*sizeof(Quartos));
    QuartoArquivo.read((char*)(&Pousada),sizeof(Quartos));
    if(Pousada.numero == 0)
    {
        gotoxy(35,5);
        fflush(stdin);
        gets(Pousada.tipo);
        gotoxy(48,5);
        fflush(stdin);
        gets(Pousada.opcional);
        gotoxy(61,5);
        fflush(stdin);
        cin >> Pousada.valor;
        gotoxy(72,5);
        fflush(stdin);
        gets(Pousada.status);
        gotoxy(88,5);
        fflush(stdin);
        cin >> pousada.consumo;

        Pousada.numero = NQuarto;
        QuartoArquivo.seekp((NQuarto-1)*sizeof(Quartos));
        QuartoArquivo.write((const char*)(&Pousada),sizeof(Quartos));
        QuartoArquivo.close();
        gotoxy(43,15);
        cout << "QUARTO CADASTRADO" << endl;
        QuartoArquivo.close();
        textcolor(RED);
        gotoxy(40,16);
        system("pause");
        login_gerencia2();
    }
    else
    {
        textcolor(RED);
        gotoxy(43,15);
        cout << "QUARTO JA CADASTRADO";
        textcolor(BLACK);
        gotoxy(40,16);
        system("pause");
        QuartoArquivo.close();
        login_gerencia2();
    }
}

void alterar_quartos()
{
    system("cls");
    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);
    Quartos pousada;
    tela_limpa();
    gotoxy(50,2);
    cout << "  ALTERAR QUARTO";
    int cont;
    textcolor(BLACK);
    gotoxy(40,4);
    cout << "NUMERO DO QUARTO QUE DESEJA ALTERAR:";
    cin >> cont;
    string sts;
    sts = pousada.status;
    QuartoArquivo.seekp((cont-1)*sizeof(Quartos));
    QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));
    if((pousada.numero != 0) && (sts != "Ocupado"))
    {
        textcolor(BLACK);
        gotoxy(45,5);
        cout << "QUARTO A SER MODIFICADO:";
        gotoxy(22,7);
        cout << "NUMERO";
        gotoxy(35,7);
        cout << "TIPO";
        gotoxy(48,7);
        cout << "OPCAO";
        gotoxy(61,7);
        cout << "VALOR";
        gotoxy(72,7);
        cout << "STATUS";
        gotoxy(88,7);
        cout << "CONSUMO";
        textcolor(RED);
        gotoxy(22,8);
        cout << pousada.numero;
        gotoxy(35,8);
        cout << pousada.tipo;
        gotoxy(48,8);
        cout << pousada.opcional;
        gotoxy(61,8);
        cout << pousada.valor;
        gotoxy(72,8);
        cout << pousada.status;
        gotoxy(88,8);
        cout << pousada.consumo;
        textcolor(BLACK);
        gotoxy(55,10);
        cout << "ALTERE:";
        gotoxy(22,11);
        cout << "NUMERO";
        gotoxy(35,11);
        cout << "TIPO";
        gotoxy(48,11);
        cout << "OPCAO";
        gotoxy(61,11);
        cout << "VALOR";
        gotoxy(72,11);
        cout << "STATUS";
        gotoxy(88,11);
        cout << "CONSUMO";
        textcolor(GREEN);
        gotoxy(22,12);
        cout << pousada.numero;
        gotoxy(35,12);
        fflush(stdin);
        cin >> pousada.tipo;
        gotoxy(48,12);
        fflush(stdin);
        cin >> pousada.opcional;
        gotoxy(61,12);
        fflush(stdin);
        cin >> pousada.valor;
        gotoxy(72,12);
        fflush(stdin);
        cin >> pousada.status;
        gotoxy(88,12);
        fflush(stdin);
        cin >> pousada.consumo;
        pousada.numero = cont;
        QuartoArquivo.seekp((cont-1)*sizeof(Quartos));
        QuartoArquivo.write((const char*)(&pousada),sizeof(Quartos));
        QuartoArquivo.close();
        gotoxy(50,17);
        textcolor(GREEN);
        cout << "QUARTO ALTERADO" << endl;
        textcolor(BLACK);
        gotoxy(40,18);
        system("pause");
        login_gerencia2();
    }
    else
    {
        textcolor(RED);
        gotoxy(45,15);
        cout << "QUARTO OCUPADO OU INEXISTENTE";
        textcolor(BLACK);
        gotoxy(40,16);
        system("pause");
        QuartoArquivo.close();
        login_gerencia2();
    }

}

void excluir_quartos()
{
    system("cls");
    int cont;
    tela_limpa();
    gotoxy(50,2);
    cout << "  EXCLUIR QUARTO";
    fstream QuartoArquivo("Quartos.txt",ios::in|ios::out);
    Quartos pousada, pousadasVazio = {0, "","",0,"",0};
    gotoxy(40,4);
    cout << "NUMERO DO QUARTO QUE DESEJA EXCLUIR: ";
    cin >> cont;
    string sts;
    sts = pousada.status;
    QuartoArquivo.seekp((cont-1)*sizeof(Quartos));
    QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));
    if(pousada.numero != 0)
    {
        textcolor(BLACK);
        gotoxy(45,5);
        cout << "QUARTO EXCLUIDO:";
        gotoxy(22,7);
        cout << "NUMERO";
        gotoxy(35,7);
        cout << "TIPO";
        gotoxy(48,7);
        cout << "OPCAO";
        gotoxy(61,7);
        cout << "VALOR";
        gotoxy(72,7);
        cout << "STATUS";
        gotoxy(88,7);
        cout << "CONSUMO";
        textcolor(RED);
        gotoxy(22,8);
        cout << pousada.numero;
        gotoxy(35,8);
        cout << pousada.tipo;
        gotoxy(48,8);
        cout << pousada.opcional;
        gotoxy(61,8);
        cout << pousada.valor;
        gotoxy(72,8);
        cout << pousada.status;
        gotoxy(88,8);
        cout << pousada.consumo;

        QuartoArquivo.seekp((cont-1)*sizeof(Quartos));
        QuartoArquivo.write((const char*)(&pousadasVazio),sizeof(Quartos));
        QuartoArquivo.close();
        textcolor(RED);
        gotoxy(50,15);
        cout << "QUARTO EXCLUIDO EXCLUIDO";
        textcolor(BLACK);
        gotoxy(40,16);
        system("pause");
        login_gerencia2();
    }
    else
    {
        textcolor(RED);
        gotoxy(45,15);
        cout << "QUARTO INEXISTENTE OU JA EXCLUIDO" << endl;
        textcolor(BLACK);
        gotoxy(40,16);
        system("pause");
        QuartoArquivo.close();
        login_gerencia2();
    }
}

void criar_QuartoArquivo(fstream &QuartoArquivo)
{
    Quartos pousadasVazio = {0, "","",0,"",0};
    QuartoArquivo.seekp(0);
    for(int i=0; i<100; i++)
    {
        QuartoArquivo.write((const char*)(&pousadasVazio), sizeof(Quartos));
    }
    QuartoArquivo.close();
    QuartoArquivo.clear();
}

void alterar_senha()
{
    tela_limpa();
    login_usuario login;
    fstream arquivo_login("login.txt", ios::in|ios::out);
    int senha_aux;
    textcolor(BLACK);
    gotoxy(50,2);
    cout << "ALTERAR SENHA";
    gotoxy(47,12);
    cout << "DIGITE A SENHA ATUAL:";
    textcolor(RED);
    gotoxy(47,13);
    cin >>senha_aux;
    arquivo_login.seekp(0);
    arquivo_login.read((char*)(&login), sizeof(login_usuario));
    if(senha_aux == login.senha)
    {
        system("cls");
        tela_limpa();
        gotoxy(50,2);
        cout << "ALTERAR SENHA";
        gotoxy(47,12);
        textcolor(BLACK);
        cout << "DIGITE NOVA SENHA:";
        textcolor(GREEN);
        gotoxy(47,13);
        cin >> login.senha;
        arquivo_login.seekp(0);
        arquivo_login.write((const char*)(&login),sizeof(login_usuario));
        arquivo_login.close();
        system("cls");
        tela_limpa();
        gotoxy(50,12);
        textcolor(GREEN);
        cout << "SENHA ATUALIZADA";
        Sleep(2000);
        main();
    }
    else
    {
        system("cls");
        tela_limpa();
        textcolor(RED);
        gotoxy(45,12);
        cout << "SENHA ERRADA";
        gotoxy(40,13);
        cout << "POR SEGURANCA ESTAMOS TE LEVANDO PARA O MENU";
        Sleep(2000);
        main();
    }
}
