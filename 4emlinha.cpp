#include <iostream>

using namespace std;

void iniciojogo() {
    // mensagens e in/out de msgs
    // captacao de decisoes do utilizador
}

bool terminoujogo() {
    //verificar se o jogo terminou
    //alguem ganhou? //tabuleiro cheio??
}

bool tabuleirocheio() {
}

bool alguemganhou() {
}

void mostrartabuleiro() {
}

int main() {
    
    string tabuleiro [8][6] {
    { "", "", "", "", "", "", "", ""},
    { "", "", "", "", "", "", "", ""},
    { "", "", "", "", "", "", "", ""},
    { "", "", "", "", "", "", "", ""},
    { "", "", "", "", "", "", "", ""},
    { "", "", "", "", "", "", "", ""}    
    };

    bool tabuleiropreenchido = false;
    bool jogoterminou = false;

    do {
        iniciojogo();
    } while (!jogoterminou);

    return 0;

}


