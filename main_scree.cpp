#include "main_scree.h"
#include "ui_main_scree.h"
#include "add_scree.h"
Main_Scree::Main_Scree(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Main_Scree)
{
    ui->setupUi(this);

}

Main_Scree::~Main_Scree()
{
    delete ui;
}


void Main_Scree::on_pushButton_clicked()
{
    close();
    Add_scree dlg;
    if(dlg.exec()==QDialog::Accepted) show();
}
