#include "Hash.h"


Hash::Hash() {
	dataScale = 1000;
}

Hash::Hash(int dataScale)	//int�͹��캯��
{
	this->dataScale = dataScale;
}

int Hash::hashSpaceRequire()	//����hash�����С
{
	return dataScale;
}

int Hash::doHash(QString string)	//����hashֵ
{
	int hashRaw = string.at(0).unicode();
	int hashFinal = (hashRaw % 10000) % 1000 / 2;

	return hashFinal;

}

Hash::~Hash()
{
}