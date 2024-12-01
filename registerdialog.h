#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextStream>
#include <QFile>
#include <QVBoxLayout>
#include <QMessageBox>


class RegisterDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit *usuarioLineEdit;
    QLineEdit *contrasenaLineEdit;

public:
    RegisterDialog(QWidget *parent = nullptr);

public slots:
    void registrarUsuario();

};

#endif // REGISTERDIALOG_H

