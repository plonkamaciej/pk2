#include "header.h"
#include "extern.h"
#include "menu.h"

void menu::display_menu(Pet & pet){
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
            graj(pet);
            break;
        case 2:
            reset(pet);
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

void menu::graj(Pet & pet) {
    logs << "uruchomiono funkcje MENU::GRAJ" << endl;
    std::cout << "Zaczynamy gre!" << std::endl;
    if ((pet.GetAge() > 10) || (pet.getSickness() && pet.GetMood() > 20)) {
        display_ending(pet);
    }
    if(pet.GetAge() == 0) {
    std::cout << "Ustaw imie swojego TAMAGOTCHI"<< std::endl;
    pet.clear();
    string tmp;
    cin >> tmp;
    pet.Set_name(tmp);
    int tmp1;
    cout << "chcesz grac [0]kotem, [1]dinozaurem czy [2]psem?" << endl;
    cin >> tmp1;
    if (tmp1 == 0) pet.Set_type(0);
    else if (tmp1 == 1) pet.Set_type(1);
    else if (tmp1 == 2) pet.Set_type(2);
    pet.Zapis();
    }
}


void menu::reset(Pet & pet){
    logs << "uruchomiono funkcje MENU::RESET" << endl;
    cout << "Czy jestes pewny?[Y/n]" << endl;
    char tmp;
    cin >> tmp;
    if(tmp != 'n'){
        pet.clear();
        pet.Zapis();
        cout << "Zresetowano gre" << endl;
        system("pause");
     }
    
}
int menu::wyjdz(){ cout << "Wracaj szybko" << endl;
    logs << "----------- ZAMKNIECIE GRY" << endl;
    exit(0);
}

void menu::display_ending(Pet pet) {
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