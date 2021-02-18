#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QMainWindow>
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Mybutton; }
QT_END_NAMESPACE

class Mybutton : public QMainWindow
{
    Q_OBJECT

public:
    Mybutton(QWidget *parent = nullptr);
    ~Mybutton();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Mybutton *ui;
};
#endif // MYBUTTON_H
