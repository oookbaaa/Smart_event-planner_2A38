#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class Fournisseurs
{
    QString nom_F;
    QString Produit;
    double Prix;
    int Num_tel;
    QString Email;

public:
    Fournisseurs();
    Fournisseurs(QString, QString,double,int, QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
};
#endif // FOURNISSEURS_H
