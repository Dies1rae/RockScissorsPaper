#include<iostream>
#include<string>
#include<ctime>
#include<Windows.h>
#include <conio.h>
using namespace std;



// ----------------DIES_IRAE------------KEYB CLEANER
void clearKeyboardBuffer() {
	while (_kbhit()) {
		_getche();
	}
}
// ----------------DIES_IRAE------------KEYB CLEANER



/* Макроопределение для функции, задающей заголовок программы */
#define SetCmdTitle SetConsoleTitleA

/* Прототип функции для очистки консоли */
inline void ClearConsoleLog(void);

/* Генерация случайного жеста для компьютера */
int GenerateRandomSign(const int MIN_RANGE = 1, const int MAX_RANGE = 3)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int randomSign = ((rand() % MAX_RANGE) + MIN_RANGE);

	return randomSign;
}

/* Структура, хранящая переменные, которые отвечают за наименования игровых жестов */
struct MySign
{
	const string strRock = "ROCK!";
	const string strPaper = "PAPER!";
	const string strScissors = "SCISSORS!";
};
MySign ms;

/* Структура, хранящая переменные, которые отвечают за игроков */
struct Players
{
	int user;
	string username;
	int computer;
	Players() {
		this->user = 0;
		this->username = "";
		this->computer = 0;
	}
	void set_username(string NAME) {
		this->username = NAME;
	}
};
Players* players = new Players();


/* Отрисовка таблицы с перечислением игровых жестов */
void DrawTable()
{
	cout << "\t\t\t\t\t +-------------------------------+" << endl;
	cout << "\t\t\t\t\t | 1.Rock | 2.Paper | 3.Scissors |" << endl;
	cout << "\t\t\t\t\t +-------------------------------+" << endl;
}

/* Ход игрока */
int UserThrow(int& user)
{
	switch (user)
	{
	case 1:
		cout << "You choose: " << ms.strRock << endl;
		break;
	case 2:
		cout << "You choose: " << ms.strPaper << endl;
		break;
	case 3:
		cout << "You choose: " << ms.strScissors << endl;
		break;
	default:
		cout << "Invalid sign!" << endl;
		break;
	}

	return user;
}

/* Ход компьютера */
int ComputerThrow(int& computer)
{
	computer = GenerateRandomSign();
	switch (computer)
	{
	case 1:
		cout << ms.strRock << endl;
		break;
	case 2:
		cout << ms.strPaper << endl;
		break;
	case 3:
		cout << ms.strScissors << endl;
		break;
	default:
		cout << "Invalid sign!" << endl;
		break;
	}

	return computer;
}

/* Выбор победителя */
void SelectWinner(int& user, int& computer, string* username)
{
	if (user == computer)
		cout << "\t\t\t\t\t\t DRAW!" << endl;
	else if (user == 1 && computer == 3)
		cout << "\t\t\t\t\t\t " << (*username) << " WIN!" << endl;
	else if (user == 3 && computer == 2)
		cout << "\t\t\t\t\t\t " << (*username) << " WIN!" << endl;
	else if (user == 2 && computer == 1)
		cout << "\t\t\t\t\t\t " << (*username) << " WIN!" << endl;
	else
		cout << "\t\t\t\t\t\t Computer WINS!" << endl;
}

/* Информация о пользователе */
void DrawInfoAboutUser()
{
	/* Ввод данных о пользователе */
	cout << "Hey, what's your name?" << endl;
	cout << "My name is ";
	string tmpUN;
	cin >> tmpUN;
	players->set_username(tmpUN);
	cout << "You are welcome, " << players->username << "!\nEnjoy the game!" << endl;
	cout << endl;
}

/* Инициализация игровых данных */
void Initialization()
{
	/* The choice of the beginning of the game or exit from the program */
	cout << "You are ready to start the game?" << endl;
	cout << "Press 'F1' to start \nPress 'F2' to quit" << endl;

	for (/*int i = 0*/; /*i < 1*/; /*i++*/)
	{
		if (GetAsyncKeyState(VK_F1) != 0)
		{
			/* Clear the screen from past data */
			ClearConsoleLog();

			/* Player Turn */
			players->user = 0;
			//----------------DIES_IRAE------------
			clearKeyboardBuffer();
			// ----------------DIES_IRAE------------
			DrawTable();
			cout << "Choose: ";
			cin >> players->user;
			UserThrow(players->user);

			cout << endl;

			/* Computer running */
			players->computer = 0;
			DrawTable();
			cout << "Computer choose: ";
			ComputerThrow(players->computer);
			break;
		}
		else if (GetAsyncKeyState(VK_F2) != 0)
		{
			/* Clear the screen from past data */
			ClearConsoleLog();

			/* Exit from the program */
			cout << "Thank you for the game! \n See you later!" << endl;
			exit(EXIT_SUCCESS);
			break;
		}
	}

	/* Selection of the winner according to the outcome of the game */
	SelectWinner(players->user, players->computer, &players->username);
}
int main()
{

	/* Устанавливаем заголовок (название) для окна */
	SetCmdTitle("ROCK - PAPER - SCISSORS");

	/* Инициализация всех данных и их обработки */
	DrawInfoAboutUser();
	Initialization();

	/* Выбор для пользователя о продолжении / окончании игры */
	while (true)
	{
		string choice;
		cout << endl;
		cout << "Do you wanna trying to play this game again?" << endl;
		cout << "Yes \t No" << endl;
		cout << "Your choice: ";
		cin >> choice;

		if (choice != "YES" && choice != "yes" && choice != "Yes")
		{
			/* Очистка экрана от прошлых данных */
			ClearConsoleLog();

			/* Выход из программы */
			cout << "Thank you for the game! \n See you later!" << endl;
			exit(EXIT_SUCCESS);
			break;
		}
		else
		{
			/* Очистка экрана от прошлых данных */
			ClearConsoleLog();
			Initialization();
			break;
		}
	}

	system("pause");
	return NULL;
}

/* Функция для очистки консоли */
inline void ClearConsoleLog(void)
{
	system("cls");
}
