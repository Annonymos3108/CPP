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
void MyMapTest(std::vector<Person>& persons) 
{
	std::map<std::string, int> personsMap
	for (size_t i = 0; i < persons.size; i++)
	{
		/* code */
	}
	
}

/*
Реализуйте функцию MyVectorTest, которая принимает на вход массив
в стиле C (int* numbers) и количество элементов в этом массиве (int size).
Вы должны скопировать все числа из C-style массива в вектор и вернуть этот вектор.
*/
void MyVectorTest() 
{

}


/*
Реализуйте функцию MyIteratingTest, которой на вход подается произвольный контейер,
который хранит значения типа Person, а также ей на вход подается объект типа 
std::ostream& (ссылочность здесь обязательна! Иначе код просто не скомпилируется!). 
Знаю, что мы пока не проходили потоки ввода-вывода, но вам достаточно относиться 
к объекту std::ostream& так же, как и к std::cout: в std::ostream тоже можно писать
какие-то значения с помощью <<. В этой функции вам необходимо вывести в переданный
std::ostream& значения, хранящиеся в переданном контейнере в формате 
"{person.name} [{person.age}]", причем в конце этой строчки обязательно 
нужно вывести std::endl. Например, мы имеем два значения типа Person. 
Первое значение имеет имя "A" и возраст 20, а второе - имя "B" и возраст 42.
Тогда в своей программе вы бы вывели такие строчки:
A [20]
B [42]
*/
void MyIteratingTest() {

}


/*
Реализуйте функцию MySortTest, которая сортирует (с помощью std::sort!)
первую половину вектора, хранящего значения произвольного типа.
*/
void MySortTest() {

}