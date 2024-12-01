#include "logindialog.h"


LoginDialog::LoginDialog(QWidget *parent): QDialog(parent)
{
    setWindowTitle("Iniciar Sesión");
    setFixedSize(300, 200);

    QLabel *usuarioLabel = new QLabel("Usuario:", this);
    usuarioLineEdit = new QLineEdit(this);

    QLabel *contrasenaLabel = new QLabel("Contraseña:", this);
    contrasenaLineEdit = new QLineEdit(this);
    contrasenaLineEdit->setEchoMode(QLineEdit::Password);

    QPushButton *iniciarSesionButton = new QPushButton("Iniciar Sesión", this);
    connect(iniciarSesionButton, &QPushButton::clicked, this, &LoginDialog::verificarCredenciales);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(usuarioLabel);
    layout->addWidget(usuarioLineEdit);
    layout->addWidget(contrasenaLabel);
    layout->addWidget(contrasenaLineEdit);
    layout->addWidget(iniciarSesionButton);

    setLayout(layout);
}

QString LoginDialog::usuarioGlobal = "";

void LoginDialog::verificarCredenciales()
{
    QString usuario = usuarioLineEdit->text();
    QString contrasena = contrasenaLineEdit->text();

    QFile archivo("data.txt");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo de datos.");
        return;
    }

    QTextStream in(&archivo);
    bool credencialesCorrectas = false;

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList datos = linea.split(",");
        if (datos.size() == 2 && datos[0] == usuario && datos[1] == contrasena)
        {
            credencialesCorrectas = true;
            break;
        }
    }

    archivo.close();

    if (credencialesCorrectas)
    {
        usuarioGlobal = usuario;
        accept();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos.");
    }
}
