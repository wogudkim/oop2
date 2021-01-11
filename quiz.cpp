#include <iostream>
#include <string>
using namespace std;

class Student{
public:
	string name;
	int mscore;
	int fscore;
	int qscore;
	int cscore;
	Student()
	{
		name = "";
		mscore = 0;
		fscore = 0;
		qscore = 0;
		cscore = 0;
	}
	Student(string _name)
	{
		name = _name
		mscore = 0;
		fscore = 0;
		qscore = 0;
		cscore = 0;
	}
	~Student()
	{
		delete Student;
		Student = NULL;
	}

	void setMidtermScore(int _mscore)
	{
		mscore = _mscore;
	}
	void setFinaltermScore(int _fscore)
	{
		fscore = _fscore;
	}
	void setQuizScore(int _qscore)
	{
		qscore = _qscore;
	}
	void setCheckinScore(int _cscore)
	{
		cscore = _cscore;
	}
};

int main(){
	cout << "1.  학생자료 등록" << endl
	<< "2. 조회" << endl << "3. 성적출력" << "0. 종료(종료시 0입력)" << endl;

	int order;
	while(1)
	{
		cin >> order;
		if(order = 1)
		{
			string name;
			int score;
			cin >> name;
			Student* s = new Student(name);
			cin >> score;
			s.setMidtermScore(score);
			cin >> score;
			s.setFinaltermScore(score);
			cin >> score;
			s.setQuizScore(score);
			cin >> score;
			s.setCheckinScore(score);
		}
		else if(order = 2)
		{
			
		}
		else if(order = 3)
		{
		}
		else if(order = 0)
		{
		}
	}
}
