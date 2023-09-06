#include <iostream>

using namespace std;



int main(){

int userN;

    cout << "How many numbers of the sequence would you like:"; cin >> userN;

int sequence[userN];
sequence[0] = 0;
sequence[1] = 1;

    cout << "\nBeginning sequence:\n";
    for(int i = 2; i < sizeof(sequence)/sizeof(int);i++){
    sequence[i] = sequence[i-1] + sequence[i-2];
    }
    for (int x : sequence){
        cout << x << " | ";
    }

}