//c++∑Á∏Ò  øÏ≈≈
#include <iostream>
using namespace std;
#include <vector>;

int FindPos(vector<int> &Vec, int a, int b);
void QuickSort(vector<int> &Vec,int a,int b)
{
	int pos;
	if (a < b)
	{
		pos = FindPos(Vec, a, b);
		QuickSort(Vec, a, pos-1);
		QuickSort(Vec, pos + 1, b);
	}
}

int FindPos(vector<int> &Vec, int a, int b)
{
	int val = Vec[a];
	while (a < b)
	{
		while (a < b&&Vec[b] >= val)
		{
			--b;
		}
		Vec[a] = Vec[b];
		while (a < b&&Vec[a] <= val)
		{
			++a;
		}
		Vec[b] = Vec[a];
	}
	Vec[a] = val;
	return a;
}
int main(void)
{
	vector<int> myVec;
	myVec.push_back(4);
	myVec.push_back(3);
	myVec.push_back(7);
	myVec.push_back(8);
	myVec.push_back(1);
	myVec.push_back(-2);
	QuickSort(myVec, 0,myVec.size()-1);
	for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		cout << (*it) << " ";
	}
	system("pause");
	return 0;
}