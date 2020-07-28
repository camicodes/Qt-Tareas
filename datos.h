#ifndef DATOS_H
#define DATOS_H

#include <QObject>


class Datos : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int numero READ numero)
    Q_PROPERTY(QString nombre READ nombre)
    Q_PROPERTY(QString tipo READ tipo)
    Q_PROPERTY(QString fecha READ fecha)

public:
    explicit Datos(QObject *parent = nullptr);
    Datos(int numero, QString nombre, QString tipo, QString fecha);
    int numero () const;
    QString nombre() const;
    QString tipo() const;
    QString fecha() const;

signals:

private:
    int m_numero;
    QString m_nombre;
    QString m_tipo;
    QString m_fecha;

};

#endif // DATOS_H
