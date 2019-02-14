#include <iostream>
#include <conio.h>
#include <windows.h>
#include <locale> 

//Used namespace std since I only had 1 custom method
using namespace std;

int getposition(const char *, size_t, char);

int main() {

	#pragma region Variables
		const int TI = 150;
		const int TA = TI * 3;
		const int SPACE = TI * 5;

		char entry[256];

		const char letters[40] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', ';', ' ' };
		const int beeps[40][6] = {
			/*A*/{TI, TA, 0,0,0,0},
			/*B*/{TA, TI, TI, TI, 0,0},
			/*C*/{TA, TI, TA, TI, 0,0},
			/*D*/{TA, TI, TI, 0,0,0},
			/*E*/{TI, 0,0,0,0,0},
			/*F*/{TI, TI, TA, TI,0,0},
			/*G*/{TA, TA, TI, 0,0,0},
			/*H*/{TI, TI, TI, TI, 0,0},
			/*I*/{TI, TI, 0,0,0,0},
			/*J*/{TI, TA, TA, TA, 0,0},
			/*K*/{TA, TI, TA, 0,0,0},
			/*L*/{TI, TA, TI, TI, 0,0},
			/*M*/{TA, TA, 0,0,0,0},
			/*N*/{TA, TI, 0,0,0,0},
			/*O*/{TA, TA, TA, 0,0,0},
			/*P*/{TI, TA, TA, TI, 0,0},
			/*Q*/{TA, TA, TI, TA, 0,0},
			/*R*/{TI, TA, TI, 0,0,0},
			/*S*/{TI, TI, TI, 0,0,0},
			/*T*/{TA, 0,0,0,0,0},
			/*U*/{TI, TI, TA, 0,0,0},
			/*V*/{TI, TI, TI, TA, 0,0},
			/*W*/{TI, TA, TA, 0,0,0},
			/*X*/{TA, TI, TI, TA, 0,0},
			/*Y*/{TA, TI, TA, TA, 0,0},
			/*Z*/{TA, TA, TI, TI, 0,0},
			/*0*/{TA, TA, TA, TA, TA, 0},
			/*1*/{TI, TA, TA, TA, TA, 0},
			/*2*/{TI, TI, TA, TA, TA, 0},
			/*3*/{TI, TI, TI, TA, TA, 0},
			/*4*/{TI, TI, TI, TI, TA, 0},
			/*5*/{TI, TI, TI, TI, TI, 0},
			/*6*/{TA, TI, TI, TI, TI, 0},
			/*7*/{TA, TA, TI, TI, TI, 0},
			/*8*/{TA, TA, TA, TI, TI, 0},
			/*9*/{TA, TA, TA, TA, TI, 0},
			/*.*/{TI, TA, TI, TA, TI, TA},
			/*,*/{TA, TA, TI, TI, TA, TA},
			/*;*/{TA, TI, TA, TI, TA, TI}
		};
	#pragma endregion

	#pragma region Main Fonction

		//Ask for entry
		cout << "Please enter text: ";

		//Take int the entry line
		cin.getline(entry, 256);

		locale loc;
		for (int count = 0; count < strlen(entry); count++) {
			char &c = entry[count];
			c = tolower(c, loc);
			int index = getposition(letters, sizeof(letters), c);

			if (c == ' ') {
				Sleep(SPACE);
			}
			else {

				for (int i = 0; i < 6; i++) {

					cout << "Length of code: " << beeps[index][i] << endl;
					Beep(250, beeps[index][i]);

					if (beeps[index][i] != 0)
						Sleep(TI);
				}
			}

		}

		_getch();
		return 0;
	#pragma endregion

}

#pragma region Extra Functions

//Get position in letters array from the entry character
int getposition(const char *array, size_t size, char c)
{
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] == c)
			return (int)i;
	}
	return -1;
}
#pragma endregion
