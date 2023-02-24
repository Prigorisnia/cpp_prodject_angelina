#include <iostream>
#include "angelina.h"

using namespace std;
Stack *Begin1, *t,*k,*Begin2;
void razdelenie_spiska(Stack**p){
    Stack * null_bg1 = new Stack;
    Stack * null_bg2 = new Stack;
    Stack * t = null_bg1;
    Stack * z = null_bg2; 
    Stack ** gl_iter = p;
    while((*gl_iter)!=NULL){
        if((*gl_iter)->info<0){
            
          z->next = *gl_iter;
           
           z=z->next;
           *gl_iter = (*gl_iter)->next;
           z->next = NULL;
           
        }
        
        if((*gl_iter)->info>=0){
            
                
            t->next = *gl_iter;
          
        
           t = t->next;
           *gl_iter = (*gl_iter)->next;
           t->next = NULL;
         
        };
    }
    Begin1 = null_bg1->next;
    Begin2 = null_bg2->next;
    delete null_bg1;
    delete null_bg2;
}
void Sort_p(Stack **p) {
   
  	Stack *t = NULL, *t1, *r;
  	if ((*p) -> next -> next == NULL) return;
  	do {
     		for (t1=*p; t1-> next->next  != t; t1=t1-> next)
           		if (t1->next->info  >  t1-> next-> next-> info){
                			r = t1->next->next;
                			t1 -> next -> next = r -> next;
                			r-> next =t1-> next;
                			t1-> next = r;
           		}
     		t= t1-> next;
  	} while ((*p)-> next -> next != t);
    delete p;
}
void Delete_otr(Stack *p) {
   
  	
    Stack * begin = new Stack;
    begin->next=p;
Stack * it = begin;
    Stack * current;
    int err_ind = 1;
    while(err_ind!=0){err_ind=0;
    while(it->next!=NULL){
        
        if(it->next->info<0){
current=it->next;
it->next = it->next->next;
delete current;
err_ind++;
        }
       it = it->next;
    }
    it = begin;}
    delete begin;
}
void Max_Vershina(Stack*p){
    Stack * it = p ;
    Stack * currentPreMax = new Stack;
    while(it->next!=NULL){
        if(currentPreMax->info<=it->next->info){
    currentPreMax = it;}
    it = it->next;
    }
    Begin2 = currentPreMax->next;
    currentPreMax->next = NULL;
    
}
void Kol_vo_Delete(Stack*p){
Stack * begin = new Stack;
    begin->info = 0 ; 
    begin->next = p;
    Stack * it = begin;
    
    Stack * currentPreMin = new Stack;
    
    Stack * currentPreMax = new Stack;
    int i = 0;
    int i1 = 0;
    int i2 = 0;
    while(it->next!=NULL){
if(currentPreMax->info<=it->next->info){
    currentPreMax = it;
    i1 = i;
} else if(currentPreMin->info>=it->next->info){
    i2 = i;
    currentPreMin = it;
}
        it = it->next;
        i++;
    }
    Stack * nach_delete;
    if(i1>i2){nach_delete = currentPreMin->next->next;
              currentPreMin->next->next= currentPreMax->next;
        currentPreMax->next = NULL;
    } else { nach_delete = currentPreMax->next->next;
        currentPreMax->next->next= currentPreMin->next;
        currentPreMin->next = NULL;};
        Stack * current;
    
    while(nach_delete!=NULL){
current = nach_delete;
nach_delete =nach_delete->next;
delete current;
    };
}
void Min_Max(Stack**p){
    Stack * begin = new Stack;
    begin->info = 0 ; 
    begin->next = *p;
    Stack * it = begin;
    
    Stack * currentPreMin = new Stack;
    
    Stack * currentPreMax = new Stack;
    
    while(it->next!=NULL){
if(currentPreMax->info<=it->next->info){
    currentPreMax = it;
} else if(currentPreMin->info>=it->next->info){
    currentPreMin = it;
}
        it = it->next;
    }
Stack * currentMax;
Stack * currentMin;
currentMax = currentPreMax->next;
currentMin = currentPreMin->next;
Stack * currentPostMax = currentPreMax->next->next;
Stack * currentPostMin = currentPreMin->next->next;
currentPreMax->next = currentMin;
currentMin->next = currentPostMax;
currentPreMin->next = currentMax;
currentMax->next = currentPostMin;
*p=begin->next;

delete begin;
}
void Begin_to_end(Stack**p){
    Stack * it = *p;
    Stack * current;
    while(it->next->next!=NULL){
        it = it->next;
    }
    current = it->next;
    it->next = *p;
    current->next = (*p)->next;
    (*p)->next=NULL;
    Begin1 = current;
}
void Delete_menshe_srednego(Stack *p) {
   
  	
    Stack * begin = new Stack;
    begin->next=p;
Stack * it = begin;

int summ = 0;
int colvo = 0;
while(it!=NULL){
summ += it->info;
colvo++;
it = it->next;
}
it = begin;
int srednie = summ/colvo;
    Stack * current;
    int err_ind = 1;
    while(err_ind!=0){err_ind=0;
    while(it->next!=NULL){
        
        if(it->next->info<srednie){
current=it->next;
it->next = it->next->next;
delete current;
err_ind++;
        }
       it = it->next;
    }
    it = begin;}
    delete begin;
}
void Delete_chetnie(Stack *p) {
   
  	
    Stack * begin = new Stack;
    begin->next=p;
Stack * it = begin;
    Stack * current;
    int err_ind = 1;
    while(err_ind!=0){err_ind=0;
    while(it->next!=NULL){
        
        if(it->next->info%2==0){
current=it->next;
it->next = it->next->next;
delete current;
err_ind++;
        }
       it = it->next;
    }
    it = begin;}
    delete begin;
}
void Sort_2(Stack * p){
    Stack * t1 = p;
   for(int i =1;i!=0;){ i=0; do {
    
        if(t1->info>t1->next->info){
            int info = t1->next->info;
            t1->next->info = t1->info;
            t1->info = info;
            i++;
        } t1 = t1->next;
    } while(t1->next!=NULL);
    t1 = p;
    }
    return;
}
void delete_kazdii_vtoroi(Stack*p){
Stack *it = p;
Stack * current;
while(it->next!=NULL){
current = it->next;
it->next = it->next->next;
delete current;
if(it->next!=NULL){
it = it->next;}
};
}
void View(Stack *p,Stack *z) {
        Stack *t = p;
        while( t != NULL) {
                
cout << t->info<< "\n";
                t = t -> next;
        }
        cout << "sek_spis\n";
        Stack *k = z;
        while( k != NULL) {
                
cout << k->info<< "\n";
                k = k -> next;
        }
}
void Del_All(Stack **p,Stack **z = NULL) {
        while(*p != NULL) {
                t = *p;
                *p = (*p) -> next;
                delete t;
        }
        if(*z!=NULL){
        while(*z != NULL) {
                k = *z;
                *z = (*z) -> next;
                delete k;
        }}
}
Stack* InStack(Stack *p, int in) {
        Stack *t = new Stack;
        t -> info = in;
        t -> next = p;
        return t;
}
int main(){
    int i, n, kod;
    srandom(1);
    while(true){
   cout << "\tCreat - 1.  \t\t\tAdd - 2.\n\tView - 3.  \t\t\tDel - 4.\n\tEXIT - 0.  \t\t\tSort1 – 5.\n\tSort2 – 6.  \t\t\tRazdel – 7.\n\tDelete_otr – 8.  \t\tDelete_chetnie – 9.\n\tBegin_to_end – 10.  \t\tMax_to_Min – 11.\n\tMax_to_Vershina – 12.  \t\tKol_vo_Delte – 13.\n\tDelete_menshe_srednego – 14.  \tDelete_kazdii_vtoroi – 15.  :  " ;
   cin >> kod;
   switch(kod) {
      case 1: case 2:         
			if(kod == 1 && Begin1 != NULL){
// Если создаем новый стек, должны освободить память, занятую предыдущим
                        	cout << "Clear Memory!" << endl;
                        	break;
         		}
         cout << "Input kol = ";    
              cin >> n;
         for(i = 1; i <= n; i++)  {
              int in = (random() % 20);
              if(random()%2==1){in *= -1;}
                Begin1 = InStack(Begin1, in);
         }
         if (kod == 1) cout << "Create " << n << endl;
         else cout << "Add " << n << endl;
      break;
      case 3:         if(!Begin1){
                		cout << "Stack Pyst!" << endl;
                		break;
         		     }
                     if(!Begin2){
                		cout << "SecStack Pyst!" << endl;
                		
         		     }
         cout << "--- Stack ---" << endl;
         View(Begin1,Begin2);
      break;
      case 4:    
         Del_All(&Begin1,&Begin2);
         cout<<"Memory Free!"<<endl;
      break;
      case 5: Sort_p(&Begin1); 
      break;
      case 6: Sort_2(Begin1); 
      break;
      case 7: razdelenie_spiska(&Begin1); 
      break;
      case 8: Delete_otr(Begin1);
      break;
      case 9: Delete_chetnie(Begin1);
      break;
      case 10: Begin_to_end(&Begin1);
      break;
      case 11: Min_Max(&Begin1);
      break;
      case 12: Max_Vershina(Begin1);
      break;
      case 13: Kol_vo_Delete(Begin1);
      break;
      case 14: Delete_menshe_srednego(Begin1);
      break;
      case 15: delete_kazdii_vtoroi(Begin1);
      break;
      


      case 0:
         if(Begin1 != NULL)
			Del_All(&Begin1);
         return 0;		// Выход – EXIT
}
     }
}