#include "header.h"
#include "menu.h"
#include "pet.h"
#include "RPS.h"
#include "extern.h"

ofstream logs("log.txt");
Pet pet;

int main()
{
	logs << "----------- URUCHOMIENIE GRY" << endl;
	menu menu1;
	
	
	auto check = [&menu1]() {
		if ((pet.GetAge() > 10) || (pet.getSickness() && pet.GetMood() > 30)) {
			menu1.display_ending();
		}
	};
	
	menu1.display_menu();
	int choice;
	
	do
	{
		system("CLS");
		cout << menu1.set_back() << endl;
		cout << "\n0 - Wyjdz z gry\n";
		cout << "1 - Porozmawiaj z petem\n";
		cout << "2 - Nakarm peta\n";
		cout << "3 - Pobaw sie z petem\n";
		cout << "4 - Wyswietl wiek\n";
		cout << "5 - Daj lekarstwo\n";
		cout << "6 - Wyswietl statystkyki\n\n";
		cout << "Wybor: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << pet.GetName() << ": Good-bye!\n";
			
			pet.Zapis();

			break;
		case 1:
			pet.Talk();
			system("pause");
			check();
			break;
		case 2:
			pet.Eat();
			system("pause");
			check();
			break;
		case 3:
			cout << "(1) zwykla zabawa" << endl;
			cout << "(2) walka" << endl;
			cout << "(3) przebiez peta" << endl;
			int tmp;
			cin >> tmp;
			if(tmp == 1)pet.Play();
			if (tmp == 2) {
				srand(time(NULL));
				RPS gra;
				bool winner = gra.winner();
				if (winner) {
					cout << "ZWYCIESTWO!!" << endl;
					cout << "obnizowno glod peta oraz pozion znudzenia" << endl;
					pet--;
				}
				else {
					cout << "Przegrales" << endl;
					cout << "Twoj pet jest chory" << endl;
					pet.Set_sickness(1);
				}
				pet.PassTime();
			}
			if (tmp == 3) {
				pet.ChangeDress();
				pet.PassTime();
			}
			system("pause");
			check();
			if (tmp != 1 && tmp != 2 && tmp != 3) break;
			break;
		case 4:
			pet.HowOld();
			system("pause");
			check();
			break;
		case 5:
			pet.Medicine();
			system("pause");
			check();
			break;
		case 6:
			pet.DisplayStats();
			system("pause");
			break;
		default:
			cout << "Twoj wybor: " << choice << " jest nieprawidlowy\n";
			system("pause");
		}

	} while (choice != 0);
	logs.close();
	return 0;
}