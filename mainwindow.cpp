#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include "dialog.h"
#include <QMessageBox>
#include<iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    r = new QTreeWidgetItem();
    b = new Lista <ArchivoBase*>();
    a = new ArchivoBase();
    almacenamiento = new Lista<ArchivoBase*>();
    b->inserta(new Carpeta("D:","D:"));
    ui->treeWidget->setColumnCount(1);
    this->It = new QTreeWidgetItem(ui->treeWidget);
    ui->treeWidget->addTopLevelItem(It);
    It->setText(0,b->buscar(0)->nombre);
    It->setIcon(0,QIcon(":/desktop.png"));
    ui->lineEdit->insert(a->path);
    ui->actionArchivo_de_Texto->setDisabled(true);
    ui->actionArchivo_Winrar->setDisabled(true);
    ui->actionArchivo_Winrar_2->setDisabled(true);
    ui->actionCopiar->setDisabled(true);
    ui->actionCopiar_2->setDisabled(true);
    ui->actionCortar->setDisabled(true);
    ui->actionCortar_2->setDisabled(true);
    ui->actionMapa_de_Bit->setDisabled(true);
    ui->actionMapa_de_bits->setDisabled(true);
    ui->actionNueva_Carpeta->setDisabled(true);
    ui->actionNueva_Carpeta_2->setDisabled(true);
    ui->actionEliminar->setDisabled(true);
    ui->actionNuevo_Archivo_2->setDisabled(true);
    ui->actionPegar->setDisabled(true);
    ui->actionPegar_2->setDisabled(true);
    ui->listWidget->setViewMode(QListWidget::IconMode);
    ui->listWidget_2->setViewMode(QListWidget::ListMode);
}

QTreeWidgetItem* MainWindow::agregarCarpet(QTreeWidgetItem * parent,QString nombre)
{
    QTreeWidgetItem* It = new QTreeWidgetItem();
    It->setText(0,nombre);
    parent->addChild(It);
    It->setIcon(0,QIcon(":/folder.png"));
    return It;
}

void MainWindow::agregarArchiv(QTreeWidgetItem* parent, QString nombre)
{
    QTreeWidgetItem* It = new QTreeWidgetItem();
    It->setText(0,nombre);
    It->setIcon(0,QIcon(":/archivo.png"));
    parent->addChild(It);
}

void MainWindow::agregarPic(QTreeWidgetItem *parent, QString nombre){

    QTreeWidgetItem* It = new QTreeWidgetItem();
    It->setText(0,nombre);
    It->setIcon(0,QIcon(":/picture.png"));
    parent->addChild(It);

}

void MainWindow::agregarWin(QTreeWidgetItem *parent, QString nombre){

    QTreeWidgetItem* It = new QTreeWidgetItem();
    It->setText(0,nombre);
    It->setIcon(0,QIcon(":/WinRAR.png"));
    parent->addChild(It);

}

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(item->text(column)+"\\"!=ui->lineEdit->text() )
       ui->lineEdit->insert(item->text(column)+"\\");
    ui->actionArchivo_de_Texto->setDisabled(false);
    ui->actionArchivo_Winrar->setDisabled(false);
    ui->actionArchivo_Winrar_2->setDisabled(false);
    ui->actionCopiar->setDisabled(false);
    ui->actionCopiar_2->setDisabled(false);
    ui->actionCortar->setDisabled(false);
    ui->actionNuevo_Archivo_2->setDisabled(false);
    ui->actionCortar_2->setDisabled(false);
    ui->actionMapa_de_Bit->setDisabled(false);
    ui->actionMapa_de_bits->setDisabled(false);
    ui->actionNueva_Carpeta->setDisabled(false);
    ui->actionNueva_Carpeta_2->setDisabled(false);
    ui->actionEliminar->setDisabled(false);
    ui->actionPegar->setDisabled(false);
    ui->actionPegar_2->setDisabled(false);
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
         ui->listWidget->clear();
         ui->listWidget_2->clear();
         if(item->text(0)!="D:"){

         }else if(item->text(0)=="D:"){

            }
          for(int i = 0; i < item->childCount();i++){

              QListWidgetItem*itm = new  QListWidgetItem(ui->listWidget);
              QListWidgetItem*itm2 = new  QListWidgetItem(ui->listWidget_2);
                itm->setText(item->child(i)->text(column));
                itm->setIcon(item->child(i)->icon(column));
                itm2->setText(item->child(i)->text(column));
                itm2->setIcon(item->child(i)->icon(column));
              }

          r = item;
          cop = item->text(0);

  }

void MainWindow::on_actionNueva_Carpeta_triggered()
{
    Dialog n;
    n.setModal(true);
    n.exec();
    b->inserta(new Carpeta(n.carpeta, n.carpeta+"//"));
    agregarCarpet(r,b->buscar(b->size-1)->nombre);
    QListWidgetItem * itm = new QListWidgetItem(ui->listWidget);
    QListWidgetItem *itm2 = new QListWidgetItem(ui->listWidget_2);
    itm->setIcon(QIcon(":/folder.png"));
    itm->setText(n.carpeta);
    itm2->setIcon(QIcon(":/folder.png"));
    itm2->setText(n.carpeta);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionIconos_2_triggered()
{
    ui->stackedWidget->setCurrentIndex(!ui->stackedWidget->currentIndex());

}

void MainWindow::on_actionArchivo_de_Texto_triggered()
{
    Dialog n;
    n.setModal(true);
    n.exec();
    b->inserta(new Archivo(n.carpeta, n.ext + "//"));
    agregarArchiv(r,b->buscar(b->size-1)->nombre);
    QListWidgetItem * itm = new QListWidgetItem(ui->listWidget);
    QListWidgetItem *itm2 = new QListWidgetItem(ui->listWidget_2);
    itm->setIcon(QIcon(":/archivo.png"));
    itm2->setIcon(QIcon(":/archivo.png"));
    itm2->setText(n.carpeta);
    itm->setText(n.carpeta);
}

void MainWindow::on_actionArchivo_Winrar_triggered()
{
    Dialog n;
    n.setModal(true);
    n.exec();
    b->inserta(new Archivo(n.carpeta, n.ext2 + "//"));
    agregarWin(r,b->buscar(b->size-1)->nombre);
    QListWidgetItem * itm = new QListWidgetItem(ui->listWidget);
    QListWidgetItem *itm2 = new QListWidgetItem(ui->listWidget_2);
    itm->setIcon(QIcon(":/WinRAR.png"));
    itm->setText(n.carpeta);
    itm2->setIcon(QIcon(":/WinRAR.png"));
    itm2->setText(n.carpeta);
}

void MainWindow::on_actionMapa_de_bits_triggered()
{
    Dialog n;
    n.setModal(true);
    n.exec();
    b->inserta(new Archivo(n.carpeta, n.ext1 + "//"));
    agregarPic(r,b->buscar(b->size-1)->nombre);
    QListWidgetItem * itm = new QListWidgetItem(ui->listWidget);
    QListWidgetItem *itm2 = new QListWidgetItem(ui->listWidget_2);
    itm->setIcon(QIcon(":/picture.png"));
    itm->setText(n.carpeta);
    itm2->setIcon(QIcon(":/picture.png"));
    itm2->setText(n.carpeta);
}

void MainWindow::on_actionSalir_triggered()
{
    exit(0);
}

void MainWindow::on_actionNueva_Carpeta_2_triggered()
{
    on_actionNueva_Carpeta_triggered();
}

void MainWindow::on_actionNuevo_Archivo_2_triggered()
{
    on_actionArchivo_de_Texto_triggered();
}

void MainWindow::on_actionArchivo_Winrar_2_triggered()
{
    on_actionArchivo_Winrar_triggered();
}

void MainWindow::on_actionMapa_de_Bit_triggered()
{
    on_actionMapa_de_bits_triggered();
}

ArchivoBase *MainWindow::busqueda(QString nombre)
{
    for(int i = 0; i < b->size; i++){
       if(b->buscar(i)->nombre == nombre){
           return b->buscar(i);
       }
    }
    return NULL;
}

void MainWindow::rellenarCarpeta(Carpeta **copiado, Carpeta **nuevo, int i)
{
    if (i >= (*copiado)->size)
        return;

    ArchivoBase* temp = (*copiado)->Ab->buscar(i);
    if (temp == NULL)
        return;
    if(temp->tipo == "C")
    {
        ArchivoBase *c = new Carpeta(temp->nombre, temp->path);
        rellenarCarpeta(((Carpeta**)&temp),((Carpeta**)&c),0);
        (*nuevo)->Ab->inserta(c);
    }else{
        Archivo *a = new Archivo(temp->nombre, temp->path);
        (*nuevo)->Ab->inserta(a);
    }
    rellenarCarpeta(copiado, nuevo, i+1);
}

void MainWindow::on_actionCopiar_triggered()
{
    almacenamiento->limpiar();
    ArchivoBase *copiado = busqueda(cop);
    ArchivoBase *nuevo;
    if(copiado == NULL)
        return;
    if(copiado->tipo == "C")
    {
        nuevo = new Carpeta(copiado->nombre, copiado->path);
        rellenarCarpeta(((Carpeta**)&copiado),((Carpeta**)&nuevo), 0);
    }
    else
    {
        nuevo = new Archivo(copiado->nombre, copiado->path);
    }
    almacenamiento->inserta(nuevo);
}

void MainWindow::on_actionCortar_triggered()
{
        almacenamiento->limpiar();
        ArchivoBase *copiado = busqueda(cop);
        ArchivoBase *nuevo;
        if(copiado == NULL)
            return;
        if(copiado->tipo == "C")
        {
            nuevo = new Carpeta(copiado->nombre, copiado->path);
        }
        else
        {
            nuevo = new Archivo(copiado->nombre, copiado->path);
        }
        almacenamiento->inserta(nuevo);

}

void MainWindow::on_actionPegar_triggered()
{
    ArchivoBase * copiar  =  almacenamiento->buscar(0);
    if(copiar == NULL)
        return;
     copiar->path = ui->lineEdit->text()+"\\" + copiar->nombre;
     b->inserta(copiar);
      QListWidgetItem* itm = new  QListWidgetItem(ui->listWidget);
      QListWidgetItem* itm2 = new  QListWidgetItem(ui->listWidget_2);
            if (copiar->tipo == "C"){
        agregarCarpet(r,b->buscar(b->size-1)->nombre);
        itm->setText(copiar->nombre);
        itm->setIcon(QIcon(":/folder.png"));
        itm2->setText(copiar->nombre);
        itm2->setIcon(QIcon(":/folder.png"));
           }else{
                agregarArchiv(r,b->buscar(b->size-1)->nombre);
                itm->setIcon(QIcon(":/archivo.png"));
                itm2->setIcon(QIcon(":/archivo.png"));
                itm->setText(copiar->nombre);
               itm2->setText(copiar->nombre);
            }
}

void MainWindow::on_actionEliminar_triggered()
{
    //b->suprimir(busqueda(cop));
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    a = b->buscar(index.row());
    if(a->tipo == "C"){
        ui->lineEdit->setText(a->path);
        b = ((Carpeta*)b)->Ab;
        ui->listWidget->clear();
        ui->listWidget_2->clear();
 }

  }


void MainWindow::on_actionCopiar_2_triggered()
{
    on_actionCopiar_triggered();
}

void MainWindow::on_actionCortar_2_triggered()
{
    on_actionCortar_triggered();
}

void MainWindow::on_actionPegar_2_triggered()
{
    on_actionPegar_triggered();
}
