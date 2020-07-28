#include "tareas.h"
#include "ui_tareas.h"

#include <QDebug>
#include "principal.h"

Tareas::Tareas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tareas)
{
    ui->setupUi(this);
}

Tareas::~Tareas()
{
    delete ui;
}

QString Tareas::nombre() const
{
    return ui->inNombre->text();
}

QString Tareas::tipo() const
{
    QString tipo;
    if(ui->inUniversidad->isChecked()){
        tipo = tr("Universidad");
    }else if (ui->inPersonal->isChecked()){
        tipo = tr("Personal");
    }else if (ui->inFamiliar->isChecked()){
        tipo = tr("Familiar");
    }
    return tipo;
}

QString Tareas::fecha() const
{
    QString dateString = ui->inFecha->text();
    return dateString;
}

void Tareas::on_buttonBox_accepted()
{
    accept();
}

void Tareas::on_buttonBox_rejected()
{
    reject();
}
