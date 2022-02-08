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

char game (char field[3][3]) {
    char prev = 'O';
    int x, y;

    for (int i = 0; i < 10; i++) {
        if (field[0][0] != ' ' && ((field[0][0] == field[0][1] && field[0][1] == field[0][2])
                                   || (field[0][0] == field[1][0] && field[1][0] == field[2][0])
                                   || (field[0][0] == field[1][1] && field[1][1] == field[2][2]))) {
            prev = field[0][0];
            break;
        }
        else if (field[1][0] != ' ' && (field[1][0] == field[1][1] && field[1][1] == field[1][2])) {
            prev = field[1][0];
            break;
        }
        else if (field[2][0] != ' ' && field[2][0] == field[2][1] && field[2][1] == field[2][2]) {
            prev = field[2][0];
            break;
        }
        else if (field[0][1] != ' ' && field[0][1] == field[1][1] && field[1][1] == field[2][1]) {
            prev = field[0][1];
            break;
        }
        else if (field[0][2] != ' ' && ((field[0][2] == field[1][2] && field[1][2] == field[2][2])
                                        || (field[0][2] == field[1][1] && field[1][1] == field[2][0]))) {
            prev =  field[0][2];
            break;
        } else if(i == 9) {
            prev = ' ';
            break;
        }

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
}

int main() {
    char field[3][3];

    std::cout << "===============\n" << "] Tic tac toe [\n" << "===============\n";
    start(field);
    output(field);


    char result = game(field);

    if(result == ' ') std::cout << "=!!! DRAW !!!=";
    else std::cout << "Player \"" << result << "\" win!";

    return 0;
}