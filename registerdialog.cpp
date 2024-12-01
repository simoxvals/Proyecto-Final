#include "registerdialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Registrate que no te arrepentiras");
    setFixedSize(300,200);

    QLabel *usuarioLabel = new QLabel("Usuario", this);
    usuarioLineEdit = new QLineEdit(this);

    QLabel *contrasenaLabel = new QLabel("Contraseña:", this);
    contrasenaLineEdit = new QLineEdit(this);
    contrasenaLineEdit->setEchoMode(QLineEdit::Password);

    QPushButton *registrarButton = new QPushButton("Registrar", this);
    connect(registrarButton, &QPushButton::clicked, this, &RegisterDialog::registrarUsuario);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(usuarioLabel);
    layout->addWidget(usuarioLineEdit);
    layout->addWidget(contrasenaLabel);
    layout->addWidget(contrasenaLineEdit);
    layout->addWidget(registrarButton);

    setLayout(layout);
}

void RegisterDialog::registrarUsuario()
{
    QString usuario = usuarioLineEdit->text();
    QString contrasena = contrasenaLineEdit->text();

    if (usuario.isEmpty() || contrasena.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor complete todos los campos.");
        return;
    }

    QFile archivo("data.txt");
    if (!archivo.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo de datos.");
        return;
    }

    QTextStream out(&archivo);
    out << usuario << "," << contrasena << "\n";
    archivo.close();

    QMessageBox::information(this, "Éxito", "Registro exitoso.");
    accept();
}
