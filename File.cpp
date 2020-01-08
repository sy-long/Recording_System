#include "File.h"
#include <QFile>
#include <QVector>
#include <QTextStream>
File::File(QString name):filename(name){}

int File::read(QVector<File::info> &infos){
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return -1;
    }
    info tinfo;
    QTextStream in(&file);
    while(!in.atEnd()){
        in>>tinfo.id;
        in>>tinfo.name;
        in>>tinfo.date;
        in>>tinfo.value;
        in>>tinfo.status;
        infos.push_back(tinfo);
    }
    return 0;
}

int File::write(QVector<info> &infos){
    QFile file(filename);
    if(!file.open((QIODevice::WriteOnly|QIODevice::Text))){
        return -1;
    }
    QTextStream out(&file);
    for(int i=0;i<infos.size();i++){
        out<<infos[i].id<<" ";
        out<<infos[i].name<<" ";
        out<<infos[i].date<<" ";
        out<<infos[i].value<<" ";
        out<<infos[i].status;
        out<<"\n";
    }
    file.close();
    return 0;
}

int File::append(info &oneinfo){
    QFile file(filename);
    if(!file.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text)){
        return -1;
    }
    QTextStream out(&file);
    out<<oneinfo.id<<" ";
    out<<oneinfo.name<<" ";
    out<<oneinfo.date<<" ";
    out<<oneinfo.value<<" ";
    out<<oneinfo.status<<" ";
    out<<"\n";
    file.close();
    return 0;
}
