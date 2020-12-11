#include "Storage.h"

Storage::Storage()
{
	QFile infoFile("SubwayInfoDatabase.txt");
	infoFile.open(QIODevice::ReadOnly);		//open file

	QTextStream cin(stdin, QIODevice::ReadOnly);
	QTextStream cout(stdout, QIODevice::WriteOnly);		//allow qstring could cout

	QString totalLineNumSTRING = infoFile.readLine();
	int totalLineNum = totalLineNumSTRING.toInt();
	lineNameList.resize(totalLineNum);

	lineOrderList.resize(totalLineNum);

	for (int i = 0; i < totalLineNum; i++)
	{
		QString aLineSTRING = infoFile.readLine();
		QString aLineSTRING_TRIMMED = aLineSTRING.trimmed();		//tail trimmed
		QStringList readLineSpilted = aLineSTRING_TRIMMED.split(' ');		//spilt by space

		int lineNum = readLineSpilted.at(0).toInt();
		QString lineName = readLineSpilted.at(1);
		int lineTotalStationNum = readLineSpilted.at(2).toInt();

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

			lineOrderList[lineNum].append(fromStationHash);
		}

		QString lastStationString = readLineSpilted.last();
		int lastStationHash = stationHashList.hash.doHash(lastStationString);
		if (lineOrderList[lineNum][0] != lastStationHash)
		{
			lineOrderList[lineNum].append(lastStationHash);
		}
	}

	stationPathList.setSpace(stationHashList.hTable.size(), stationHashList.volume);

	infoFile.close();
}


bool Storage::setFromStation(QString fromStation)
{
	stationPathList.reset();
	int fromStationHash = stationHashList.search(fromStation);
	stationPathList.operate(&stationAdjacencyList, fromStationHash);
	return true;
}

QVector<QString> Storage::getPath(QString toStation)
{
	int toStationHash = stationHashList.search(toStation);
	QVector<QString> path;
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
}

QVector<QString> Storage::getLineNameList()
{
	return lineNameList;
}

QVector<int> Storage::getLineOrderList(int lineNum)
{
	return lineOrderList[lineNum];
}

Storage::~Storage()
{
}