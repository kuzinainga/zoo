#include "pch.h"
#include <iostream>
#include <string> 
using namespace std;

// Особь в зоопарке
class ZooSpecimen
{
protected:
	// Название животного
	string AnimalName; 
	// Возраст животного
	int Age;
	// Кличка животного
	string AnimalNickName;

public:
	// Конструктор
	ZooSpecimen(std::string _animalName, int _age, std::string _animalNickName)
	{
		AnimalName = _animalName;
		Age = _age;
		AnimalNickName = _animalNickName;
	}

	// Возвращает описание животного
	string GetDescription()
	{
		string res = "Вид: " + AnimalName + +"\n";
		res += "Возраст: " + to_string(Age) + "\n";
		res += "Кличка: " + AnimalNickName + "\n";

		return res;
	}

	// Метод, который определяет, понравится ли данная особь детям
	bool ChildrenLikeIt()
	{
		// По умолчанию детям нравится всегда
		return true;
	}
};

// Водоплавающее животное - подкласс особи в зоопарке
class SwimmingAnimal : public ZooSpecimen
{
private:
	// Может показывать водное шоу
	bool CanMakeWaterShow;

public:
	// Конструктор
	SwimmingAnimal(string _animalName, int _age, string _animalNickName, bool _canMakeWaterShow) : ZooSpecimen(_animalName, _age, _animalNickName)
	{
		CanMakeWaterShow = _canMakeWaterShow;
	}

	// Переопределяем метод (полиморфизм)
	string GetDescription()
	{
		// Общее описание для всех животных
		string res = ZooSpecimen::GetDescription();

		// Специфичное только для этого вида
		res += "Может показывать водное шоу: ";
		if (CanMakeWaterShow)
		{
			res += "да\n";
		}
		else
		{
			res += "нет\n";
		}

		return res;
	}

	// Переопределяем метод (полиморфизм)
	bool ChildrenLikeIt()
	{
		// Детям понравится, если животное может показывать водное шоу
		return CanMakeWaterShow;
	}
};

// Сухопутное животное - подкласс особи в зоопарке
class LandAnimal : public ZooSpecimen
{
private:
	// Можно кормить посетителям
	bool CanBeFed;

public:
	// Конструктор
	LandAnimal(string _animalName, int _age, string _animalNickName, bool _canBeFed) : ZooSpecimen(_animalName, _age, _animalNickName)
	{
		CanBeFed = _canBeFed;
	}

	// Переопределяем метод (полиморфизм)
	string GetDescription()
	{
		// Общее описание для всех животных
		string res = ZooSpecimen::GetDescription();

		// Специфичное только для этого вида
		res += "Можно кормить: ";
		if (CanBeFed)
		{
			res += "да\n";
		}
		else
		{
			res += "нет\n";
		}

		return res;
	}


	// Переопределяем метод (полиморфизм)
	bool ChildrenLikeIt()
	{
		// Детям понравится, если животное можно кормить и оно не слишком старое
		return CanBeFed && Age < 10;
	}
};

// Змея - подкласс особи в зоопарке
class Snake : public ZooSpecimen
{
private:
	// Ядовитая ли змея
	bool IsPoisonous;

public:
	// Конструктор
	Snake(string _animalName, int _age, string _animalNickName, bool _isPoisonous) : ZooSpecimen(_animalName, _age, _animalNickName)
	{
		IsPoisonous = _isPoisonous;
	}

	// Переопределяем метод (полиморфизм)
	string GetDescription()
	{
		// Общее описание для всех животных
		string res = ZooSpecimen::GetDescription();

		// Специфичное только для этого вида
		res += "Ядовитая: ";
		if (IsPoisonous)
		{
			res += "да\n";
		}
		else
		{
			res += "нет\n";
		}

		return res;
	}

	// Переопределяем метод (полиморфизм)
	bool ChildrenLikeIt()
	{
		// Детям понравится, если змея неядовитая
		return !IsPoisonous;
	}
};

// Место в зоопарке
class ZooPlace
{
protected:
	// Порядковый номер места
	int PlaceNumber;	
	// Особи, живущие в данном месте
	ZooSpecimen *Species;

public:
	// Конструктор класса (передается количество особей, живущих в данном месте)
	ZooPlace(int _placeNumber, ZooSpecimen *_species)
	{
		Species = _species;
		PlaceNumber = _placeNumber;
	}

	// Деструктор класса
	~ZooPlace()
	{
		delete[]Species;
	}
};

// Клетка - подкласс места в зоопарке
class Cage : public ZooPlace
{
private:
	// Площадь клетки
	int CageSquare; 

public:
	// Конструктор класса - вызывается родительский конструктор
	Cage(int _placeNumber, ZooSpecimen *_species, int _cageSquare) : ZooPlace(_placeNumber, _species)
	{
		CageSquare = _cageSquare;
	}
};

// Бассейн - подкласс места в зоопарке
class Pool : public ZooPlace
{
private:
	// Объем бассейна
	int PoolVolume;

public:
	// Конструктор класса - вызывается родительский конструктор
	Pool(int _placeNumber, ZooSpecimen *_species, int _poolVolume) : ZooPlace(_placeNumber, _species)
	{
		PoolVolume = _poolVolume;
	}
};

// Террариум - подкласс места в зоопарке
class Terrarium : public ZooPlace
{
private:
	// Террариум открытого или закрытого вида
	bool IsOpened;

public:
	// Конструктор класса - вызывается родительский конструктор
	Terrarium(int _placeNumber, ZooSpecimen *_species, bool _isOpened) : ZooPlace(_placeNumber, _species)
	{
		IsOpened = _isOpened;
	}
};

// Посетитель зоопарка
class Person
{
private:
	// Имя
	string Name;
	// Возраст
	int Age;

public:
	// Другой вид инкапсуляции через аксессоры и мутаторы
	void setName(string _name)
	{
		Name = _name;
	}

	void setAge(int _age)
	{
		Age = _age;
	}

	int getAge()
	{
		return Age;
	}	
};

// Билет в зоопарк
class ZooTicket
{
public:
	// Регистрируем билет за посетителем, возвращаем стоимость билета
	int BuyTicket(Person _visitor)
	{
		Visitor = _visitor;
		return getCost();
	}

private:
	// Значения взрослого и детского тарифа (поля закрыты от вмешательства - инкапсуляция)
	int childrenTariff = 50;
	int adultTariff = 100;

	// Посетитель, купивший билет
	Person Visitor;

	// Метод, вычисляющий стоимость билета в зависимости от возраста посетителя
	int getCost()
	{
		int cost = 0;

		if (Visitor.getAge() <= 10)
		{
			cost = childrenTariff;
		}
		else
		{
			cost = adultTariff;
		}

		return cost;
	}
};


int main()
{
	// Заполняем животных, которые обитают в зоопарке
	SwimmingAnimal dolphin1 = SwimmingAnimal("Дельфин", 5, "Вениамин", true);
	SwimmingAnimal dolphin2 = SwimmingAnimal("Дельфин", 6, "Екатерина", true);
	SwimmingAnimal hippo = SwimmingAnimal("Дельфин", 20, "Василиса", false);

	LandAnimal lion = LandAnimal("Лев", 12, "Владимир", false);
	LandAnimal monkey1 = LandAnimal("Обезьяна", 3, "Игорь", true);
	LandAnimal monkey2 = LandAnimal("Обезьяна", 3, "Федор", true);

	Snake snake1 = Snake("Гремучая змея", 10, "Ирина", true);
	Snake snake2 = Snake("Полоз", 8, "Виктор", false);

	// Заполняем бассейны, клетки и террариумы
	Pool pool1 = Pool(1, new ZooSpecimen[2]{ dolphin1, dolphin2 }, 1000);
	Pool pool2 = Pool(2, new ZooSpecimen[1]{ hippo }, 800);

	Cage cage1 = Cage(3, new ZooSpecimen[1]{ lion }, 300);
	Cage cage2 = Cage(4, new ZooSpecimen[2]{ monkey1, monkey2 }, 500);

	Terrarium terr1 = Terrarium(5, new ZooSpecimen[1]{ snake1 }, false);
	Terrarium terr2 = Terrarium(6, new ZooSpecimen[1]{ snake2 }, true);

	// Все места в зоопарке
	ZooPlace *zoo = new ZooPlace[6] { pool1, pool2, cage1, cage2, terr1, terr2 };
	
	// Посетитель зоопарка
	Person visitor;
	string name;
	int age;

	cout << "Как Вас зовут?\n";
	getline(cin, name);

	cout << "Сколько Вам лет?\n";
	cin >> age;

	visitor.setName(name);
	visitor.setAge(age);

	ZooTicket ticket;
	int cost = ticket.BuyTicket(visitor);

	cout << "Стоимость Вашего билета: " << cost << "\n";

	int answer = 0;

	while (answer != 7)
	{
		cout << "Что Вы хотите сделать?\n";
		cout << "1 - Посмотреть бассейн №1. \n";
		cout << "2 - Посмотреть бассейн №2. \n";
		cout << "3 - Посмотреть клетку №3. \n";
		cout << "4 - Посмотреть клетку №4. \n";
		cout << "5 - Посмотреть террариум №5. \n";
		cout << "6 - Посмотреть террариум №6. \n";
		cout << "7 - Выйти из зоопарка. \n";

		cin >> answer;

		// Пример полиморфизма - описание животных переопределено дочерними классами
		switch (answer)
		{
		case 1:
			cout << dolphin1.GetDescription();
			cout << "***** \n";
			cout << dolphin2.GetDescription();
			cout << "***** \n";
			break;
		case 2:
			cout << hippo.GetDescription();
			cout << "***** \n";
			break;
		case 3:
			cout << lion.GetDescription();
			cout << "***** \n";
			break;
		case 4:
			cout << monkey1.GetDescription();
			cout << "***** \n";
			cout << monkey2.GetDescription();
			cout << "***** \n";
			break;
		case 5:
			cout << snake1.GetDescription();
			cout << "***** \n";
			break;
		case 6:
			cout << snake2.GetDescription();
			cout << "***** \n";
			break;
		}

	}

	cout << "Спасибо, что посетили наш зоопарк!";
}