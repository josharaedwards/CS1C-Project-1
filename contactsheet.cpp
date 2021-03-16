#include "contactsheet.h"
#include "dialog.h"
#include "ui_contactsheet.h"
#include "ui_dialog.h"

#include <QMessageBox>

///Contact sheet GUI allows the user to send inquiries and questions.
///The window prompt the user to fill in boxes such as full name, e-mail and message. When the message is sent a pop up window let
///the user know that was suscesfully sent
ContactSheet::ContactSheet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactSheet)
{
    ui->setupUi(this);
}

ContactSheet::~ContactSheet()
{
    delete ui;
}

void ContactSheet::sendBtnHandler()
{
    Dialog *prompt = new Dialog(nullptr, "Message sent successfully!");

    prompt->setWindowTitle("Success");
    prompt->setAttribute(Qt::WA_DeleteOnClose);
    prompt->show();

    this->~ContactSheet();
}

void ContactSheet::clear()
{
    ui->plainTextEdit->setPlainText("");
}
