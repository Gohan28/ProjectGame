#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void menuUtama(){
    cout << "===== RPG SYSTEM =====" << endl;
    cout << "1. Battle" << endl;
    cout << "2. Gacha" << endl;
    cout << "3. Upgrade Weapon" << endl;
    cout << "4. Skill Tree" << endl;
    cout << "5. Keluar" << endl;
}

void tampilkanPlayer(string nama,int HP,int ATK){
    cout << "===== PLAYER =====" << endl;
    cout << "Nickname: " << nama << endl;
    cout << "HP: " << HP << endl;
    cout << "ATK: " << ATK << endl;
}

int hitungDEF(int dmg){
    return dmg / 2;
}

void menuBattle() {
    cout << "===== BATTLE MENU =====" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Heal" << endl;
    cout << "4. Run" << endl;
    cout << "Pilihan Battle: ";
}

void battle(int playerATK){
    cout << "Memasuki Battle System!!" << endl;
    cout << "===== BATTLE BEGINS =====" << endl;
    
    string nickname = "Player 1";
    int playerHP = 100;
    int monsterHP = 80;
    int monsterATK = 15;
    int pilihBattle = 0;
    int ronde = 1;
    
    while(playerHP > 0 && monsterHP > 0){
        cout << "\n ROUND " << ronde << endl;
        tampilkanPlayer(nickname,playerHP,playerATK);
    
        cout << "===== MONSTER =====" << endl;
        cout << "HP: " << monsterHP << endl;
        cout << "ATK: " << monsterATK << endl;
    
        menuBattle();
        cin >> pilihBattle;
        
        int dmgMonster = monsterATK;
    
        if (pilihBattle == 1){
            cout << "=====+=====" << endl;
            cout << "Kamu memilih Attack!" << endl;
            cout << "=====+===== \n" << endl;
            cout << "Daya hancur seranganmu adalah: " << playerATK << endl;
            if (playerATK < monsterHP){
                monsterHP = monsterHP - playerATK;
                cout << "Seranganmu Berhasil dan sisa HP Monster tersebut adalah: " << monsterHP << endl;
                cout << "=====+===== \n" << endl;
            }
            else if(playerATK == monsterHP){
                monsterHP = 0;
                cout << "Seranganmu membunuh Monster!!" << endl;
                    cout << "=====+=====" << endl;
            }
            else{
                monsterHP = 0;
                cout << "Seranganmu langsung membunuh Monster tersebut secara BRUTAL!!" << endl;
                            cout << "=====+=====" << endl;
            }
        }
        else if(pilihBattle == 2){
            cout << "\n Kamu memilih Defend! \n" << endl;
            cout << "Kamu mendapatkan pertahanan sebanyak 50% dari serangan musuh" << endl;
            
            dmgMonster = hitungDEF(dmgMonster);
            
        }
        else if (pilihBattle == 3) {
            cout << "\n Kamu memilih Heal! \n" << endl;
    
            if (playerHP >= 100) {
                cout << "HPmu SUDAH PENUH!!" << endl;
                continue;
            }
    
            int NEWplayerHP = playerHP + 25;
    
            if (NEWplayerHP > 100) {
                NEWplayerHP = 100;
            }
    
            cout << "HPmu bertambah " << NEWplayerHP - playerHP << " HP!" << endl;
    
            playerHP = NEWplayerHP;
    
            cout << "HPmu sekarang adalah: " << playerHP << endl;
    
            if (playerHP == 100) {
                cout << "HPmu sekarang SUDAH MAKSIMAL!!" << endl;
            }
    
            cout << "=====+=====" << endl;
        }
        
        else if(pilihBattle == 4){
            cout << "\n Kamu memilih Run! \n" << endl;
            cout << "==========" << endl;
            cout << "Kamu lari dari pertarungan! \n" << endl;
            cout << "Status Terakhir adalah: " << endl;
            cout << "==========" << endl;
            cout << nickname << " HP: " << playerHP << endl;
            cout << "Monster" << " HP: " << monsterHP << endl;
            cout << "==========" << endl;
            break;
        }
        else{
            cout << "\n Masukkan angka yang valid!! \n" << endl;
            continue;
        }
        
        if(playerHP > 0 && monsterHP > 0){
            cout << "Monster tersebut melayangkan Counterattack dengan power: " << dmgMonster << endl;
            playerHP = playerHP - dmgMonster;
            if(playerHP <= 0){
                playerHP = 0;
                cout << "Kamu KALAH!" << endl;
            }else{
                cout << "HPmu sekarang: " << playerHP << endl;
            }
        }
        else if(monsterHP <= 0){
            monsterHP = 0;
            cout << "Pertarungan sudah selesai "<< nickname << " menang!" << endl;
        }
    
            ronde++;
            cout << "\n" << endl;
        }
}

void gacha(){
    cout << "Memasuki laman Gacha..." << endl;
    int pilihGacha = 1;
    
    while(pilihGacha == 1){
        
        int angka = rand() % 100 + 1;
        
        cout << "\n" << endl;
        cout << "===== GACHA =====" << endl;
        cout << "Angka Gacha kamu: " << angka << endl;
        
        if(angka <= 70){
            cout << "Kamu mendapatkan COMMON!" << endl;
        }
        else if(angka <= 95){
            cout << "Kamu mendapatkan RARE!" << endl;
        }
        else{
            cout << "BINGO!! Kamu mendapatkan EPIC!!!" << endl;
        }
    
    cout << "1. Gacha Lagi \t 2. Kembali ke Main Menu \n" << endl;
    cout << "Tulis aksimu: ";
    cin >> pilihGacha;
    }
}

int hitungbiayaUP(int level){
    return level * 100;
}

void upgradeWeapon(int &gold, int &weaponLevel, int &weaponATK){
    cout << "Membuka laman Upgrade..." << endl;
    
    int pilihUpgrade = 1;
    
    while(pilihUpgrade == 1){
        int biayaUP = hitungbiayaUP(weaponLevel);
        
        cout << "===== WEAPON UPGRADE =====" << endl;
        cout << "Gold: " << gold << endl;
        cout << "Weapon Level: " << weaponLevel << endl;
        cout << "weaponATK: " << weaponATK << endl;
    
        cout << "Biaya Upgrade: " << biayaUP << " Gold!" << endl;
        if(gold >= biayaUP){
            weaponLevel++;
            weaponATK = weaponATK + 5;
            cout << "Upgrade Berhasil, Weapon Level +1 & WeaponATK +5, SELAMAT!!" << endl;
            gold -= biayaUP;
        }
        else{
            cout << "Goldmu tidak mencukupi untuk melakukan UPGRADE! KERJA SANA!" << endl;
        }
    
        cout << "===================" << endl;
        cout << "Goldmu sekarang: " << gold << endl;
        cout << "Apa yang akan kamu lakukan?" << endl;
        cout << "1. Lanjut \t 2. Keluar" << endl;
        cout << "Tentukan langkahmu : ";
        cin >> pilihUpgrade;
        cout << "==========" << endl;
    }
}

void skillTree(int &skillPoint, bool &powerSlash, bool &doubleSlash){
    cout << "Membuka Skill Tree..." << endl;
    
    int pilihSkill = 0;
    
    while(pilihSkill != 3){
        cout << "===== SKILL TREE =====" << endl;
        cout << "Skill Pointmu: " << skillPoint << endl;
        cout << "\n" << endl;
        if(powerSlash == true){
            cout << "1. Power Slash = UNLOCKED" << endl;
        }else{
            cout << "1. Power Slash = LOCKED" << endl;
        }
        if(doubleSlash == true){
            cout << "2. Double Slash = UNLOCKED" << endl;
        }else{
            cout << "2. Double Slash = LOCKED" << endl;
        }
        
        cout << "====================" << endl;
        
        if(powerSlash == true){
            cout << "1. Power Slash (UNLOCKED)" << endl;
        }else{
            cout << "1. Unlock Power Slash" << endl;
        }
        if(doubleSlash == true){
            cout << "2. Double Slash (UNLOCKED)" << endl;
        }else{
            cout << "2. Unlock Double Slash" << endl;
        }
        cout << "3. Kembali ke Main Menu" << endl;
        cout << "Tentukan langkahmu : ";
        cin >> pilihSkill;
        cout << "==========" << endl;
        
        if(pilihSkill == 1){
            if(skillPoint >= 1 && powerSlash == false){
                skillPoint -= 1;
                powerSlash = true;
                cout << "Power Slash berhasil dipelajari!!" << endl;
            }
            else if(powerSlash == true){
                cout << "Power Slashmu sudah aktif, gunakan terlebih dahulu!" << endl;
            }
            else if(skillPoint < 1){
                cout << "SPmu kurang, cari cara untuk meningkatkannya!" << endl;
            }
            else{
                cout << "Tindakanmu tidak valid!" << endl;
            }
        }
        else if(pilihSkill == 2){
            if(skillPoint >= 1 && powerSlash == true && doubleSlash == false){
                skillPoint -= 1;
                doubleSlash = true;
                cout << "Double Slash berhasil dipelajari!!" << endl;
            }
            else if(doubleSlash == true){
                cout << "Double Slashmu sudah aktif, gunakan terlebih dahulu!" << endl;
            }   
            else if(powerSlash == false){
                cout << "Pelajari Power Slash terlebih dahulu!" << endl;
            }
            else if(skillPoint < 1){
                cout << "SPmu kurang, cari cara untuk meningkatkannya!" << endl;
            }

        }
        else if(pilihSkill == 3){
            cout << "Keluar dari Skill Tree" << endl;
        }
        else{
            cout << "Pilihan tidak valid!" << endl;
        }
    }
}

int main(){
    
    int skillPoint = 2;
    bool powerSlash = false;
    bool doubleSlash = false;
    int weaponLevel = 1;
    int weaponATK = 20;
    int gold = 500;
    int pilih = 0;
    srand(time(0));
    
    while(pilih != 5){
        menuUtama();
        cout << "======================" << endl;
        cout << "Pilihan: ";
        cin >> pilih;
        
        if(pilih == 1){
            battle(weaponATK);
        }
        else if(pilih == 2){
            gacha();
        }
        else if(pilih == 3){
            upgradeWeapon(gold, weaponLevel, weaponATK);
        }
        else if(pilih == 4){
            skillTree(skillPoint, powerSlash, doubleSlash);
        }
        else if(pilih == 5){
            cout << "Keluar dari pertempuran..." << endl;
        }
        else{
            cout << "Pilihan anda tidak Valid!" << endl;
        }
    }

    cout << "Sampai Jumpa Kembali!" << endl;

    
}