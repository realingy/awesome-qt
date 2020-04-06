#include <QPushButton>

#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}"); //正则表达式
    lineEdit->setValidator(new QRegExpValidator(regExp, this)); //设置正则表达式

    connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged(const QString &str)
{
    Q_UNUSED(str)
    //buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}
