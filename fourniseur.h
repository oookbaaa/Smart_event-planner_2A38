#ifndef FOURNISEUR_H
#define FOURNISEUR_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Fourniseur
{
public:
    Fourniseur();
    Fourniseur(QString,QString,QString,double,int,int);
    QString getnom_f();
    QString getproduit();
    QString getimg();
    double getprix();
    int getid();
    int getnum_t();
    void setid(int);
    void setnum_t(int);
    void setnom_f(QString);
    void setproduit(QString);
    void setimg(QString);
    void setprix(double);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_f(int id);
    QSqlQueryModel * rechercher(const QString&);

    QSqlQueryModel * afficher_tri_prix ();
    QSqlQueryModel * afficher_tri_produit ();
    QSqlQueryModel * afficher_tri_nom_f ();
    int calculer1(int choix,int choix2);
//    QString  * retourpath();




private:
        QString nom_f,produit,img;
        double prix;
        int id,num_t;

};

#endif // FOURNISEUR_H
