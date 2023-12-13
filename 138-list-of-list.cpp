#include <bits/stdc++.h>
using  namespace std;

string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

class slot{
    public:
    int time;
    string sub;
    slot* next;
    slot(int t, string s) : time(t), sub(s), next(NULL) {}
};

class day{
    public:
    int dno;
    day *next;
    slot *slots;
    day(int d = -1): dno(d), next(NULL), slots(NULL) {}
};

day *lastd = NULL;
day* sortInsDay(day *dd, int d){
    if(!dd || dd->dno == d){
        lastd = (!dd)? new day(d) : dd;
        return lastd;
    }
    if(d < dd->dno){
        lastd = new day(d);
        lastd->next = dd;
        return lastd;
    }
    dd->next = sortInsDay(dd->next, d);
    return dd;
}

slot* helpIns(slot *sl, int time, string sub){
    if(!sl || time <= sl->time){
        slot *s = new slot(time, sub);
        s->next = sl;
        return s;
    }
    sl->next = helpIns(sl->next, time, sub);
    return sl;
}
void sortInsSlot(day *dd, int day, int time, string sub){
    sortInsDay(dd, day);
    lastd->slots = helpIns(lastd->slots, time, sub);
}

void printList(day* d){
    if(!d) cout << "FREE!!" << endl;
    while(d){
        cout << days[d->dno] << " : \n";
        slot *s = d->slots;
        while(s){
            cout << "Slot - " << s->time << " : Subject - " << s->sub << endl;
            s = s->next;
        }
        d = d->next;
        cout << endl;
    }
}

int main(){

    day  *dummyday = new day; 

    cout << "\nDay 0 is Monday, Day 2 is Tuesday and so on...\n\n";
    int choice = 1;
    while(choice){
        cout << "Enter day, time and subject: ";
        int day, time; string sub;
        cin >> day >> time >> sub;
        sortInsSlot(dummyday, day, time, sub);
        cout << endl << "Enter 1 to continue (else 0 to exit): "; cin >> choice;
        cout << endl;
    }
    printList(dummyday->next);
    return 0;
}