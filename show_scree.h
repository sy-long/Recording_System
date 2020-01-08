#ifndef SHOW_SCREE_H
#define SHOW_SCREE_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class show_scree;
}

class show_scree : public QDialog
{
    Q_OBJECT

public:
    explicit show_scree(QWidget *parent = nullptr);
    ~show_scree();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void Updatatableview();
private:
    Ui::show_scree *ui;
    QStandardItemModel *model;
};

#endif // SHOW_SCREE_H
