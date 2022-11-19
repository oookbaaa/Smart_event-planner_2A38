#include "fournisseurs.h"

Fournisseurs:: Fournisseurs(QString nom_F, QString Produit,double Prix,int Num_tel, QString Email)
{
    this->nom_F=nom_F;
    this->Produit=Produit;
    this->Prix=Prix;
    this->Num_tel=Num_tel;
    this->Email=Email;
}
