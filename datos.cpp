#include "datos.h"

Datos::Datos(QObject *parent) : QObject(parent)
{

}

Datos::Datos(int numero, QString nombre, QString tipo, QString fecha)
{
    m_numero = numero;
    m_nombre = nombre;
    m_tipo = tipo;
    m_fecha = fecha;
}

int Datos::numero() const
{
    return m_numero;
}

QString Datos::nombre() const
{
    return m_nombre;
}

QString Datos::tipo() const
{
    return m_tipo;
}

QString Datos::fecha() const
{
    return m_fecha;
}




