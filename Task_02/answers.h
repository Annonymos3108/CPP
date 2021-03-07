#include <iostream>
#include <string>
#include <vector>

typedef unsigned long long size_t;

struct Person {
	std::string name;
	int age;

	bool operator<(const Person& other) const {
		return age < other.age;
	}
};

std::istream& operator>>(std::istream& in, Person& person) {
	in >> person.name;
	in.ignore(2); // пропускаем  [
	in >> person.age;
	in.ignore(1); // пропускаем ]
	return in;
}


/*
Реализуйте функцию MyMapTest, которая принимает на вход вектор значений
типа Person (этот тип определен в answer.h, не удаляйте его!) и возвращает
std::map вида *имя личности*: *его возраст*.
*/

std::map<std::string, int> MyMapTest(std::vector<Person>& persons) 
{
	std::map<std::string, int> personsMap;
	for (size_t i = 0; i < persons.size(); i++) 
	{
		personsMap[persons[i].name] = persons[i].age;
	}
	return personsMap;
}

/*
Реализуйте функцию MyVectorTest, которая принимает на вход массив
в стиле C (int* numbers) и количество элементов в этом массиве (int size).
Вы должны скопировать все числа из C-style массива в вектор и вернуть этот вектор.
*/
std::vector<int> MyVectorTest(int* array, int size)
{
	std::vector<int> arr(size);
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = array[i];
	}
	return arr;
}


/*
Реализуйте функцию MyIteratingTest, которой на вход подается произвольный контейер,
который хранит значения типа Person, а также ей на вход подается объект типа 
std::ostream& (ссылочность здесь обязательна! Иначе код просто не скомпилируется!). 

В этой функции вам необходимо вывести в переданный
std::ostream& значения, хранящиеся в переданном контейнере в формате 
"{person.name} [{person.age}]", причем в конце этой строчки обязательно 
нужно вывести std::endl. Например, мы имеем два значения типа Person. 
Первое значение имеет имя "A" и возраст 20, а второе - имя "B" и возраст 42.
Тогда в своей программе вы бы вывели такие строчки:
A [20]
B [42]
*/

template <typename T>
void MyIteratingTest(T collection, std::ostream& os)
{
	std::iterator<T> it;
	for (size_t i = 0; i < collection.size(); i++)
	{
		os << (std::string)sprintf("%s [%i]", collection[it].name, collection[it].age) << std::endl;
	}
}


/*
Реализуйте функцию MySortTest, которая сортирует (с помощью std::sort!)
первую половину вектора, хранящего значения произвольного типа.
*/
template <typename T>
void MySortTest(std::vector<T>& vec)
{
	std::sort(vec[0], vec[vec.size() / 2]);
}