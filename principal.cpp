#include "principal.h"
#include "ui_principal.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTableWidgetItem>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    inicializarDatos();
    fila = -1;
}

Principal::~Principal()
{
    delete ui;
}

void Principal::inicializarDatos()
{
    //Abrir el archivo tareas
    QFile archivo ("Tareas.csv");
    if(archivo.open(QFile::ReadOnly)){
        QTextStream in(&archivo);
        while (!in.atEnd()){
            QString linea = in.readLine();
            //Separa datos por ';'
            QStringList datos = linea.split(';');
            int numero = datos[0].toInt();
            QString nombre = datos[1];
            QString tipo = datos[2];
            QString fecha = datos[3];
           // qDebug() << numero << nombre << tipo << fecha;
           int posicion = ui->outTareas->rowCount();
           ui->outTareas->insertRow(posicion);
           ui->outTareas->setItem(posicion,0,new QTableWidgetItem(QString::number(numero)));
           ui->outTareas->setItem(posicion,1,new QTableWidgetItem(nombre));
           ui->outTareas->setItem(posicion,2,new QTableWidgetItem(tipo));
           ui->outTareas->setItem(posicion,3,new QTableWidgetItem(fecha));
        }
    }else{
        qDebug () << "Error al abrir el archivo";
    }
    archivo.close();
}

int Principal::setNumero()
{
    return ++m_numero;
}

void Principal::on_actionAgregar_triggered()
{
    int res;
    Tareas dialog(this);
    res = dialog.exec();
    if(res == QDialog::Rejected)
        return;
    QString nombre = dialog.nombre();
    QString fecha = dialog.fecha();
    QString tipo = dialog.tipo();
    int posicion = ui->outTareas->rowCount();
    ui->outTareas->insertRow(posicion);
    ui->outTareas->setItem(posicion,0,new QTableWidgetItem(QString::number(setNumero())));
    ui->outTareas->setItem(posicion,1,new QTableWidgetItem(nombre));
    ui->outTareas->setItem(posicion,2,new QTableWidgetItem(tipo));
    ui->outTareas->setItem(posicion,3, new QTableWidgetItem(fecha));
}

void Principal::on_actionFinalizar_triggered()
{
    ui->outTareas->removeRow(fila);
    ui->statusbar->showMessage(tr("Fila eliminada"), 5000);
}

void Principal::on_outTareas_itemClicked(QTableWidgetItem *item)
{
    fila = item->row();
}

