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
    painter.drawRect(x+50, y+50+incYN1,100,alto1);

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
    painter.drawRect(x+170, y+50+incYN2, 100, alto2);

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
    painter.drawRect(x+290,y+50+incYN3,100,alto3);

/* ========================================================================
 *                              PROMEDIO
 * ========================================================================
 */

    // Poner el color y el estilo
    QColor colorLinea(0,0,0);
    pincel.setColor(colorLinea);

    // Obtener el promedio de las notas
    float promedio = (nota1 + nota2 + nota3) / 3;
    int alto4 = this->getAlto(promedio);
//    int incYN4 = this->incY(alto4);

    // Dibujar la rasha
    painter.drawLine(x,y+50+alto4,500,y+50+alto4);

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
