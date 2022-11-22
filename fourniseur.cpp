#include "fourniseur.h"
#include<QSqlQuery>
#include<QtDebug>
//test conection github.
Fourniseur::Fourniseur()
{
id=0; num_t=0; nom_f=""; produit="";prix=0;
}


Fourniseur::Fourniseur(QString nom_f ,QString produit,QString img,double prix,int id,int num_t)
{this->id=id; this->num_t=num_t; this->nom_f=nom_f;this->produit=produit ;this->prix=prix;this->img=img;}
int Fourniseur::getid(){return id;}
int Fourniseur::getnum_t(){return num_t;}
QString Fourniseur::getnom_f(){return nom_f;}
QString Fourniseur::getimg(){return img;}
QString Fourniseur::getproduit(){return produit;}
double Fourniseur::getprix(){return prix;}
void Fourniseur::setid(int id){this->id=id;}
void Fourniseur::setnum_t(int num_t){this->num_t=num_t;}
void Fourniseur::setnom_f(QString nom_f){this->nom_f=nom_f;}
void Fourniseur::setimg(QString img){this->img=img;}
void Fourniseur::setproduit(QString produit){this->produit=produit;}
void Fourniseur::setprix(double prix){this->prix=prix;}
bool Fourniseur::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString num_string= QString::number(num_t);
    QString prix_string= QString::number(prix);
    query.prepare("INSERT INTO FOURNISSEUR (PRIX, NUM_T, ID, PRODUIT, NOM_F,IMG)""values (:prix,:num_t,:id,:produit,:nom_f,:img)");
    //Creation des variable liees.
    query.bindValue(":prix",prix_string);
    query.bindValue(":num_t",num_string);
    query.bindValue(":id",id_string);
    query.bindValue(":produit",produit);
    query.bindValue(":nom_f",nom_f);
    query.bindValue(":img",img);
    return query.exec();

}

 QSqlQueryModel * Fourniseur::afficher()
{
  QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("SELECT* FROM FOURNISSEUR");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom_f"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("num_t"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("img"));



     return model;
}

 bool Fourniseur::supprimer(int id)
 {
     QSqlQuery query;
     QString sup=QString::number(id);

     query.prepare("Delete from fournisseur where id= :id");
     query.bindValue(":id",sup);

     return query.exec();
 }
 bool Fourniseur::modifier_f(int id)
 {
     QSqlQuery query;
     QString id_string= QString::number(id);
     QString num_string= QString::number(num_t);
      QString prix_string= QString::number(prix);

query.prepare("UPDATE FOURNISSEUR SET prix=:prix,num_t=:num_t,id=:id,produit=:produit ,nom_f=:nom_f WHERE id=:id");
        query.bindValue(":prix",prix_string);
        query.bindValue(":num_t",num_string);
        query.bindValue(":id",id_string);
        query.bindValue(":produit",produit);
        query.bindValue(":nom_f",nom_f);
        query.bindValue(":img",img);



          return    query.exec();
 }
QSqlQueryModel* Fourniseur::rechercher(const QString &str)

 {
       QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("SELECT* FROM FOURNISSEUR where nom_f like '"+str+"%' or id like '"+str+"%' or produit like '"+str+"%'");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom_f"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num_t"));
           model->setHeaderData(4,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("img"));


       return model;
}

//QString Fourniseur::retourpath()
//{
//    int id;

//    // Requête pour récupérer la question en cours
//    QSqlQuery query("SELECT question FROM questions WHERE id = ?");
//    query.bindValue(0, id);

//    // S'il n'y a pas d'erreur(s) on affiche
//    if (query.first())
//        return query.value(5).toString();
//        return QString();
//    // S'il y a une erreur on affiche un message
//    if (!query.exec())
//        return QString("<font color=\"red\">Impossible de récupérer les questions !</font>");

//}


 //************************************************************* TRI *************************************************



 // tri par prix

 QSqlQueryModel * Fourniseur::afficher_tri_prix ()
 {
     QSqlQueryModel * model= new QSqlQueryModel();


 model->setQuery("SELECT* FROM FOURNISSEUR order by prix desc ");

 model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom_f"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("num_t"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("id"));

     return model;
 }





 // tri par poduit

 QSqlQueryModel *Fourniseur::afficher_tri_produit()
 {
     QSqlQueryModel * model= new QSqlQueryModel();


 model->setQuery("SELECT* FROM FOURNISSEUR order by produit ");

 model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom_f"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("num_t"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("id"));

     return model;
 }






 QSqlQueryModel *Fourniseur::afficher_tri_nom_f()
 {
     QSqlQueryModel * model= new QSqlQueryModel();


 model->setQuery("SELECT* FROM FOURNISSEUR order by nom_f ");

 model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom_f"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("produit"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("num_t"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("img"));



     return model;
 }
 int Fourniseur::calculer1(int choix,int choix2)
     {
         QSqlQuery query;
               query.prepare("SELECT* FROM FOURNISSEUR WHERE prix BETWEEN (:choix) AND (:choix2)");
               query.bindValue(":choix",choix);
               query.bindValue(":choix2",choix2);

               query.exec();
               int total = 0;
               while (query.next()) {
                 total++;

      }
               return total;

      }
