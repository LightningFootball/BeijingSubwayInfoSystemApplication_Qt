#include "InvalidInputDialog.h"
#include "ui_InvalidInputDialog.h"

InvalidInputDialog::InvalidInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InvalidInputDialog)
{
    ui->setupUi(this);
}

InvalidInputDialog::~InvalidInputDialog()
{
    delete ui;
}
