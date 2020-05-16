#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

//базовый класс деньги
class c_money
{
	long rubli_; //рубли
	unsigned char kopeyki_; //копейки
public:

	//конструктор без параметров
	c_money()
	{
		rubli_ = 0;
		kopeyki_ = 0;
	}

	void read()
	{
		cout << "Рубли -> ";
		cin >> rubli_;
		cout << "Копейки -> ";
		int t;
		cin >> t;
		kopeyki_ = t;
	}

	//конструктор с параметрами
	c_money(int rubli, int kopeyki)
	{
		rubli_ = rubli;
		kopeyki_ = kopeyki;
	}

	//функция конвертации в копейки
	int convert_to_kopeyki()
	{
		return rubli_ * 100 + kopeyki_;
	}

	//функция конвертации из копеек
	void convert_from_kopeyki(int kop)
	{
		rubli_ = kop / 100;
		kopeyki_ = kop % 100;
	}

	//функция сложения
	void plus(int kop)
	{
		convert_from_kopeyki(convert_to_kopeyki() + kop);
	}

	//метод добавления денег к деньгам
	void plus(c_money* m)
	{
		plus(m->convert_to_kopeyki());
	}

	//функция вычитания
	void minus(int kop)
	{
		convert_from_kopeyki(convert_to_kopeyki() - kop);
	}

	//метод вычитания денег из денег
	void minus(c_money* m)
	{
		minus(m->convert_to_kopeyki());
	}

	//деление на N частей
	void divide(int n)
	{
		this->convert_from_kopeyki(convert_to_kopeyki() / n);
	}

	//деление на дробное число
	void divide(float n)
	{
		this->convert_from_kopeyki((int)(convert_to_kopeyki() / n));
	}

	//умножение на дробное число
	void multiply(float n)
	{
		this->convert_from_kopeyki((int)(convert_to_kopeyki() * n));
	}

	//функция сравнения
	int compare(c_money* m)
	{
		int my_cop = convert_to_kopeyki();
		int sec_cop = m->convert_to_kopeyki();

		if (my_cop < sec_cop)
		{
			return -1;
		}
		else if (my_cop > sec_cop)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	//функция вывода
	string toString()
	{
		string s;
		if (rubli_ < 10)
		{
			s += "0"; //если рублей только на 1 цифру, выводим дополнительный 0
		}
		s += to_string(rubli_) + ",";
		if ((int)kopeyki_ < 10)
		{
			s += "0"; //если копеек только на 1 цифру, выводим дополнительный 0
		}
		s += to_string(static_cast<int>(kopeyki_)) + "к\n";
		return s;
	}
};


int main()
{
	setlocale(LC_ALL, "russian");

	//Создаём изначальную сумму
	//-------------------------
	cout << "Введите изначальную сумму: " << endl;

	c_money* m = new c_money();
	m->read();
	cout << m->toString();
	//-------------------------

	//Обрабатываем сложение
	//---------------------
	cout << "Введите сумму для сложения: " << endl;

	c_money* m2 = new c_money();
	m2->read();
	cout << m2->toString();

	m->plus(m2);
	cout << m->toString();
	//---------------------

	//Обрабатываем вычитание
	//---------------------
	cout << "Введите сумму для вычитания: " << endl;

	m2 = new c_money();
	m2->read();
	cout << m2->toString();

	m->minus(m2);
	cout << m->toString();
	//----------------------

	//Обрабатываем деление на N частей
	//--------------------------------
	int n;
	cout << "Введите количество частей, на которое разделить деньги -> ";
	cin >> n;

	m->divide(n);
	cout << m->toString();
	//--------------------------------


	//Обрабатываем деление на дробное число
	//-------------------------------------
	float floating_number;
	cout << "Введите дробное число, на которое разделить деньги -> ";
	cin >> floating_number;

	m->divide(floating_number);
	cout << m->toString();
	//-------------------------------------

	//Обрабатываем умножение на дробное число
	//---------------------------------------
	cout << "Введите дробное число, на которое умножить деньги -> ";
	cin >> floating_number;

	m->multiply(floating_number);
	cout << m->toString();
	//---------------------------------------

	//Обрабатываем сравнение
	//----------------------
	cout << "Введите сумму для сравнения: " << endl;

	m2 = new c_money();
	m2->read();
	cout << m2->toString();

	int compare_result = m->compare(m2);
	if (compare_result == 1)
	{
		cout << "Первая сумма больше" << endl;
	}
	else if (compare_result == -1)
	{
		cout << "Первая сумма меньше" << endl;
	}
	else
	{
		cout << "Суммы равны" << endl;
	}
	//----------------------

	system("pause");
	return 0;
}
