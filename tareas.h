#ifndef TAREAS_H
#define TAREAS_H

#include <QDialog>

namespace Ui {
class Tareas;
}

class Tareas : public QDialog
{
    Q_OBJECT

public:
    explicit Tareas(QWidget *parent = nullptr);
    ~Tareas();
    void obtenerDatos();

    QString nombre() const;
    QString tipo() const;
    QString fecha() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Tareas *ui;
};

#endif // TAREAS_H
