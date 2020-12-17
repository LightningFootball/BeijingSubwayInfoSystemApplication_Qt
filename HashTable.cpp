#include "HashTable.h"

HashTable::HashTable()
{
	volume = 0;
	hTable.resize(1000);
}

HashTable::HashTable(int dataScale)	//需要给出数据量的构造函数
{
	volume = 0;
	hTable.resize(hash.hashSpaceRequire());
}

int HashTable::insert(QString string)	//插入则返回插入位置，存在则返回false
{
	//检测如果hash位置为空则储存，非空则检测是否相同，相同则返回false，不相同则去到下一位置
	//下一位置的探寻规则为单向二次探查
	int hashPointer = hash.doHash(string);
	/*while(hashPointer >= hTable.size())
	{
		resize(hashPointer);
	}*/

	for (int i = 0; !hTable.at(hashPointer).isEmpty(); ++i)
	{
		if (hTable.at(hashPointer) == string)
		{
			return hashPointer;
		}
		hashPointer = (hashPointer + i * i) % hTable.size();
	}

	hTable[hashPointer] = string;
	++volume;

	return hashPointer;
}

int HashTable::search(QString string)
{
	//传入string，计算hash
	//查找hash位置：空-未查询到，满-检查是否相等：相等-返回此时hash位置。不相等，下一个hash位置
	int hashPointer = hash.doHash(string);
	for (int i = 0; !hTable.at(hashPointer).isEmpty(); ++i)
	{
		if (hTable.at(hashPointer) == string)
		{
			return hashPointer;
		}
		hashPointer = (hashPointer + i * i) % hTable.size();
	}
	return -1;
}

QString HashTable::getName(int hashNum)
{
	return hTable[hashNum];
}

QVector<int> HashTable::fuzzySearch(QString string)
{
	QVector<int> fuzzyList;
	for(int i=0;i<hTable.size();++i)
	{
		for(int j=0;j<string.size();++j)
		{
			if(hTable.at(i).contains(string.at(j)))
			{
				bool conflict=false;
				for(int k=0;k<fuzzyList.size();++k)
				{
					if(fuzzyList.at(k)==i)
					{
						conflict=true;
					}
				}
				if(!conflict)
				{
					fuzzyList.append(i);
				}
			}
		}
	}
	return fuzzyList;
}

QVector<int> HashTable::fullMatchingFuzzySearch(QString string)
{
	QVector<int> fuzzyList;
	for(int i=0;i<hTable.size();++i)
	{
		if(hTable.at(i).contains(string))
		{
			bool conflict=false;
			for(int k=0;k<fuzzyList.size();++k)
			{
				if(fuzzyList.at(k)==i)
				{
					conflict=true;
				}
			}
			if(!conflict)
			{
				fuzzyList.append(i);
			}
		}
	}
	return fuzzyList;
}

bool HashTable::resize()
{
	hTable.resize(hTable.size() / 0.75);
	return true;
}

bool HashTable::resize(int dataScale)
{
	hTable.resize(dataScale / 0.75);
	return true;
}

HashTable::~HashTable()
{
}
