#include "add_scree.h"
#include "ui_add_scree.h"
#include "File.h"
#include <QMessageBox>
Add_scree::Add_scree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_scree)
{
    ui->setupUi(this);
}

Add_scree::~Add_scree()
{
    delete ui;
}

void Add_scree::on_pushButton_clicked()
{
    File::info tinfo;
    tinfo.id=ui->lineEdit->text();
    tinfo.name=ui->lineEdit_2->text();
    tinfo.date=ui->lineEdit_3->text();
    tinfo.value=ui->lineEdit_4->text().toDouble();
    tinfo.status=ui->lineEdit_5->text();
    if(tinfo.id.size()==0||tinfo.name.size()==0||tinfo.date.size()==0||tinfo.value==0||tinfo.status.size()==0){
        QMessageBox::information(this,"提示","请填写所有数据",QMessageBox::Ok);
        return;
    }
    File file("data.txt");
    file.append(tinfo);
    accept();
}

void Add_scree::on_pushButton_2_clicked()
{
    accept();
}
