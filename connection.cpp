#include "connection.h"
//test conection github.

Connection::Connection()
{

}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
db.setDatabaseName("Source_Projet_2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("zikouzikou");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

    return  test;
}
void Connection::closeconnection(){db.close();}
