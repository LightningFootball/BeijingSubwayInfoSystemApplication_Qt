#pragma once

#include "Hash.h"

#include <qvector.h>
#include <qstring.h>

/*Vector�У�sizeΪVectorʵ���Ѿ�ʹ�ÿռ䣬capacityΪVectorʵ���Ѿ�����Ĵ�С�ռ�*/

class HashTable
{
public:

	QVector<QString> hTable;
	Hash hash;
	int volume;

	HashTable();
	HashTable(int dataScale);
	
	bool resize();
	bool resize(int dataScale);
	
	int insert(QString string);
	int search(QString string);
	QString getName(int hashNum);
	
	~HashTable();

private:

};