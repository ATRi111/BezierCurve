#include "Program.h"
#include<string>
using namespace std;

//注意在Release而不是Debug模式下运行此程序
int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 100000;		//控制算法运行次数；测试集中包含100个测试用例，则总运行次数=times×100

	TestCase* t = GenerateTestCase();
	t->Print();
	BezierCurveAlgorithm curve;
	TestAnswer* a = curve.Run(t, nullptr);
	a->Print();
}