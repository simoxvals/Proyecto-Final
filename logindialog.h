#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>



class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    static QString usuarioGlobal;

public slots:
    void verificarCredenciales();

private:
    QLineEdit *usuarioLineEdit;
    QLineEdit *contrasenaLineEdit;
};

#endif // LOGINDIALOG_H
