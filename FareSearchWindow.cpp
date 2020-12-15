#include "FareSearchWindow.h"

FareSearchWindow::FareSearchWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	lineStringListModel.setStringList(database.getLineNameList());
	ui.lineSwitch->setModel(&lineStringListModel);
	stationStringListModel.setStringList(database.getLineStationOrderList(ui.lineSwitch->currentText()));
	ui.stationSwitch->setModel(&stationStringListModel);
}

FareSearchWindow::~FareSearchWindow()
{
}

void FareSearchWindow::on_lineSwitch_currentIndexChanged(const QString &arg1)
{
    stationStringListModel.setStringList(database.getLineStationOrderList(arg1));
    ui.stationSwitch->setCurrentIndex(0);
    ui.stationSwitch->setModel(&stationStringListModel);
}

void FareSearchWindow::on_stationSwitch_currentTextChanged(const QString &arg1)
{
	if(arg1==NULL)
	{
		ui.stationSwitch->setCurrentIndex(0);
	}
	database.setFromStation(ui.stationSwitch->currentText());

	/*
	 * �������վ�������п�
	 * ��һ�������վ��Ʊ��������
	 * ѭ���������·ȫ����վ��������Ӧ��Ʊ��
	 *
	 * ͳ��վ����������վ��������Լռһ����Ŀ����ķ�һ�У�ʾ��Լ60վ��
	 * ��̬������С
	 *
	 * linePointer
	 *
	 * for linePointer < lineNum
	 * while stationBasket!=50~70
	 *      pointer++
	 * pointer-1 if stationBasket<40 pointer+1
	 * for i<pointer
	 *      output table
	 * resize table
	 */



	int linePointer=0;
	int currentLinePointer=0;
	int stationBasket=0;

	int rowPointer=0;
	int columnPointer=0;
	QStandardItemModel* stationItemModel=new QStandardItemModel;
	while (linePointer<database.getTotalLineNum()-1)	//ȫ����·����������ѭ��
	{
		//stationBasket init
		stationBasket=0;
		//���������·��������
		while (stationBasket<80)
		{
			stationBasket+=database.getLineStationNum(linePointer);
			++linePointer;
			if(linePointer>=database.getTotalLineNum()-1)
			{
				break;
			}
		}
		if(stationBasket>100)
		{
			--linePointer;
		}

		//�������
		while (currentLinePointer<linePointer)
		{
			//��·���ƶ�
			ui.fareTable->setSpan(rowPointer,columnPointer,1,2);
			QStandardItem* tempLineName=new QStandardItem(database.getLineNameList().at(currentLinePointer));
			tempLineName->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
			tempLineName->setData(QBrush(database.getLineColor(currentLinePointer)));
			stationItemModel->setItem(rowPointer,columnPointer,tempLineName);
			rowPointer++;

			//��·����ͷ
			QStandardItem* lineHead1=new QStandardItem("Station");
			QStandardItem* lineHead2=new QStandardItem("Fare");
			lineHead1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
			lineHead2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
			stationItemModel->setItem(rowPointer,columnPointer,lineHead1);
			stationItemModel->setItem(rowPointer,columnPointer+1,lineHead2);
			rowPointer++;

			//��·վ���
			for(int i=0;i<database.getLineStationNum(currentLinePointer);i++)
			{
				QStandardItem* tempStationName=new QStandardItem(database.getLineStationOrderList(currentLinePointer).at(i));
				QString* tempFareString=new QString;
				int testFare=database.getFare(database.getLineStationOrderList(currentLinePointer).at(i));
				tempFareString->setNum(testFare);
				QStandardItem* tempFare=new QStandardItem(*tempFareString);
				tempStationName->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
				tempFare->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
				stationItemModel->setItem(rowPointer,columnPointer,tempStationName);
				stationItemModel->setItem(rowPointer,columnPointer+1,tempFare);
				++rowPointer;
			}
			++currentLinePointer;
		}
		rowPointer=0;
		columnPointer+=2;
	}
	ui.fareTable->setModel(stationItemModel);
	ui.fareTable->resizeRowsToContents();
	//ui.fareTable->horizontalHeader()->setVisible(true);
	//ui.fareTable->verticalHeader()->setVisible(true);
}
