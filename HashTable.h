#pragma once

#include "Hash.h"

#include <qvector.h>
#include <qstring.h>

/*Vector中，size为Vector实际已经使用空间，capacity为Vector实际已经分配的大小空间*/

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

	QVector<int> fuzzySearch(QString string);
	QVector<int> fullMatchingFuzzySearch(QString string);
	
	~HashTable();

private:

};
