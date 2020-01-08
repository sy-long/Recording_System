#ifndef MAIN_SCREE_H
#define MAIN_SCREE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_Scree; }
QT_END_NAMESPACE

class Main_Scree : public QWidget
{
    Q_OBJECT

public:
    Main_Scree(QWidget *parent = nullptr);
    ~Main_Scree();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Main_Scree *ui;
};
#endif // MAIN_SCREE_H
