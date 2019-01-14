#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::map;
using std::vector;

struct Specialization
{
	string value;
	explicit Specialization(const string& newValue) : value(newValue) { }
};

struct Course
{
	string value;
	explicit Course(const string& newValue) : value(newValue) { }
};

struct Week
{
	string value;
	explicit Week(const string& newValue) : value(newValue) { }
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	explicit LectureTitle(const Specialization& newSpecialization, const Course& newCourse, const Week& newWeek) 
		: specialization(newSpecialization.value), course(newCourse.value), week(newWeek.value) { }
};


//int main() {
//
//	// works
//	LectureTitle title(
//		Specialization("C++"),
//		Course("White belt"),
//		Week("4th")
//	);
//
//	const char vasya[4] = "C++";
//
//	if (title.specialization != vasya)
//	{
//
//	}
//
//	//// don't work
//	//LectureTitle title("C++", "White belt", "4th");
//
//	//LectureTitle title(string("C++"), string("White belt"), string("4th"));
//
//	//LectureTitle title = { "C++", "White belt", "4th" };
//
//	//LectureTitle title = { { "C++" },{ "White belt" },{ "4th" } };
//
//	//LectureTitle title(
//	//	Course("White belt"),
//	//	Specialization("C++"),
//	//	Week("4th")
//	//);
//
//	//LectureTitle title(
//	//	Specialization("C++"),
//	//	Week("4th"),
//	//	Course("White belt")
//	//);
//
//	return 0;
//}