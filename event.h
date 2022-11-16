#ifndef EVENT_H
#define EVENT_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include<QDateTime>
#include<QMessageBox>
#include<QRadioButton>
#include <QWidget>

class Event
{

    QString NOM_EV,TYPE_EV,NOM_HIS;
    QDateTime DATE_EV;
    int CIN_EV,ID_EV,NB_INV_EV,ID_HIS,CIN_HIS;
public:
    // Constructeurs
    Event(){}
    Event(int,int,int,QString,QString,QDateTime);
    // Getters
    QString getnom_ev(){return NOM_EV;}
    QString gettype_ev(){return TYPE_EV;}
    QDateTime getdate_ev(){return DATE_EV;}
    int getcin_ev(){return CIN_EV;}
    int getid_ev(){return ID_EV;}
    // setters
    void Setnom_ev(QString n){NOM_EV=n;}
    void Settype_ev(QString t){TYPE_EV=t;}
    void setdate_ev(QDateTime d){DATE_EV=d;}
    void setcin_ev(int CIN_EV){this->CIN_EV=CIN_EV;}
    void setid_ev(int ID_EV){this->ID_EV=ID_EV;}
    //Functions
    bool  ajouter_ev();
    bool supprimer_ev(int ID_EV);
    bool modifier_ev(int ID_EV,int CIN_EV,int NB_INV_EV);


    QSqlQueryModel * afficher_ev();
    QSqlQueryModel * afficher_his();
    QSqlQueryModel * afficher_tri_date();
    QSqlQueryModel * afficher_tri_nom();
    QSqlQueryModel * afficher_tri_nb_inv();
    QSqlQueryModel* rechercher(QString);


};

#endif // EVENT_H
