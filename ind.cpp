#include <iostream>
#include <string>
using namespace std;

int comparison(string a, string b)
{
	if (a.length() > b.length())
		return -1;
	else if (a.length() < b.length())
		return 1;
	else if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] > b[i])
				return -1;
			else if (b[i] > a[i])
				return 1;
		}
		return 0;
	}
}
void ZeroDelete(string& a)
{
	while (a[0] == '0' && a.length() > 1)
		a.erase(0, 1);
}
bool enter(string a, string b)
{
	bool a1 = true, b1 = true, f=false;
	if (a.length() > 20 && b.length() > 20)
	{
		for (int i = 0; i < a.length(); i++)
			if (!(a[i] >= 48 && a[i] <= 57))
				a1 = false;
		for (int i = 0; i < b.length(); i++)
		{
			if (!(b[i] >= 48 && b[i] <= 57))
				b1 = false;
			if (b[i] != '0')
				f = true;
		}
		if (a1 && b1 && f)
			return true;
		else return false;
	}
	else return false;
}
void revers(string& a)
{
	int temp;
	int i;
	for (i = 0; i < a.length() / 2; i++)
	{
		temp = a[i];
		a[i] = a[a.length() - 1 - i];
		a[a.length() - 1 - i] = temp;
	}
}

string Subtraction(string a, string b)
{
	revers(a);
	revers(b);
	int i = 0;
	string c = "";
	while (b.length() < a.length())
		b += "0";
	while (i < b.length())
	{
		if (a[i] >= b[i])
			c += to_string(a[i] - b[i]);
		else
		{
			int razr = i + 1;
			while (a[razr] == '0')
			{
				a[razr] = '9';
				razr++;
			}
			a[razr] = a[razr] - 1;
			c += to_string(a[i] - b[i] + 10);
		}
		i++;
	}
	revers(c);
	ZeroDelete(c);
	return c;
}
string Sum(string x, string y)
{
	revers(x);
	revers(y);
	int i = 0;
	string c = "";
	y += "0";
	x += "0";
	while (y.length() < x.length())
		y += "0";
	while (y.length() > x.length())
		x += "0";
	for (;i < y.length(); i++)
	{
		if (x[i] + y[i] - '0' - '0' < 10)
			c += to_string(x[i] + y[i] - '0' - '0');
		else
		{
			x[i + 1] = x[i + 1] + 1;
			c += to_string(x[i] + y[i] - '0' - '0' - 10);
		}
	}
	revers(c);
	ZeroDelete(c);
	return c;
}
string ColumnDivision(string x, string y)
{
	string nakrazr, delitelPROM, ostatokPROM;
	int j, size;
	while (comparison(x, y) == -1 || comparison(x, y) == 0)
	{
		size = x.length();
		ostatokPROM = "";
		nakrazr = "";
		j = 1;
		nakrazr += x[0];
		delitelPROM = "0";
		while (comparison(nakrazr, y) == 1)			// увеличиваем разряд, пока он не будет больше делителя
		{
			nakrazr += x[j];
			j++;
		}
		while (comparison(nakrazr, delitelPROM) == -1 || comparison(nakrazr, delitelPROM) == 0)  
		{
			delitelPROM = Sum(delitelPROM, y);
		}
		delitelPROM = Subtraction(delitelPROM, y);             // шаг назад
		ostatokPROM = Subtraction(nakrazr, delitelPROM);       // Промежуточный остаток
		while (j < size)
		{
			ostatokPROM += x[j];
			j++;
		}
		x = ostatokPROM;		
	}
	ZeroDelete(x);
	return x;
}
int main()
{
	setlocale(LC_ALL, "rus");
	string delimoe, delitel, ostatok = "0";
	cout << "Введите делимое: " << endl;
	cin >> delimoe;
	cout << "Введите делитель: " << endl;
	cin >> delitel;
	if (enter(delimoe, delitel))
	{
		ZeroDelete(delimoe);
		ZeroDelete(delitel);
		ostatok = ColumnDivision(delimoe, delitel);
		cout << "Остаток от деления " << delimoe << " на " << delitel << " = " << ostatok << endl;
	}
	else cout << "Проверьте правильность введенных данных!" << endl << "m,n>0, на 0 делить нельзя." << endl;
	system("pause");
}

