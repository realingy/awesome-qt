#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

//单格
class Cell : public QTableWidgetItem
{
public:
    Cell();

    QTableWidgetItem *clone() const;
    void setData(int role, const QVariant &value);
    QVariant data(int role) const;
    void setFormula(const QString &formula);
    QString formula() const;
    void setDirty();

private:
    QVariant value() const;
    QVariant evalExpression(const QString &str, int &pos) const;
    QVariant evalTerm(const QString &str, int &pos) const;
    QVariant evalFactor(const QString &str, int &pos) const;

    //mutable：在const成员函数中可以修改
    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;
};

#endif
