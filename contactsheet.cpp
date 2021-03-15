#include "contactsheet.h"
#include "dialog.h"
#include "ui_contactsheet.h"
#include "ui_dialog.h"

#include <QMessageBox>

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
}

void ContactSheet::clear()
{
    ui->plainTextEdit->setPlainText("");
}
