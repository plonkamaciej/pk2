#include "header.h"
#include "menu.h"
#include "extern.h"

void menu::display_menu(){
logs << "uruchomiono funkcje MENU::DISPLAY_MENU" << endl;
while(menu::opcja != 1) {
    system("CLS");

    std::cout << "What do you want to do? "<< std::endl
         << "(1) GRAJ!"         << std::endl
         << "(2) ZRESAETUJ GRE" << std::endl
         << "(3) WYJDZ Z GRY"   << std::endl;
    
    std::cin >> menu::opcja;
    
    switch(opcja) {
        case 1:
            graj();
            break;
        case 2:
            reset();
            break;
        case 3:
            wyjdz();
        default:
            std::cout << "zla opcja" << std::endl;
    }
}

}

std::string menu::set_back(){
    logs << "uruchomiono funkcje MENU::SET_BACK" << endl;
    std::string r = R"(
___________                                           .__    .__ 
\__    ___/____    _____ _____     ____   ____   ____ |  |__ |__|
  |    |  \__  \  /     \\__  \   / ___\ /  _ \_/ ___\|  |  \|  |
  |    |   / __ \|  Y Y  \/ __ \_/ /_/  >  <_> )  \___|   Y  \  |
  |____|  (____  /__|_|  (____  /\___  / \____/ \___  >___|  /__|
               \/      \/     \//_____/             \/     \/    
		)";
    return r;
}

void menu::graj() {
    logs << "uruchomiono funkcje MENU::GRAJ" << endl;
    std::cout << "Zaczynamy gre!" << std::endl;
    if ((pet.GetAge() > 10) || (pet.getSickness() && pet.GetMood() > 20)) {
        display_ending();
    }
    if(pet.GetAge() == 0 && pet.GetName() == "") {
    std::cout << "Ustaw imie swojego TAMAGOTCHI"<< std::endl;
    string tmp;
    cin >> tmp;
    pet.Set_name(tmp);
    }
}


void menu::reset(){
    logs << "uruchomiono funkcje MENU::RESET" << endl;
    cout << "Czy jestes pewny?[Y/n]" << endl;
    char tmp;
    cin >> tmp;
    if(tmp != 'n'){
        pet.clear();
        pet.Zapis();
     }
    
}
int menu::wyjdz(){ cout << "Wracaj szybko" << endl;
    logs << "----------- ZAMKNIECIE GRY" << endl;
    exit(0);
}

void menu::display_ending() {
    logs << "uruchomiono funkcje MENU::DISPLAY_ENDING" << endl;
    system("CLS");

    cout << R"(
          (___)
   ____
 _\___ \  |\_/|
\     \ \/ , , \ ___
 \__   \ \ ="= //|||\
  |===  \/____)_)||||
  \______|    | |||||
      _/_|  | | =====
     (_/  \_)_) 
  _________________

	)" << endl;

    cout << pet.GetName() << " mial " << pet.GetAge() << " kiedy odszedl" << endl;
    pet.Zapis();
    system("pause");
    exit(0);
}