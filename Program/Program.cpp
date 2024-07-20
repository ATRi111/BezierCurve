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
	Vector2 Calculate(Vector2* controlPoints, int count, float t) override
	{
		//完成这个函数
		return Vector2::Zero;
	}
};

static void TestMyAlgorithm(std::string path, int times)
{
	std::cout << "你的曲线生成算法:" << std::endl;
	Test(path, times, 3, MyAlgorithm::CreateMyAlgorithm);
}

//注意在Release而不是Debug模式下运行此程序
int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find("\\x64\\")) + "\\Answer.txt";
	int times = 10000;		//控制算法运行次数；测试集中包含100个测试用例，则总运行次数=times×100

	TestBezierCurveAlgorithm(path, times);
	TestMyAlgorithm(path, times);
}