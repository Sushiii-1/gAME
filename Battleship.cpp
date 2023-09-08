#include <iostream>
#include <cstdlib>

using namespace std;

int row, column, NumberTurns = 0, userhits = 0,cpuhits = 0, play, shipload;

void rowCHECK(){ //check if row is valid number

    while(row < 1 || row > 5){
        cout << "\nINVALID! PLEASE PICK BETWEEN 1 AND 5!\n";
        cout << endl << "Row:";
        cin >> row;
    }
}

void columnCHECK(){ //check if column is valid number

    while(column < 1 || column > 5){
        cout << "\nINVALID! PLEASE PICK BETWEEN 1 AND 5!\n";
        cout << endl << "Column:";
        cin >> column;
    }
}

bool ship[5][5]={ //computers grid
{0,0,0,0,0}, //1
{0,0,0,0,0}, //2
{0,0,0,0,0}, //3
{0,0,0,0,0}, //4
{0,0,0,0,0}, //5
};

bool playerSHIPS[5][5]={ // players grid
{0,0,0,0,0}, //1
{0,0,0,0,0}, //2
{0,0,0,0,0}, //3
{0,0,0,0,0}, //4
{0,0,0,0,0}, //5
};

char userGRID[5][5]={ //players grid
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'},     
};

void userSIDE(){ //print users grid

        for(int x = 0; x < 5;x++){
        for(int y = 0; y < 5;y++){
            cout << userGRID[x][y] << " ";
        }
        cout << endl;
    }
}

char grid[5][5]={ // grid to show cpu's grid 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'},     
};

void cpuGRID(){ // print cpu's grid

    for(int x = 0; x < 5;x++){
        for(int y = 0; y < 5;y++){
            cout << grid[x][y] << " ";
        }
        cout << endl;
    }
}

void comSHIP(){ //computer placing ships

    cout << "\nComputer is placing ships...\n";
    int shipC = 0;
    while (shipC != 8){
        srand(time(0));
        int compr = 0 + rand() % 4;
        int compc = 0 + rand() % 4;
        if(ship[compr][compc]  == false){
            ship[compr][compc] =  true;
            shipC++;
            shipload++;
            cout << "Placing ships..." << shipload << "/8" << endl;
        }
    }
    cout << "\nComputer is done\nCommencing game...\n\n";
}

void playerSHIP(){ //player placing ships

    int placedSHIPS = 8;
    while (placedSHIPS != 0){
        cout << "\nPlease place " << placedSHIPS << " ships anywhere on the grid,\n";
        userSIDE();
        cout << "Row:";
        cin >> row;
        rowCHECK();
        row--;
        cout << "Column:";
        cin >> column;
        columnCHECK();
        column--;
        if(playerSHIPS[row][column] == false){
            playerSHIPS[row][column] = true;
            userGRID[row][column] = '|';
            placedSHIPS--;
        }
        else{
            cout << "\nShip already present!\n";
        }
    }
}

int again(){ // play again
    cout << "Would you like to play again?\n";
    cout << "1.Yes\\2.No" << endl;
    cin >> play;
    while(play != 1 && play != 2){
        cout << "Invalid! Please use 1 or 2.";
        cin >> play;
    }
    return play;
}

void cpuTURN(){ //cpu

    cout << "\n---CPU's TURN---\n";
    srand(time(NULL));
    int compr = 0 + rand() % 4;
    int compc = 0 + rand() % 4;
    if(userGRID[compr][compc] == 'X'){
        cpuTURN();  
    }
    if(playerSHIPS[compr][compc] ==  true){
        cout << "DIRECT HIT BY CPU!\n";
        playerSHIPS[compr][compc] = false;
        userGRID[compr][compc] = 'X';
        cpuhits++; 
    }
    else {
        cout << "CPU MISSED!";
        userGRID[compr][compc] = 'X'; 
    }
}

void game(){ // actual game

    while(userhits != 8 || cpuhits != 8){
        cout << endl << "Please choose where you would like to strike:" << endl;
        cout << "-------------------CPU SIDE------------------" << endl;
        cpuGRID();
        cout << endl;
        cout << "-----------------PLAYER SIDE------------------" << endl;
        userSIDE();
        cout << endl;
        cout << endl << "Row: ";
        cin >> row;
        rowCHECK();
        row--;
        cout << "Column: ";
        cin >> column;
        columnCHECK();
        column--;
        if(ship[row][column] == true){
            ship[row][column] = false;
            grid[row][column] = 'X';
            cout << endl << "Direct hit!" << endl;
            userhits++;
            cout << (8-userhits) << " ships are remaining!" << endl;
            NumberTurns++;
        }
        else{
            cout << endl << "You missed!" << endl;
            grid[row][column] = '0';
            cout << (8-userhits) << " ships are remaining!" << endl;
            NumberTurns++;
        }
        cpuTURN();
    }
}

int main(){

    cout << "-------------------" << endl;
    cout << "Welcome to Battleship!" << endl;

    playerSHIP();
    comSHIP();
    game();

    again();

    if(play == 1){
        main();
    }
    else{
        cout << "Thank you for playing!";
    }
        return 0;
    }


