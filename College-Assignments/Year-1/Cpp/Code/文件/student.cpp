#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	int id;
	string name;
public:
	void setlnfo(int i, string n);
	void display();
};

void Student::setlnfo(int i, string n) {
	id = i;
	name = n;
}
void Student::display() {
	cout << "学号:" << id << ",姓名:" << name << endl;
}

int main()
{
	Student stu1, stu2;
	stu1.setlnfo(1001, "张三");
	stu2.setlnfo(1002, "李四");
	cout << "学生信息如下:" << endl;
	stu1.display();
	stu2.display();
	int id3;
	string name3;
	cout << "输入三个学生学号姓名:";
	cin >> id3 >> name3;
	Student stu3;
	stu3.setlnfo(id3, name3);
	cout << "第三个学生信息:";
	stu3.display();
	return 0;
}

