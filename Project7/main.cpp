#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class Student
{
private:
	std::string name, number, grade;


public:
	Student() : name(""), number(""), grade("") {};
	Student(std::string name, std::string number, std::string grade);
	void student_print(Student studnet);
	std::string retrun_number();
};

std::string Student::retrun_number()
{
	return number;
}

Student::Student(std::string name, std::string number, std::string grade)
{
	this->name = name;
	this->number = number;
	this->grade = grade;
	
}

void Student::student_print(Student student)
{
	std::cout << "이름 : " << student.name << "학번 : " << student.number << "학점 : " << student.grade << std::endl;
}

class GradeManger
{
private:
	Student student[100];
	int count = 0;
public:
	GradeManger();
	void start(bool num);
	void add(Student student);
	void print();
	void remove(std::string num);
	void gemsak(std::string number);
	bool exit();
};
GradeManger::GradeManger()
{

}
void GradeManger::start(bool num)
{
	int meun = 0;
	std::string name = "", number = "", grade = "";
	while (num)
	{
		system("cls");
		std::cout << " ----- 메뉴 ----- " << std::endl;
		std::cout << "1. 학생 추가" << std::endl;
		std::cout << "2. 전체 출력" << std::endl;
		std::cout << "3. 학생 검색" << std::endl;
		std::cout << "4. 학생 제거" << std::endl;
		std::cout << "5. 종료" << std::endl;
		std::cout << "원하시는 메뉴를 선택해주세요.";
		std::cin >> meun;

		switch(meun)
		{
			case 1:
			{
				std::cout << "이름 : ";
				std::cin >> name;
				std::cout << "학번 : ";
				std::cin >> number;
				std::cout << "학점 : ";
				std::cin >> grade;
				Student s(name, number, grade);
				add(s);
				Sleep(500);
				break;
			}
				
			case 2:
				print();
				break;
			case 3:
				std::cout << "학번을 입력해주세요." << std::endl;
				std::cout << "학번 : ";
				std::cin >> number;
				gemsak(number);
				break;
			case 4:
				std::cout << "학번을 입력해주세요." << std::endl;
				std::cout << "학번 : ";
				std::cin >> number;
				remove(number);
				break;
			case 5:
				num = exit();
				break;
			default:
				std::cout << "1 - 5 까지만 입력해주세요.";
				num = false;
				break;

		}
	}
}
void GradeManger::add(Student student1)
{
	student[count] = student1;
	count++;
}
void GradeManger::print()
{
	system("cls");
	std::cout << " ----- 학생 수 -----" << count << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << count << "번 : ";
		student[i].student_print(student[i]);
	}
	system("pause");

}
void GradeManger::gemsak(std::string number)
{
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (student[i].retrun_number() == number) {
			found = true;
			student[i].student_print(student[i]);
		}
	}

	if (!found) 
		std::cout << "해당 학번의 학생을 찾을 수 없습니다." << std::endl;
	system("pause");
	
}
//count 번호를 입력하면 학생이 사라진다.
void GradeManger::remove(std::string number)
{
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (student[i].retrun_number() == number) {
			found = true;

			for (int j = i; j < count - 1; j++) {
				student[j] = student[j + 1];
			}

			count--; // 전체 학생 수 하나 줄임
			std::cout << "삭제 완료!" << std::endl;
			break;
		}
	}

	if (!found) cout << "해당 학번의 학생을 찾을 수 없습니다." << std::endl;
	system("pause");



}
//종료
bool GradeManger::exit()
{
	system("cls");
	std::cout << "종료합니다.";
	return false;
}

int main()
{
	GradeManger g1;
	g1.start(1);
}