#ifndef INVALIDINPUTDIALOG_H
#define INVALIDINPUTDIALOG_H

#include <QDialog>

namespace Ui {
class InvalidInputDialog;
}

class InvalidInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InvalidInputDialog(QWidget *parent = nullptr);
    ~InvalidInputDialog();

private:
    Ui::InvalidInputDialog *ui;
};

#endif // INVALIDINPUTDIALOG_H
