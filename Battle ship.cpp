#include<iostream> 
#include <windows.h>  
using namespace std;

const int size = 10;
void Random_ship(char map1[][10], char map2[][10], const int size) {
	srand(time(NULL));
	int ship1 = 14;
	int ship2 = 14;
	int x = rand() % 2;
	cout << "Your map:" << endl;
	if (x == 0)
	{
		for (int i = 0; i < size; i++) {
			for (int k = 0; k < size; k++) {
				if (k <= 0 && i < 5 || k == 5 && i>5 && i < 10 || i == 0 && k>6 && k < 10 || i == 9 && k>6 && k < 9) {
					map1[i][k] = 'G';
				}
				else {
					map1[i][k] = '*';
				}
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}
	}
	else if (x == 1) {
		for (int i = 0; i < size; i++) {
			for (int k = 0; k < size; k++) {
				if (i == 6 && k > 4 && k < 10 || i == 1 && k < 4 || k == 9 && i < 3 || k == 6 && i < 2) {
					map1[i][k] = 'G';
				}
				else {
					map1[i][k] = '*';
				}
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}
	}

	cout << "\nComputer map:" << endl;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t k = 0; k < size; k++)
		{
			map2[i][k] = '*';
			cout << map2[i][k] << " ";
		}
		cout << endl;
	}

	if (x == 0)
	{
		for (int i = 0; i < size; i++) {
			for (int k = 0; k < size; k++) {
				if (k == 3 && i < 5 || i == 6 && k < 4 || k == 9 && i < 3 || k == 6 && i >5 && i < 8) {
					map2[i][k] = 'G';
				}
				else {
					map2[i][k] = '*';
				}
			}
		}
	}
	else if (x == 1) {
		for (int i = 0; i < size; i++) {
			for (int k = 0; k < size; k++) {
				if (i == 6 && k > 4 && k < 10 || k == 1 && i>5 && i < 10 || i == 0 && k>6 && k < 10 || i == 9 && k>6 && k < 9) {
					map2[i][k] = 'G';
				}
				else {
					map2[i][k] = '*';
				}

			}
		}
	}
}

void Manual_ship(char map1[][10], char map2[][10], const int size) {
	int choice5;
	cout << "Enter choice(1-Straight ship,2-Crooked ship): ";
	cin >> choice5;

	if (choice5 == 1) {
		// 5-ship
		int x, y;
		cout << "Enter horizontal for 5-ship (0-5): ";
		cin >> y;
		cout << "Enter vertical for 5-ship (0-5): ";
		cin >> x;

		while (true) {
			if (x >= 0 && x < size && y >= 0 && y < 6) {
				bool canPlace = true;
				for (int j = 0; j < 5; j++) {
					if (map1[y][x + 1] == 'G' || map1[y + 1][x] == 'G' || map1[y][x - 1] == 'G' || map1[y - 1][x] == 'G') {
						canPlace = false;
						break;
					}
				}
				if (canPlace) {
					for (int j = 0; j < 5; j++) {
						map1[y + j][x] = 'G';
					}
					break;
				}
				else {
					cout << "Invalid coordinates or cells already occupied" << endl;
				}
			}
			else {
				cout << "Invalid coordinates" << endl;
			}
			cout << "Enter horizontal for 5-ship (0-5): ";
			cin >> y;
			cout << "Enter vertical for 5-ship (0-5): ";
			cin >> x;
		}

		cout << "Current state of the map:" << endl;
		for (size_t i = 0; i < size; i++) {
			for (size_t k = 0; k < size; k++) {
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}

		// 4-ship
		int x1, y1;
		cout << "Enter horizontal for 4-ship (0-6): ";
		cin >> y1;
		cout << "Enter vertical for 4-ship (0-6): ";
		cin >> x1;
		system("cls");

		while (true) {
			if (x1 >= 0 && x1 < size && y1 >= 0 && y1 < 7) {
				bool canPlace = true;
				for (int j = 0; j < 4; j++) {
					if (map1[y1][x1 + 1] == 'G' || map1[y1 + 1][x1] == 'G' || map1[y1][x1 - 1] == 'G' || map1[y1 - 1][x1] == 'G') {
						canPlace = false;
						break;
					}
				}
				if (canPlace) {
					for (int j = 0; j < 4; j++) {
						map1[y1 + j][x1] = 'G';
					}
					break;
				}
				else {
					cout << "Invalid coordinates or cells already occupied" << endl;
				}
			}
			else {
				cout << "Invalid coordinates" << endl;
			}
			cout << "Enter horizontal for 4-ship (0-6): ";
			cin >> y1;
			cout << "Enter vertical for 4-ship (0-6): ";
			cin >> x1;
		}

		cout << "Current state of the map:" << endl;
		for (size_t i = 0; i < size; i++) {
			for (size_t k = 0; k < size; k++) {
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}

		// 3-ship
		int x2, y2;
		cout << "Enter horizontal for 3-ship (0-7): ";
		cin >> y2;
		cout << "Enter vertical for 3-ship (0-7): ";
		cin >> x2;

		while (true) {
			if (x2 >= 0 && x2 < size && y2 >= 0 && y2 < 8) {
				bool canPlace = true;
				for (int j = 0; j < 3; j++) {
					if (map1[y2][x2 + 1] == 'G' || map1[y2 + 1][x2] == 'G' || map1[y2][x2 - 1] == 'G' || map1[y2 - 1][x2] == 'G') {
						canPlace = false;
						break;
					}
				}
				if (canPlace) {
					for (int j = 0; j < 3; j++) {
						map1[y2 + j][x2] = 'G';
					}
					break;
				}
				else {
					cout << "Invalid coordinates or cells already occupied" << endl;
				}
			}
			else {
				cout << "Invalid coordinates" << endl;
			}
			cout << "Enter horizontal for 3-ship (0-7): ";
			cin >> y2;
			cout << "Enter vertical for 3-ship (0-7): ";
			cin >> x2;
		}

		cout << "Current state of the map:" << endl;
		for (size_t i = 0; i < size; i++) {
			for (size_t k = 0; k < size; k++) {
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}

		// 2-ship
		int x3, y3;
		cout << "Enter horizontal for 2-ship (0-8): ";
		cin >> y3;
		cout << "Enter vertical for 2-ship (0-8): ";
		cin >> x3;

		while (true) {
			if (x3 >= 0 && x3 < size && y3 >= 0 && y3 < 9) {
				bool canPlace = true;
				for (int j = 0; j < 2; j++) {
					if (map1[y3][x3 + 1] == 'G' || map1[y3 + 1][x3] == 'G' || map1[y3][x3 - 1] == 'G' || map1[y3 - 1][x3] == 'G') {
						canPlace = false;
						break;
					}
				}
				if (canPlace) {
					for (int j = 0; j < 2; j++) {
						map1[y3 + j][x3] = 'G';
					}
					break;
				}
				else {
					cout << "Invalid coordinates or cells already occupied" << endl;
				}
			}
			else {
				cout << "Invalid coordinates" << endl;
			}
			cout << "Enter horizontal for 2-ship (0-8): ";
			cin >> y3;
			cout << "Enter vertical for 2-ship (0-8): ";
			cin >> x3;
		}

		cout << "Current state of the map:" << endl;
		for (size_t i = 0; i < size; i++) {
			for (size_t k = 0; k < size; k++) {
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}
	}
	else if (choice5 == 2) {
		// 5-ship
		int x, y;
		cout << "Enter horizontal for 5-ship (0-5): ";
		cin >> y;
		cout << "Enter vertical for 5-ship (0-5): ";
		cin >> x;

		while (true) {
			if (x >= 0 && x < 6 && y >= 0 && y < size) {
				bool canPlace = true;
				for (int j = 0; j < 5; j++) {
					if (map1[y][x + j] == 'G' || map1[y + 1][x] == 'G' || map1[y][x - 1] == 'G' || map1[y - 1][x] == 'G' ||
						map1[y][x + j + 1] == 'G' || map1[y + 1][x + j] == 'G' || map1[y][x + j - 1] == 'G' || map1[y - 1][x + j] == 'G') {

						canPlace = false;
						break;
					}
				}
				if (canPlace) {
					for (int j = 0; j < 5; j++) {
						map1[y][x + j] = 'G';
					}
					break;
				}
				else {
					cout << "Invalid coordinates or cells already occupied" << endl;
				}
			}
			else {
				cout << "Invalid coordinates" << endl;
			}
			cout << "Enter horizontal for 5-ship (0-5): ";
			cin >> y;
			cout << "Enter vertical for 5-ship (0-5): ";
			cin >> x;
		}

		cout << "Current state of the map:" << endl;
		for (size_t i = 0; i < size; i++) {
			for (size_t k = 0; k < size; k++) {
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}

		// 4-ship

		int x1, y1;
		cout << "Enter horizontal for 4-ship (0-6): ";
		cin >> y1;
		cout << "Enter vertical for 4-ship (0-6): ";
		cin >> x1;
		system("cls");

		while (true) {
			if (x1 >= 0 && x1 < 7 && y1 >= 0 && y1 < size) {
				bool canPlace = true;
				for (int j = 0; j < 4; j++) {
					if (map1[y1][x1 + j] == 'G' || map1[y1 + 1][x1] == 'G' || map1[y1][x1 - 1] == 'G' || map1[y1 - 1][x1] == 'G' ||
						map1[y1][x1 + j + 1] == 'G' || map1[y1 + 1][x1 + j] == 'G' || map1[y1][x1 + j - 1] == 'G' || map1[y1 - 1][x1 + j] == 'G') {
						canPlace = false;
						break;

					}
				}
				if (canPlace) {
					for (int j = 0; j < 4; j++) {
						map1[y1][x1 + j] = 'G';
					}
					break;
				}
				else {
					cout << "Invalid coordinates or cells already occupied" << endl;
				}

			}
			else {
				cout << "Invalid coordinates" << endl;
			}
			cout << "Enter horizontal for 4-ship (0-6): ";
			cin >> y1;
			cout << "Enter vertical for 4-ship (0-6): ";
			cin >> x1;

		}
		cout << "Current state of the map:" << endl;
		for (size_t i = 0; i < size; i++) {
			for (size_t k = 0; k < size; k++) {
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}
		// 3-ship
		int x2, y2;
		cout << "Enter horizontal for 3-ship (0-7): ";
		cin >> y2;
		cout << "Enter vertical for 3-ship (0-7): ";
		cin >> x2;
		system("cls");
		while (true) {
			if (x2 >= 0 && x2 < 8 && y2 >= 0 && y2 < size) {
				bool canPlace = true;
				for (int j = 0; j < 3; j++) {
					if (map1[y2][x2 + j] == 'G' || map1[y2 + 1][x2] == 'G' || map1[y2][x2 - 1] == 'G' || map1[y2 - 1][x2] == 'G' ||
						map1[y2][x2 + j + 1] == 'G' || map1[y2 + 1][x2 + j] == 'G' || map1[y2][x2 + j - 1] == 'G' || map1[y2 - 1][x2 + j] == 'G') {
						canPlace = false;
						break;
					}
				}
				if (canPlace) {
					for (int j = 0; j < 3; j++) {
						map1[y2][x2 + j] = 'G';
					}
					break;
				}
				else {
					cout << "Invalid coordinates or cells already occupied" << endl;
				}
			}
			else {
				cout << "Invalid coordinates" << endl;
			}
			cout << "Enter horizontal for 3-ship (0-7): ";
			cin >> y2;
			cout << "Enter vertical for 3-ship (0-7): ";
			cin >> x2;
		}

		cout << "Current state of the map:" << endl;
		for (size_t i = 0; i < size; i++) {
			for (size_t k = 0; k < size; k++) {
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}

		// 2-ship
		int x3, y3;
		cout << "Enter horizontal for 2-ship (0-8): ";
		cin >> y3;
		cout << "Enter vertical for 2-ship (0-8): ";
		cin >> x3;
		system("cls");
		while (true) {
			if (x3 >= 0 && x3 < 9 && y3 >= 0 && y3 < size) {
				bool canPlace = true;
				for (int j = 0; j < 2; j++) {
					if (map1[y3][x3 + j] == 'G' || map1[y3 + 1][x3] == 'G' || map1[y3][x3 - 1] == 'G' || map1[y3 - 1][x3] == 'G' ||
						map1[y3][x3 + j + 1] == 'G' || map1[y3 + 1][x3 + j] == 'G' || map1[y3][x3 + j - 1] == 'G' || map1[y3 - 1][x3 + j] == 'G') {
						canPlace = false;
						break;
					}
				}
				if (canPlace) {
					for (int j = 0; j < 2; j++) {
						map1[y3][x3 + j] = 'G';
					}
					break;
				}
				else {
					cout << "Invalid coordinates or cells already occupied" << endl;
				}
			}
			else {
				cout << "Invalid coordinates" << endl;
			}
			cout << "Enter horizontal for 2-ship (0-8): ";
			cin >> y3;
			cout << "Enter vertical for 2-ship (0-8): ";
			cin >> x3;
		}

		cout << "Current state of the map:" << endl;
		for (size_t i = 0; i < size; i++) {
			for (size_t k = 0; k < size; k++) {
				cout << map1[i][k] << " ";
			}
			cout << endl;
		}
	}

	cout << "\nComputer map:" << endl;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t k = 0; k < size; k++)
		{
			map2[i][k] = '*';
			cout << map2[i][k] << " ";
		}
		cout << endl;
	}
	int x = rand() % 2;

	if (x == 0)
	{
		for (int i = 0; i < size; i++) {
			for (int k = 0; k < size; k++) {
				if (k == 3 && i < 5 || i == 6 && k < 4 || k == 9 && i < 3 || k == 6 && i >5 && i < 8) {
					map2[i][k] = 'G';
				}
				else {
					map2[i][k] = '*';
				}
			}
		}
	}
	else if (x == 1) {
		for (int i = 0; i < size; i++) {
			for (int k = 0; k < size; k++) {
				if (i == 6 && k > 4 && k < 10 || k == 1 && i>5 && i < 10 || i == 0 && k>6 && k < 10 || i == 9 && k>6 && k < 9) {
					map2[i][k] = 'G';
				}
				else {
					map2[i][k] = '*';
				}

			}
		}
	}
}

void SetConsoleColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Attack(char map1[][10], char map2[][10], const int size, int lastHitX, int lastHitY) {
	bool alreadyHit[10][10] = { false };
	bool alreadyHitPlayer[10][10] = { false };
	int playerShips = 14;
	int computerShips = 14;
	int x, y;

	while (playerShips > 0 && computerShips > 0) {
		cout << "Enter horizontal (0-9): ";
		cin >> y;
		cout << "Enter vertical (0-9): ";
		cin >> x;

		if (0 <= y && 0 <= x && y < 10 && x < 10) {

			if (alreadyHit[y][x]) {
				SetConsoleColor(12);
				cout << "Same cordinate!" << endl;
				continue;
			}
			system("cls");
			if (map2[y][x] == 'G') {
				SetConsoleColor(10);
				cout << "Player Hit!" << endl;
				map2[y][x] = 'x';
				computerShips--;
			}
			else if (map2[y][x] != 'G' && map2[y][x] != 'x') {
				SetConsoleColor(12);
				cout << "Player Miss!" << endl;
				map2[y][x] = '!';
			}
			SetConsoleColor(7);

			alreadyHit[y][x] = true;
			if (0 < lastHitY && lastHitY < 10 && 0 < lastHitX && lastHitX < 10) {
				int direction = rand() % 4;

				switch (direction) {
				case 0:
					x = lastHitX + 1;
					y = lastHitY;
					break;
				case 1:
					x = lastHitX;
					y = lastHitY + 1;
					break;
				case 2:
					x = lastHitX - 1;
					y = lastHitY;
					break;
				case 3:
					x = lastHitX;
					y = lastHitY - 1;
					break;
				}
			}

			else {
				do {
					x = rand() % 10;
					y = rand() % 10;
				} while (alreadyHitPlayer[y][x] || map2[y][x] == 'x');

			}
			if (alreadyHitPlayer[y][x]) {
				SetConsoleColor(12);
				cout << "Computer same coordinate!\n";
				do {
					x = rand() % 10;
					y = rand() % 10;
				} while (alreadyHitPlayer[y][x] || map1[y][x] == 'x');
				
			}

			if (map1[y][x] == 'G') {
				SetConsoleColor(10);
				cout << "Computer Hit!" << endl;
				map1[y][x] = 'x';
				lastHitX = x;
				lastHitY = y;
				playerShips--;
			}
			else {
				SetConsoleColor(12);
				cout << "Computer Miss!" << endl;
				map1[y][x] = '!';
				lastHitX = -1;
				lastHitY = -1;
			}
			alreadyHitPlayer[y][x] = true;

			SetConsoleColor(7);
			for (size_t i = 0; i < size; i++)
			{
				for (size_t k = 0; k < size; k++)
				{
					if (map1[i][k] == 'x') {
						SetConsoleColor(10);
					}
					else if (map1[i][k] == '!') {
						SetConsoleColor(12);

					}
					cout << map1[i][k] << " ";
					SetConsoleColor(7);
				}
				cout << endl;
			}

			cout << endl;
			cout << "Horizontal: " << y << endl;
			cout << "Vertical: " << x << endl;
			cout << endl;
			for (size_t i = 0; i < size; i++) {
				for (size_t k = 0; k < size; k++) {
					if (map2[i][k] == 'x') {
						SetConsoleColor(10);
					}
					else if (map2[i][k] == '!') {
						SetConsoleColor(12);

					}

					else if (map2[i][k] == 'G') {
						cout << "* ";
						continue;
					}
					cout << map2[i][k] << " ";

					SetConsoleColor(7);
				}
				cout << endl;
			}
		}
		else {
			SetConsoleColor(12);
			cout << "Invalid input! " << endl;

		}
	}
	if (playerShips == 0) {
		SetConsoleColor(10);
		cout << "Computer Wins!" << endl;
	}
	else if (computerShips == 0) {
		SetConsoleColor(10);
		cout << "Player Wins!" << endl;
	}

}
void Start() {
	int choice1;
	cout << "1. Arrange the ships randomly\n";
	cout << "2. Arrange the ships manually\n";
	cout << "Enter choice: ";
	cin >> choice1;
	const int size = 10;
	char map1[size][size]{};
	char map2[size][size]{};
	int lastHitX = -1;
	int lastHitY = -1;
	if (choice1 == 1) {
		Random_ship(map1, map2, size);
		Attack(map1, map2, size, lastHitX, lastHitY);
	}
	else if (choice1 == 2) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				map1[i][j] = '*';
			}
		}
		Manual_ship(map1, map2, size);
		Attack(map1, map2, size, lastHitX, lastHitY);
	}
}
void About_game() {
	cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~Battle ship~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Our game has a menu and there are 3 options in the menu:\n"
		"If you choose 1, it starts the game. If you choose 2, it allows you to manually arrange the ships.\n"
		"If you choose 3, it exits the game.\n"
		"The game is between the PC and you, and you shoot the ships based on coordinates.\n"
		"When you hit the ship, it turns green, and when you can't hit it, it turns red.\n";
}
void main() {
	while (true) {
		int choice;
		cout << "1. Start the game\n";
		cout << "2. Information about the game\n";
		cout << "3. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		if (choice == 1) {
			Start();
		}
		else if (choice == 2) {
			About_game();
		}
		else if (choice == 3) {
			cout << "Good bye";
		}
		break;
	}
}