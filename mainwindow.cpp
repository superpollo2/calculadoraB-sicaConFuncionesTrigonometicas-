#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>
#include <QTextEdit>
#include <QMessageBox>
using namespace std;
double primerNum;//variable global, primer numero de una operacion binaria o cualquier otra que necesite dos numeros para realizarse
bool ole=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //conectividad de los botones
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));



    //handleButton
    connect(ui->pushButton_a,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_b,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_c,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_d,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_e,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_f,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_masmenos,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_enviar,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_decimal,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_facto,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_raiz,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_potencia,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_cos,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_tan,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_multi,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_sen,SIGNAL(released()),this,SLOT(handleButton()));
    connect(ui->pushButton_suma,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divi,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_resta,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_potenciax,SIGNAL(released()),this,SLOT(binary_operation_pressed()));


    //bool Esta propiedad se mantiene si el botón es seleccionable
    ui->pushButton_multi->setCheckable(true);
    ui->pushButton_suma->setCheckable(true);
    ui->pushButton_divi->setCheckable(true);
    ui->pushButton_resta->setCheckable(true);
    ui->pushButton_potenciax->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

int asignarletra(QString letras,QString letra){
    int numero,i,i2=0,numeroLetra,c=0;
    QString machete = "A,B,C,D,E,F";
    QStringList machetazo = machete.split(",");
    while(c==0){
        QString caracter = letras.at(i2);
        if(caracter==letra){
            i = machetazo.indexOf(caracter);
            c=1;
        }
        i2++;
}
    numeroLetra=i + 10;
    return numeroLetra;

}

unsigned long long factorial(unsigned long long int n){//metodo factorial

    int cont;//contador
    unsigned long long int fac=1;//factorial
    if(n==0){//caso especial del factorial (0)!=1
        return 1;
    }

    for (cont=1; cont<=n; cont++){
        fac*=cont;

    }
    return fac;//retorna al valor de factorial
}
double raiz(unsigned int num){



    float r,h=0.00001, raiz=h;//funciona muy bien, pero las raices "exactas" las muestra con sus respectivos decimales
    while(raiz*raiz<num){
        raiz+=h;
    }
    return raiz;//retorna al  valor de raiz

}

long double potencia(float base, float exp){//metodo potencia
    long double cont;//contador
    double potencia ;
    if (exp==0){//caso especiale de la potencia x^0=1
        return 1;
    }

    else if(exp==1){//caso especiale de la potencia x^1=x
        return base;//base de la operacion
    }

    else if(exp>1){

        for (cont=1;exp>0; exp--){
            cont*=base;
        }

    }
    return cont;

}
void MainWindow::digit_pressed()//cuando un boton envia(es presionado)
{
    QPushButton * button=(QPushButton*) sender();

    double labelNumber;
    QString newLabel;


    if((ui->pushButton_suma->isChecked() || ui->pushButton_multi->isChecked() ||ui->pushButton_resta->isChecked()
        || ui->pushButton_divi->isChecked() || ui->pushButton_potenciax->isChecked() ) && (!ole) ){//cuando se presione un boton de operacion(+,-,*,/) esto hace que se restablesca el label y al escribir otro numero aparezca ese
        labelNumber=button->text().toDouble();//toDouble convierte el texto en un numero de punto flotante de tipo double
        ole = true;//el usuario ha presionado un boton
        newLabel=QString::number(labelNumber, 'g','15');//Devuelve un equivalente de cadena del número n , formateado según el formato y la precisión especificados
        //'g'  representa la precision y el número máximo de dígitos significativos
    }
    else {
        if(ui->label->text().contains('.') && button->text()== "0"){//permite que luego del punto decimal haya un cero
            newLabel=ui->label->text()+button->text();
        }


            else {
                if(ui->label->text().contains('.') && button->text()!= "0"){//permite que luego del punto decimal haya cualquier numero diferente de cero
                    newLabel=ui->label->text()+button->text();

                }
                else {
                    if((ui->label->text().contains('B')||ui->label->text().contains('C')|| ui->label->text().contains('A')||ui->label->text().contains('D') || ui->label->text().contains('E')||ui->label->text().contains('F'))
                            && button->text()!= "0"){//permite que luego de un caracter haya un numero
                        newLabel=ui->label->text()+button->text();
                    }
                    else {
                        if((ui->label->text().contains('B')||ui->label->text().contains('C')|| ui->label->text().contains('A')||ui->label->text().contains('D') || ui->label->text().contains('E')||ui->label->text().contains('F'))
                                && button->text()== "0"){//permite que luego de un caractar haya un cero

                            newLabel=ui->label->text()+button->text();

                        }


                        else {
                            labelNumber=(ui->label->text() + button->text()).toDouble();//si no es presionado alguno de los botones de operacion binaria se puede seguir escribiendo numeros de corrido
                            newLabel=QString::number(labelNumber, 'g','15');
                        }


                    }
                }
        }

    }

        ui->label->setText(newLabel);
    }






void MainWindow::on_pushButton_igual_released()//totalizar cuando se oprima el boton igual
{
    double  labelNumber, segundoNum;
    QString newLabel;
    int cont=1;

    segundoNum= ui->label->text().toDouble();//casting de un sting a un double

    if(ui->pushButton_multi->isChecked()){//operacion multiplicacion

        labelNumber = primerNum * segundoNum;
        newLabel= QString::number(labelNumber,'g','15');
        ui->label->setText(newLabel);
        ui->pushButton_multi->setChecked(false);
    }


    else if(ui->pushButton_suma->isChecked()){//operacion suma

        labelNumber = primerNum + segundoNum;
        newLabel=QString::number(labelNumber,'g','15');
        ui->label->setText(newLabel);
        ui->pushButton_suma->setChecked(false);

    }

    else if(ui->pushButton_divi->isChecked()){//operacion division

        if(labelNumber>-1){
            labelNumber = primerNum / segundoNum;
            newLabel=QString::number(labelNumber,'g','15');
            ui->label->setText(newLabel);
            ui->pushButton_divi->setChecked(false);
        }else{
            QMessageBox msgb;
            msgb.setText("Error, no se puede dividir por 0");
            msgb.exec();
        }
    }

    else if(ui->pushButton_resta->isChecked()){//operacion resta
        labelNumber= primerNum - segundoNum;
        newLabel=QString::number(labelNumber,'g','15');
        ui->label->setText(newLabel);
        ui->pushButton_resta->setChecked(false);

    }
    else if(ui->pushButton_potenciax->isChecked()){//operacion potencia
        long  double labelNumber;
        labelNumber=potencia(primerNum,segundoNum);


        newLabel=QString::number(labelNumber,'g','8');
        ui->label->setText(newLabel);
        ui->pushButton_potenciax->setChecked(false);
    }


    ole = false;
}



void MainWindow::binary_operation_pressed()
{
    QPushButton *button =(QPushButton*)sender();
    primerNum =ui->label->text().toDouble();
    button->setChecked(true);



}
void MainWindow::handleButton(){//esto calcula el numero que este en el label luego de presionar un boton correspomdiente a una operacion

    double labelNumber;//labelNumber es un auxiliar de tipo doble al que luego se le hace casting para destinarlo al label

    QString newLabel;//newLabel el un caracter al cual se ha llevado la convercion de labelNumber
    QPushButton *button =(QPushButton*)sender();



    if (button->text()=="!"){//factorial

        unsigned long long  labelNumber;
        labelNumber=ui->label->text().toDouble();//casting de un sting a un double
        if(labelNumber>=0 && labelNumber<=20){
            labelNumber=factorial(labelNumber);
            newLabel=QString::number(labelNumber,'g','15');
            ui->label->setText(newLabel);
        }else{
            QMessageBox msgb;
            msgb.setText("Error, el factorial en esta calculadora\n tiene el intervalo [0,20] ");
            msgb.exec();
            ui->label->setText("");
        }
    }

    if (button->text()=="√"){//es una aproximacion de la raiz cuadrada
        float labelNumber;
        labelNumber=ui->label->text().toDouble();//casting de un sting a un double
        if(labelNumber>-1){
            labelNumber=raiz(labelNumber);
            newLabel=QString::number(labelNumber);
            ui->label->setText(newLabel);
        }else{
            QMessageBox msgb;
            msgb.setText("Error, no hay raiz de un numero negativo en los reales");
            msgb.exec();
            ui->label->setText("");
        }
    }

    if (button->text()=="χ²"){//potencia al cuadrado

        labelNumber=ui->label->text().toDouble();//casting de un sting a un double
        labelNumber=potencia(labelNumber,2);
        newLabel=QString::number(labelNumber,'g','15');
        ui->label->setText(newLabel);

    }
    if (button->text()=="+/-"){//cambio de signo

        labelNumber=ui->label->text().toDouble();//casting de un sting a un double
        labelNumber=-1*labelNumber;
        newLabel=QString::number(labelNumber,'g','15');
        ui->label->setText(newLabel);

    }

    if(button->text()=="."){//punto decimal
        ui->label->setText(ui->label->text()+".");

    }

    //botones de letra

        if(button->text()== "0" && button->text()=="A"){
       QMessageBox msgb;
       msgb.setText("Error, el numero cero no puede ir de primeras en esta operacion");
       msgb.exec();
    }
    if(button->text()=="A"){
        ui->label->setText(ui->label->text()+"A");
    }
    if(button->text()=="B"){
        ui->label->setText(ui->label->text()+"B");
    }
    if(button->text()=="C"){
        ui->label->setText(ui->label->text()+"C");
    }
    if(button->text()=="D"){
        ui->label->setText(ui->label->text()+"D");
    }
    if(button->text()=="E"){
        ui->label->setText(ui->label->text()+"E");
    }
    if(button->text()=="F"){
        ui->label->setText(ui->label->text()+"F");
    }
    if (button->text()=="Enviar"){

        QString str;
             str=ui->label->text();
             float acum=0,acum2=0, c3=0, s=0,c4=0,s2=0,s3=0,c5=0;
             double numero;
             char letra;
             int letraNumero;
             QStringList label=str.split(".");
             QString left;
             QString right;
             QString caracter;
             QString letras = "ABCDEF";
             QString numeros = "0123456789";

             left = label.at(0);

             right = label.at(1);

             int base = ui->lineEdit->text().toInt();
             int tamano = left.size(); // parte izquierda

             while(c3<tamano){

                //este while permite verificar que los numeros o letras ingresados pertenescan a la base.
                //por ejemplo: que no alla un 6 en una base 3, o que no alla una F en una base 13.
                //este primer while es para la parte izquierda.
                 QString label = left.at(c3);

                 if(letras.contains(label)){//letra. el primer IF verifica las letras.
                    letraNumero=asignarletra(left,label);
                    //usamos la funciion "asignarLetra" para convertir la letra en su respectivo valor en base hexadecimal.
                    if(letraNumero>9 && letraNumero<base){
                        //si cada letra pertence a la base se lleva una suma.
                        s++;
                    }
                     c3++;
                 }else if(numeros.contains(label)){//numero. el segundo IF verifica los numeros.
                     numero= label.toInt();
                     if(numero>-1 && numero<base){//si cada numero pertenece a la base se continua la suma.
                         s++;
                     }
                     c3++;
                 }else{
                     QMessageBox msgb;
                     msgb.setText("Error, los datos ingresados no permiten hacer el calculo");
                     msgb.exec();
                 }
             }
             int tamano2 = right.size(); //parte derecha
             right = label.at(1);
             while(c4<tamano2){

                 //este while permite verificar que los numeros o letras ingresados pertenescan a la base.
                 //por ejemplo: que no alla un 6 en una base 3, o que no alla una F en una base 13.
                 //este primer while es para la parte derecha.
                 QString label = right.at(c4);

                 if(letras.contains(label)){//letra
                     letraNumero=asignarletra(right,label);
                     //usamos la funciion "asignarLetra" para convertir la letra en su respectivo valor en base hexadecimal.
                     if(letraNumero>9 && letraNumero<base){
                         s2++;
                     }
                     c4++;
                 }else if(numeros.contains(label))    {//numero
                     numero= label.toInt();
                     if(numero>-1 && numero<base){
                         s2++;
                     }
                     c4++;
                 }else{
                     //en caso de que se encuentre un caracter
                     //que no pertenece a la base asignada
                     //se arroja un error.
                     QMessageBox msgb;
                     msgb.setText("Error, los datos ingresados no permiten hacer el calculo");
                     msgb.exec();
                 }
             }

             if(s==tamano && s2==tamano2 && base<17){
                 // si al final cada caracter pertenece a la base,
                 //el contador tendra el mismo valor que el tamaÃ±o izquierdo o derecho.
                 QMessageBox msgb;
                 msgb.setText("el numero a base 10 es");
                 msgb.exec();

                 left = label.at(0);
                 for(int c=0 ;c < left.size(); c++){
                     //FOR para la parte derecha
                     QString caracter = left.at(c);
                     //uso de un IF ELSE que sepera los numeros de las letras
                     if(numeros.contains(caracter)){
                         numero= caracter.toDouble();
                     }else{
                         numero=asignarletra(left,caracter);
                     }
                     //calculo final por cada caracter, llevando su sumatoria.
                     int exponente = (left.size()-1-c);
                     acum+=numero*potencia(base,exponente);
                 }

                 if (str.contains(".")){
                     //IF que determina la existencia de una parte derecha
                     //marcada por un punto.
                     right = label.at(1);

                     for(int i2=0;i2<right.size();i2++){
                         //FOR para la parte derecha
                         QString caracter= right.at(i2);
                         // IF ELSE que separa las letras de los numeros.
                         if(numeros.contains(caracter)){
                             numero=caracter.toDouble();
                         }else{
                             numero=asignarletra(right,caracter);
                         }
                         //para el respectivo calculo por caracter
                         //y su respectiva inclucion a la sumatoria.
                         int exponente2 = (i2+1);
                         acum2+=numero/(potencia(base,exponente2));
                     }
                 }

                 float equiv = acum + acum2;
                 //equivalencia que suma las dos respectivas sumatorias
                 //de los dos lados, tanto izquierdo como derecho
                 msgb.setText(QString::number(equiv));
                 msgb.exec();
                 labelNumber=equiv;
                 newLabel=QString::number(labelNumber,'g','15');
                 ui->label->setText(newLabel);
                 //para mostrar su resultado en pantalla

             }else{
                 //en caso de que el caracter perteneciente al numero ingresado
                 //no pertenezca a ninguna base.
                 //por ejemplo la letra K que no hace parte de ninguna de las bases permitidas.
                 //se arroja un mensaje de error.
                 QMessageBox msgb;
                 msgb.setText("Syntax error");
                 msgb.exec();
         }

             ui->lineEdit->setText("");
             return;
}


    if (button->text()=="sin"){//funcion seno correcta
        float labelNumber;
        int i,n=9;
        double seno=0;
        labelNumber=(ui->label->text().toDouble())*M_PI/180;//conversion de grados a radianes
        if(labelNumber>(-1)){
            for (i=0; i<n; i++) {
                seno+=potencia(-1,i)*potencia(labelNumber,2*i+1)/factorial(2*i+1);
            }
            labelNumber= seno;
            newLabel=QString::number(labelNumber);
            ui->label->setText(newLabel);
        }else{
            QMessageBox msgb;
            msgb.setText("Syntax error");
            msgb.exec();
        }
    }

    if (button->text()=="cos"){//funcion coseno correcta //no da un dato exacto

        QString newlabel;

        float labelNumber ;
        int k,n=9,q=0,u;
        double cos=0;

        labelNumber=(ui->label->text().toDouble())*M_PI/180;//conversion de grados a radianes
        if(labelNumber>-1){

            for (k=0; k<n; k++) {
                cos+=potencia(-1,k)*potencia(labelNumber,2*k)/factorial(2*k);
                u=cos;
            }
            labelNumber=cos;
            newLabel=QString::number(labelNumber);
            ui->label->setText(newLabel);
        }


    }
    if (button->text()=="tan"){//funcion tangente correcta

        float labelNumber;
        int i,k,n=9;
        double seno=0,cos=0;
        labelNumber=ui->label->text().toDouble();
        if(labelNumber==90){//casos en los que la tangente de un numero da infinito o se dice que no existe
            ui->label->setText("+∞");
            newLabel=QString::number(labelNumber);
            return;


        }

        if(labelNumber==270){//casos en los que la tangente de un numero da infinito o se dice que no existe
            ui->label->setText("-∞");
            newLabel=QString::number(labelNumber,'g','15');
            return;
        }

        if (labelNumber!=90 && labelNumber!=270){
            labelNumber=(ui->label->text().toDouble())*M_PI/180;//conversion de grados a radianes


            for (i=0; i<n; i++) {//for para calcular el seno

                seno+=potencia(-1,i)*potencia(labelNumber,2*i+1)/factorial(2*i+1);

            }

            for (k=0; k<n; k++) {//for para cualcular el coseno

                cos+=potencia(-1,k)*potencia(labelNumber,2*k)/factorial(2*k);

            }


            labelNumber= seno/cos; //identidad trigonometrica de tanx = sen/cos

            newLabel=QString::number(labelNumber);
            ui->label->setText(newLabel);

        }

    }








}

void MainWindow::on_pushButton_borrar_released()//resetear el label
{
    ui->pushButton_suma->setChecked(false);
    ui->pushButton_divi->setChecked(false);
    ui->pushButton_resta->setChecked(false);
    ui->pushButton_multi->setChecked(false);
    ui->pushButton_multi->setChecked(false);

    ole=false;

    ui->label->setText("");
}








/*void MainWindow::on_pushButton_decimal_pressed()
{

          ui->label->setText(".");

}*/

void MainWindow::on_pushButton_enviar_pressed()
{

}
