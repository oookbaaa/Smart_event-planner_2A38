#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
db.setDatabaseName("Projet_2A");
db.setUserName("okba");
db.setPassword("okba");

if (db.open()) test=true;

    return  test;
}
void Connection::closeconnection(){db.close();}
