#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
using namespace std;

// structures
struct person{
    int start_num=0;
    string fullname="";
    string location="";
    double tek_1=0.0;
    double tek_2=0.0;
    double tek_rez=0.0;
};

// functions
void process_data(person people[]);
void print_people(person people[], int n);
void generate_rez_1(person people[], int n);
void sort_data_by_tek_1(person people[], int n);
void generate_rez_2(person people[], int n);
void sort_data_by_tek_2(person people[], int n);
void generate_rez_skup(person people[], int n);
void sort_data_by_tek_skup(person people[], int n);

int main(){
    // data setup
    int n=5;
    person people[n];
    srand(time(0));

    process_data(people);

    cout<<"[STARTNA LISTA]";
    print_people(people, n);

    // tek 1
    generate_rez_1(people, n);
    sort_data_by_tek_1(people, n);
    cout<<endl<<"[TEK 1]";
    print_people(people, n);

    // tek 2
    generate_rez_2(people, n);
    sort_data_by_tek_2(people, n);
    cout<<endl<<"[TEK 2]";
    print_people(people, n);

    // skup tek
    generate_rez_skup(people, n);
    sort_data_by_tek_skup(people, n);
    cout<<endl<<"[TEK SKUP]";
    print_people(people, n);
}

void process_data(person people[]){
    int start_num=0;
    string fullname="", location="";
    ifstream data("data.txt");

    int counter=0;
    while(data>>start_num>>fullname>>location){
        people[counter].start_num=start_num;
        people[counter].fullname=fullname;
        people[counter].location=location;
        counter+=1;
    }
    //cout<<"[data has been processed]"<<endl;
}
void print_people(person people[], int n){
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<people[i].start_num<<setw(20)<<people[i].fullname<<setw(15)<<people[i].location<<setw(10)<<people[i].tek_1<<setw(10)<<people[i].tek_2<<setw(10)<<people[i].tek_rez<<endl;
    //cout<<"[data has been printed]"<<endl;
}
void generate_rez_1(person people[], int n){
    for(int i=0; i<n; i++){ // loop for every person
        double rez = (rand()%2001+4000)/100.0;
        people[i].tek_1=rez;
    }
    //cout<<endl<<"[data has been sorted]"<<endl; // alert
}
void sort_data_by_tek_1(person people[], int n){
    for(int i=0; i<n; i++){ // loop for every person
        if(i!=n-1){ // do if is not last element
            for(int j=i; j<n; j++){
                if(people[i].tek_1<people[j].tek_1){
                    person temporary_person = people[i]; // create temporary person
                    people[i]=people[j]; // swap
                    people[j]=temporary_person; // swap
                }
            }
        }else{
            break; // go out of loop if is last element
        }
    }

    ofstream tek_1("tek_1.txt");
    for(int i=0; i<n; i++){
        tek_1<<"["<<i+1<<"] "<<people[i].start_num<<" "<<people[i].fullname<<" "<<people[i].tek_1<<" 0 0"<<endl;
    }

    //cout<<endl<<"[data has been sorted]"<<endl; // alert
}
void generate_rez_2(person people[], int n){
    for(int i=0; i<n; i++){ // loop for every person
        double rez = (rand()%2001+4000)/100.0;
        people[i].tek_2=rez;
    }
    //cout<<endl<<"[data has been sorted]"<<endl; // alert
}
void sort_data_by_tek_2(person people[], int n){
    for(int i=0; i<n; i++){ // loop for every person
        if(i!=n-1){ // do if is not last element
            for(int j=i; j<n; j++){
                if(people[i].tek_2<people[j].tek_2){
                    person temporary_person = people[i]; // create temporary person
                    people[i]=people[j]; // swap
                    people[j]=temporary_person; // swap
                }
            }
        }else{
            break; // go out of loop if is last element
        }
    }

    ofstream tek_2("tek_2.txt");
    for(int i=0; i<n; i++){
        tek_2<<"["<<i+1<<"] "<<people[i].start_num<<" "<<people[i].fullname<<" "<<people[i].tek_1<<" "<<people[i].tek_2<<" 0"<<endl;
    }
}
void generate_rez_skup(person people[], int n){
    for(int i=0; i<n; i++){ // loop for every person
        people[i].tek_rez=(people[i].tek_1+people[i].tek_2) / 2.00;
    }
    //cout<<endl<<"[data has been sorted]"<<endl; // alert
}
void sort_data_by_tek_skup(person people[], int n){
    for(int i=0; i<n; i++){ // loop for every person
        if(i!=n-1){ // do if is not last element
            for(int j=i; j<n; j++){
                if(people[i].tek_rez<people[j].tek_rez){
                    person temporary_person = people[i]; // create temporary person
                    people[i]=people[j]; // swap
                    people[j]=temporary_person; // swap
                }
            }
        }else{
            break; // go out of loop if is last element
        }
    }

    ofstream tek_skup("tek_skup.txt");
    for(int i=0; i<n; i++){
        tek_skup<<"["<<i+1<<"] "<<people[i].start_num<<" "<<people[i].fullname<<" "<<people[i].tek_1<<" "<<people[i].tek_2<<" "<<people[i].tek_rez<<endl;
    }
}
