#include<iostream>
using namespace std;

char element[10] = {'0','1','2','3','4','5','6','7','8','9'};

void board(){
    system("cls");
    cout << "\n\nTic Tac Toe Game \n\n";
    cout << "Player 1(x) - player 2(O)" << endl << endl;
    cout << endl;
    cout << "     |     |     \n";
    cout << "   " << element[1] << " |  " << element[2] << "  | " << element[3] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "   " << element[4] << " |  " << element[5] << "  | " << element[6] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "   " << element[7] << " |  " << element[8] << "  | " << element[9] << "\n";  
    cout << "     |     |     \n"; 
}

int checkwin(){
    if(element[1] == element[2] && element[2] == element[3])
        return 1;
    else if(element[4] == element[5] && element[5] == element[6])
        return 1;
    else if(element[7] == element[8] && element[8] == element[9])
        return 1;
    else if(element[1] == element[4] && element[4] == element[7])
        return 1;
    else if(element[2] == element[5] && element[5] == element[8])
        return 1;
    else if(element[3] == element[6] && element[6] == element[9])
        return 1;
    else if(element[1] == element[5] && element[5] == element[9])
        return 1;
    else if(element[3] == element[5] && element[5] == element[7])
        return 1;
    else if(element[1] != '1' && element[2] != '2' && element[3] != '3' && 
            element[4] != '4' && element[5] != '5' && element[6] != '6' && 
            element[7] != '7' && element[8] != '8' && element[9] != '9')
        return 0;
    else
        return -1;
}

int main(){
    int player = 1, i, choice;
    char mark;
    bool playAgain = true;

    while (playAgain) {
        for (int i = 1; i <= 9; i++)
            element[i] = char('0' + i);

        do {
            board();
            player = (player % 2) ? 1 : 2;
            cout << "Player " << player << ", enter the number: ";
            cin >> choice;

            mark = (player == 1) ? 'x' : 'o';
            if (choice >= 1 && choice <= 9 && element[choice] == char('0' + choice))
                element[choice] = mark;
            else {
                cout << "INVALID MOVE!";
                player--;
                cin.ignore();
                cin.get();
            }
            i = checkwin();
            player++;
        } while (i == -1);

        board();
        if (i == 1)
            cout << "\aCONGRATULATION! PLAYER " << --player << " WINS!";
        else
            cout << "\aGAME DRAW!";

        cout << "\nDo you want to play again (yes/no)? ";
        string response;
        cin >> response;
        if (response == "no" || response == "NO") {
            playAgain = false;
        }
    }

    cout << "Have a Great day!!!\n";
    return 0;
}
