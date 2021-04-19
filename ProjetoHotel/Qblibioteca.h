#ifndef QBLIBIOTECA_H_INCLUDED
#define QBLIBIOTECA_H_INCLUDED
#endif // QBLIBIOTECA_H_INCLUDED

#include "tela.h"

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio2.h>
#include <locale.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "clientes.h"
using namespace :: std;
struct Quartos
{
    int numero;
    char tipo[30];
    char opcional[30];
    int valor;
    char status[30];
    float consumo;
};

struct produto
{
    int numero;
    char nome[50];
    float preco;
};

struct Quartos pousada;

void RecursividadeOcupar(int erros);
void RecursividadeLiberar(int erros);
void LiberarQuarto();
void ReservarQuarto();
void Carregarstruct();
void CriarArquivo(fstream &QuartoArquivo);
void MostrarQuartos();
void menusdq();
void criarcar();
void lercar();
void pedido();
void Alugar_Cliente(string cpf_aux);
float troco(float valor, float recebido);
int sair,n,NQuarto,teste ;
int *opc = new int;
char ocupado[30] = "Ocupado";
char livre[30] = "Livre";
int erros = 2;

int menu()
{
    string cpf_aux;
    textbackground(WHITE);
    system("cls");
    textcolor(BLACK);

    system("cls");
    desenhaTela3();
    cin >> *opc;
    switch(*opc)
    {
    case 1:
        system("cls");
        tela_limpa();
        gotoxy(45,10);
        cout << "DIGITE O CPF DO CLIENTE:";
        gotoxy(45,11);
        cin >> cpf_aux;
        Alugar_Cliente(cpf_aux);
        break;
    case 2:
        system("cls");
        LiberarQuarto();
        break;
    case 3:
        system("cls");
        menusdq();
        menu();
    case 4:
        system("cls");
        fflush(stdin);
        break;
    default:
        cout << "Valor Inv�ido:"<< endl;
        fflush(stdin);
        system("pause");
        menu();
        break;
    }
}

void MostrarQuartos()
{
    int i=4;
    Quartos_tela();
    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);
    textcolor(BLACK);
    Quartos pousada;
    QuartoArquivo.seekp(0);
    QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));
    while(! QuartoArquivo.eof())
    {
        if(pousada.numero != 0)
        {
            i++;
            gotoxy(22,i);
            cout << pousada.numero;
            gotoxy(35,i);
            cout << pousada.tipo;
            gotoxy(48,i);
            cout << pousada.opcional;
            gotoxy(61,i);
            cout << pousada.valor;
            gotoxy(72,i);
            cout << pousada.status;
            gotoxy(88,i);
            cout << pousada.consumo;
        }
        QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));
    }

}

void ReservarQuarto()
{

    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);

    Quartos pousada;
    RecursividadeOcupar(erros);

    QuartoArquivo.seekp((NQuarto-1)*sizeof(Quartos));
    QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));

    strcpy(pousada.status,ocupado);
    pousada.consumo = pousada.valor;

    pousada.numero = NQuarto;
    QuartoArquivo.seekp((NQuarto-1)*sizeof(Quartos));
    QuartoArquivo.write((const char*)(&pousada),sizeof(Quartos));
    QuartoArquivo.close();

    system("cls");
    MostrarQuartos();
    textcolor(GREEN);
    gotoxy(50,18);
    cout<< "Quarto Alugado com Sucesso!"<<endl;
    gotoxy(40,19);
    fflush(stdin);
    system("pause");
    menu();

}

void LiberarQuarto()
{

    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);
    Quartos pousada;
    NQuarto = n;
    RecursividadeLiberar(erros);


    pousada.numero = NQuarto;
    QuartoArquivo.seekp((NQuarto-1)*sizeof(Quartos));
    QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));

    strcpy(pousada.status,livre);
    pousada.consumo = 0;

    pousada.numero = NQuarto;
    QuartoArquivo.seekp((NQuarto-1)*sizeof(Quartos));
    QuartoArquivo.write((const char*)(&pousada),sizeof(Quartos));
    QuartoArquivo.close();

    system("cls");
    MostrarQuartos();
    textcolor(GREEN);
    gotoxy(50,18);
    cout<< "Quarto Liberado com Sucesso!"<<endl;
    gotoxy(40,19);
    fflush(stdin);
    system("pause");
    menu();


}

void RecursividadeOcupar(int erros)
{

    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);
    Quartos pousada;
    MostrarQuartos();
    cout<<endl;
    gotoxy(50,19);
    cout << "FAZER RESERVA" << endl;
    gotoxy(50,20);
    cout << "NUMERO DO QUARTO:"<<endl;
    gotoxy(50,21);
    cin>> n;
    if(n > 0 && n < 11 )
    {
        NQuarto = n;
        QuartoArquivo.seekp((n-1)*sizeof(Quartos));
        QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));
        string sts;

        sts = pousada.status;
        if(sts == "Ocupado") // VERIFICA SE QUARTO JA ESTA OCUPADO
        {
            Quartos Pousada;
            MostrarQuartos();
            textcolor(RED);
            gotoxy(50,17);
            cout <<"QUARTO JA OCUPADO!";
            gotoxy(40,18);
            fflush(stdin);
            system("pause");
            if(erros == 0)
            {
                system("cls");
                textcolor(RED);
                gotoxy(40,15);
                cout << "3, ERROS VOCE VAI RETORNAR AO MENU!" << endl;
                gotoxy(40,16);
                fflush(stdin);
                system("pause");
                menu();
            }
            else
            {
                RecursividadeOcupar(erros-1);
            }
        }
    }
    else
    {
        system("cls");
        Quartos_tela();
        MostrarQuartos();
        textcolor(RED);
        gotoxy(50,19);
        cout<< "Numero Invalido"<<endl;
        gotoxy(40,20);
        fflush(stdin);
        system("pause");
        menu();

    }
}

void RecursividadeLiberar(int erros)
{

    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);
    Quartos pousada;
    float valor, recebido, res;
    MostrarQuartos();
    gotoxy(50,19);
    cout << "  CONSUMO: ";
    cin >> valor;
    gotoxy(50,20);
    cout << "VALOR RECEBIDO: ";
    cin >> recebido;
    gotoxy(50,21);
    cout << "   TROCO: ";
    res = troco(valor,recebido);
    cout << res;
    gotoxy(40,22);
    system("pause");
    system("cls");
    MostrarQuartos();
    gotoxy(50,19);
    cout << " LIBERAR QUARTO" << endl;
    gotoxy(50,20);
    cout << "NUMERO DO QUARTO:"<<endl;
    gotoxy(50,21);
    cin>> n;
    if(n > 0 && n < 11 )
    {
        NQuarto = n;
        QuartoArquivo.seekp((n-1)*sizeof(Quartos));
        QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));
        string sts;
        sts = pousada.status;
        if(sts == "Livre")
        {
            Quartos pousada;
            MostrarQuartos();
            textcolor(RED);
            gotoxy(50,17);
            cout <<"QUARTO JA LIBERADO!";
            gotoxy(40,18);
            system("pause");
            if(erros == 0)
            {
                system("cls");
                textcolor(RED);
                gotoxy(40,15);
                cout << "3 ERROS, VOCE VAI RETORNAR AO MENU" << endl;
                gotoxy(40,16);
                fflush(stdin);
                system("pause");
                menu();
            }
            else
            {
                RecursividadeLiberar(erros-1);
            }

        }

    }
    else
    {
        system("cls");
        Quartos_tela();
        MostrarQuartos();
        textcolor(RED);
        gotoxy(50,19);
        cout<< "NUMERO INVALIDO"<<endl;
        gotoxy(40,20);
        fflush(stdin);
        system("pause");
        menu();
    }


}

void menusdq()
{
    int x;
    do
    {
        system("cls");
        desenhaTela2();
        cin >> x;
        if (x == 1)
        {
            system("cls");
            cardapio();
            lercar();
            textcolor(RED);
            gotoxy(40,24);
            system("pause");
            system("cls");
        }
        else if (x == 2)
        {
            system("cls");
            pedido();
        }
    }
    while (x != 3);
}

void lercar()
{
    int i=4;
    produto c;
    ifstream inCredito("credito.dat", ios::in);
    inCredito.read((char *)(&c),sizeof(produto));
    while (inCredito && ! inCredito.eof())
    {
        if (c.numero != 0 )
        {
            i++;
            gotoxy(22,i);
            cout << c.numero;
            gotoxy(52,i);
            cout << c.nome;
            gotoxy(88,i);
            cout << c.preco <<"$";
        }
        inCredito.read((char *)(&c),sizeof(produto));
    }
}

void pedido()
{
    int n;
    MostrarQuartos();
    gotoxy(40,19);
    cout << "NUMERO DO QUARTO QUE DESEJA FAZER PEDIDO: ";
    cin >> n;
    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);
    Quartos pousada;
    if(n > 0 && n < 11 )
    {
        NQuarto = n;
        QuartoArquivo.seekp((n-1)*sizeof(Quartos));
        QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));
        string sts;

        sts = pousada.status;
        if(sts == "Ocupado") // VERIFICA SE QUARTO JA ESTA OCUPADO
        {
            system("cls");
            cardapio();
            float x[100];
            produto c;
            int i=4;
            int cod, consumo, cont = 1;
            ifstream inCredito("credito.dat", ios::in);
            inCredito.read((char *)(&c),sizeof(produto));
            while (inCredito && ! inCredito.eof())
            {
                if(c.numero != 0)
                {
                     i++;
                    gotoxy(22,i);
                    cout << c.numero;
                    gotoxy(52,i);
                    cout << c.nome;
                    gotoxy(88,i);
                    cout << c.preco <<"$";
                }
                inCredito.read((char *)(&c),sizeof(produto));
                x[cont] = c.preco;
                cont++;
            }
            gotoxy(45,19);
            cout << "DIGITE O CODIGO DO PEDIDO: ";
            cin >> cod;
            consumo = x[cod];
            QuartoArquivo.seekp((NQuarto-1)*sizeof(Quartos));
            QuartoArquivo.read((char*)(&pousada),sizeof(Quartos));

            strcpy(pousada.status,ocupado);
            pousada.consumo = pousada.consumo + consumo;
            QuartoArquivo.seekp((NQuarto-1)*sizeof(Quartos));
            QuartoArquivo.write((const char*)(&pousada),sizeof(Quartos));
            QuartoArquivo.close();

            gotoxy(45,20);
            textcolor(GREEN);
            cout << "PEDIDO REALIZADO COM SUCESSO!";
            gotoxy(40,21);
            system("pause");
            system("cls");
            MostrarQuartos();
            textcolor(RED);
            gotoxy(40,24);
            system("pause");
            system("cls");
        }
        else
        {
            textcolor(RED);
            gotoxy(50,15);
            cout << "Quarto desocupado";
            gotoxy(40,16);
            system("pause");
        }

    }
}

void Alugar_Cliente(string cpf_aux)
{
    fstream clientesARQ;
    clienteStr retorno;
    string linha;
    int verificacao;

    retorno = buscarCliente(cpf_aux);

    if(retorno.nome != "NULL")
    {
        system("cls");
        tela_limpa();
        textcolor(GREEN);
        gotoxy(50,10);
        cout << "CPF ACEITO";
        Sleep(1500);
        clientesARQ.close();
        ReservarQuarto();
    }
    else
    {
        system("cls");
        tela_limpa();
        textcolor(RED);
        gotoxy(50,10);
        cout << "CPF NAO CADASTRADO";
        Sleep(1500);
        menu();
        fflush(stdin);
        system("pause");
    }
}

void verificar_checkout(string cpf_aux)
{
    fstream clientesARQ;
    clienteStr retorno;
    string linha;
    int verificacao;
    int cont;
    retorno = buscarCliente(cpf_aux);
    fstream QuartoArquivo("Quartos.txt", ios::in|ios::out);
    Quartos pousada;

    if(retorno.nome != "NULL")
    {
        system("cls");
        tela_limpa();
        textcolor(GREEN);
        gotoxy(50,10);
        cout << "CPF ACEITO";
        Sleep(1500);
        clientesARQ.open("clientes.dat",ios::in);
        system("cls");
        tela_limpa();
        gotoxy(50,10);
        cout << "CLIENTE: " << retorno.nome << endl;
        gotoxy(40,11);
        system("pause");
        LiberarQuarto();
    }
    else
    {
        system("cls");
        tela_limpa();
        textcolor(RED);
        gotoxy(50,10);
        cout << "CPF NAO CADASTRADO";
        Sleep(1500);
        menu();
        fflush(stdin);
        system("pause");
    }
}

float troco(float valor, float recebido)
{
    float  resultado;
    if(valor < recebido || valor == recebido)
    {
        resultado = recebido - valor;

    }
    return resultado;
}
