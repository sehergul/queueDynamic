#include <iostream>
#define SIZE 10

using namespace std;

struct node{
    int data;
    node *next;
};

struct queue{
    int indis;
    node *front, *rear;
};


void baslangicDegerleri(queue *q){
    q->indis = 0;
    q->rear = q->front = NULL;
}


void enqueue(queue *q, int key){

    node *eleman= new node();
    eleman->data=key;

    if(q->indis==SIZE) //Kuyruk doluysa
        cout << "Kuyruk dolu!" << endl;

    else if(q->indis==0){ //Kuyruk bossa
        eleman->next=NULL;
        q->rear = q->front = eleman;
        q->indis++;
        cout << eleman->data << " kuyruga ilk dugum eklendi!" << endl;    }

    else{
        eleman->next=q->rear;
        q->rear=eleman;
        q->indis++;
        cout << key << " dugumu kuyruga eklendi!" << endl;
    }

}


void dequeue(queue *q){

    if(q->indis==0)
        cout << "Kuyruk bos!" << endl;

    else if(q->indis==1){ //Kuyrukta tek dugum varsa
        cout << q->front->data << " dugumu silindi, kuyrukta dugum kalmadi!" << endl;
        delete q->front;
        q->front=NULL;
        q->rear=NULL;
        q->indis--;}

    else{
        cout << q->front->data << " dugumu silindi!" << endl;
        node *temp = q->rear;
        while(temp->next!=q->front) //ilk degere kadar git
            temp = temp->next;
        delete q->front;
        q->front = temp;
        q->front->next = NULL;
        q->indis--;}
}

void print(queue *q){
    system("cls");
    if(q->indis==0)
        cout << "Kuyruk bos!" << endl;
    else{
        node* iter = q->rear;
        while(iter!=NULL){
            cout  << " <- " <<  iter->data;
            iter=iter->next;}
        cout << endl;

    }
}





int main()
{
    queue qu;
    baslangicDegerleri(&qu);
    int sayi, secim;
    while(true){
        cout << endl;
        cout << "KUYRUK UYGULAMASI" << endl;
        cout << "1- Enqueue " << endl;
        cout << "2- Dequeue " << endl;
        cout << "3- Print " << endl;
        cout << "4- Cikis " << endl;
        cout << "Yapmak istediginiz islemi seciniz: "; cin >> secim;
        switch(secim){
        case 1:
            cout << "Eklemek istediginiz sayiyi giriniz: "; cin >> sayi;
            enqueue(&qu, sayi);
            break;
        case 2:
            dequeue(&qu);
            break;
        case 3:
            print(&qu);
            break;
        case 4:
            cout << "Cikis yapiliyor..." << endl;
            return 0;
        default:
            cout << "Lutfen gecerli bir islem giriniz!" << endl;
            break;
        }
    }


    return 0;
}
