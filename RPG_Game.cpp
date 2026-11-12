#include <iostream>

using namespace std;

int main(){
    string nickname;
    int Hpplayer = 100;
    int Atkplayer = 10;
    int gold = 50;
    cout << "==== RPG System ====" << endl;
    cout << "Welcome to RPG World!" << endl;

    cout << "Masukan Nickname : ";
    cin >> nickname;

    cout << "\n===== STATUS PLAYER =====" << endl;
    cout << " Nickname : " << nickname << endl;
    cout << " HP Player : " << Hpplayer << endl;
    cout << " Damage Player : " << Atkplayer << endl;
    cout << " Gold : " << gold << endl;
    

return 0;

}

