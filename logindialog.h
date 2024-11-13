#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

class QLineEdit;

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);

private slots:
    void verificarCredenciales();

private:
    QLineEdit *usuarioLineEdit;
    QLineEdit *contrasenaLineEdit;
};

#endif // LOGINDIALOG_H
