#include "Storage.h"

Storage::Storage()
{
	//QFile infoFile("C:/WorkSpace/Beijing Subway Info System/BeijingSubwayInfoSystemApplication_Qt/SubwayInfoDatabase.txt");
	QFile infoFile("SubwayInfoDatabase.txt");
	infoFile.open(QIODevice::ReadOnly/*|QIODevice::Text*/);		//open file

	QTextStream cin(stdin, QIODevice::ReadOnly);
	QTextStream cout(stdout, QIODevice::WriteOnly);		//allow qstring could cout

	QString totalLineNumSTRING = infoFile.readLine();
	totalLineNum = totalLineNumSTRING.toInt();
	lineNameList.resize(totalLineNum);
	lineStationNumList.resize(totalLineNum);
    lineStationOrderList.resize(totalLineNum);

	for (int i = 0; i < totalLineNum; i++)
	{
		QString aLineSTRING = infoFile.readLine();
		QString aLineSTRING_TRIMMED = aLineSTRING.trimmed();		//tail trimmed
		QStringList readLineSpilted = aLineSTRING_TRIMMED.split(' ');		//spilt by space

		int lineNum = readLineSpilted.at(0).toInt();
		QString lineName = readLineSpilted.at(1);
		int lineTotalStationNum = readLineSpilted.at(2).toInt();

		lineStationNumList[i]=lineTotalStationNum;

		lineNameList[lineNum] = lineName;

		for (int i = 3; i < (readLineSpilted.size() - 3 + 1); i = i + 2)
		{
			QString fromStation = readLineSpilted.at(i);
			QString toStation = readLineSpilted.at(i + 2);
			int distance = readLineSpilted.at(i + 1).toInt();

			int fromStationHash = stationHashList.insert(fromStation);
			int toStationHash = stationHashList.insert(toStation);

			stationAdjacencyList.insert(fromStationHash, toStationHash, distance);
			stationAdjacencyList.insert(toStationHash, fromStationHash, distance);	//exchange direction

            lineStationOrderList[lineNum].append(fromStationHash);
		}

		QString lastStationString = readLineSpilted.last();
		int lastStationHash = stationHashList.hash.doHash(lastStationString);
        if (lineStationOrderList[lineNum][0] != lastStationHash)
		{
            lineStationOrderList[lineNum].append(lastStationHash);
		}
	}

	stationPathList.setSpace(stationHashList.hTable.size(), stationHashList.volume);

	QString colorString={"190 54 49 \
190 54 49 \
15 97 146 \
0 137 148 \
165 35 122 \
210 148 4 \
249 195 116 \
0 146 99 \
0 146 99 \
150 190 11 \
0 154 186 \
248 225 20 \
212 167 161 \
212 167 161 \
107 55 119 \
124 158 33 \
0 0 205 \
226 6 33 \
176 86 31 \
225 92 40 \
221 131 176 \
225 92 40 \
226 0 114 \
160 154 184"};
	QStringList colorStringList=colorString.split(' ');
	lineColorList.resize(totalLineNum);
	for(int i=0;i<totalLineNum;i++)
	{
		lineColorList[i].setRgb(colorStringList.at(i*3).toInt(),colorStringList.at(i*3+1).toInt(),colorStringList.at(i*3+2).toInt());
	}

	infoFile.close();
}


int Storage::setFromStation(QString fromStation)
{
	stationPathList.reset();
	int fromStationHash = stationHashList.search(fromStation);
    if(fromStationHash==-1)
    {
        return false;
    }
	stationPathList.operate(&stationAdjacencyList, fromStationHash);
	return true;
}

QStringList Storage::getPath(QString toStation)
{
	int toStationHash = stationHashList.search(toStation);
    QStringList path;
	for (int i = 1; stationPathList.dijkstraList[toStationHash][i] != -1; i++)
	{
		path.append(stationHashList.getName(stationPathList.dijkstraList[toStationHash][i]));
	}
	return path;
}

int Storage::getDistance(QString toStation)
{
	int toStationHash = stationHashList.search(toStation);
	return stationPathList.dijkstraList[toStationHash][0];
}

int Storage::getFare(QString toStation)
{
	//起步6公里（含）内3元，6 公里至12公里（含）4元，12公里至22公里（含）5元，22公里至32公里（含）6元，32公里以上部分，每增加1元可乘坐20公里。票价不封顶。
	int distance = getDistance(toStation);
	if (distance > 0 && distance <= 6000)
	{
		return 3;
	}
	else if (distance > 6000 && distance <= 12000)
	{
		return 4;
	}
	else if (distance > 12000 && distance <= 22000)
	{
		return 5;
	}
	else if (distance > 22000 && distance <= 32000)
	{
		return 6;
	}
	else if (distance > 32000)
	{
		if (((distance - 32000) % 20000) > 0)
		{
			return 6 + (distance - 32000) / 20000 + 1;
		}
		else
		{
			return 6 + (distance - 32000) / 20000;
		}
	}
	return 3;
}

QStringList Storage::getLineNameList()
{

    QStringList lineNameStringList=lineNameList.toList();
    return lineNameStringList;
}

QStringList Storage::getLineStationOrderList(QString lineName)
{
    int lineNum;
    for(lineNum=0;lineNum<lineNameList.size();lineNum++)
    {
        if(lineName==lineNameList[lineNum])
        {
            break;
        }
    }
    QStringList lineStationOrderStringList;
    for(int i = 0;i<lineStationOrderList[lineNum].size();i++)
    {
        lineStationOrderStringList.append(stationHashList.hTable[lineStationOrderList[lineNum][i]]);
    }
	return lineStationOrderStringList;
}

QStringList Storage::getLineStationOrderList(int lineNum)
{
	QStringList lineStationOrderStringList;
	for(int i = 0;i<lineStationOrderList[lineNum].size();i++)
	{
		lineStationOrderStringList.append(stationHashList.hTable[lineStationOrderList[lineNum][i]]);
	}
	return lineStationOrderStringList;
}

int Storage::getLineStationNum(int lineNum)
{
	return lineStationNumList[lineNum];
}

int Storage::getTotalLineNum()
{
	return  totalLineNum;
}

QColor Storage::getLineColor(int lineNum)
{
	return lineColorList[lineNum];
}




Storage::~Storage()
{
}
