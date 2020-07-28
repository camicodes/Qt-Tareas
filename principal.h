#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "tareas.h"

#include "datos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionAgregar_triggered();
    void on_actionFinalizar_triggered();
    void on_outTareas_itemClicked(QTableWidgetItem *item);

private:
    Ui::Principal *ui;
    QList<Datos*> m_datos;
    void inicializarDatos();
    int m_numero = 3;
    int setNumero();
    int fila;
};
#endif // PRINCIPAL_H
