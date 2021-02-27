#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <algorithm>

#define DO_ASSERT(expr) \
	if (!(expr))        \
		throw AssertException(#expr " is false");

void TestVarModifyig();
void TestStringVectorModifyig();
void TestSwapTemplate();



// Напиши определения функций с именами MyVarModifying, MyStringVectorModifying и MySwapTemplate здесь

//=============================================================================

template <typename T>
void MyVarModifying(T& a) {
	a += 42;
}

char asciiRegExchanger(char in) {
    if (in <= 'z' && in >= 'a')   	// 98-122 ASCII
        return in - ('z' - 'Z');
	if (in <= 'Z' && in >= 'A')		//65-97 ASCII
        return in - ('Z' - 'z');
    return in;						//other symbols in ASCII
}

void MyStringVectorModifying(std::vector<std::string>& vec) 
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::transform(vec[i].begin(), vec[i].end(), vec[i].begin(),
			asciiRegExchanger);
	}
	
}

template <typename T>
void MySwapTemplate(T& a, T& b) {
	T var;
	var = a;
	a = b;
	b = var;
}

//=============================================================================

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
		TestVarModifyig();
		TestStringVectorModifyig();
		TestSwapTemplate();
	} catch (const AssertException& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}

	std::cout << "The tests are successfully passed!\n";

	return 0;
}


void TestVarModifyig() {
	int a = 5;
	MyVarModifying(a);
	DO_ASSERT(a == 47)

	struct Point {
		int x, y;
		Point& operator=(const Point& other) {
			x = other.x;
			y = other.y;
			return *this;
		}
		Point operator+(int offset) const {
			return Point{x + offset, y + offset};
		}
		void operator+=(int offset) {
			x += offset;
			y += offset;
		}
	};
	Point point{-42, 42};
	MyVarModifying(point);
	DO_ASSERT(point.x == 0 && point.y == 84)
}


void TestStringVectorModifyig() {
	std::vector<std::string> str_vec;
	str_vec.push_back("abcabc");
	str_vec.push_back("Co.U,r.S,e");
	str_vec.push_back("MAKE;; ME,; SMALL");
	str_vec.push_back("looks LIKE EmO!!!");

	MyStringVectorModifying(str_vec);

	std::vector<std::string> to_check = {"ABCABC", "cO.u,R.s,E", "make;; me,; small", "LOOKS like eMo!!!"};
	for (int i = 0; i < str_vec.size(); ++i) {
		DO_ASSERT(to_check[i] == str_vec[i])
	}
}


void TestSwapTemplate() {
	int a = 10, b = 42;
	MySwapTemplate(a, b);
	DO_ASSERT(a == 42 && b == 10)

	std::string first_string = "first string";
	std::string second_string = "second string";
	MySwapTemplate(first_string, second_string);
	DO_ASSERT(first_string == "second string" && second_string == "first string")

	std::vector<std::string> first_vector = {"one", "two", "three"};
	std::vector<std::string> second_vector = {"i guess?", "ok...", "do it"};
	auto to_check_first = second_vector;
	auto to_check_second = first_vector;
	MySwapTemplate(first_vector, second_vector);
	DO_ASSERT(first_vector == to_check_first && second_vector == to_check_second)
}