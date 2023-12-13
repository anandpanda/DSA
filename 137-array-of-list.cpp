#include <bits/stdc++.h>
using  namespace std;

class slot{
    public:
    int time;
    string sub;
    slot* next;
    slot(int t, string s) : time(t), sub(s), next(NULL) {}
};

void printList(slot* h){
    slot* head = h;
    if(head == NULL) cout << "FREE!!" << endl;
    while(head){
        cout << "Slot - " << head->time << " : Subject - " << head->sub << endl;
        head = head->next;
    }
    cout << endl;
}

void sortedInsert(slot* tt[], int day, int time, string sub){
    slot* s = new slot(time, sub);
    if (!tt[day] || tt[day]->time > time) {
        s->next = tt[day];
        tt[day] = s;
        return;
    }
    slot *p = NULL;
    slot *n = tt[day];
    while(n && n->time <= time){
        p = n;
        n = n->next;
    }
    p->next = s;
    s->next = n; 
}

int main(){
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    slot* tt[7] = {NULL};
    cout << "Day 0 is Monday, Day 2 is Tuesday and so on..." << endl << endl;
    int choice = 1;
    while(choice){
        cout << "Enter day, time and subject: ";
        int day, time; string sub;
        cin >> day >> time >> sub;
        sortedInsert(tt, day, time, sub);
        cout << endl << "Enter 1 to continue (else 0 to exit): "; cin >> choice;
        cout << endl;
    }
    for(int i=0; i<7; i++){
        cout << days[i] << " : " << endl;
        printList(tt[i]);
    }

    return 0;
}