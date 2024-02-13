#include <iostream>

using namespace std;

// Declara��o da fun��o mostrartabuleiro para que ela possa ser usada antes de ser definida
void mostrartabuleiro(string tabuleiro[6][8]);

// Fun��o para verificar se algum jogador ganhou
bool alguemganhou(string tabuleiro[6][8]) {
    // Verificar horizontalmente
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 5; j++) {
            // Se encontrarmos 4 pe�as iguais consecutivas na horizontal, mostramos uma mensagem de vit�ria
            if(tabuleiro[i][j] != "" && tabuleiro[i][j] == tabuleiro[i][j+1] && tabuleiro[i][j] == tabuleiro[i][j+2] && tabuleiro[i][j] == tabuleiro[i][j+3]) {
                cout << "Parab�ns, jogador " << tabuleiro[i][j] << " ganhou!" << endl;
                return; // Retornamos imediatamente pois o jogo terminou
            }
        }
    }

    // Verificar verticalmente
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 8; j++) {
            // Se encontrarmos 4 pe�as iguais consecutivas na vertical, mostramos uma mensagem de vit�ria
            if(tabuleiro[i][j] != "" && tabuleiro[i][j] == tabuleiro[i+1][j] && tabuleiro[i][j] == tabuleiro[i+2][j] && tabuleiro[i][j] == tabuleiro[i+3][j]) {
                cout << "Parab�ns, jogador " << tabuleiro[i][j] << " ganhou!" << endl;
                return; // Retornamos imediatamente pois o jogo terminou
            }
        }
    }

    // Verificar diagonalmente (de cima para baixo)
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            // Se encontrarmos 4 pe�as iguais consecutivas na diagonal (de cima para baixo), mostramos uma mensagem de vit�ria
            if(tabuleiro[i][j] != "" && tabuleiro[i][j] == tabuleiro[i+1][j+1] && tabuleiro[i][j] == tabuleiro[i+2][j+2] && tabuleiro[i][j] == tabuleiro[i+3][j+3]) {
                cout << "Parab�ns, jogador " << tabuleiro[i][j] << " ganhou!" << endl;
                return; // Retornamos imediatamente pois o jogo terminou
            }
        }
    }

    // Verificar diagonalmente (de baixo para cima)
    for(int i = 3; i < 6; i++) {
        for(int j = 0; j < 5; j++) {
            // Se encontrarmos 4 pe�as iguais consecutivas na diagonal (de baixo para cima), mostramos uma mensagem de vit�ria
            if(tabuleiro[i][j] != "" && tabuleiro[i][j] == tabuleiro[i-1][j+1] && tabuleiro[i][j] == tabuleiro[i-2][j+2] && tabuleiro[i][j] == tabuleiro[i-3][j+3]) {
                cout << "Parab�ns, jogador " << tabuleiro[i][j] << " ganhou!" << endl;
                return; // Retornamos imediatamente pois o jogo terminou
            }
        }
    }
}

// Fun��o para mostrar o tabuleiro
void mostrartabuleiro(string tabuleiro[6][8]) {
    // Pergunta ao jogador se deseja ver o tabuleiro atual
    char resposta;
    cout << "Deseja ver o tabuleiro atual? (S/N): ";
    cin >> resposta;
    // Se a resposta for afirmativa, mostra o tabuleiro
    if (resposta == 'S' || resposta == 's') {
        cout << "Tabuleiro atual:" << endl;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 8; j++) {
                cout << tabuleiro[i][j] << " ";
            }
            cout << endl;
        }
    }
}

// Fun��o para verificar se o tabuleiro est� cheio
bool tabuleirocheio(string tabuleiro[6][8]) {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 8; j++) {
            // Se houver uma posi��o vazia no tabuleiro, retornamos falso
            if(tabuleiro[i][j] == "") {
                return false;
            }
        }
    }
    // Se n�o houver nenhuma posi��o vazia, retornamos verdadeiro
    return true;
}

// Fun��o para iniciar o jogo
void iniciojogo(string tabuleiro[6][8], char letras[2]) {
    // In�cio do jogo
    cout << "Inicio do jogo!" << endl;
    int coluna;
    int jogador = 0; // jogador 0 � o jogador 1, jogador 1 � o jogador 2
    char resposta; // Vari�vel para armazenar a resposta do jogador
    // Loop do jogo
    do {
        // Pergunta ao jogador se deseja ver o tabuleiro atual
        cout << "Deseja ver o tabuleiro atual? (S/N): ";
        cin >> resposta;
        if (resposta == 'S' || resposta == 's') {
            mostrartabuleiro(tabuleiro); // Mostra o tabuleiro se a resposta for afirmativa
        }

        // Solicitar a jogada do jogador atual
        cout << "Jogador " << jogador + 1 << " (" << letras[jogador] << "), fa�a sua jogada (coluna 0-7): ";
        cin >> coluna;

        // Verificar se a coluna est� dentro do intervalo v�lido
        if (coluna < 0 || coluna > 7) {
            cout << "Coluna inv�lida. Tente novamente." << endl;
            continue;
        }

        // Encontrar a primeira posi��o vazia na coluna escolhida
        int linha;
        for (linha = 5; linha >= 0; linha--) {
            if (tabuleiro[linha][coluna] == "") {
                tabuleiro[linha][coluna] = letras[jogador]; // Preencher a posi��o com a letra do jogador
                break;
            }
        }

        // Verificar se houve 4 em linha
        alguemganhou(tabuleiro);

        // Trocar de jogador
        jogador = (jogador + 1) % 2;

    } while (!tabuleirocheio(tabuleiro) && !alguemganhou(tabuleiro)); // Continuar enquanto houver espa�o vazio no tabuleiro e ningu�m ganhar
}

 int main() {
    string nomes[2];
    char letras[2];

    string tabuleiro[6][8] {
        { "", "", "", "", "", "", "", ""},
        { "", "", "", "", "", "", "", ""},
        { "", "", "", "", "", "", "", ""},
        { "", "", "", "", "", "", "", ""},
        { "", "", "", "", "", "", "", ""},
        { "", "", "", "", "", "", "", ""}
    };

    cout << "\n*************** BEM VINDO AO JOGO ***************" << endl << endl;

    // Solicitar nomes dos jogadores e suas letras
    for (int i = 0; i < 2; i++) {
        cout << "Nome jogador " << i + 1 << ": ";
        cin >> nomes[i];
        do {
            cout << "Escolha 'X' ou 'O': ";
            cin >> letras[i];
        } while (letras[i] != 'X' && letras[i] != 'O');
    }

    // Iniciar o jogo
    iniciojogo(tabuleiro, letras);

    return 0;
}
