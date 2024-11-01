/**
 * Algoritmo de Biseccion
 * Hecho por Owen Solis
 * Version 1.0
 * Fecha: 29/10/2024
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int Iteraciones;

    //Explicacion del metodo
    cout << "Bienvenido, este programa aproxima raices usando el metodo de biseccion,\n";
    cout << "con una precision de 4 cifras significativas.\n\n";
    cout <<"El metodo de biseccion funciona utilizando una funcion f(x) y un\n";
    cout <<"intervalo definido en la forma [a,b], donde a es el valor del extremo izquierdo en\n";
    cout << "del intervalo, y b es el valor que toma en el extremo derecho, ambos valores en el eje de las abcisas.\n\n";
    cout << "Con los valores del intervalo, calculamos un punto medio llamado Pn (donde n es el numero de iteraciones\n";
    cout << "a realizar por el programa), para calcular Pn hacemos lo siguiente: (a+b)/2.\n\n";
    cout << "Ya que tenemos el valor de Pn, evaluamos f(x) con dicho valor, de igual forma evaluamos f(x) en a y\n";
    cout << "comparamos con los siguiente criterios:\n\n";
    cout << "1. Si f(Pn) = 0, el algoritmo se detiene, ya que P = Pn.\n";
    cout << "2. Si f(Pn) =/= 0, entonces f(Pn) tiene el mismo signo que f(an) o f(bn).\n";
    cout << "3. Si f(Pn) y f(an) tienen el mismo signo, entonces P esta entre Pn y bn, por ende\n";
    cout << "an+1 = Pn y bn+1 = bn.\n";
    cout << "4. Si f(Pn) y f(an) tienen signos opuestos, entonces P esta entre an y Pn, por ende\n";
    cout << "an+1 = an y bn = Pn.\n\n";
    cout << "La funcion se debe programar en el codigo, junto a su intervalo (mas detalles en los comentarios del programa).\n\n";
    cout<< "Ingrese el numero de iteraciones:";
    cin >> Iteraciones;

    /**
     * Variables a ser utilizadas.
     * a = extremo izquierdo del intervalo
     * b = extremo derecho del intervalo
     * TOL = tolerancia para aproximar la raiz
     * Evala = evaluacion de f(x) con x = a
     * Evalp = evaluacion de f(x) con x = p
     */
    double a,b,TOL, Evala,Evalp;
    //Modificar a para el extremo izquierdo del intervalo.
    a = 1;
    //Modificar b para el extremo derecho del intervalo.
    b= 2;
    //Modificar TOL para ajustar la precision requerida de la aproximacion.
    //OJO: Tambien deben modificarse fixed y setprecision que se encuentran dentro del ciclo, esto para mantener coherencia.
    TOL = 0.00001;

    /**
     * Ciclo encargado de calcular cada iteracion hasta que se llegue a la tolerancia deseado o se exceda el limite de iteraciones.
     * Se utilizo el setprecision para fijar el numero decimal a 4 cifras, y se uso fixed para evitar notacion cientifica.
     */
    for (int i = 1; i <= Iteraciones; i++) {
        cout << "Iteracion #" << i << "\n";
        /**
         * Calculo de Pn
         */
        double p = ((a+b)/2);
        cout << "[" << a << "," << b << "]\n";
        cout << "P#" << i << "="<< fixed << setprecision(5) << p << "\n";
        /**
         * Evaluacion de f(an)
         */
        //Reemplazar con la funcion f(x) que se quiere evaluar con an.
        Evala = pow(a,3)-a-1;
        cout << "f(a#" << i << ")=" << fixed << setprecision(5) << Evala << "\n";
        /**
         * Evaluacion de f(Pn)
         */
         //Reemplazar con la funcion f(x) que se quiere evaluar con Pn.
        Evalp = pow(p,3)-p-1;
        cout << "f(p#" << i << ")=" << fixed << setprecision(5) << Evalp << "\n\n";

        /**
         * Revision de condiciones
         */
        if(Evalp < TOL && Evalp > -TOL){
            cout << "Se encontro una aproximacion en la iteracion#" << i << ", con P=" << p << " con f(p)=" << Evalp << "\n";
            break;
        }else if(Evala * Evalp < 0){
            b=p;
        }else{
            a=p;
        }

        if(i == Iteraciones){
            cout << "No se encontro una aproximacion adecuada dentro de las iteraciones deseadas.";
        }
    }
    return 0;
}