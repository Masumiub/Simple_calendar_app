#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

int convert_date_month(string month_name);
void display_calender_withStar();

int year;
string day;

struct remaindar {
    string title;
    string description;
    int date;
    string month;
};

remaindar r;
list<remaindar> mylist;

void add_remainder() {
    cout<< "Reminder title: ";
    getline(cin, r.title);
    //cin>> r.title;
    cout<< "Reminder description: ";
    getline(cin, r.description);
    //cin>> r.description;
    cout<< "Enter Date: ";
    cin>> r.date;
    cout<< "Enter Month: ";
    cin>> r.month;
    mylist.push_back(r);
    display_calender_withStar();
}

void update_remainder() {

    cout<< "Enter a reminder name to update: "<< endl;
    string str;
    getline(cin, str);
    //cin>>str;
    string new_title; string new_des; int new_date; string new_month;


    for(list<remaindar>::iterator it = mylist.begin(); it != mylist.end(); it++ ) {
        if(it->title == str){
            cout<< "New Reminder title: ";
            getline(cin, new_title);
            //cin>> new_title;
            it->title= new_title;
            cout<< "New Reminder description: ";
            getline(cin, new_des);
            //cin>> new_des;
            it->description = new_des;
            cout<< "Enter New Date: ";
            cin>>new_date;
            it->date = new_date;
            cout<< "Enter New Month: ";
            cin>> new_month;
            it->month = new_month;
        }
    }
    display_calender_withStar();
}

void display_remainder() {
    string str;
    cout<< "Enter a Month to display All Reminder: ";
    cin>>str;
    for(list<remaindar>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){
        if(it->month == str){
            cout<< "Tilte: ";
            cout<< it->title<< endl;
            cout<< "Description: ";
            cout<< it->description<< endl;
            cout<< "Date: ";
            cout<< it->date<< endl;
            cout<< "Month: ";
            cout<< it->month<< endl;
        }
    }
}

void delete_remainder() {
    string str;
    cout<< "Enter a Reminder Title to delete: ";
    cin>>str;
    for(list<remaindar>::iterator it = mylist.begin() ; it != mylist.end(); it++ ){
        if(it->title == str){
            mylist.erase(it);
            break;
        }
    }
    display_calender_withStar();
}


int convert_date_month(string month_name) {
    if(month_name == "January") {
        return 0;
    }
    else if(month_name == "February") {
        return 1;
    }
    else if(month_name == "March"){
        return 2;
    }
    else if(month_name == "April"){
        return 3;
    }
    else if(month_name == "May"){
        return 4;
    }
    else if(month_name == "June"){
        return 5;
    }
    else if(month_name == "July"){
        return 6;
    }
    else if(month_name == "August"){
        return 7;
    }
    else if(month_name == "September"){
        return 8;
    }
    else if(month_name == "October"){
        return 9;
    }
    else if(month_name == "November"){
        return 10;
    }else if(month_name == "December"){
        return 11;
    }
    else{
        return 0;
    }
}

bool check_leap_year(int year){
    if (year%400 == 0) {
        return true;
    }
    else if(year%4==0 && year%100!=0){
        return true;
    }else{
        return false;
    }
}

void day_name(){
    cout<< "\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat    "<< endl;
}
int get_first_day(string day){
    if(day=="Sunday" || day=="sunday"){
        return 0;
    }
    else if(day=="Monday" || day=="monday"){
        return 1;
    }
    else if(day=="Tuesday" || day=="tuesday"){
        return 2;
    }
    else if(day=="Wednesday" || day=="wednesday"){
        return 3;
    }
    else if(day=="Thursday" || day=="thursday"){
        return 4;
    }
    else if(day=="Friday" || day=="friday" ){
        return 5;
    }
    else{
        return 6;
    }

}
void display_calender(int year, string day){
    int days_in_month[12] = {31,28,31,30,31, 30, 31,31,30, 31, 30, 31};
    string months[12]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


    if(check_leap_year(year)==true){
        days_in_month[1]=28+1;
    }
    int j, total_days;int k;
    int weekdays=0;
    weekdays = get_first_day(day);

    int **A= new int*[12]; // declaring 2d dynamic array for calendar
    for (int i = 0; i < 12; i++) {
        A[i] = new int[31];
    }

    for (int i = 0; i < 12; i++) {

          cout<< endl;
          cout<< "----------------------"<< months[i]<<"----------------------" << endl;
          day_name();

        for(k=1; k<=weekdays; k++){
            cout<<"      "; // printing space
        }

        total_days = days_in_month[i];
        for(j=1; j<=total_days; j++){
            if(j>9){

            A[i][j]=j;
            cout<<"    "<<A[i][j];

            }
            else{
                A[i][j]=j;
                cout<<"     "<<A[i][j];
            }
            weekdays++;
            if(weekdays>6){
                weekdays =0;
                cout<< endl;
            }
        }
        cout<< endl<< endl;
    }

    for (int i = 0; i < 12; i++) {
        delete[] A[i];
    }
    delete[] A;

}


void display_calender_withStar(){
    int days_in_month[12] = {31,28,31,30,31, 30, 31,31,30, 31, 30, 31};
    string months[12]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int date; string month_name;
    int month_num;


    if(check_leap_year(year)==true){
        days_in_month[1]=28+1;
    }
    int j, total_days;int k;
    int weekdays=0;
    weekdays = get_first_day(day);


int rem_month,rem_date;

    int **A= new int*[12] ;
    for (int i = 0; i < 12; i++) {
        A[i] = new int[31];
    }

int count=0;

    for (int i = 0; i < 12; i++){
        list<int>ll;

        for(list<remaindar>::iterator it = mylist.begin() ; it != mylist.end(); it++) {
          if(it -> month == months[i]) {
            ll.push_back(it->date);
          }
        }

        cout<< endl;
        cout<< "----------------------"<< months[i]<<"----------------------" << endl;
        day_name();

        for(k=1; k<=weekdays; k++){
            cout<<"      "; // for printing space

        }

        total_days = days_in_month[i];
        for(j=1; j<=total_days; j++){

            if(j>9) { // those days are greater than=9
                bool ok = false;
                for(list<int>::iterator itt = ll.begin() ; itt != ll.end(); itt++) {
                    if(*itt == j) {
                        A[i][j]=j;
                        cout<<"   *"<<A[i][j];
                        ok = true;
                    }
                }
                if(!ok) {
                    A[i][j]=j;
                    cout<<"    "<<A[i][j];
                }
            }

            else{
                bool ok = false;
                for(list<int>::iterator itt = ll.begin() ; itt != ll.end(); itt++) {
                    if(*itt == j) {
                        cout<<"    *"<<A[i][j];
                        ok = true;
                    }
                }
                if(!ok) {
                    A[i][j]=j;
                    cout<<"     "<<A[i][j];
                }else{
                    A[i][j]=j;
                    cout<<"     "<<A[i][j];
                }
            }
            weekdays++;
            if(weekdays>6){
                weekdays =0;
                cout<< endl;
            }

        }

        cout<< endl<< endl;
    }

    for (int i = 0; i < 12; i++) {
        delete[] A[i];
    }
    delete[] A;
}

void to_do(){
    cout<< "\nPress 1. To Add a Reminder."<< endl;
    cout<< "\nPress 2. To Update a Reminder."<< endl;
    cout<< "\nPress 3. To Display a Reminder."<< endl;
    cout<< "\nPress 4. To Delete a Reminder."<< endl;
    cout<< "\nPress 0. To Exit The Program."<< endl;
}
int main()
{

    cout<< "Year: ";
    cin>> year;

    cout<< "Starting day of the year: ";
    cin>> day;
    display_calender(year, day);


    char n;
    do{
    to_do();
    cin>> n;
    cin.ignore();
    switch(n){
        case '1':
            add_remainder();
            break;
         case '2':
            update_remainder();
            break;
        case '3':
            display_remainder();
            break;
        case '4':
            delete_remainder();
            break;
        case '0':
            display_calender_withStar();
            exit(0);
            break;
    }
    }while(n!=0);

    return 0;
}
