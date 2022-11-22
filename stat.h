#ifndef STAT_H
#define STAT_H
//test conection github.

#include <QDialog>
#include <QGridLayout>
#include <QWidget>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
#include "fourniseur.h"

QT_CHARTS_USE_NAMESPACE


//class statistiques;

namespace Ui {
class statistiques : public stat{};
}

class statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
   /* virtual */~statistiques();

private:
    Ui::statistiques *ui;
    stat s;
    Fourniseur A ;
};
#endif // STAT_H
