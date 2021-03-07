#include <iostream>
#include <string>

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




void MyMapTest() {

}

void MyVectorTest() {

}

void MyIteratingTest() {

}

void MySortTest() {

}