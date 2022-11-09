#include "event.h"
Event::Event(int CIN_EV, int ID_EV , int NB_INV_EV , QString NOM_EV, QString TYPE_EV, QDateTime DATE_EV)
{
this->CIN_EV=CIN_EV;
this->ID_EV=ID_EV;
this->NB_INV_EV =NB_INV_EV ;
this->NOM_EV=NOM_EV;
this->TYPE_EV=TYPE_EV;
this->DATE_EV=DATE_EV;
}

bool Event::ajouter_ev()
{
    QSqlQuery query1;// Requete d'ajout sur table EVENT
    QSqlQuery query2;// Requete d'ajout sur table HISEV
    QString ress = QString::number(CIN_EV);
    QString res = QString::number(ID_EV);
    QString resss = QString::number(NB_INV_EV);

    query1.prepare("insert into EVENT (TYPE_EV,NOM_EV,DATE_EV,ID_EV,CIN_EV,NB_INV_EV)""values (:TYPE_EV,:NOM_EV,:DATE_EV,:ID_EV,:CIN_EV,:NB_INV_EV)");

    query2.prepare("insert into HISEV (NOM_HIS,ID_HIS,CIN_HIS,ACTION,USER_HIS)""values (:NOM_HIS,:ID_HIS,:CIN_HIS,'CREATED','ADMIN')");

    //Creation des variable liees a EVENT

    query1.bindValue(":TYPE_EV",TYPE_EV);
    query1.bindValue(":NOM_EV",NOM_EV);
    query1.bindValue(":DATE_EV",DATE_EV);
    query1.bindValue(":CIN_EV",ress);
    query1.bindValue(":NB_INV_EV",resss);
    query1.bindValue(":ID_EV",res);

   //Creation des variable liees a HISTORIQUE

     query2.bindValue(":NOM_HIS",NOM_EV);
     query2.bindValue(":CIN_HIS",ress);
     query2.bindValue(":ID_HIS",res);



    query1.exec();
   return query2.exec();

}


bool Event::supprimer_ev(int ID_EV)
{


    QSqlQuery query;// Requete d'ajout sur table EVENT
    QSqlQuery query2;// Requete d'ajout sur table HISEV
    QString res=QString::number(ID_EV);



    query.prepare("Delete from EVENT where ID_EV=:ID_EV");


    query2.prepare( "insert into HISEV (NOM_HIS,ID_HIS,CIN_HIS,ACTION,USER_HIS)""SELECT NOM_EV,ID_EV,CIN_EV,'DELETED','ADMIN' FROM EVENT WHERE ID_EV=:ID_EV");


    //Creation des variable liees
    query.bindValue(":ID_EV",res);
    query2.bindValue(":ID_EV",res);


             query2.exec();
    return query.exec();

}




bool Event::modifier_ev(int ID_EV,int CIN_EV,int NB_INV_EV)
{
 QSqlQuery query;// Requete d'ajout sur table EVENT
 QSqlQuery query2;// Requete d'ajout sur table HISEV

 QString res=QString::number(ID_EV);
 QString ress = QString::number(CIN_EV);
 QString resss = QString::number(NB_INV_EV);
        query.prepare ("UPDATE EVENT set  NOM_EV = :NOM_EV, TYPE_EV = :TYPE_EV,DATE_EV= :DATE_EV, CIN_EV= :CIN_EV,NB_INV_EV = :NB_INV_EV where ID_EV=:ID_EV");
        query2.prepare("insert into HISEV (NOM_HIS,ID_HIS,CIN_HIS,ACTION,USER_HIS)""values (:NOM_HIS,:ID_HIS,:CIN_HIS,'UPDATED','ADMIN')");


//Creation des variable liees

        query.bindValue(":ID_EV",res);
        query.bindValue(":CIN_EV",CIN_EV);
        query.bindValue(":NOM_EV",NOM_EV);
        query.bindValue(":TYPE_EV",TYPE_EV);
        query.bindValue(":DATE_EV",DATE_EV);
        query.bindValue(":NB_INV_EV",resss);

//Creation des variable liees a HISTORIQUE

        query2.bindValue(":NOM_HIS",NOM_EV);
        query2.bindValue(":CIN_HIS",ress);
        query2.bindValue(":ID_HIS",res);

        query.exec();
        return query2.exec();


}

// Afficher la liste des evenements :

QSqlQueryModel * Event::afficher_ev()
{
  QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("select TYPE_EV,NOM_EV,DATE_EV,CIN_EV,ID_EV,NB_INV_EV from EVENT");

   model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE D'EVENEMENT :"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM D'EVENEMENT :"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE D'EVENEMENT :"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN CLIENT :"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID D'EVENEMENT :"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("NOMBRE D'INVITE :"));

     return model;
}



/////////////////////////////// fin d'implementation des crud  /////////////////////////////////



// Afficher l'historique des evenements :

QSqlQueryModel * Event::afficher_his()
{
  QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("select * from HISEV ORDER BY DATE_HIS DESC");

   model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM :"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID :"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("CIN :"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("ACTION :"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("BY :"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE :"));

     return model;
}




//********************************************************* RECHERCHE ***************************************************



/*



QSqlQueryModel * Event::rechercher_ev()
{
    QSqlQuery query;// Requete d'ajout sur table rech/tri

    QString res=QString::number(ID_EV);
    QString ress = QString::number(CIN_EV);
    QString resss = QString::number(NB_INV_EV);


    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT TYPE_EV,NOM_EV,DATE_EV,CIN_EV,ID_EV,NB_INV_EV FROM EVENT WHERE CIN_EV LIKE :CIN_EV OR ID_EV LIKE :ID_EV OR NB_INV_EV LIKE :NB_INV_EV");


    query.bindValue(":ID_EV",res);
    query.bindValue(":CIN_EV",ress);
    query.bindValue(":NB_INV_EV",resss);









    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM :"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID :"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CIN :"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ACTION :"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("BY :"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE :"));

    return model;

}



*/







//************************************************************* TRI ***************************************************



// tri par date

QSqlQueryModel * Event::afficher_tri_date()
{
    QSqlQueryModel * model= new QSqlQueryModel();


model->setQuery("select TYPE_EV,NOM_EV,DATE_EV,CIN_EV,ID_EV,NB_INV_EV from EVENT order by DATE_EV desc ");

model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE D'EVENEMENT :"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM D'EVENEMENT :"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE D'EVENEMENT :"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN CLIENT :"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID D'EVENEMENT :"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NOMBRE D'INVITE :"));

    return model;
}




// tri par nom

QSqlQueryModel * Event::afficher_tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();


model->setQuery("select TYPE_EV,NOM_EV,DATE_EV,CIN_EV,ID_EV,NB_INV_EV from EVENT order by NOM_EV ");

model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE D'EVENEMENT :"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM D'EVENEMENT :"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE D'EVENEMENT :"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN CLIENT :"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID D'EVENEMENT :"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NOMBRE D'INVITE :"));

    return model;
}




// tri par nb inv

QSqlQueryModel * Event::afficher_tri_nb_inv()
{
    QSqlQueryModel * model= new QSqlQueryModel();


model->setQuery("select TYPE_EV,NOM_EV,DATE_EV,CIN_EV,ID_EV,NB_INV_EV from EVENT order by NB_INV_EV desc ");

model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE D'EVENEMENT :"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM D'EVENEMENT :"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE D'EVENEMENT :"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN CLIENT :"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID D'EVENEMENT :"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NOMBRE D'INVITE :"));

    return model;
}




//************************************************************* STAT ***************************************************


