#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <string>
#include <deque>
#include <map>
#include <set>

#include "answers.h"

#define DO_ASSERT(expr, message) \
	if (!(expr))        \
		throw AssertException(message);


void TestMap();
void TestVector();
void TestIterating();
void TestSorting();


class AssertException : public std::exception
{
public:
	std::string error_msg;

	AssertException(std::string msg)
		: std::exception(), error_msg(std::move(msg)) {}

	const char* what() const noexcept override {
		return error_msg.c_str();
	}
};

int main()
{
	try {
		TestMap();
		TestVector();
		TestIterating();
		TestSorting();
	} catch (const AssertException& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}

	std::cout << "The tests are successfully passed!\n";

	return 0;
}


// В ф-ю передается вектор структур, нужно сделать из него map
void TestMap() {
	std::vector<Person> persons(26*26*26*26);
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			for (int k = 0; k < 26; ++k) {
				for (int l = 0; l < 26; ++l) {
					persons[26*i + 26*j + 26*k + l] = {
						std::string(1, char(96+i)) + char(96+j) + char(96+k) + char(96+l),
						rand() % 10000
					};
				}
			}
		}
	}

	auto start = std::chrono::steady_clock::now();
	auto persons_database = MyMapTest(persons);
	auto end = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	DO_ASSERT(diff.count() <= 1000, "Функция MyMapTest работает слишком медленно!");

	DO_ASSERT(persons.size() == persons_database.size(), "Количество записей не совпадает с изначальным!");
	for (int i = 0; i < persons.size(); ++i) {
		DO_ASSERT(persons[i].age == persons_database[persons[i].name], "Некоторые записи не совпадают!");
	}
}


void TestVector() {
	int size = 50000000;
	int* numbers = new int[size];
	for (int i = 0; i < size; ++i) {
		numbers[i] = rand() % 10000;
	}

	auto start = std::chrono::steady_clock::now();
	auto vector_numbers = MyVectorTest(numbers, size);
	auto end = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	DO_ASSERT(diff.count() <= 1000, "Функция MyVectorTest работает слишком медленно!");

	DO_ASSERT(vector_numbers.size() == size, "Количество элементов в векторе не совпадает с изначальным!");
	for (int i = 0; i < size; ++i) {
		DO_ASSERT(vector_numbers[i] == numbers[i], "Некоторые числа не совпадают!");
	}
}

void TestIterating() {
	std::set<Person> sperson_set = {
		{"Neumann", 118},
		{"Einstein", 142},
		{"Hoking", 79},
		{"Tesla", 165},
		{"Poincare", 167}
	};
	std::vector<Person> vperson_set = {
		{"Neumann", 118},
		{"Einstein", 142},
		{"Hoking", 79},
		{"Tesla", 165},
		{"Poincare", 167}
	};
	std::deque<Person> dperson_set = {
		{"Neumann", 118},
		{"Einstein", 142},
		{"Hoking", 79},
		{"Tesla", 165},
		{"Poincare", 167}
	};

	std::ostringstream set_ss, vec_ss, deq_ss;

	MyIteratingTest(sperson_set, set_ss);
	MyIteratingTest(vperson_set, vec_ss);
	MyIteratingTest(dperson_set, deq_ss);

	Person temp;
	std::istringstream set_input(set_ss.str());
	for (const auto& person : sperson_set) {
		set_input >> temp;
		DO_ASSERT(temp.name == person.name &&
				  temp.age == person.age, "Некоторые записи не совпадают");
	}

	std::istringstream vec_input(vec_ss.str());
	for (const auto& person : vperson_set) {
		vec_input >> temp;
		DO_ASSERT(temp.name == person.name &&
				  temp.age == person.age, "Некоторые записи не совпадают");
	}

	std::istringstream deq_input(deq_ss.str());
	for (const auto& person : dperson_set) {
		deq_input >> temp;
		DO_ASSERT(temp.name == person.name &&
				  temp.age == person.age, "Некоторые записи не совпадают");
	}
}


void TestSorting() {
	std::vector<Person> some_random_info(1000000);
	std::vector<int> some_random_ints(321421);
	std::vector<std::string> some_random_strings(3122);
	for (int i = 0; i < some_random_info.size(); ++i) {
		some_random_info[i] = {"some name idk", rand() % 1000};
	}
	for (int i = 0; i < some_random_ints.size(); ++i) {
		some_random_ints[i] = rand() % 1231;
	}
	for (int i = 0; i < some_random_strings.size(); ++i) {
		some_random_strings[i] = std::string(1, char(rand() % 128)) + 
								 char(rand() % 1231) + char(rand() % 1231);
	}

	MySortTest(some_random_info);
	MySortTest(some_random_ints);
	MySortTest(some_random_strings);

	DO_ASSERT(
		std::is_sorted(some_random_info.begin(), some_random_info.begin() + some_random_info.size() / 2) &&
		std::is_sorted(some_random_ints.begin(), some_random_ints.begin() + some_random_ints.size() / 2) &&
		std::is_sorted(some_random_strings.begin(), some_random_strings.begin() + some_random_strings.size() / 2),
		"Сортировка работает неверно!"
	);
}