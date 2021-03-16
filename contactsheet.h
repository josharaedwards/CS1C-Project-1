/**
 *  @file contactsheet.h
 *  @brief GUI controls for contactsheet
 */


#ifndef CONTACTSHEET_H
#define CONTACTSHEET_H

#include <QWidget>

///GUI, allows user to send a message or inquiry to the organization
namespace Ui {

class ContactSheet;
}

class ContactSheet : public QWidget
{
    Q_OBJECT

public:
    explicit ContactSheet(QWidget *parent = nullptr);
    ~ContactSheet();

private slots:
    void sendBtnHandler();
    void clear();

private:
    Ui::ContactSheet *ui;
};

#endif // CONTACTSHEET_H
