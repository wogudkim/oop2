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
	Student slist[10];
	int num = 0;
	cout << "1.  학생자료 등록" << endl
	<< "2. 조회" << endl << "3. 성적출력" << "0. 종료(종료시 0입력)" << endl;

	int order;
	while(1)
	{
		cin >> order;
		if(order == 1)
		{
			string name;
			int score;
			cout << "학생의 이름을 입력해주세요: ";
			cin >> name;
			Student s(name) = new Student;
			cout << "중간고사 점수 입력해주세요: ";
			cin >> score;
			s.setMidtermScore(score);
			cout << "기말고사 점수 입력해주세요: ";
			cin >> score;
			s.setFinaltermScore(score);
			cout << "퀴즈 점수 입력해주세요: ";
			cin >> score;
			s.setQuizScore(score);
			cout << "출석 점수 입력해주세요: ";
			cin >> score;
			s.setCheckinScore(score);
			slist[num] = s;
			num++;
		}
		else if(order == 2)
		{
			cout << "학생의 이름을 입력해주세요: ";
			int name;
			cin >> name;
			for(int i = 0; i < 10; i++){
				if(slist[i].name == name){
					int total = slist[i].mscore +
						slist[i].fscore +
						slist[i].qscore +
						slist[i].cscore;
					cout << "총점: " << endl;
				}
			}
			
		}
		else if(order == 3)
		{
		}
		else if(order == 0)
		{
		}
	}
}
