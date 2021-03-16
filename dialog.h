#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>

namespace Ui {
class Dialog;
}

class Dialog : public QWidget
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    Dialog(QWidget *parent = nullptr, QString dialogText = "");
    ~Dialog();

private slots:
    void closeDialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
