#include "show_scree.h"
#include "ui_show_scree.h"
#include "File.h"
#include "add_scree.h"
#include <QVector>
#include <QString>
#include <QFont>
show_scree::show_scree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_scree)
{
    ui->setupUi(this);
    QFont ft;
    ft.setPointSize(20);
    ui->label->setFont(ft);
    model=NULL;
    Updatatableview();
}

show_scree::~show_scree()
{
    delete ui;
}

void show_scree::on_pushButton_2_clicked()
{
    File::info tinfo;
    QVector<File::info> infos;
    QModelIndex index;
    for(int i=0;i<model->rowCount();i++){
        index=model->index(i,0,QModelIndex());
        tinfo.id=index.data().toString();
        index=model->index(i,1,QModelIndex());
        tinfo.name=index.data().toString();
        index=model->index(i,2,QModelIndex());
        tinfo.date=index.data().toString();
        index=model->index(i,3,QModelIndex());
        tinfo.value=index.data().toDouble();
        index=model->index(i,4,QModelIndex());
        tinfo.status=index.data().toString();
        infos.push_back(tinfo);
    }
    File file("data.txt");
    file.write(infos);
    Updatatableview();
}

void show_scree::on_pushButton_3_clicked()
{
        int currow=ui->tableView->currentIndex().row();
        File::info tinfo;
        QVector<File::info> infos;
        File file("data.txt");
        file.read(infos);
        infos.erase(infos.begin()+currow);
        file.write(infos);
        Updatatableview();
}

void show_scree::on_pushButton_4_clicked()
{
    close();
    Add_scree dlg;
    if(dlg.exec()==QDialog::Accepted) show();
    Updatatableview();
}

void show_scree::Updatatableview()
{
    if(model!=NULL) delete model;
    model=new QStandardItemModel;
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    model->setColumnCount(6);
    model->setHeaderData(0,Qt::Horizontal,"单号");
    model->setHeaderData(1,Qt::Horizontal,"单名");
    model->setHeaderData(2,Qt::Horizontal,"日期");
    model->setHeaderData(3,Qt::Horizontal,"价格");
    model->setHeaderData(4,Qt::Horizontal,"状态");
    model->setHeaderData(5,Qt::Horizontal,"实收");
    QVector<File::info> infos;
    File file("data.txt");
    file.read(infos);
    double total=0;
    double nowget=0;
    for(int i=0;i<infos.size();i++){
        model->setItem(i,0,new QStandardItem(infos[i].id));
        model->setItem(i,1,new QStandardItem(infos[i].name));
        model->setItem(i,2,new QStandardItem(infos[i].date));
        model->setItem(i,3,new QStandardItem(QString::number(infos[i].value)));
        model->setItem(i,4,new QStandardItem(infos[i].status));
        model->setItem(i,5,new QStandardItem(QString::number(infos[i].value*0.7)));
        total+=infos[i].value;
        if(infos[i].status=="finish")
            nowget+=infos[i].value*0.7;
    }
    ui->lineEdit->setText(QString::number(total));
    ui->lineEdit_2->setText(QString::number(total*0.7));
    ui->lineEdit_3->setText(QString::number(nowget));
}

void show_scree::on_pushButton_clicked()
{
    close();
}
