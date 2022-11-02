#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
db.setDatabaseName("Projet_2A");
db.setUserName("okba");//inserer nom de l'utilisateur
db.setPassword("okba");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

    return  test;
}
void Connection::closeconnection(){db.close();}
