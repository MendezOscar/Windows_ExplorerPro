#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include <qlistwidget.h>
#include "Lista.h"
#include "carpeta.h"
#include "archivo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString cop;
    QTreeWidgetItem* It;
    QTreeWidgetItem * r;
    ArchivoBase *a;
    Lista <ArchivoBase*>* b;
    Lista <ArchivoBase*>* almacenamiento;
    QListWidgetItem* cortar;
    QListWidgetItem* eliminar;
    QListWidgetItem* agCar(QString name);
    QTreeWidgetItem* agregarCarpet(QTreeWidgetItem * parent,QString name);
    void agregarArchiv(QTreeWidgetItem* parent, QString name);
    void agArch(QListWidgetItem* parent, QString name);
    void agregarPic(QTreeWidgetItem* parent, QString name);
    void agPict(QListWidgetItem* parent, QString name);
    void agregarWin(QTreeWidgetItem* parent, QString name);
    void agW(QListWidgetItem* parent, QString name);

private slots:

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_actionNueva_Carpeta_triggered();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_actionIconos_2_triggered();

    void on_actionArchivo_de_Texto_triggered();

    void on_actionArchivo_Winrar_triggered();

    void on_actionMapa_de_bits_triggered();

    void on_actionSalir_triggered();

    void on_actionNueva_Carpeta_2_triggered();

    void on_actionNuevo_Archivo_2_triggered();

    void on_actionArchivo_Winrar_2_triggered();

    void on_actionMapa_de_Bit_triggered();

    void on_actionCopiar_triggered();

    void on_actionCortar_triggered();

    void on_actionPegar_triggered();

    void on_actionEliminar_triggered();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_actionCopiar_2_triggered();

    void on_actionCortar_2_triggered();

    void on_actionPegar_2_triggered();

private:

    ArchivoBase* busqueda(QString nombre);

    void rellenarCarpeta(Carpeta **copiado, Carpeta** nuevo, int i);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
