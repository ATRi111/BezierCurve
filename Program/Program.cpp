#include "Program.h"
#include<string>
using namespace std;

class MyAlgorithm : public CurveAlgorithm
{
	//���������ﶨ���Ա�����ͳ�Ա����
public:
	static MyAlgorithm* CreateMyAlgorithm()
	{
		return new MyAlgorithm();
	}

	//���ݸ������Ƶ��Լ�ʱ��t�������ɵĵ㣬��ΧΪ��0.01
	Vector3 Calculate(Vector3* controlPoints, int count, float t) override
	{
		//����������
	}
};

static void TestMyAlgorithm(std::string path, int times)
{
	std::cout << "�ҵ����������㷨:" << std::endl;
	Test(path, times, MyAlgorithm::CreateMyAlgorithm);
}

//ע����Release������Debugģʽ�����д˳���
int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 1000;		//�����㷨���д��������Լ��а���100�������������������д���=times��100

	//GenerateAnswers(path);
	TestBezierCurveAlgorithm(path, times);
	//TestMyAlgorithm(path, times);
}