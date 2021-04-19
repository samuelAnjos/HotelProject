#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

#include <iostream>
using namespace std;

void desenhaTela3()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("TECLE: P/ALUGAR [1] / LIBERAR [2] / SERVIÇO DE QUARTO [3] / SAIR [4]");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    for (k = 2; k<=18; k++)
    {
        gotoxy(43,2);
        cout << ("                                   ");
        textcolor(BLUE);
        gotoxy(67-k,2);
        cout << "  GERENCIAR QUARTOS  ";
        gotoxy(20,3);
        cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    }

    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,8);
    cout << "   ALUGAR";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(32,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(32,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,16);
    cout << "  LIBERAR";
    textcolor(BLUE);
    gotoxy(32,16);
    cout << ("^");
    gotoxy(45,16);
    cout << ("^");
    gotoxy(32,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,7);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,8);
    textcolor(BLUE);
    gotoxy(76,8);
    cout << ("^");
    gotoxy(77,8);
    textcolor(BLACK);
    cout << "SERV QUARTO";
    gotoxy(89,8);
    textcolor(BLUE);
    cout << ("^");
    textcolor(BLUE);
    gotoxy(76,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(76,16);
    cout << ("   SAIR ");
    textcolor(BLUE);
    gotoxy(76,16);
    cout << ("^");
    gotoxy(89,16);
    cout << ("^");
    gotoxy(76,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
}

void adm_senha()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("      DIGITE SENHA PARA TER ACESSO OU CADASTRE UMA SENHA PARA ACESSO");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    for (k = 2; k<=18; k++)
    {
        gotoxy(43,2);
        cout << ("                                   ");
        textcolor(BLUE);
        gotoxy(72-k,2);
        cout << "   ADM";
        gotoxy(20,3);
        cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    }
}

void adm_escolha()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("TECLE: P/ CADASTRAR FUNCIONARIO[1] / EXCLUIR[2] / LISTAR/[3] / MENU[4]");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    for (k = 2; k<=18; k++)
    {
        gotoxy(43,2);
        cout << ("                                   ");
        textcolor(BLUE);
        gotoxy(72-k,2);
        cout << "   ADM";
        gotoxy(20,3);
        cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    }
    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(33,8);
    cout << " CADASTRAR";
    gotoxy(33,9);
    cout << "FUNCIONARIO";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(32,9);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(45,9);
    cout << ("^");
    gotoxy(32,10);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(32,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,16);
    cout << "    LISTAR";
    gotoxy(32,17);
    cout << " FUNCIONARIO";
    textcolor(BLUE);
    gotoxy(32,16);
    cout << ("^");
    gotoxy(32,17);
    cout << ("^");
    gotoxy(45,16);
    cout << ("^");
    gotoxy(45,17);
    cout << ("^");
    gotoxy(32,18);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,7);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,8);
    textcolor(BLUE);
    gotoxy(76,8);
    cout << ("^");
    gotoxy(76,9);
    cout << ("^");
    gotoxy(77,8);
    textcolor(BLACK);
    cout << "  EXCLUIR";
    gotoxy(77,9);
    cout << "FUNCIONARIO";
    gotoxy(89,8);
    textcolor(BLUE);
    cout << ("^");
    gotoxy(89,9);
    cout << ("^");
    textcolor(BLUE);
    gotoxy(76,10);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(76,16);
    cout << ("     MENU ");
    gotoxy(76,17);
    cout << ("   PRINCIPAL ");
    textcolor(BLUE);
    gotoxy(76,16);
    cout << ("^");
    gotoxy(76,17);
    cout << ("^");
    gotoxy(89,16);
    cout << ("^");
    gotoxy(89,17);
    cout << ("^");
    gotoxy(76,18);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(80,21);
    cout << "PAG 2, Tecle 5";
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
}

void tela_cad()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("    COD: DE 1 A 100! / NOME: NOME E SOBRENOME /  CPF: APENAS NUMEROS");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(50,2);
    textcolor(BLUE);
    cout << "CADASTRAR FUNCIONARIO";
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(22,12);
    cout << "CODIGO: ";
    gotoxy(39,12);
    cout << "NOME: ";
    gotoxy(62,12);
    cout << "CPF: ";
    gotoxy(82,12);
    cout << "CARGO: ";

}

void tela_excluir()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("    COD: DE 1 A 100! / NOME: NOME E SOBRENOME /  CPF: APENAS NUMEROS");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(50,2);
    textcolor(BLUE);
    cout << "CADASTRAR FUNCIONARIO";
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(38,7);
    cout << "CODIGO DO FUNCIONARIO QUE DESEJA SER EXCLUIDO";
    gotoxy(52,10);
    cout << "CODIGO: ";
}

void tela_lista()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(50,2);
    textcolor(BLUE);
    cout << "FUNCIONARIOS CADASTRADOS";
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    textcolor(BLUE);
    gotoxy(22,4);
    cout << "CODIGO: ";
    gotoxy(39,4);
    cout << "NOME: ";
    gotoxy(62,4);
    cout << "CPF: ";
    gotoxy(82,4);
    cout << "CARGO: ";
}
void tela_fechar()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,8);
    cout << "  RECEPCAO";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(32,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(32,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,16);
    cout << "  CHECK-OUT";
    textcolor(BLUE);
    gotoxy(32,16);
    cout << ("^");
    gotoxy(45,16);
    cout << ("^");
    gotoxy(32,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,7);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,8);
    textcolor(BLUE);
    gotoxy(76,8);
    cout << ("^");
    gotoxy(79,8);
    textcolor(BLACK);
    cout << "AREA ADM";
    gotoxy(89,8);
    textcolor(BLUE);
    cout << ("^");
    textcolor(BLUE);
    gotoxy(76,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(76,16);
    cout << ("     SAIR ");
    textcolor(BLUE);
    gotoxy(76,16);
    cout << ("^");
    gotoxy(89,16);
    cout << ("^");
    gotoxy(76,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
    for (k = 2; k<=18; k++)
    {
        textcolor(BLUE);
        gotoxy(72-k,2);
        cout << "FECHANDO PROGRAMA              ";
        Sleep(100);
    }

    for (k = 2; k<=18; k++)
    {
        textcolor(BLUE);
        gotoxy(72-k,24);
        cout << "ATE LOGO             ";
        Sleep(100);
    }
    gotoxy(18,26);
    cout << " " << endl;

}

void tela_base()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("                DIGITE O CODIGO PARA ENTRAR NA AREA DE RECEPCAO");
}

void desenhaTela2()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("TECLE: P/CARDAPIO[1] / FAZER PEDIDO[2] / VOLTAR [3] ");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    for (k = 2; k<=18; k++)
    {
        gotoxy(43,2);
        cout << ("                                   ");
        textcolor(BLUE);
        gotoxy(72-k,2);
        cout << "   SERVIÇO DE QUARTO  ";
        gotoxy(20,3);
        cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    }

    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,8);
    cout << "  CARDAPIO";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(32,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(32,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,16);
    cout << " FAZER PEDIDO";
    textcolor(BLUE);
    gotoxy(32,16);
    cout << ("^");
    gotoxy(45,16);
    cout << ("^");
    gotoxy(32,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,7);

    gotoxy(76,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(76,16);
    cout << ("   VOLTAR ");
    textcolor(BLUE);
    gotoxy(76,16);
    cout << ("^");
    gotoxy(89,16);
    cout << ("^");
    gotoxy(76,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
}

void desenhaTela()
{
   int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^OPCAO: [1] RECEPCAO / [2] AREA ADMINISTRATIVA  /  [3]  CHECKOUT  /  [4] SAIR ^");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,8);
    cout << "  RECEPCAO";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(32,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(32,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,16);
    cout << "  CHECK-OUT";
    textcolor(BLUE);
    gotoxy(32,16);
    cout << ("^");
    gotoxy(45,16);
    cout << ("^");
    gotoxy(32,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,7);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,8);
    textcolor(BLUE);
    gotoxy(76,8);
    cout << ("^");
    gotoxy(79,8);
    textcolor(BLACK);
    cout << "AREA ADM";
    gotoxy(89,8);
    textcolor(BLUE);
    cout << ("^");
    textcolor(BLUE);
    gotoxy(76,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(76,16);
    cout << ("     SAIR ");
    textcolor(BLUE);
    gotoxy(76,16);
    cout << ("^");
    gotoxy(89,16);
    cout << ("^");
    gotoxy(76,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
}
void Quartos_tela()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(50,02);
    cout << ("QUARTOS");

    gotoxy(22,4);
    cout << "NUMERO";
    gotoxy(35,4);
    cout << "TIPO";
    gotoxy(48,4);
    cout << "OPCAO";
    gotoxy(61,4);
    cout << "valor";
    gotoxy(72,4);
    cout << "statuS";
    gotoxy(88,4);
    cout << "consumo";

}

void cardapio()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    textcolor(BLACK);
    gotoxy(50,2);
    cout << "CARDAPIO";
    gotoxy(22,4);
    cout << "NUMERO";
    gotoxy(52,4);
    cout << "PRODUTO";
    gotoxy(88,4);
    cout << "PRECO";

}

void recepcao()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    }
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^OPCAO: [1] GERENCIAR CLIENTES       / [2] GERENCIAR QUARTOS /       [3] SAIR ^");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,8);
    cout << "  CLIENTES";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(32,9);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLUE);
    gotoxy(76,7);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,8);
    textcolor(BLUE);
    gotoxy(76,8);
    cout << ("^");
    gotoxy(79,8);
    textcolor(BLACK);
    cout << " QUARTOS";
    gotoxy(89,8);
    textcolor(BLUE);
    cout << ("^");
    textcolor(BLUE);
    gotoxy(76,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(53,15);
    cout << (">>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(54,16);
    cout << ("  VOLTAR");
    textcolor(BLUE);
    gotoxy(53,16);
    cout << ("^");
    gotoxy(63,16);
    cout << ("^");
    gotoxy(53,17);
    cout << (">>>>>>>>>>>");
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
}

void tela_limpa()
{
        int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    }
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("                                                                               ");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
}

void tela2()
{
        int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("TECLE:P/GERENCIAR QUARTOS[1]/GERENCIAR PRODUTOS[2]/ALTERAR SENHA[3]/VOLTAR[4]");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    for (k = 2; k<=18; k++)
    {
        gotoxy(43,2);
        cout << ("                                   ");
        textcolor(BLUE);
        gotoxy(72-k,2);
        cout << "   ADM";
        gotoxy(20,3);
        cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    }
    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(33,8);
    cout << " GERENCIAR";
    gotoxy(33,9);
    cout << "  QUARTO";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(32,9);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(45,9);
    cout << ("^");
    gotoxy(32,10);
    cout << (">>>>>>>>>>>>>");
    gotoxy(76,7);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,8);
    textcolor(BLUE);
    gotoxy(76,8);
    cout << ("^");
    gotoxy(76,9);
    cout << ("^");
    gotoxy(77,8);
    textcolor(BLACK);
    cout << " GERENCIAR";
    gotoxy(77,9);
    cout << "  PRODUTO";
    gotoxy(89,8);
    textcolor(BLUE);
    cout << ("^");
    gotoxy(89,9);
    cout << ("^");
    textcolor(BLUE);
    gotoxy(76,10);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(52,15);
    cout << (">>>>>>>>>>>>>");
    gotoxy(52,17);
    cout << (">>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(51,16);
    cout << " ALTERAR SENHA";
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
}

void tela_produtos()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("TECLE:P/ ADICIONAR PRODUTO[1]/ALTERAR PRODUTO[2] /EXCLUIR PRODUTO[3] /SAIR[4]");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    for (k = 2; k<=18; k++)
    {
        gotoxy(43,2);
        cout << ("                                   ");
        textcolor(BLUE);
        gotoxy(72-k,2);
        cout << "   ADM";
        gotoxy(20,3);
        cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    }
    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,8);
    cout << " ADICIONAR";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(32,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(32,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,16);
    cout << "  ALTERAR";
    textcolor(BLUE);
    gotoxy(32,16);
    cout << ("^");
    gotoxy(45,16);
    cout << ("^");
    gotoxy(32,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,7);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,8);
    textcolor(BLUE);
    gotoxy(76,8);
    cout << ("^");
    gotoxy(77,8);
    textcolor(BLACK);
    cout << " EXCLUIR";
    gotoxy(89,8);
    textcolor(BLUE);
    cout << ("^");
    textcolor(BLUE);
    gotoxy(76,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(76,16);
    cout << ("   SAIR ");
    textcolor(BLUE);
    gotoxy(76,16);
    cout << ("^");
    gotoxy(89,16);
    cout << ("^");
    gotoxy(76,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
}

void tela_adicionar()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    }
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("                                                                               ");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,3);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(40,12);
    cout << "NUMERO:";
    gotoxy(55,12);
    cout << "PRODUTO:";
    gotoxy(70,12);
    cout << "VALOR:";
}

void tela_quartos()
{
    int k;
    textcolor(BLUE);
    textbackground(WHITE);
    clrscr();
    gotoxy(20,1);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    for (k = 2; k<=22; k++)
    {
        gotoxy(20,k);
        cout << "^";
        gotoxy(98,k);
        printf("^");
    };
    gotoxy(20,23);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    gotoxy(20,24);
    cout << ("^                                                                             ^");
    textcolor(BLACK);
    gotoxy(22,24);
    cout << ("TECLE:P/ ADICIONAR QUARTO[1]/ ALTERAR QUARTO[2] /EXCLUIR QUARTO[3] / SAIR[4]");

    textcolor(BLUE);
    gotoxy(20,25);
    cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    for (k = 2; k<=18; k++)
    {
        gotoxy(43,2);
        cout << ("                                   ");
        textcolor(BLUE);
        gotoxy(72-k,2);
        cout << "   ADM";
        gotoxy(20,3);
        cout << (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    }
    textcolor(BLUE);
    gotoxy(32,7);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,8);
    cout << " ADICIONAR";
    textcolor(BLUE);
    gotoxy(32,8);
    cout << "^";
    gotoxy(45,8);
    cout << ("^");
    gotoxy(32,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(32,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(32,16);
    cout << "  ALTERAR";
    textcolor(BLUE);
    gotoxy(32,16);
    cout << ("^");
    gotoxy(45,16);
    cout << ("^");
    gotoxy(32,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,7);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,8);
    textcolor(BLUE);
    gotoxy(76,8);
    cout << ("^");
    gotoxy(77,8);
    textcolor(BLACK);
    cout << " EXCLUIR";
    gotoxy(89,8);
    textcolor(BLUE);
    cout << ("^");
    textcolor(BLUE);
    gotoxy(76,9);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(76,15);
    cout << (">>>>>>>>>>>>>>");
    textcolor(BLACK);
    gotoxy(76,16);
    cout << ("   SAIR ");
    textcolor(BLUE);
    gotoxy(76,16);
    cout << ("^");
    gotoxy(89,16);
    cout << ("^");
    gotoxy(76,17);
    cout << (">>>>>>>>>>>>>>");
    gotoxy(55,21);
    textcolor(BLACK);
    cout << "OPCAO: ";
}

#endif // TELA_H_INCLUDED
