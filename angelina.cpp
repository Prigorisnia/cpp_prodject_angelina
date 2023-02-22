#include <iostream>
#include "Struct.h"
#include <fstream>
using namespace std;

Stack *tt;
Stack *Begin;
const char * file = "students.txt";
fstream finout; 
fstream ostrem;
int main(int argc, char **argv)
{
  
	int i, n, kod;
finout.open( file, ios_base::in |  ios_base::out|  ios_base::binary );
finout.seekg(0);

ostrem.open("razmer.txt",  ios_base::in|  ios_base::binary );
ostrem.seekg(0);
if(finout.is_open()&&ostrem.is_open()){
int number ;
 ostrem >> number;
 ostrem.clear();
 ostrem.close();


for(int i = 0; i != number; i++)  {
               Info  in;
              
                finout.read((char *)&in,sizeof in);
                 
               Begin = InStack(Begin, &in);}}
finout.clear();
    
while(true){
   cout << "\n\tCreat - 1.\n\tAdd - 2.\n\tView - 3.\n\tDel - 4.\n\tEXIT – 0.  :  " ;
   cin >> kod;
   switch(kod) {
      case 1: case 2:         
			if(kod == 1 && Begin != NULL){
// Если создаем новый стек, должны освободить память, занятую предыдущим
                        	cout << "Clear Memory!" << endl;
                        	break;
         		}
         cout << "Input kol = ";        
          cin >> n;
         for(i = 1; i <= n; i++)  {
               
               cout << "Vvedite ocencki v stroky:";
               int o1;
               int o2;
               int o3;
               int o4;
               
               cin >> o1;
               
               cin >> o2;
               
                cin >> o3;
                
                cin >> o4;
                

               
               Info * in = new Info;
               cout << "\nGOd rozdenia:";
               int god_rozd;
               cin >> god_rozd;
               cout << "\nIniciali:";
               
               cin.get();
               cin.getline(in->str_inicial,10);

               in->god_rozdenia = god_rozd;
                
               
                in->chem = o1;
                in->math =o2;
                in->inform = o3;
                in->fiz = o4;           
               Begin = InStack(Begin, in);
         }
         if (kod == 1) cout << "Create " << n << endl;
         else cout << "Add " << n << endl;
      break;
      case 3:         if(!Begin){
                		cout << "Stack Pyst!" << endl;
                		break;
         		     }
         cout << "--- Stack ---" << endl;
         View(Begin);
      break;
      case 4:    
         Del_All(&Begin);
         cout<<"Memory Free!"<<endl;
      break;
      case 0:{
         if(Begin != NULL && finout.is_open()){
         Zapis(Begin);
			Del_All(&Begin);}
         return 0;
         		
      }
}
}

return 0;
}
Stack* InStack(Stack *p, Info * in) {
        Stack *t = new Stack;
        t -> info = in;
        t -> next = p;
        return t;
}
void Zapis(Stack *p) {
        Stack *t = p;
        

        int i = 0;
        while( t != NULL) {
               i++; 
               t = t -> next;
        }
        ostrem.open("razmer.txt",ios_base::out |  ios_base::binary );
        ostrem << i;
        ostrem.close();
        t = Begin;

        while( t != NULL) {
         finout.write((char *)&(*(t->info)),sizeof *(t->info)) << flush;
                
                t = t -> next;
        }
}
void View(Stack *p) {
        Stack *t = p;
        while( t != NULL) {
                cout << t->info->god_rozdenia << "\n"<<t->info->str_inicial<<"\n"<<t->info->chem<<"\n"<<t->info->math<<"\n"<<t->info->fiz<<"\n"<<t->info->inform<<"\n";
                t = t -> next;
        }
}
void Del_All(Stack **p) {
        while(*p != NULL) {
                tt = *p;
                *p = (*p) -> next;
               

                delete tt->info;
                delete tt;
        }
}
