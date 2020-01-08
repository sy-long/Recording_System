#ifndef FILE_H
#define FILE_H

#include <QString>
class File{
public:
    struct info{
        QString id;
        QString name;
        QString date;
        double value;
        QString status;
    };
private:
    QString filename;
public:
    File(QString);
    int read(QVector<info> &);
    int write(QVector<info> &);
    int append(info&);
};

#endif // FILE_H
