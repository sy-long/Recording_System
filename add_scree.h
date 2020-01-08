#ifndef ADD_SCREE_H
#define ADD_SCREE_H

#include <QDialog>

namespace Ui {
class Add_scree;
}

class Add_scree : public QDialog
{
    Q_OBJECT

public:
    explicit Add_scree(QWidget *parent = nullptr);
    ~Add_scree();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Add_scree *ui;
};

#endif // ADD_SCREE_H
