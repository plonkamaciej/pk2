#include "RPS.h"
#include "extern.h"
#include "header.h"

void RPS::Fmenu() {
	logs << "uruchomiono funkcje RPS::FMENU" << endl;
	system("CLS");
	cout << "zycie peta: " << hero.getHP() << endl;
	cout << "zycie przeciwnika: " << enemy.getHP() << endl;
	cout << "wybierz bron: " << endl;
	cout << "(1) miecz" << endl;
	cout << "(2) luk" << endl;
	cout << "(3) rozdzka " << endl;
}

bool RPS::winner(){
	logs << "uruchomiono funkcje RPS:WINNER" << endl;
bool herowon;
	 do {
		int enemy_weapon = rand() % 3 + 1;
		Fmenu();
		cin >> choice;
		switch (choice)
		{
		case 1: 
			if (enemy_weapon == 1) {
				cout << "remis, atakujecie sie wzajemnie..." << endl;
				enemy.Attacked(hero.ATT_ENEMY(hero.getATT()/2));
				hero.Attacked(enemy.ATT_ENEMY(enemy.getATT()/2));
			}
			if (enemy_weapon == 2) {
				cout << "atakujesz przeciwnika!" << endl;
				enemy.Attacked(hero.ATT_ENEMY(hero.getATT()));
			}
			if (enemy_weapon == 3) {
				cout << "przeciwnik atakuje!" << endl;
				hero.Attacked(enemy.ATT_ENEMY(enemy.getATT()));
			}
			system("pause");
			break;
		case 2:
			if (enemy_weapon == 2) {
				cout << "remis, atakujecie sie wzajemnie..." << endl;
				enemy.Attacked(hero.ATT_ENEMY(hero.getATT()/2));
				hero.Attacked(enemy.ATT_ENEMY(enemy.getATT()/2));
			}
			if (enemy_weapon == 3) {
				cout << "atakujesz przeciwnika!" << endl;
				enemy.Attacked(hero.ATT_ENEMY(hero.getATT()));
			}
			if (enemy_weapon == 1) {
				cout << "przeciwnik atakuje!" << endl;
				hero.Attacked(enemy.ATT_ENEMY(enemy.getATT()));
			}
			system("pause");
			break;
		case 3:
			if (enemy_weapon == 3) {
				cout << "remis, atakujecie sie wzajemnie..." << endl;
				enemy.Attacked(hero.ATT_ENEMY(hero.getATT()/2));
				hero.Attacked(enemy.ATT_ENEMY(enemy.getATT()/2));
			}
			if (enemy_weapon == 1) {
				cout << "atakujesz przeciwnika!" << endl;
				enemy.Attacked(hero.ATT_ENEMY(hero.getATT()));
			}
			if (enemy_weapon == 2) {
				cout << "przeciwnik atakuje!" << endl;
				hero.Attacked(enemy.ATT_ENEMY(enemy.getATT()));
			}
			system("pause");
			break;

		default:
			cout << "zly wybor" << endl;
			system("pause");
			break;
		}
		if (hero.getHP() > 0) herowon = 1;
		else herowon = 0;
	 } while (hero.getHP() > 0 && enemy.getHP() > 0);
	return herowon;
}