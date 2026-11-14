#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void menuUtama(){
    cout << "\n===== MAIN MENU =====" << endl;
    cout << "1. Battle " << endl;
    cout << "2. Gacha  " << endl;
    cout << "3. Status Player " << endl;
    cout << "4. Inventory " << endl;
    cout << "5. Exit " << endl;
}

void StatusPlayer(string Name, int HP, int Dmg, int gold, int level){
    cout << "\n===== STATUS PLAYER =====" << endl;
    cout << " Nickname      : " << Name << endl;
    cout << " Level Player  : " << level << endl;
    cout << " HP Player     : " << HP << endl;
    cout << " Damage Player : " << Dmg << endl;
    cout << " Gold          : " << gold << endl;
}


int hitungDEF(int dmg){
    return dmg * 75 / 100;
}

void battle(int &HP, int ATK, int& gold){
    int angkaMonster = rand() % 3 + 1;

    string namaMonster;
    int monsterHP;
    int monsterATK;

    if(angkaMonster == 1){
        namaMonster = "Slime";
        monsterHP = 30;
        monsterATK = 8;
    }
    else if(angkaMonster == 2){
        namaMonster = "Goblin";
        monsterHP = 40;
        monsterATK = 10;
    }
    else if(angkaMonster == 3){
        namaMonster = "Golem";
        monsterHP = 70;
        monsterATK = 6;
    }

    cout << "\nMonster Appeared: " << namaMonster << endl;

    int pilihBattle = 0;

    cout << "\n===== BATTLE START =====" << endl;

    while (HP > 0 && monsterHP > 0){

        cout << "\n===== STATUS PLAYER =====" << endl;
        cout << "HP  : " << HP << endl;
        cout << "ATK : " << ATK << endl;

        cout << "\n===== STATUS MONSTER =====" << endl;
        cout << "Name Of This Monster : " << namaMonster << endl;
        cout << "HP  : " << monsterHP << endl;
        cout << "ATK : " << monsterATK << endl;

        cout << "\n===== BATTLE MENU =====" << endl;
        cout << "1. Attack " << endl;
        cout << "2. Defend " << endl;
        cout << "3. Go Run " << endl;

        cout << "Pilihan Battle: ";
        cin >> pilihBattle;

        int dmgMonster = monsterATK;

        if (pilihBattle == 1){

            monsterHP = monsterHP - ATK;

            if(monsterHP < 0){
                monsterHP = 0;
            }

            cout << "Direct Hit!" << endl;
            cout << "Remaining Monster HP: " << monsterHP << endl;
        }
        else if(pilihBattle == 2){
            dmgMonster= hitungDEF(dmgMonster);

            cout << " You choice to defend! " << endl;
        }
        else if(pilihBattle == 3){
            cout << "You Escaped the battle!" << endl;
            return;
        }
        else{
            cout << " Invalid Choice " << endl;
            continue;
        }
        if(monsterHP > 0){
            HP = HP - dmgMonster;

            if (HP < 0){
                HP = 0;
            }

            cout << "The Monster attacked!" << endl;
            cout << "Damage Taken : " << dmgMonster << endl;
        }
    }

    if(monsterHP == 0){

        cout <<"\nYou Win!" << endl;
        gold = gold + 25;
        cout << "Gained 25 gold!" << endl;
    }
    else{

        cout << "\n You Lose!" << endl;
        cout << "Your HP has been Restored to try again" << endl;
        HP = 100;
    }

}

void gacha(vector<string> &inventory, int &Atkplayer){

    int pilihGacha = 0;

    while(pilihGacha != 2){

        cout << "\n===== GACHA SYSTEM =====" << endl;
        cout << "1. Roll Gacha" << endl;
        cout << "2. Back to Main Menu" << endl;

        cout << "Your Choice : ";
        cin >> pilihGacha;

        if(pilihGacha == 1){

            int angka = rand() % 100 + 1;
            string item;
            int atkBaru = 10;

            cout << "\nYour Gacha Number : " << angka << endl;

            if(angka <= 70){
                item = "Wooden Stick (COMMON)";
                atkBaru = 12;
            }
            else if(angka <= 95){
                item = "Iron Hammer (RARE)";
                atkBaru = 15;
            }
            else{
                item = "Dragon Eye (EPIC)";
                atkBaru = 20;
            }

            inventory.push_back(item);

            cout << "You Got: " << item << endl;
            cout << "Item Added to Inventory!" << endl;
            
        if(atkBaru > Atkplayer){
            Atkplayer = atkBaru;
            cout << "Your ATK increased to: " << Atkplayer << endl;
        }
        else{
            cout << "Your current weapon is already stronger!" << endl;
        }

        }
        else if(pilihGacha == 2){
            cout << "\nBack to Main Menu!" << endl;
        }
        else{
            cout << "\nInvalid Choice!" << endl;
        }

   }
}   



void lihatInventory(vector<string> inventory){

    cout << "\n===== PLAYER INVENTORY =====" << endl;

    if(inventory.size() == 0){
        cout << "Your Inventory is Empty!" << endl;
    }
    else{

        for(int i = 0; i < inventory.size(); i++){

            cout << i + 1 << ". " << inventory[i] << endl;

        }

    }

}

int main(){

    srand(time(0));
    string nickname;
    int Hpplayer = 100;
    int Atkplayer = 10;
    int gold = 50;
    int playerlevel = 1;
    int pilih = 0;
    vector<string> inventory;

    cout << "==== RPG System ====" << endl;
    cout << "Welcome to RPG World!" << endl;

    cout << "Masukan Nickname : ";
    cin >> nickname;

    StatusPlayer(nickname, Hpplayer, Atkplayer, gold, playerlevel);
    
    while(pilih !=5){

    menuUtama();

    cout << "Your Choice : " ;
    cin >> pilih;

    if (pilih == 1){
         battle(Hpplayer, Atkplayer, gold);
    }
    else if (pilih == 2){
       gacha(inventory, Atkplayer);
    }
    else if (pilih == 3){
        
        StatusPlayer(nickname, Hpplayer, Atkplayer, gold, playerlevel);
    }
    else if(pilih == 4){
        lihatInventory(inventory);
}   
    else if (pilih == 5){
        cout << "\nGoodbye! See You Next Time ^^" << endl; 
    }
    else{
        cout << "\nInvalid Choice" << endl;
    }
  }

  return 0;

}

