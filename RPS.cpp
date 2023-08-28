#include <iostream>
#include <cstdlib>

using namespace std;

char nameC;
char nameU;
int userC;
int play;

int comNUM(){
    srand(time(NULL));
    int compC = 1 + rand() % 3;
    switch (compC){
        case 1 :
        nameC = 'r';
            break;
        case 2 :
        nameC = 'p';
            break;
        case 3 :
            nameC = 's';
            break;
    }
    return nameC;
}

int userNUM(){
    switch(userC){
    case 1:
        nameU = 'r';
        break;
    case 2:
        nameU = 'p';
        break;
    case 3:
        nameU = 's';
        break;
    }   
    return nameU;
}

void winner(){
    if (nameU == 'r' && nameC == 'p'){
        cout << "You win! Computer played paper.";
    }
    else if(nameU == 'r' && nameC == 's'){
        cout << "You lose! Computer played scissors.";
    }
    else if(nameU == 'p' && nameC == 'r'){
        cout << "You win! Computer played rock.";
    }
    else if(nameU == 'p' && nameC == 's' ){
        cout << "You Lose Computer played scissors.";
    }
    else if(nameU == 's' && nameC == 'p'){
        cout << "You win! Computer played paper.";
    }
    else if(nameU == 's' && nameC == 'r'){
        cout << "You lose! Computer played rock.";
    }
    else{
        cout << "Tie!";
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

    cout << "-----------------------------------------" << endl;
    cout << "Please pick one of the numbered options:" << endl;
    cout << "1.Rock\n" << "2.Paper\n" << "3.Scissors" << endl;
    cin >> userC;
    cout << endl;

while (userC != 1 && userC != 2 && userC != 3){
        cout << "Please pick one of the numbered options ONLY: " << endl;
        cout << "1.Rock\n" << "2.Paper\n" << "3.Scissors" << endl;
        cin >> userC;
    }

    comNUM();
    userNUM();
    winner();
    again();
    if(play==1){
        main();
    }
    else{
    cout << endl << "-----------------------";
    cout << endl << "Thank you for playing!";
    }

    return 0;

}


