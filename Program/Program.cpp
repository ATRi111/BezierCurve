#include "Program.h"
#include<string>
using namespace std;

//ע����Release������Debugģʽ�����д˳���
int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 100000;		//�����㷨���д��������Լ��а���100�������������������д���=times��100

	TestCase* t = GenerateTestCase();
	t->Print();
	BezierCurveAlgorithm curve;
	TestAnswer* a = curve.Run(t, nullptr);
	a->Print();
}