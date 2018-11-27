#include "pch.h"
#include <iostream>

// Особь в зоопарке
class ZooSpecimen
{
public:
	// Название животного
	std::string AnimalName; 
	// Возраст животного
	int Age;
	// Кличка животного
	std::string AnimalNickName;

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
public:
	// Может показывать водное шоу
	bool CanMakeWaterShow;

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
public:
	// Можно кормить посетителям
	bool CanBeFed;

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
public:
	// Ядовитая ли змея
	bool IsPoisonous;

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
public:
	// Порядковый номер места
	int PlaceNumber;	
	// Особи, живущие в данном месте
	ZooSpecimen *Species;

	// Конструктор класса (передается количество особей, живущих в данном месте)
	ZooPlace(int SpeciesAmount)
	{
		// Определяем массив особей
		Species = new ZooSpecimen[SpeciesAmount];
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
public:
	// Площадь клетки
	int CageSquare; 

	// Конструктор класса - вызывается родительский конструктор
	Cage(int SpeciesAmount) : ZooPlace(SpeciesAmount)
	{		
	}
};

// Бассейн - подкласс места в зоопарке
class Pool : public ZooPlace
{
public:
	// Объем бассейна
	int PoolVolume;

	// Конструктор класса - вызывается родительский конструктор
	Pool(int SpeciesAmount) : ZooPlace(SpeciesAmount)
	{
	}
};

// Террариум - подкласс места в зоопарке
class Terrarium : public ZooPlace
{
public:
	// Террариум открытого или закрытого вида
	bool IsOpened;

	// Конструктор класса - вызывается родительский конструктор
	Terrarium(int SpeciesAmount) : ZooPlace(SpeciesAmount)
	{
	}
};

// Посетитель зоопарка
class Person
{
public:
	// Имя
	std::string Name;
	// Возраст
	int Age;
};

// Билет в зоопарк
class ZooTicket
{
public:
	// Посетитель, купивший билет
	Person Person;

	// Метод, вычисляющий стоимость билета в зависимости от возраста посетителя
	int getCost()
	{
		int cost = 0;

		if (Person.Age <= 10)
		{
			cost = childrenTariff;
		}
		else
		{
			cost = adultTariff;
		}

		return cost;
	}

private:
	// Значения взрослого и детского тарифа (поля закрыты от вмешательства - инкапсуляция)
	int childrenTariff = 50;
	int adultTariff = 100;
};

// Визит в зоопарк
class ZooVisit
{
public:
	// По какому билету произошел визит
	ZooTicket Ticket;
	// Места с какими номерами посетил клиент за свой визит
	int *VisitedPlacesNumbers;

	// Конструктор класса (передается количество посещенных мест)
	ZooVisit(int VisitedPlacesCount)
	{
		// Определяем массив номеров мест
		VisitedPlacesNumbers = new int[VisitedPlacesCount];
	}

	// Деструктор класса
	~ZooVisit()
	{
		delete[]VisitedPlacesNumbers;
	}
};

int main()
{
	// Заполняем животных, которые обитают в зоопарке
	SwimmingAnimal dolphin1;
	dolphin1.AnimalName = "Дельфин";
	dolphin1.Age = 5;
	dolphin1.AnimalNickName = "Вениамин";
	dolphin1.CanMakeWaterShow = true;

	SwimmingAnimal dolphin2;
	dolphin2.AnimalName = "Дельфин";
	dolphin2.Age = 6;
	dolphin2.AnimalNickName = "Екатерина";
	dolphin2.CanMakeWaterShow = true;

	SwimmingAnimal hippo;
	hippo.AnimalName = "Бегемот";
	hippo.Age = 20;
	hippo.AnimalNickName = "Василиса";
	hippo.CanMakeWaterShow = false;

	LandAnimal lion;
	lion.AnimalName = "Лев";
	lion.Age = 12;
	lion.AnimalNickName = "Владимир";
	lion.CanBeFed = false;

	LandAnimal monkey1;
	monkey1.AnimalName = "Обезьяна";
	monkey1.Age = 3;
	monkey1.AnimalNickName = "Игорь";
	monkey1.CanBeFed = true;

	LandAnimal monkey2;
	monkey2.AnimalName = "Обезьяна";
	monkey2.Age = 3;
	monkey2.AnimalNickName = "Федор";
	monkey2.CanBeFed = true;

	Snake snake1;
	snake1.AnimalName = "Гремучая змея";
	snake1.Age = 10;
	snake1.AnimalNickName = "Ирина";
	snake1.IsPoisonous = true;

	Snake snake2;
	snake2.AnimalName = "Полоз";
	snake2.Age = 8;
	snake2.AnimalNickName = "Виктор";
	snake2.IsPoisonous = false;

	// Заполняем бассейны, клетки и террариумы
	Pool pool1 = Pool(2);
	pool1.PlaceNumber = 1;
	pool1.PoolVolume = 1000;
	pool1.Species[0] = dolphin1;
	pool1.Species[1] = dolphin2;

	Pool pool2 = Pool(1);
	pool1.PlaceNumber = 2;
	pool1.PoolVolume = 800;
	pool1.Species[0] = hippo;

	Cage cage1 = Cage(1);
	cage1.PlaceNumber = 3;
	cage1.CageSquare = 300;
	cage1.Species[0] = lion;

	Cage cage2 = Cage(2);
	cage2.PlaceNumber = 4;
	cage2.CageSquare = 500;
	cage2.Species[0] = monkey1;
	cage2.Species[1] = monkey2;

	Terrarium terr1 = Terrarium(1);
	terr1.PlaceNumber = 5;
	terr1.IsOpened = false;
	terr1.Species[0] = snake1;

	Terrarium terr2 = Terrarium(1);
	terr1.PlaceNumber = 6;
	terr1.IsOpened = true;
	terr1.Species[0] = snake2;
	
	// Посетитель зоопарка
	Person person;
	person.Name = "Константин";
	person.Age = 25;

	// Купленный билет
	ZooTicket ticket;
	ticket.Person = person;

	// Что посетил клиент
	ZooVisit visit = ZooVisit(4);
	visit.Ticket = ticket;
	visit.VisitedPlacesNumbers[0] = 1;
	visit.VisitedPlacesNumbers[1] = 2;
	visit.VisitedPlacesNumbers[2] = 4;
	visit.VisitedPlacesNumbers[3] = 6;    
}