#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Insert(Elem*& L, Info value);
void Print(Elem* L);
bool Process(Elem* L);
int Count(Elem* L);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* L = NULL;

	Info value, N;

	do
	{
		cout << "Введіть кількість елементів списку: "; cin >> N;
	} while (N < 0);

	for (int i = 0; i < N; i++)
	{
		cout << "Введіть дані: "; cin >> value;
		Insert(L, value);
	}

	cout << "Елементи черги: "; Print(L); cout << endl;

	cout << "Рузультат: ";
	if (Process(L) == true) { cout << "Так!"; }
	else { cout << "Ні"; }

	return 0;
}
void Insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link;

		T->link = tmp;
	}
	else
		L = tmp;

	tmp->link = L;
}
void Print(Elem* L)
{
	if (L == NULL)
		return;

	Elem* first = L;
	cout << L->info << " ";
	while (L->link != first)
	{
		L = L->link;
		cout << L->info << " ";
	}
}
bool Process(Elem* L)
{
	int count = 0,
		number_of_elements = Count(L),
		cur_poss = 0;

	if (number_of_elements == 1)
		return false;

	Info curent,
		next;

	while (cur_poss < number_of_elements - 1)
	{
		curent = L->info;
		L = L->link;
		next = L->info;
		if (next >= curent)
			count++;
		cur_poss++;
	}
	if (count == number_of_elements - 1)
		return true;
	else
		return false;
}
int Count(Elem* L)
{
	if (L == NULL)
		return 0;

	Elem* first = L;
	int k = 1;
	while (L->link != first)
	{
		k++;
		L = L->link;
	}
	return k;
}