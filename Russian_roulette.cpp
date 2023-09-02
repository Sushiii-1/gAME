#include <iostream>
#include <cstdlib>

using namespace std;

int bulletp, start, act,x , y;
string luck;

bool chamber[6] = {0,0,0,0,0,0};

int gun(){
    srand(6);
    bulletp = 0 + rand() % 5;
    return bulletp;
}

int chamb(){
    srand(time(0));
    start = 0 + rand() % 5;
    return start;
}

bool player1(){
        cout << "\n\nType anything for goodluck:\n";
        cin >> luck;
        if(chamber[start]){
            cout << "\nPLAYER 1 DIED.";
            return 0;
        }
        else {
            cout << "\nPLAYER 1 LIVED.";
            start++;
            return 1;
        }
}

bool player2(){
        cout << "\n\nType anything for goodluck:\n";
        cin >> luck;
        if(chamber[start] == true){
            cout << "\nPLAYER 2 DIED.";
            return 0;
        }
        else {
            cout << "\nPLAYER 2 LIVED.";
            start++;
            return 1;
        }
}

bool cpu(){
    if(chamber[start]){
        cout << "\nCPU has malfuncioned, YOU WIN!\n";
        return 0;
    }
    else {
        cout << "\nCPU lives(?) another day!\n";
        start++;
        return 1;
    }
}

void playergame(){

     while(player1()){

        if(start > 5){
        start = (start-6);
        }

        if(player2() == false){
        break;
        }
    }
}

void cpugame(){

    while(player1()){

        if(start > 5){
        start = (start-6);
        }

        if(cpu() == false){
        break;
        }
    }
}

int main(){

    cout << "---Russian Roulette---";

    while(true){

        cout << "\nPlay against:\n1.Opponent\n2.CPU\n3.Exit\n";

        cin >> act;

        if(act == 1){
            gun();
            chamber[bulletp] = true;
            chamb();
            playergame();
            cout << "\n---GAME OVER---\n";
        }
        else if(act == 2){
            gun();
            chamber[bulletp] = true;
            chamb();
            cpugame();
            cout << "\n---GAME OVER---\n";
        }
        else{

            break;

        }
    }
}

