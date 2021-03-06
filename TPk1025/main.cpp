#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#define RUTAPOLIZA "Asegurados.BAK"


using namespace std;
char menu ()
{
    cout << "========= ASEGURADORA BIT =========" << endl;
    cout << "1- Cargar una poliza" << endl;
    cout << "2- Buscar una poliza existente" << endl;
    cout << "3- Desactivar una poliza existente" << endl;
    cout << "4- Listar todas las polizas (ordenado por cantidad de accidentes)" << endl;
    cout << "5- Mostrar todas las p?lizas que no tengan la cuota al d?a (En formato CSV y HTML)." << endl;
    cout << "6- Procesar un lote de incidentes" << endl;
    cout << "Para finalizar el dia presiona s" << endl;
    char opcion;
    do
    {
       opcion = getch ();
    } while ((opcion!='0') && (opcion!='1') &&(opcion!='2') && (opcion!='3') && (opcion!='5') && (opcion!='6') && (opcion!='4') && (opcion != 27));
    return opcion;
}
struct Polizas
{
    int poliza ;
    char dni [11];
    char nombre [12];
    char apellido [15];
    bool cuota;
    char patente [8];
    bool activa;
    int accidentes ;
};
struct incidente
{
    int Codigoincidente;
    int Fechahora;
    char DniAsegurado [11];
    char DniotroConductor[11];
    int Nropoliza;
    char Calle [50];
    int Altura;
};
struct NodoIncidente
{
    incidente info;
    NodoIncidente *sgte;
};
void cargarpolizaprueba ()
{
    FILE *f;
    f= fopen (RUTAPOLIZA, "wb");
    Polizas p;
    if (f)
    {
        strcpy(p.apellido,"ALEGRE");
        strcpy(p.nombre,"JUAN");
        strcpy(p.dni,"23.456.789");
        p.cuota=false;
        strcpy(p.patente,"IFT560");
        p.activa=false;
        p.accidentes=0;
        p.poliza=1234;
        fwrite(&p, sizeof(Polizas),1,f);

        strcpy(p.apellido,"DIFILIPPO");
        strcpy(p.nombre,"MAURO");
        strcpy(p.dni,"44.544.627");
        p.cuota=false;
        strcpy(p.patente,"IGD150");
        p.activa=true;
        p.accidentes=1;
        p.poliza=9999;
        fwrite(&p, sizeof(Polizas),1,f);

        strcpy(p.apellido,"PUCENICZ");
        strcpy(p.nombre,"MATIAS");
        strcpy(p.dni,"76.890.345");
        p.cuota=true;
        strcpy(p.patente,"MMG234");
        p.activa=true;
        p.accidentes=10;
        p.poliza=3456;
        fwrite(&p, sizeof(Polizas),1,f);
        fclose (f);

    }
    else
        cout << "Error: no se pudo crear el archivo" << endl;
    return;
}
void cargarincidentesprueba ()
{
    FILE *f;
    incidente p;

    f = fopen ("lote1", "a");
    if (f)
    {
        p.Codigoincidente = 2234;
        p.Fechahora = 202112091717;
        strcpy(p.DniAsegurado, "44.544.627");
        strcpy(p.DniotroConductor, "13.444.724");
        p.Nropoliza = 9999;
        strcpy(p.Calle, "Av. Rivadavia");
        p.Altura = 5442;
        fwrite(&p, sizeof(incidente),1,f);

        p.Codigoincidente = 9831;
        p.Fechahora = 201903121538;
        strcpy(p.DniAsegurado, "44.544.627");
        strcpy(p.DniotroConductor, "12.231.764");
        p.Nropoliza = 9999;
        strcpy(p.Calle, "Ambroseti");
        p.Altura = 232;
        fwrite(&p, sizeof(incidente),1,f);
        p.Codigoincidente = 6521;
        p.Fechahora = 201903121538;
        strcpy(p.DniAsegurado, "23.456.789");
        strcpy(p.DniotroConductor, "36.993.543");
        p.Nropoliza = 1234;
        strcpy(p.Calle, "Av. Independencia");
        p.Altura = 3986;
        fwrite(&p, sizeof(incidente),1,f);
        fclose(f);
        }
    else
    {
        cout << "Error: no se pudo crear el archivo" << endl;
    }
    f= fopen ("lote2", "a");
    if (f)
    {
        p.Codigoincidente = 5834;
        p.Fechahora = 202010220938;
        strcpy(p.DniAsegurado, "76.890.345");
        strcpy(p.DniotroConductor, "13.444.724");
        p.Nropoliza = 3456;
        strcpy(p.Calle, "Suipacha");
        p.Altura = 918;
        fwrite(&p, sizeof(incidente),1,f);

        p.Codigoincidente = 8868;
        p.Fechahora = 201904041046;
        strcpy(p.DniAsegurado, "76.890.345");
        strcpy(p.DniotroConductor, "39.231.981");
        p.Nropoliza = 3456;
        strcpy(p.Calle, "Condarco");
        p.Altura = 1440;
        fwrite(&p, sizeof(incidente),1,f);

        p.Codigoincidente = 8056;
        p.Fechahora = 202101010055;
        strcpy(p.DniAsegurado, "23.456.789");
        strcpy(p.DniotroConductor, "40.935.012");
        p.Nropoliza = 1234;
        strcpy(p.Calle, "Terrada");
        p.Altura = 665;
        fwrite(&p, sizeof(incidente),1,f);
        fclose(f);
    }
    else
    {
        cout << "Error: no se pudo crear el archivo" << endl;
    }
    f= fopen ("lote3", "a");
    if (f)
    {
        p.Codigoincidente = 4329;
        p.Fechahora = 202011220941;
        strcpy(p.DniAsegurado, "44.544.627");
        strcpy(p.DniotroConductor, "45.909.408");
        p.Nropoliza = 9999;
        strcpy(p.Calle, "Yerbal");
        p.Altura = 12;
        fwrite(&p, sizeof(incidente),1,f);

        p.Codigoincidente = 8868;
        p.Fechahora = 201904041046;
        strcpy(p.DniAsegurado, "76.890.345");
        strcpy(p.DniotroConductor, "50.221.727");
        p.Nropoliza = 3456;
        strcpy(p.Calle, "Castro Barros");
        p.Altura = 8512;
        fwrite(&p, sizeof(incidente),1,f);

        p.Codigoincidente = 8056;
        p.Fechahora = 202101010055;
        strcpy(p.DniAsegurado, "23.456.789");
        strcpy(p.DniotroConductor, "40.935.012");
        p.Nropoliza = 1234;
        strcpy(p.Calle, "Av. 9 De Julio");
        p.Altura = 1001;
        fwrite(&p, sizeof(incidente),1,f);
        fclose(f);
    }
    else {
        cout << "Error: no se pudo crear el archivo" << endl;
    }
    return;
}
struct Nodopoliza
{
    Polizas info;
    Nodopoliza *sgte;
};
void mostrarpoliza( Nodopoliza *lista )
{
    cout << "Poliza nro: " << lista->info.poliza << endl;
    cout << "DNI: " << lista->info.dni << endl;
    cout << "Nombres: " << lista->info.nombre << endl;
    cout << "Apellidos: " << lista->info.apellido<< endl;
    cout << "Cuota: " << lista->info.cuota << endl;
    cout << "Patente: " << lista->info.patente << endl;
    cout << "Activa: " << lista->info.activa << endl;
    cout << "cantidad de incidentes: " << lista->info.accidentes<< endl;
    cout << endl;
}
void mostrarpolizas (Nodopoliza *lista)
{
    while (lista)
    {
        cout << "Poliza nro: " << lista -> info.poliza << endl;
        cout << "DNI: " << lista -> info.dni << endl;
        cout << "Nombres: " << lista -> info.nombre << endl;
        cout << "Apellidos: " << lista -> info.apellido<< endl;
        cout << "Cuota: " << lista -> info.cuota << endl;
        cout << "Patente: " << lista -> info.patente << endl;
        cout << "Activa: " << lista -> info.activa << endl;
        cout << "cantidad de incidentes: " << lista -> info.accidentes << endl;
        cout << endl;
        lista = lista->sgte;
    }
}
Nodopoliza *ObtenerSiguiente(Nodopoliza  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}
Nodopoliza* Buscarpoliza(Nodopoliza *raiz, int polizabuscada)
{
    Nodopoliza *p = raiz;
    while (p && (p->info.poliza != polizabuscada))
    {
        p = p->sgte;
    }
    return p;
}
void BuscarpolizaDNI (Nodopoliza *raiz, char dnibuscado [])
{
    Nodopoliza *p = raiz;
    while (p)
    {
        if (!strcmp (p->info.dni,dnibuscado))
        {
            cout << "Poliza nro: " << p->info.poliza << endl;
            cout << "DNI: " << p->info.dni << endl;
            cout << "Nombres: " << p->info.nombre << endl;
            cout << "Apellidos: " << p->info.apellido<< endl;
            cout << "Cuota: " << p->info.cuota << endl;
            cout << "Patente: " << p->info.patente << endl;
            cout << "Activa: " << p->info.activa << endl;
            cout << "cantidad de incidentes: " << p->info.accidentes << endl;
            cout << endl;
        }
        p = p->sgte;
    }
    return;
}
Nodopoliza* BuscarNodoAnterior(Nodopoliza * raiz, Nodopoliza * anterior_a)
{
    Nodopoliza *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    else
        return NULL;
}
Nodopoliza *ListapolizaObtenerSiguiente(Nodopoliza  *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}
void ListapolizaborrarLista(Nodopoliza *&lista)
{
    Nodopoliza *anterior;
    Nodopoliza *paux;
    while (lista!=NULL)
    {
        anterior=NULL;
        paux= lista;
        while (paux && paux->sgte)
        {
            anterior = paux;
            paux= paux->sgte;
        }
        if (paux)
        {
            delete paux;
            if (anterior!=NULL)
                anterior->sgte=NULL;
            else
                lista =NULL;
        }
    }
    return;
}
void ListaPolizaBorrarSiguiente(Nodopoliza  *n)
{
    Nodopoliza  *borrar = n->sgte;
    Nodopoliza  *sgteborrar;
    if (borrar)
        sgteborrar= borrar->sgte;
    else
        sgteborrar = NULL;
    n->sgte = sgteborrar;
    delete borrar;
    return;
}
void ListaPolizaInsertarSiguiente (Nodopoliza  *&n, Polizas x)
{
    Nodopoliza *nuevo= new Nodopoliza();
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte = n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }

    return;
}
void ListaincidenteInsertarSiguiente (NodoIncidente  *&n, incidente x)
{
    NodoIncidente *nuevo= new NodoIncidente();
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }

    return;
}
void insertarOrdenado(Nodopoliza *&lista, Polizas p)
{
    Nodopoliza *paux = lista;
    Nodopoliza *anterior =NULL;
    while (paux && paux->info.accidentes < p.accidentes)
    {
        anterior = paux;
        paux = paux->sgte;
    }
    if ( paux!= lista)
    {
        anterior->sgte = new Nodopoliza();
        anterior->sgte->info = p;
        anterior->sgte->sgte = paux;
    }
    else
    {
        lista = new Nodopoliza();
        lista->sgte = paux;
        lista->info = p;
    }
    return;
}
void levantarPoliza(Nodopoliza *&a)
{
    FILE *f;
    Polizas p;
    f=fopen(RUTAPOLIZA,"r");
    fread(&p,sizeof(Polizas),1,f);
    while (!feof(f))
    {
        ListaPolizaInsertarSiguiente(a,p);
        fread(&p,sizeof(Polizas),1,f);
    }
    fclose(f);
    return;
}
void levantarincidente(NodoIncidente *&a, char lote[])
{
    FILE *f;
    incidente i;
    f=fopen(lote,"r");
    fread(&i,sizeof(incidente),1,f);
    while (!feof(f))
    {
        ListaincidenteInsertarSiguiente(a,i);
        fread(&i,sizeof(incidente),1,f);
    }
    fclose(f);
    return;
}
void borrarNodopoliza(Nodopoliza *& raiz, Nodopoliza * aborrar)
{
    if (raiz && aborrar)
    {
        if (aborrar==raiz)
        {
            raiz = raiz->sgte;
            delete aborrar;
        }
        else
        {
            Nodopoliza *x = BuscarNodoAnterior(raiz,aborrar);
            ListaPolizaBorrarSiguiente(x);
        }
    }
    return;
}
void guardarpolizaDisco(Nodopoliza *la)
{
    FILE *pol;
    Nodopoliza *auxpol=NULL;
    if (pol = fopen(RUTAPOLIZA,"wb"))
    {
            auxpol= la;
            while (auxpol)
            {
                fwrite(&(auxpol->info), sizeof(Polizas),1,pol);
                auxpol = ListapolizaObtenerSiguiente(auxpol);
            }
            fclose(pol);
    }
        else
            cout << "ERROR AL INTENTAR GRABAR ARCHIVO DE POLIZAS" << endl;
    return;
}
void mostrarenHTML (Nodopoliza *lista)
{
    FILE *f;
    Polizas p;
    f = fopen ("salidahtml.html","wt");
    fprintf(f,"<html><body>\n");
    fprintf(f,"<h1>Polizas que no estan al dia</h1>\n");
    fprintf(f,"<table border=1>\n");
    fprintf(f,"<th>Poliza</th><th>Apellido</th><th>Nombre</th><th>Dni</th><th>Patente</th><th>Cantidad de accidentes</th>\n");
    while (lista)
    {
        if (lista->info.cuota == false)
        {
            fprintf(f,"<tr>\n");
            fprintf(f,"<td>%d</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%d</td>\n",lista->info.poliza,lista->info.apellido,lista->info.nombre,lista->info.dni,lista->info.patente,lista->info.accidentes);
            fprintf(f,"</tr>\n");
        }
        lista=lista->sgte;
    }
    fprintf(f, "</table>");
    fprintf(f, "</body>");
    fprintf(f, "</html>");
    fclose(f);
    return;
}
void mostrarenCSV(Nodopoliza *lista)
{
    FILE *f;
    f = fopen("salidaexcel.csv", "wt");
    fprintf(f,"Poliza;Apellido;Nombre;Dni;Patente;Cdad de Accidentes\n");
    while (lista)
    {
        if (lista->info.cuota==false)
        {
            fprintf(f,"%d;%s;%s;%s;%s;%d\n",lista->info.poliza,lista->info.apellido,lista->info.nombre,lista->info.dni,lista->info.patente,lista->info.accidentes);
        }
        lista = lista->sgte;
    }
    fclose(f);
    return;
}
void procesarincidente (int opcion, Nodopoliza* lista)
{
    FILE *Inc;
    FILE *canal;
    char lote[10], aux[3];
    NodoIncidente *listainc = NULL;
    incidente i;
    Polizas p;

    strcpy(lote, "lote");
    sprintf(aux, "%d", opcion);
    strcat(lote, aux);

    canal = fopen ("Procesados.BAK", "ab");
    if (canal)
    {
        Inc = fopen (lote,"rb");
        levantarincidente(listainc, lote);
        fread (&i,sizeof(incidente),1,Inc);
        while (!feof(Inc))
    {
        if (Buscarpoliza(lista,i.Nropoliza))
        {
            lista = Buscarpoliza(lista,i.Nropoliza);
            lista ->info.accidentes = lista -> info.accidentes + 1;
        }
        fread (&i,sizeof(incidente),1,Inc);
        fwrite (&i,sizeof (incidente),1,canal);
        }
        fclose (Inc);

    }
    else {
        cout << "No se encontro el archivo" << endl;
        fclose (canal);
    }

}
void ordenarLista(Nodopoliza *P)
{
     Nodopoliza *actual = NULL;
     Nodopoliza *siguiente = NULL;
     Polizas t;
     actual = P;
     while(actual->sgte != NULL)
     {
          siguiente = actual->sgte;

          while(siguiente!=NULL)
          {
               if(actual->info.accidentes > siguiente->info.accidentes)
               {
                    t = siguiente->info;
                    siguiente->info = actual->info;
                    actual->info = t;
               }
               siguiente = siguiente->sgte;
          }
          actual = actual->sgte;
          siguiente = actual->sgte;

     }
}
int main()
{
    Nodopoliza *lista = NULL;
    Nodopoliza *aux=NULL;
    Nodopoliza *x=NULL;
    FILE *pol;
    Polizas p;
    int poliza, poliza2;
    char opcion; char cuota; char activa; char dni [11];
    ListapolizaborrarLista(lista);
    /*cargarincidentesprueba ();
    cargarpolizaprueba ();*/
    levantarPoliza (lista);
    do
    {
        opcion = menu();
        switch (opcion)
        {
            case '1':
                Polizas nuevapoliza;
                cout << "Ingrese los datos de la poliza: " << endl;
                cout << "Poliza (9999): " << endl;
                cin >> nuevapoliza.poliza;
                if (Buscarpoliza(lista,nuevapoliza.poliza))
                {
                    cout << "ERROR: YA HAY UNA POLIZA CON EL NRO QUE INTENTA INGRESAR" << endl;
                }
                else
                {
                    cout << "Ingrese el dni (xx.xxx.xxx): " << endl;
                    cin >> nuevapoliza.dni;
                    cout << "Nombre: ";
                    cin >> nuevapoliza.nombre;
                    cout << "Apellido: ";
                    cin >> nuevapoliza.apellido;
                    cout << "?Cuota al dia? (v,f): ";
                    cin >> cuota;
                    if (cuota == 'v')
                        nuevapoliza.cuota = true;
                    else
                        nuevapoliza.cuota=false;
                    cout << "Patente del auto (AAA999AA o AAA999): ";
                    cin >> nuevapoliza.patente;
                    cout << "?Esta activa? (v,f): ";
                    cin >> activa;
                    if (activa == 'v')
                        nuevapoliza.activa = true;
                    else
                        nuevapoliza.activa=false;
                    cout << "Cantidad de accidentes: ";
                    cin >> nuevapoliza.accidentes;
                    insertarOrdenado(lista,nuevapoliza);
                }
                break;
            case '2':
                cout << "Ingrese 1 para buscar por numero de poliza o ingrese 2 para buscar polizas por numero de DNI: " << endl;
                char eleccion;
                cin >> eleccion;
                if (eleccion == 49)
                {
                    cout << "Ingrese la poliza a buscar (9999): " << endl;
                    cin >> poliza;
                    x = Buscarpoliza (lista,poliza);
                }
                else if (eleccion == 50)
                {
                    cout << "Ingrese su dni (xx.xxx.xxx): " << endl;
                    cin >> dni;
                    BuscarpolizaDNI (lista,dni);
                }
                if (x)
                    mostrarpoliza(x);
                else
                    cout << "La poliza no esta en el archivo." << endl;
                break;
            case '3':
                    cout << "Ingrese legajo de la poliza a desactivar: " << endl;
                    cin >> poliza2;
                    borrarNodopoliza (lista, Buscarpoliza(lista,poliza2));
                    cout << "Se ha borrado correctamente" << endl;
                break;
            case '4':
                    ordenarLista (lista);
                    x = lista;
                    mostrarpolizas (x);
                break;
            case '5':
                mostrarenCSV (lista);
                mostrarenHTML (lista);
                break;
            case '6':
                int nrolote;
                cout << "Ingrese el numero de lote que desea procesar (1,2,3): " << endl;
                cin >> nrolote;
                procesarincidente (nrolote,lista);
                break;
    }
    }
    while (opcion != 27);
    guardarpolizaDisco (lista);
    ListapolizaborrarLista(lista);
    return 0;
}
