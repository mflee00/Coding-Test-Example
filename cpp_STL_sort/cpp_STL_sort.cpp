// cpp_STL_sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>



#if 0
using namespace std;
int main()
{
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
}
#endif

#if 0
using namespace std;
bool compare(int a, int b)
{
	//return a < b; //오름차순
	return a > b;   //내림차순
}

int main()
{
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10, compare);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
}
#endif

#if 1

#include <string>
using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	bool operator <(Student &student)
	{
		return this->score < student.score;
	}
};
int main(void)
{
	Student students[] = {
		Student("이정철" , 90),
		Student("이정철2", 80),
		Student("이정철3", 70),
		Student("이정철4", 10),
		Student("이정철5", 50)
	};
	sort(students, students + 5);

	for (int i = 0; i < 5; i++)
	{
		cout<<students[i].name << ' ';
	}

}

#endif