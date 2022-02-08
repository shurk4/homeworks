#include <iostream>
bool check (std::string row) {
    bool check = true;
    if(row.length() > 3) check = false;
    else {
        for (int i = 0; i < 3; i++){
            if(row[i] != 'X' && row[i] != 'O' && row[i] != '.') {
                check = false;
                break;
            }
        }
    }
    return check;
}

std::string input(int num) {
    std::string row;
    do {
        std::cout << "Enter row " << num << ": ";
        std::cin >> row;
        if(!check(row)) std::cout << "Wrong input!\n";
    } while(!check(row));
    return row;
}

int counter (std::string row1, std::string row2, std::string row3, char ch) {
    int result = 0;
    for(int i = 0; i < 3; i++) {
        if(row1[i] == ch) {
            result++;
        }
        if(row2[i] == ch) {
            result++;
        }
        if(row3[i] == ch) {
            result++;
        }
    }
    return result;
}

std::string gameResult (std::string row1, std::string row2, std::string row3){
    int countX = 0, countO = 0, moves = 0, win = 0;
    std::string result;

    countX = counter(row1, row2, row3, 'X');
    moves += counter(row1, row2, row3, 'X');
    countO = counter(row1, row2, row3, 'O');
    moves += counter(row1, row2, row3, 'O');

    if (row1[0] != '.' && (row1[0] == row1[1] && row1[1] == row1[2])) {
        result = row1[0];
        win++;
    }
    if (row1[0] != '.' && (row1[0] == row2[0] && row2[0] == row3[0])) {
        result = row1[0];
        win++;
    }
    if (row2[1] != '.' && (row2[0] == row2[1] && row2[1] == row2[2])){
        result = row2[1];
        win++;
    }
    if (row2[1] != '.' && (row1[1] == row2[1] && row2[1] == row3[1])) {
        result = row2[1];
        win++;
    }
    if (row2[1] != '.' && (row1[0] == row2[1] && row2[1] == row3[2])) {
        result = row2[1];
        win++;
    }
    if (row2[1] != '.' && (row1[2] == row2[1] && row2[1] == row3[0])) {
        result = row2[1];
        win++;
    }
    if (row3[2] != '.' && (row1[2] == row2[2] && row2[2] == row3[2])) {
        result = row3[2];
        win++;
    }
    if (row3[2] != '.' && (row3[0] == row3[1] && row3[1] == row3[2])){
        result = row3[2];
        win++;
    }

    if(win > 1 ||countX < countO || countX - 1 > countO || (result == "X" && countX == countO) || (result == "O" && countX > countO)) result = "Incorrect";
    else if(win == 0) result = "Nobody!";
    else if(result == "X") result = "Petya won!";
    else if(result == "O") result = "Vanya won!";

    return result;
}

int main() {
    std::string row1, row2, row3;

    row1 = input(1);
    row2 = input(2);
    row3 = input(3);


    std::cout << gameResult(row1, row2, row3);

    return 0;
}