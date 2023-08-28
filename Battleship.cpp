#include <iostream>
#include <cstdlib>

using namespace std;

int row, column, NumberTurns = 0, hits = 0, play;

bool ship[5][5]={
{0,0,0,0,0}, //1
{0,0,0,0,0}, //2
{0,0,0,0,0}, //3
{0,0,0,0,0}, //4
{0,0,0,0,0}, //5
};

char grid[5][5]={
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'}, 
{'O','O','O','O','O'},     
};

void comSHIP(){

    int shipC = 0;
    while (shipC != 8){
        srand(time(0));
        int compr = 0 + rand() % 4;
        int compc = 0 + rand() % 4;
        if(ship[compr][compc]  == false){
            ship[compr][compc] =  true;
            shipC++;
        }
    }
}

void playerGRID(){

    for(int x = 0; x < 5;x++){
        for(int y = 0; y < 5;y++){
            cout << grid[x][y] << " ";
        }
        cout << endl;
    }
}

int again(){
    cout << "Would you like to play again?\n";
    cout << "1.Yes\\2.No" << endl;
    cin >> play;
    while(play != 1 && play != 2){
        cout << "Invalid! Please use 1 or 2.";
        cin >> play;
    }
    return play;
}

int main(){

    cout << "-------------------" << endl;
    cout << "Welcome to Battleship!" << endl;

    comSHIP();

    while(hits < 8){
        cout << "Please choose where you would like to strike:" << endl;
        playerGRID();
        cout << endl << "Row: ";
        cin >> row;
        row--;
        cout << "Column: ";
        cin >> column;
        column--;
        if(ship[row][column] == true){
            ship[row][column] = false;
            grid[row][column] = 'X';
            cout << endl << "Direct hit!" << endl;
            hits++;
            cout << (8-hits) << " ships are remaining!" << endl;
            NumberTurns++;
        }
        else{
            cout << endl << "You missed!" << endl;
            grid[row][column] = '0';
            cout << (8-hits) << " ships are remaining!" << endl;
            NumberTurns++;
        }
}

    cout << "You won in " << NumberTurns << " Turns." << endl;

    again();

    if(play == 1){
        main();
    }
    else{
        cout << "Thank you for playing!";
    }
        return 0;
    }


