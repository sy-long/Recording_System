#include "main_scree.h"
#include <QVector>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Main_Scree w;
    w.show();
    return a.exec();
}
