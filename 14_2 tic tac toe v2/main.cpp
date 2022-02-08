#include <iostream>

char start (char field[3][3]){

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            field[i][j] = ' ';
        }
    }
    return field[3][3];
}

void output (char field[3][3]){
    for (int i = 0; i < 3; i++){
        std::cout << " -------------\n";
        for (int j = 0; j < 3; j++) {
            if (j == 2) std::cout << " | " << field[i][j] << " |\n";
            else std::cout << " | " << field[i][j];
        }
        if (i == 2) std::cout << " -------------\n";
    }
}

char gameCheck (char field[3][3], char prev) {
    char result;
    int countX[4]{0};
    int countO[4]{0};
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (field[j][k] != ' ') field[j][k] == 'X' ? countX[0]++ : countO[0]++;
            if (field[k][j] != ' ') field[k][j] == 'X' ? countX[1]++ : countO[1]++;
            if (field[k][k] != ' ') field[k][k] == 'X' ? countX[2]++ : countO[2]++;
            if (field[k][2 -k] != ' ') field[k][2 - k] == 'X' ? countX[3]++ : countO[3]++;
        }
        for (int j = 0; j < 4; j++) {
            if(countX[j] == 3 || countO[j] == 3) result = prev;
        }
        if(result == prev) break;

        for(int j = 0; j < 4; j++) {
            countX[j] = 0;
            countO[j] = 0;
        }
    }
    return result;
}

int main() {
    char field[3][3];
    char prev = 'O', result = ' ';
    int x, y;

    std::cout << "===============\n" << "] Tic tac toe [\n" << "===============\n";
    start(field);
    output(field);

    for (int i = 0; i < 10; i++) {
        result = gameCheck(field, prev);

        if(result == prev) break;

        do {
            std::cout << "Enter the X, Y coordinates of the player \"" << (prev == 'O' ? "X" : "O") << "\":\n";
            std::cin >> x >> y;
            if (x < 1 || x > 3 || y < 1 || y > 3) std::cout << "Wrong input! Try again:\n";
            else if (field[x - 1][y - 1] != ' ') std::cout << "This cell is already filled! Try again:\n";
        } while (x < 1 || x > 3 || y < 1 || y > 3 || field[x - 1][y - 1] != ' ');
        prev == 'O' ? prev = 'X' : prev = 'O';
        field[x - 1][y - 1] = prev;
        output(field);
    }

    if(result == ' ') std::cout << "=!!! DRAW !!!=";
    else std::cout << "Player \"" << result << "\" win!";

    return 0;
}