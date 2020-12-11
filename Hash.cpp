#include "Hash.h"


Hash::Hash() {
	dataScale = 1000;
}

Hash::Hash(int dataScale)	//int型构造函数
{
	this->dataScale = dataScale;
}

int Hash::hashSpaceRequire()	//返回hash所需大小
{
	return dataScale;
}

int Hash::doHash(QString string)	//返回hash值
{
	int hashRaw = string.at(0).unicode();
	int hashFinal = (hashRaw % 10000) % 1000 / 2;

	return hashFinal;

}

Hash::~Hash()
{
}