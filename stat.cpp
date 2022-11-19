#include "stat.h"
#include "ui_stat.h"
#include <qvariant.h>
#include "fourniseur.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCore>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
#include <qwindow.h>
#include <QChartView>
statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
   // ui->setupUi(this);
       QBarSet *set=new QBarSet("Nombre des prix");
      *set<<A.calculer1(1,10)<<A.calculer1(11,100)<<A.calculer1(101,1000)<<A.calculer1(1001,10000)<<A.calculer1(10001,100000);
       QBarSeries *series=new QBarSeries();
       series->append(set);
       QChart *chart=new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistiques des prix");
       chart->setAnimationOptions(QChart::AllAnimations);
       QStringList prix;
       prix<<"[1dt..10dt]"<<"[11dt..100dt]"<<"[101dt..1000dt]"<<"[1001dt..10000dt]"<<"[10001dt..100000dt]";
       QBarCategoryAxis *axis=new QBarCategoryAxis();
       axis->append(prix);
       chart->createDefaultAxes();
       chart->setAxisX(axis,series);

       QChartView *chartview=new QChartView(chart);

       QGridLayout *mainLayout = new QGridLayout;
       mainLayout->addWidget(chartview, 5, 5);
       this->setLayout(mainLayout);
}
statistiques ::~statistiques()
{
delete ui;
}
