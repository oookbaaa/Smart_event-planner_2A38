#include "mainwindow.h"
#include "connection.h"
#include "QMessageBox"
#include "QApplication"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr("connection successful.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
        QObject::tr("connection failed.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
