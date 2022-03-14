#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct Node {
	int data;
	string name;
	string fam;
	string otc;
	Node* next;
};
Node* head;
Node* tail;

void create()
{
	head = NULL;
	tail = head;
	cout << "Пустой список создан" << endl;
}

void first(int i, string name, string fam, string otc)
{
	Node* nNode = new Node;
	head = nNode;
	tail = nNode;
	nNode->data = i;
	nNode->name = name;
	nNode->fam = fam;
	nNode->otc = otc;
	nNode->next = head;
	tail->next = head;
}

void addfront()
{
	string name;
	string fam;
	string otc;
	int i = 0;
	int on = 0;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Введите информацию об участнике" << endl;
	cout << "Ключ: ";
	cin >> i;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите фамилию: ";
	cin >> fam;
	cout << "Введите отчество: ";
	cin >> otc;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Вы уверены что хотите добавить этого участника?" << endl;
	cout << "1. Да          2. Нет" << endl;
	cout << "Выберите действие: ";
	cin >> on;
	if (on == 1)
	{
		if (head == NULL)
		{
			first(i, name, fam, otc);
		}
		else
		{
			Node* nNode = new Node;
			nNode->next = head;
			nNode->data = i;
			nNode->name = name;
			nNode->fam = fam;
			nNode->otc = otc;
			head = nNode;
			tail->next = head;
		}
		cout << "Участник успешно добавлен" << endl;
	}
}

void addback()
{
	string name;
	string fam;
	string otc;
	int i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Введите информацию об участнике" << endl;
	cout << "Ключ: ";
	cin >> i;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите фамилию: ";
	cin >> fam;
	cout << "Введите отчество: ";
	cin >> otc;
	cout << "-----------------------------------------------------------------" << endl;
	int on = 0;
	cout << "Вы уверены что хотие добавить этого участника?" << endl;
	cout << "1. Да          2. Нет" << endl;
	cout << "Выберите действие: ";
	cin >> on;
	if (on == 1)
	{
		if (head == NULL)
		{
			first(i, name, fam, otc);
		}
		else
		{
			Node* nNode = new Node;
			tail->next = nNode;
			nNode->data = i;
			nNode->name = name;
			nNode->fam = fam;
			nNode->otc = otc;
			tail = nNode;
			tail->next = head;
		}
		cout << "Участник успешно добавлен" << endl;
	}
}

void delfront()
{
	if (head != NULL)
	{
		int on;
		cout << "Вы уверены что хотите удалить участниак?" << endl;
		cout << "1. Да                    2. Нет" << endl;
		cout << "Выберите действие: ";
		cin >> on;
		if (on == 1)
		{
			if (head->next == head)
				head = NULL;
			else if (head->next == tail)
			{
				delete head;
				head = tail;
				head->next = head;
			}
			else
			{
				Node* nNode = head;
				nNode = head->next;
				delete head;
				head = nNode;
			}
			cout << "Участник успешно удален";
			cout << endl;
		}
	}
	else
		cout << "В списке нечего удалять (((" << endl;

}

void delback()
{
	if (head != NULL)
	{
		int on;
		cout << "Вы уверены что хотите удалить участниак?" << endl;
		cout << "1. Да                    2. Нет" << endl;
		cout << "Выберите действие: ";
		cin >> on;
		if (on == 1)
		{
			if (head->next == head)
				head = NULL;
			else if (head->next == tail)
			{
				delete tail;
				tail = head;
				tail->next = head;
			}
			else
			{
				Node* nNode = head;
				while (nNode->next != tail)
					nNode = nNode->next;
				swap(tail, nNode);
				delete nNode;
				tail->next = head;
			}
			cout << "Участник успешно удален";
			cout << endl;
		}
	}
	else
		cout << "В списке нечего удалять (((" << endl;
}

void display()
{
	int count = 0;
	if (head != NULL)
	{
		cout << " №" << "\t|| Ключ:" << "\t|| ФИО:" << endl;
		Node* nNode = head;
		do
		{
			count++;
			cout << "[" << count << "]" << "\t|| " << nNode->data << "\t\t|| " << nNode->fam << " " << nNode->name << " " << nNode->otc << endl;
			nNode = nNode->next;
		} while (nNode != head);
		cout << "-----------------------------------------------------------------" << endl;
		if (count == 1)
			cout << "В списке " << count << " элемент" << endl;
		else if (count < 5)
			cout << "В списке " << count << " элемента" << endl;
		else
			cout << "В списке " << count << " элементов" << endl;
	}
	else if (head == NULL)
		cout << "Список пуст\n";
}

void mainfun()
{
	if (head->next != tail)
	{
		bool cycle = false;
		int a = 0;
		tail->next = head;
		Node* qNode = head;
		Node* wNode = head;
		wNode = wNode->next;
		Node* eNode = wNode;
		eNode = eNode->next;
		while (qNode != head || cycle == false)
		{
			if (wNode->data < qNode->data && wNode->data < eNode->data)
			{
				a++;
				Node* dNode = new Node;
				wNode->next = dNode;
				dNode->data = wNode->data;
				dNode->name = wNode->name;
				dNode->fam = wNode->fam;
				dNode->otc = wNode->otc;
				dNode->next = eNode;
			}
			qNode = qNode->next;
			wNode = wNode->next;
			eNode = eNode->next;
			cycle = true;
		}
		if (a > 0)
			cout << "Были созданы друзья для слабых участников" << endl;
	}
	else
		cout << "Слишком мало элементов в списке" << endl;
}

void annihilation()
{
	if (head == NULL)
		delete head;
	else if (head->next == head)
		delete head;
	else if (head->next == tail)
	{
		delete tail;
		delete head;
	}
	else
	{
		while (head->next != tail)
		{
			Node* nNode = head;
			nNode = nNode->next;
			head->next = nNode->next;
			delete nNode;
		}
		delete tail;
		delete head;
	}
	cout << "Список удален" << endl;
}

void intro()
{
	cout << "            _____     ___   __   __ __   __    ___    " << endl;
	cout << "            ||   )   |   |  ||   || ||   ||   |   |   " << endl;
	cout << "            ||   |) ||   || ||  ||  ||   ||  (     )  " << endl;
	cout << "            ||===|  ||===|| ||=||   ||===|| ((     )) " << endl;
	cout << "            ||   |) ||   || ||  ||  ||   ||  (     )  " << endl;
	cout << "            ||___)  ||   || ||   || ||   ||   |___|   " << endl;
	cout << endl;
	cout << "                        КУРСОВАЯ РАБОТА" << endl;
	cout << "       по дисциплине «Алгоритмизация и программирование»" << endl;
	cout << " на тему «Дублирование рядом элементов, у которых значение ключа" << endl;
	cout << " строго меньше значения ключа его предшествующего и последующего" << endl;
	cout << "        элементов в однонаправленном циклическим списке»" << endl;
	cout << "                   Хакимов Бахоуддин Назимович" << endl;
	cout << "                     Группа: 15.11Д-МО11/19б" << endl;
	cout << endl;
}

void end();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	intro();
	int action, choose;
	bool on = true;
	bool Node = false;
	while (on == true)
	{
		choose = 0;
		cout << "\n               МЕНЮ ВЫБОРА ДЕЙСТВИЙ";
		cout << "\n1. Создать список новый (старый список удаляется)";
		cout << "\n2. Меню добавления элемента";
		cout << "\n3. Меню удаления элемента";
		cout << "\n4. Создать друзей для участников чей ключ строго меньше предшествующего и следующего элемента";
		cout << "\n5. Удалить список c освобождением памяти";
		cout << "\n9. Показать список";
		cout << "\n0. Завершить программу (при завершении список удаляется)" << endl << endl;
		cout << "Выберите действие: ";
		cin >> action;
		if (Node == true)
			switch (action)
			{
			case 2:
				while (choose != 3)
				{
					cout << "\n1. Добавить нового участника в конец списка";
					cout << "\n2. Добавить нового участника в начало списка";
					cout << "\n3. Вернуться в меню" << endl << endl;;
					cout << "Выберите действие: ";
					cin >> choose;
					switch (choose)
					{
					case 1:
						addback();
						break;
					case 2:
						addfront();
						break;
					}
				}
				break;
			case 3:
				while (choose != 3)
				{
					cout << "\n1. Удалить первого участника списка";
					cout << "\n2. Удалить последнего участника списка";
					cout << "\n3. Вернуться в меню" << endl << endl;;
					cout << "Выберите действие: ";
					cin >> choose;
					switch (choose)
					{
					case 1:
						delfront();
						break;
					case 2:
						delback();
					}
				}
				break;
			case 4:
				mainfun();
				break;
			case 5:
				cout << "Вы уверены что хотите удалить список?" << endl;
				cout << "1. Да        2. Нет " << endl;
				cin >> choose;
				if (choose == 1)
				{
					annihilation();
					Node = false;
				}
				break;
			case 9:
				cout << "-----------------------------------------------------------------" << endl;
				display();
				cout << "-----------------------------------------------------------------" << endl;
				break;
			}
		else if (action != 1)
			cout << "Создайте список!" << endl << endl;
		// создание списка
		if (action == 1)
		{
			if (Node == true)
			{
				cout << "Вы уверены что хотите удалить старый список" << endl;
				cout << "1. Да            2. Нет" << endl;
				cout << "Выберите дейсвтие: ";
				cin >> choose;
				if (choose == 1)
				{
					annihilation();
					create();
					Node = true;
				}
			}
			else
			{
				create();
				Node = true;
			}
		}
		// выход из программы
		if (action == 0)
		{
			cout << "Вы уверены что хотите выйти?" << endl;
			cout << "1. Выход из программы    2. Вернуться" << endl;
			cin >> choose;
			if (choose == 1)
				on = false;
			if (Node == true)
				annihilation();
		}
	}
	end();
	return 0;
}

void end()
{
	cout << endl;
	cout << "For my valentine" << endl;
	cout << "I know, I can't be with you, I just want to say you" << endl;
	cout << "Never give up, do your best and don't lock back" << endl;
}

