#include "show_scree.h"
#include <QVector>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    show_scree w;
    w.show();
    return a.exec();
}
