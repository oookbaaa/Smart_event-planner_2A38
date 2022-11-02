#include "event.h"

Event::Event(int CIN_EV,QString NOM_EV,QString TYPE_EV,QDateTime DATE_EV)
{
this->CIN_EV=CIN_EV;
this->NOM_EV=NOM_EV;
this->TYPE_EV=TYPE_EV;
this->DATE_EV=DATE_EV;
}

bool Event::ajouter_ev()
{
    QSqlQuery query;
    QString res = QString::number(CIN_EV);
    query.prepare("insert into EVENT (TYPE_EV,NOM_EV,DATE_EV,CIN_EV)""values (:TYPE_EV,:NOM_EV,:DATE_EV,:CIN_EV)");
    //Creation des variable liees

    query.bindValue(":TYPE_EV",TYPE_EV);
    query.bindValue(":NOM_EV",NOM_EV);
    query.bindValue(":DATE_EV",DATE_EV);
    query.bindValue(":CIN_EV",res);

    return query.exec();

}


bool Event::supprimer_ev(int CIN_EV)
{
    QSqlQuery query;
    QString res=QString::number(CIN_EV);

    query.prepare("Delete from EVENT where CIN_EV=:CIN_EV");

    //Creation des variable liees
    query.bindValue(":CIN_EV",res);

    return query.exec();
}



QSqlQueryModel * Event::afficher_ev()
{
  QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("select TYPE_EV,NOM_EV,DATE_EV,CIN_EV from EVENT");

   model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE D'EVENEMENT :"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM D'EVENEMENT :"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE D'EVENEMENT :"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN CLIENT :"));

     return model;
}


bool Event::modifier_ev(int CIN_EV)
{
 QSqlQuery query;
 QString res=QString::number(CIN_EV);
         query.prepare ("UPDATE EVENT set  NOM_EV = :NOM_EV, TYPE_EV = :TYPE_EV,DATE_EV= :DATE_EV where CIN_EV=:CIN_EV" );

        query.bindValue(":CIN_EV",CIN_EV);
        query.bindValue(":NOM_EV",NOM_EV);
        query.bindValue(":TYPE_EV",TYPE_EV);
        query.bindValue(":DATE_EV",DATE_EV);


    return    query.exec();

}

/*
bool client::modifier(int id)
{
    QSqlQuery query;

       QString res= QString::number(id);
       query.prepare("UPDATE client SET id=:id,nom=:nom,prenom=:prenom ,adresse=:adresse WHERE id=:id");
       query.bindValue(":id", id);
       query.bindValue(":nom", nom);
       query.bindValue(":prenom", prenom);
       query.bindValue(":adresse", adresse);




          return    query.exec();
}
*/
