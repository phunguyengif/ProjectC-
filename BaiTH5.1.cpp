#include<bits/stdc++.h>
using namespace std;
class Student
{
private:
    string name;
    int age;
    float gpa;
public:
   Student(string n, int a, float g){
    name = n;
    age = a;
    gpa = g;
   }
   string getName() const {
    return name;
   }
   int getAge() const{
    return age;
   }
   float getGpa() const{
    return gpa;
   }
   void setName(string n){
    name =n;
   } 
   void setAge(int a){
    age = a;
   }
   void setGpa(float g){
    gpa = g;
   }
   void displayInfo() const{
    cout<<"Ten: "<<name<<endl;
    cout<<"Tuoi: "<<age<<endl;
    cout<<"GPA: "<<gpa<<endl;
   }
};
int main(){
    Student t("Nguyen Van A", 20, 3.5);
    cout<<"Thong tin sinh vien:"<<endl;
    t.displayInfo();
    t.setGpa(3.8);
    cout<<"\nThong tin sau khi cap nhat: "<<endl;
    t.displayInfo();
    return 0;
}
