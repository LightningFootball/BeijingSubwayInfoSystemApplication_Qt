#pragma once

//负载因子以0.75为宜，总站点数在400+，所以Hash大小设置为530为宜
//对于Qstring存储的UTF-16编码，其中中文编码范围为4E00-9FBF，范围大小19968
//本hash算法采用折叠法并通过乘系数使更table大小更接近负载因子

#include <qstring.h>
#include <qvector.h>

class Hash	//该类仅适用于对Qstring的第一个字进行Hash，不可推广
{
public:
	Hash();
	Hash(int dataScale);
	int hashSpaceRequire();
	int doHash(QString string);
	~Hash();

protected:

	int dataScale;

};