#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

enum sintomas{Fiebre,Dolor_de_cabeza,Nauseas,Mareos};
enum Doctor{Doc1,Doc2,Doc3,Doc4,Doc5,Doc6,Doc7,Doc8};
enum Estado{Estable,Grave,Critico};

struct pacientes_intensivos
{
    string nombre;
    string apellido;
    int edad;
    Estado in;
    string Enfermedad;
}; 

struct citas_medicas
{
    string nombre;
    string apellido;
    int edad;
    list<sintomas>sint;
    Doctor doct;
}; 

struct pacientes_F
{
    string nombre;
    string apellido;
    int edad;
}; 

void citas(list <citas_medicas> &Citas){
    bool m = true, continuar = true;
    int option, n, o;
    char c = 'y';
    struct citas_medicas citas_medicas;
    list <sintomas> &nec = citas_medicas.sint;
    

       while (m)
    {
        cout <<"______________________________________________________________________________\n"<< endl;
        cout <<"|\n/Bienvenido al sistema de citas de doctores/                              |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;
        cout <<"|1. Ingresar una persona a una cita con un Doctor                            |\n"<< endl;
        cout <<"|2. Eliminar a una persona de la lista de un Doctor                             |\n"<< endl;
        cout <<"|3. Mostrar lista de las citas                                              |\n"<< endl;
        cout <<"|4. Volver                                                                   |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;
        cout <<"| Introduzca un numero                                                       |\n"<< endl;
        cout <<"| Procesando                                                                 |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;

        cin >> option; cout<<endl; cin.ignore();
        switch (option)
        {
        case 1:
            continuar = true;
            cout << "Ingrese primer y segundo nombre \n";
            getline(cin, citas_medicas.nombre); cout << endl;
            cout << "Ingrese primer y segundo apellido \n";
            getline(cin, citas_medicas.apellido); cout << endl;
            do
            {
            cout << "Ingrese edad \n";
            cin>>citas_medicas.edad; 
            } while (citas_medicas.edad <= 0);
            
            cin.ignore();
        
            while (continuar){
            cout <<"________________________________ \n"<< endl;   
            cout <<"|Ingrese sintomas que presenta: |\n"<< endl; 
            cout <<"|1.fiebre                       |\n"<< endl; 
            cout <<"|2.Dolor de cabeza              |\n"<< endl; 
            cout <<"|3.Nauseas                      |\n"<< endl;
            cout <<"|4.Mareo                        |\n"<< endl;
            cout <<"|_______________________________|\n"<< endl;
            cin >> n;
            switch(n){
                case 1 : citas_medicas.sint.insert(citas_medicas.sint.end(),Fiebre);
                    cout << "Existe otra sintoma? (y/n)";
                    cin >> c;
                    if (c == 'n') continuar = false;
                    break;

                case 2 : citas_medicas.sint.insert(citas_medicas.sint.end(),Dolor_de_cabeza); 
                    cout << "Existe otra sintoma? (y/n)";
                    cin >> c;
                    if (c == 'n') continuar = false;
                    break;

                case 3 : citas_medicas.sint.insert(citas_medicas.sint.end(),Nauseas);
                    cout << "Existe otra sintoma? (y/n)";
                    cin >> c;
                    if (c == 'n') continuar = false;
                    break;

                case 4 : citas_medicas.sint.insert(citas_medicas.sint.end(),Mareos);
                    cout << "Existe otra sintoma? (y/n)";
                    cin >> c;
                    if (c == 'n') continuar = false;
                    break;

                default :
                    cout<<"opción no valida"<< endl;
                    break;
           } 
        }
            cout<<"______________________________________________________________________________\n"<< endl;
            cout<<"|  Ingrese el doctor que que atendera esta cita                              |\n"<< endl;
            cout<<"|____________________________________________________________________________|\n"<< endl;
            cout<<"|1.(Doc1) Guillermo Torres                                                   |\n"<< endl;
            cout<<"|2.(Doc2) Pablo Cornejo                                                      |\n"<< endl;
            cout<<"|3.(Doc3) Henry Arevalo                                                      |\n"<< endl;
            cout<<"|4.(Doc4) Dennis Funes                                                       |\n"<< endl;
            cout<<"|5.(Doc5) Mayra Bukele                                                       |\n"<< endl;
            cout<<"|6.(Doc6) Trinidad Benavides                                                 |\n"<< endl;
            cout<<"|7.(Doc7) Bárbara Cerón                                                      |\n"<< endl;
            cout<<"|8.(Doc8) Conny Lenom                                                        |\n"<< endl;
            cout<<"|____________________________________________________________________________|\n"<< endl;
            cin>>o; cout<< endl;
            switch(o){
                case 1 : citas_medicas.doct = Doc1;  
                    break;
                case 2 : citas_medicas.doct = Doc2; 
                    break;
                case 3 : citas_medicas.doct = Doc3; 
                    break;
                case 4 : citas_medicas.doct = Doc4;  
                    break;
                case 5 : citas_medicas.doct = Doc5; 
                    break;
                case 6 : citas_medicas.doct = Doc6; 
                    break;
                case 7 : citas_medicas.doct = Doc7;
                    break;
                case 8 : citas_medicas.doct = Doc8; 
                    break;
                default :
                    cout<<"opción no valida"<< endl;
                    break;
            }
            Citas.insert(Citas.end(), citas_medicas);

            break;
            case 2:
            cout << "Ingrese los nombres de la persona \n"<< endl;
            getline(cin, citas_medicas.nombre); cout << endl;

            cout << "Ingrese los apellidos de la persona r\n";
            getline(cin, citas_medicas.apellido); cout << endl;

            cout << "Ingrese la edad\n";
            cin >> citas_medicas.edad;
                 
            for(auto iter = Citas.begin(); iter != Citas.end(); ++iter)
                if(iter->nombre == citas_medicas.nombre && iter->apellido == citas_medicas.apellido 
                && iter->edad == citas_medicas.edad){
                    iter = Citas.erase(iter);
                    cout<<endl<<" Eliminando datos de la persona atendida..."<< endl;
                    break;
                } else cout<<endl<<" No se ha encontrado en la lista..."<< endl;
                       
            break;

        case 3:
        cout<<endl<<"Mostrando lista: "<<endl;
            for (citas_medicas i : Citas) {
                cout <<"\n Nombres: "<< i.nombre << " ";
                cout <<"\n Apellidos: "<< i.apellido << " ";
                cout <<"\n Edad: "<< i.edad << endl;
                for ( sintomas j : i.sint ){
                cout <<"\n Sintomas: ";
                 switch(j){
                  case Fiebre: cout << "Fiebre" << " "; break;
                  case Dolor_de_cabeza: cout << "Dolor_de_cabeza" << " "; break;
                  case Nauseas: cout << "Nauseas" << " "; break;
                  case Mareos: cout <<"Mareos"<< " "; break;
                 }
                }
                cout <<" Doctor: ";
                switch(i.doct){
                  case Doc1: cout << "1.(Doc1) Guillermo Torres" << endl; break;
                  case Doc2: cout << "2.(Doc2) Pablo Cornejo\n"<< endl; break;
                  case Doc3: cout << "3.(Doc3) Henry Arevalo\n"<< endl; break;
                  case Doc4: cout << "4.(Doc4) Dennis Funes\n"<< endl; break;
                  case Doc5: cout << "5.(Doc5) Mayra Bukele\n " << endl; break;
                  case Doc6: cout << "6.(Doc6) Trinidad Benavides\n"<< endl; break;
                  case Doc7: cout << "7.(Doc7) Bárbara Cerón\n"<< endl; break;
                  case Doc8: cout << "8.(Doc8) Conny Lenom\n"<< endl; break;
                }
           }
           cout<< endl;
        
            break;


        case 4:
            cout<<"Menu anterior ->"<< endl;
            m = false;
            break;

        default:
             cout"opción no valida"<< endl;
                    break;
        }

    }
}
void pacientes_intensivos( list <pacientes_intensivos> &pacientes_intensivos){
    bool m = true, continuar = true;
    int option, n;
    struct pacientes_intensivos;
    while (m)
    {
        cout <<"______________________________________________________________________________\n"<< endl;
        cout <<"|Bienvenido al Menu de Cuidados intensivos                                   |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;
        cout <<"|1. Ingresar una persona para tratamiento                                    |\n"<< endl;
        cout <<"|2. Eliminar una persona que ya ha recibido tratamiento                      |\n"<< endl;
        cout <<"|3. Ver lista de personas en cuidados                                        |\n"<< endl;
        cout <<"|4. Volver                                                                   |\n"<< endl;
        cout <<"|Introdusca el número de la acción a realizar                                |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;

        cin >> option;cout<<endl;cin.ignore();
        switch (option)
        {
        case 1:
            cout << "Ingrese primer y segundo nombre \n";
            getline(cin, pacientes_intensivos.nombre); cout << endl;
            cout << "Ingrese primer y segundo apellido \n";
            getline(cin, pacientes_intensivos.apellido); cout << endl;
            do
            {
            cout << "Ingrese edad \n";
            cin >> pacientes_intesivos.edad;
            } while (pacientes_intensivos.edad <= 0);
            
            cin.ignore();
            cot<<"Ingrese su estado\n"<< endl;
            getline(cin, pacientes_intensivos.Enfermedad); cout << endl;
            cout <<"_____________________________\n"<< endl;
            cout<<" |Ingrese el estado del Herido|\n"<< endl;
            cout<<" |1. Estable                  |\n"<< endl;
            cout<<" |2.Grave                     |\n"<< endl;
            cout<<" |3.Crítico                   |\n"<< endl;
            cout <<"|____________________________|\n"<< endl;
            cin>>n;cout<< endl;
            switch(n){
                case 1 : pacientes_intensivos.in = Estable; continuar = false; 
                    break;
                case 2 : pacientes_intensivos.in = Grave; continuar = false; 
                    break;
                case 3 : pacientes_intensivos.in = Critico; continuar = false; 
                    break;

                default : 
                    cout"opción no valida"<< endl;
                    break;
            }
           
            pacientes_intensivos.insert(pacientes_intensivos.end(), pacientes_intensivos);

            break;
        case 2:
            cout << "Ingrese nombre de la persona ingresada\n";
            getline(cin, pacientes_intensivos.nombre); cout << endl;

            cout << "Ingrese los apellidos de la persona ingresada\n";
            getline(cin, pacientes_intensivos.apellido); cout << endl;

            cout << "Ingrese la edad\n";
            cin >> pacientes_intensivos.edad;  
            
            for(auto iter = pacientes_intensivos.begin(); iter != pacientes_intensivos.end(); ++iter)
                if(iter->nombre == pacientes_intensivos.nombre && iter->apellido == pacientes_intensivos.apellido 
                && iter->edad == pacientes_intensivos.edad){
                    iter = pacientes_intensivos.erase(iter);
                    cout << endl << " Eliminando datos de la persona ingresada..."<< endl;
                    break;
                } else cout << endl <<" No se ha encontrado en la lista..."<< endl;
                               
            break;

        case 3:
        cout<<endl<<"Mostrando lista: "<< endl;
            for (pacientes_intensivos i : pacientes_intensivos) {
                cout <<"Nombres: "<< i.nombre << " ";
                cout <<"\n Apellidos: "<< i.apellido << " ";
                cout <<"\n Edad: "<< i.edad << " ";
                cout<<"\n Enfermedad"<<i.Enfermedad<< endl;
                cout <<" Estado: ";
                switch(i.in){
                    case Estable: cout << "Estable" << endl; break;
                    case Grave: cout << "Grave" << endl; break;
                    case Critico: Cout<<"Crítico"<< endl; break;
                }
                cout<< endl;
           }

            break;

        case 4:
           cout<<"Menu anterior ->">>endl;
            m=false;
            break;

        default:
             cout"opción no valida"<< endl;
                    break;
        }

    }
}
void pacientes_F(list <pacientes_F> &pacientes_F){
    bool m=true;
    int option;
    struct pacientes_F pacientes_F;
    while (m)
    {
        cout <<"______________________________________________________________________________\n"<< endl;
        cout <<"|Bienvenido al Menu de La Morgue                                             |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;
        cout <<"|1. Ingresar el Nombre de la persona que fallecio                            |\n"<< endl;
        cout <<"|2. Eliminar un cuerpo que a sido llevado al velorio                          |\n"<< endl;
        cout <<"|3. Ver lista de personas en la morgue                                       |\n"<< endl;
        cout <<"|4. Volver                                                                   |\n"<< endl;
        cout <<"|Introdusca el número de la acción a realizar                                |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;
        cin >> option;cout<<endl;cin.ignore();
        switch (option)
        {
        case 1:
            cout << "Ingrese primer y segundo nombre \n";
            getline(cin, pacientes_F.nombre); cout << endl;
            cout << "Ingrese primer y segundo apellido \n";
            getline(cin, pacientes_F.apellido); cout << endl;
            cout << "Ingrese edad \n";
            cin >> pacientes_F.edad;
            pacientes_F.insert(pacientes_F.end(), pacientes_F);
            break;
        case 2:
            cout << "ingrese el nombre del difunto\n";
            getline(cin, pacientes_F.nombre); cout << endl;
        
            cout << "Ingrese los apellidos del difunto\n";
            getline(cin, pacientes_F.apellido); cout << endl;

            cout << "Ingrese la edad \n";
            cin >> pacientes_F.edad;

            for(auto iter = pacientes_F.begin(); iter != pacientes_F.end(); ++iter)
                if(iter->nombre == pacientes_F.nombre && iter->apellido == pacientes_F.apellido 
                && iter->edad == pacientes_F.edad){
                    iter = pacientes_F.erase(iter);
                    cout << endl << " Eliminando datos de la persona fallecida..."<< endl;
                    break;
                } else cout << endl <<" No se ha encontrado en la lista..."<< endl;

            break;

        case 3:
        cout<<endl<<"Mostrando lista: "<< endl;
            for (pacientes_F i : pacientes_F) {
                cout <<"Nombres: "<< i.nombre << " ";
                cout <<"Apellidos: "<< i.apellido << " ";
                cout <<"Edad: "<< i.edad << endl;
           }

            break;
        case 4:
        cout<<"Menu anterior ->"<< endl;
            m=false;
            break;

         cout"opción no valida"<< endl;
                    break;
        }

    }
}
void menu(list <citas_medicas> &Citas, list <pacientes_intensivos> &pacientes_intensivos, list <pacientes_F> &pacientes_F){
     bool m = true;
     int option;
     citas_medicas afec;

    while (m)
    {
        cout <<"______________________________________________________________________________\n"<< endl;
        cout <<"|Bienvenido al Sistema del Hospital Me fui feliz                             |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;
        cout <<"|1. Registrar una Cita medica                                                |\n"<< endl;
        cout <<"|2. Registros de Cuidados intensivos                                         |\n"<< endl;
        cout <<"|3. Registros de la morgue                                                   |\n"<< endl;
        cout <<"|4. Volver                                                                   |\n"<< endl;
        cout <<"|Introdusca el número de la acción a realizar                                |\n"<< endl;
        cout <<"|____________________________________________________________________________|\n"<< endl;

        cin >> option;
        switch (option)
        {
        case 1:
            citas(Citas);
            break;
        case 2:
            pacientes_intensivos(pacientes_intensivos);
            break;
        case 3:
            pacientes_F(pacientes_F);
            break;
        case 4:
            cout<<"Cerrando Sistema..."<< endl;
            m=false;
            break;

         cout"opción no valida"<< endl;
                    break;
        }

    }
}

int main(void){
 list <citas_medicas> Citas;
 list <pacientes_intensivos> pacientes_intensivos;
 list <pacientes_F> pacientes_F;

 menu(Citas,pacientes_intensivos,pacientes_F);

 return 0;
} 
