#ifndef CONTACT_H
#define CONTACT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class contact; }
QT_END_NAMESPACE

class contact : public QMainWindow
{
    Q_OBJECT

public:
    contact(QWidget *parent = nullptr);
    ~contact();

private slots:
    void on_pushButton_clicked();
    void clear();

private:
    Ui::contact *ui;
};
#endif // CONTACT_H
