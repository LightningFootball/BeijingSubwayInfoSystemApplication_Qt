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
	 * 先输出车站名，两列宽
	 * 下一行输出车站、票价两个词
	 * 循环，输出线路全部车站，和他对应的票价
	 *
	 * 统计站点数量，把站点数量大约占一个数目区间的放一列，示例约60站，
	 * 动态调整大小
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
	while (linePointer<database.getTotalLineNum()-1)	//全部线路数量次数的循环
	{
		//stationBasket init
		stationBasket=0;
		//单列输出线路数量调控
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

		//输出单列
		while (currentLinePointer<linePointer)
		{
			//线路名称段
			ui.fareTable->setSpan(rowPointer,columnPointer,2,2);
			QStandardItem* tempLineName=new QStandardItem(database.getLineNameList().at(currentLinePointer));
			tempLineName->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
			tempLineName->setBackground(QBrush(database.getLineColor(currentLinePointer)));
			tempLineName->setForeground(QBrush(QColor("white")));
			stationItemModel->setItem(rowPointer,columnPointer,tempLineName);
			rowPointer+=2;

			//线路名称头
			QStandardItem* lineHead1=new QStandardItem("Station");
			QStandardItem* lineHead2=new QStandardItem("Fare");
			lineHead1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
			lineHead2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
			stationItemModel->setItem(rowPointer,columnPointer,lineHead1);
			stationItemModel->setItem(rowPointer,columnPointer+1,lineHead2);
			rowPointer++;

			//线路站点段
			for(int i=0;i<database.getLineStationNum(currentLinePointer);i++)
			{
				QStandardItem* tempStationName=new QStandardItem(database.getLineStationOrderList(currentLinePointer).at(i));
				QString* tempFareString=new QString;
				tempFareString->setNum(database.getFare(database.getLineStationOrderList(currentLinePointer).at(i)));
				QStandardItem* tempFare=new QStandardItem(*tempFareString);

				tempStationName->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
				tempFare->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
				switch (database.getFare(database.getLineStationOrderList(currentLinePointer).at(i)))
				{
					case 3:
						tempFare->setBackground(QBrush(QColor("yellowgreen")));
						break;
					case 4:
						tempFare->setBackground(QBrush(QColor("green")));
						break;
					case 5:
						tempFare->setBackground(QBrush(QColor("dodgerblue")));
						break;
					case 6:
						tempFare->setBackground(QBrush(QColor("midnightblue")));
						break;
					case 7:
						tempFare->setBackground(QBrush(QColor("mediumvioletred")));
						break;
					case 8:
						tempFare->setBackground(QBrush(QColor("lightslategray")));
						break;
					default:
						tempFare->setBackground(QBrush(QColor("darkslategray")));
						break;
				}
				if(ui.stationSwitch->currentText()==database.getLineStationOrderList(currentLinePointer).at(i))
				{
					tempStationName->setBackground(QBrush(QColor("darkviolet")));
					tempStationName->setForeground(QBrush(QColor("white")));
				}
				tempFare->setForeground(QBrush(QColor("white")));

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

void FareSearchWindow::on_returnButton_clicked()
{
	emit fareWindowCloseSignal();
	this->close();
}

void FareSearchWindow::on_fareTable_doubleClicked(const QModelIndex &index)
{
	QVariant variant=index.data();
	if(!database.getPath(index.data().toString()).isEmpty())
	{
		PathPopup* window =new PathPopup;
		window->setToStation(index.data().toString());
		window->show();
	}
}
