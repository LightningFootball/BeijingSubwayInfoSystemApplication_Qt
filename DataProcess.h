#pragma once

#include "ListGraph.h"
#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"
#include "Hash.h"
#include "PriorityQueue.h"
#include "Dijkstra.h"

#include <string>
#include <fstream>
#include <stdio.h>

#include<qstring.h>
#include<qfile.h>
#include<qtextstream.h>

//head for test
#include <iostream>

using namespace std;

//int dataProcess() {
//	QFile infoFile("SubwayInfoDatabase.txt");
//	infoFile.open(QIODevice::ReadOnly);		//open file
//
//	
//	QString totalLineNumSTRING = infoFile.readLine();
//	int totalLineNum = totalLineNumSTRING.toInt();
//
//	QTextStream cin(stdin, QIODevice::ReadOnly);
//	QTextStream cout(stdout, QIODevice::WriteOnly);		//allow qstring could cout
//	
//	ListGraph stationAdjacencyList;
//	HashTable stationHashList;
//
//	for (int i = 0; i < totalLineNum; i++)
//	{
//		QString aLineSTRING = infoFile.readLine();
//		QString aLineSTRING_TRIMMED = aLineSTRING.trimmed();		//tail trimmed
//		QStringList readLineSpilted = aLineSTRING_TRIMMED.split(' ');		//spilt by space
//
//		int lineNum = readLineSpilted.at(0).toInt();
//		QString lineName = readLineSpilted.at(1);
//		int lineTotalStationNum = readLineSpilted.at(2).toInt();
//
//		for (int i = 3; i < (readLineSpilted.size()-3+1); i=i+2)
//		{
//			QString fromStation = readLineSpilted.at(i);
//			QString toStation = readLineSpilted.at(i + 2);
//			int distance = readLineSpilted.at(i + 1).toInt();
//			
//			int fromStationHash = stationHashList.insert(fromStation);
//			int toStationHash = stationHashList.insert(toStation);
//
//			
//			stationAdjacencyList.insert(fromStationHash, toStationHash, distance);
//			stationAdjacencyList.insert(toStationHash, fromStationHash, distance);	//exchange direction
//		}
//	}
//
//	cout << stationHashList.volume << endl;
//
//	QString fromStationName;
//	QString toStationName;
//	cout << "Type in from station name:" << endl;
//	cin >> fromStationName;
//	cout << "Type in to station name:" << endl;
//	cin >> toStationName;
//	int temp = stationHashList.hash.doHash(fromStationName);
//	int fromStationHash = stationHashList.search(fromStationName);
//	int toStationHash = stationHashList.search(toStationName);
//
//	//Dijkstra test(stationHashList.hTable.size(),stationHashList.volume);
//	test.operate(&stationAdjacencyList, fromStationHash);
//
//	cout << "Distance : " << test.dijkstraList[toStationHash][0] << endl;
//	cout << "Route : " << endl;
//	for (int i = 1 ; test.dijkstraList[toStationHash][i]!=-1; i++)
//	{
//		cout << stationHashList.hTable[test.dijkstraList[toStationHash][i]] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

