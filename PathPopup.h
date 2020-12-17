#ifndef PATHPOPUP_H
#define PATHPOPUP_H

#include <QDialog>
#include "QString"
#include "QStringListModel"

#include "Storage.h"

extern Storage database;

namespace Ui {
	class PathPopup;
}

class PathPopup : public QDialog
{
		Q_OBJECT

	public:
		explicit PathPopup(QWidget *parent = nullptr);

		void setToStation(QString string);

		QStringListModel pathStringListModel;

		~PathPopup();

	private slots:
		void on_okButton_clicked();

	private:
		Ui::PathPopup *ui;
};

#endif // PATHPOPUP_H
