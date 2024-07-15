#include "Program.h"
#include<string>
using namespace std;

class MyAlgorithm : public CurveAlgorithm
{
	//可以在这里定义成员变量和成员函数
public:
	static MyAlgorithm* CreateMyAlgorithm()
	{
		return new MyAlgorithm();
	}

	//根据给定控制点以及时间t计算生成的点，误差范围为±0.01
	Vector3 Calculate(Vector3* controlPoints, int count, float t) override
	{
		//完成这个函数
	}
};

static void TestMyAlgorithm(std::string path, int times)
{
	std::cout << "我的曲线生成算法:" << std::endl;
	Test(path, times, MyAlgorithm::CreateMyAlgorithm);
}

//注意在Release而不是Debug模式下运行此程序
int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 1000;		//控制算法运行次数；测试集中包含100个测试用例，则总运行次数=times×100

	//GenerateAnswers(path);
	TestBezierCurveAlgorithm(path, times);
	//TestMyAlgorithm(path, times);
}