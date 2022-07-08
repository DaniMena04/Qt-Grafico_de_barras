#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

/* ========================================================================
 *                              BARRA 1
 * ========================================================================
*/

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Crear colores
    QColor colorBorde1(12, 14, 87);
    QColor colorRelleno1(30, 32, 114);

    // Establecer el pincel al "pintor"
    pincel.setColor(colorBorde1);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);

    // Obtener datos para la primera barra

    int nota1 = ui->inNota1->value();
    int alto1 = this->getAlto(nota1);
    int incYN1 = this->incY(alto1);


    // Dibujar primera barra
    painter.drawRect(x+70, y+50+incYN1,100,alto1);
    painter.drawText(x+95,y+480,"Nota N°1");

/* ========================================================================
 *                              BARRA 2
 * ========================================================================
*/

    // Crear un objeto color para el relleno
    QColor colorRelleno(0,160,120);
    // Crear otro objeto color para el borde
    QColor colorBorde(0, 122, 91);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    // Obtener datos para la segunda barra

    int nota2 = ui->inNota2->value();
    int alto2 = this->getAlto(nota2);
    int incYN2 = this->incY(alto2);

    // Dibujar segunda barra
    painter.drawRect(x+190, y+50+incYN2, 100, alto2);
    painter.drawText(x+215,y+480,"Nota N°2");

/* ========================================================================
 *                              BARRA 3
 * ========================================================================
*/

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(198, 8, 72);
    QColor cBordeBarra3(154, 0, 52);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Obtener datos para la segunda barra

    int nota3 = ui->inNota3->value();
    int alto3 = this->getAlto(nota3);
    int incYN3 = this->incY(alto3);

    // Dibujar tercera barra
    painter.drawRect(x+310,y+50+incYN3,100,alto3);
    painter.drawText(x+335,y+480,"Nota N°3");

/* ========================================================================
 *                              PROMEDIO
 * ========================================================================
 */

    // Poner el color y el estilo
    QColor colorLinea(41,223,41);
    pincel.setColor(colorLinea);
    painter.setPen(pincel);

    // Obtener el promedio de las notas
    float promedio = (nota1 + nota2 + nota3) / 3.0;
    int alto4 = this->getAlto(promedio);
    int incYN4 = this->incY(alto4);

    // Dibujar la rasha
    painter.drawLine(x+30,y+50+incYN4,450,y+50+incYN4);
    ui->inPromedio->setText(QString::number(promedio));


/* ========================================================================
 *                              PLANO CARTESIANO
 * ========================================================================
*/

// EJE Y

    pincel.setColor(Qt::black);

    painter.setPen(pincel);

    painter.drawLine(x+35,y+20,x+35,y+470);

    // Divicones

//    Valor de 10
    painter.drawLine(x+30,y+410,x+40,y+410);
    painter.drawLine(x+30,y+430,x+40,y+430);
    painter.drawText(x+3,y+415,"10");
//    Valor de 20
    painter.drawLine(x+30,y+370,x+40,y+370);
    painter.drawLine(x+30,y+390,x+40,y+390);
    painter.drawText(x+3,y+375,"20");
//    Valor de 30
    painter.drawLine(x+30,y+330,x+40,y+330);
    painter.drawLine(x+30,y+350,x+40,y+350);
    painter.drawText(x+3,y+335,"30");
//    Valor de 40
    painter.drawLine(x+30,y+290,x+40,y+290);
    painter.drawLine(x+30,y+310,x+40,y+310);
    painter.drawText(x+3,y+295,"40");
//    Valor de 50
    painter.drawLine(x+30,y+250,x+40,y+250);
    painter.drawLine(x+30,y+270,x+40,y+270);
    painter.drawText(x+3,y+255,"50");
//    Valor de 60
    painter.drawLine(x+30,y+210,x+40,y+210);
    painter.drawLine(x+30,y+230,x+40,y+230);
    painter.drawText(x+3,y+215,"60");
//    Valor de 70
    painter.drawLine(x+30,y+170,x+40,y+170);
    painter.drawLine(x+30,y+190,x+40,y+190);
    painter.drawText(x+3,y+175,"70");
//    Valor de 80
    painter.drawLine(x+30,y+130,x+40,y+130);
    painter.drawLine(x+30,y+150,x+40,y+150);
    painter.drawText(x+3,y+135,"80");
//    Valor de 90
    painter.drawLine(x+30,y+90,x+40,y+90);
    painter.drawLine(x+30,y+110,x+40,y+110);
    painter.drawText(x+3,y+95,"90");
//    Valor de 100
    painter.drawLine(x+30,y+50,x+40,y+50);
    painter.drawLine(x+30,y+70,x+40,y+70);
    painter.drawText(x,y+55,"100");

// EJE X

    pincel.setColor(Qt::black);

    painter.setPen(pincel);

    painter.drawLine(x+10,y+450,x+450,y+450);
}

int Principal::getAlto(int valor)
{
    return 4 * valor;
}

int Principal::incY(int alto)
{
    return 400 - alto;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg1)
{
    dibujar();
}
