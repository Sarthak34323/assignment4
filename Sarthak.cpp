#include<iostream>
using namespace std;
// demonstrating inheritance
class student
{
    protected:
    char name[10];
    int roll;
    int age;
    public:
    void input()
    {
        cout<<"enter name of the student: ";
        cin>>name;
        cout<<"enter roll no of student: ";
        cin>>roll;
        cout<<"enter age of student: ";
        cin>>age;
    }
};
class test:public virtual student
{
    protected:
    int marks[5];
    public:
    void get()
    {
        input();
        cout<<"enter marks in 5 subjects: ";
        for(int i=0;i<5;i++)
        {
            cin>>marks[i];
        }
    }
};
class sports:public virtual student
{
    protected:
    int mark_sport;
    public:
    void get()
    {
        cout<<"enter marks in sports activity: ";
        cin>>mark_sport;
    }
};
class result:public test,public sports 
{
    int total=0;
    float percentage;
    public:
    void cal()
    {
        test::get();
        sports::get();
       for(int i=0;i<5;i++)
      {
          total+=marks[i];
      }
      percentage=total/5;
    }
    void display()
    {
        cout<<"name of the student is: "<<name<<endl;
        cout<<"roll no of the student is: "<<roll<<endl;
        cout<<"age of the student is: "<<age<<endl;
        cout<<"marks of the student is: "<<endl;
        for(int i=0;i<5;i++)
        cout<<marks[i]<<endl;
        cout<<"marks of student in sports activity is: "<<mark_sport;
        cout<<"total marks of the student is: "<<total<<endl;
        cout<<"percentage is: "<<percentage;
    }

};
// demonstrating constructors and destructors
int count=0;
class time
{
    int hours;
    int minutes;
    public:
    time()
    {
        count++;
        hours=10;
       minutes=5;
    }
    time(int x,int y=0)
    {
        count++;
        hours=x;
        minutes=y;
    }

    void display(void)
    {
        cout<<"time is: "<<hours<<":"<<minutes<<endl;
    }
    ~time()
    {
        cout<<"now the destructor is being invoked for object"<<count<<endl;
        count--;
    }
};
// demonstrating function overloading
void volume(float radius)
{
    float v;
    v=(4*3.14*radius)/3;
    cout<<"the volume of the sphere is: "<<v<<endl;
}
void volume(float radius1,float height1)
{
    float v;
    v=3.14*radius1*radius1*height1;
    cout<<"the volume of cylinder is: "<<v<<endl;
}
void volume(float length,float breadth,float height)
{
    float v;
    v=length*breadth*height;
    cout<<"the volume of the cuboid is: "<<v<<endl;
}
// demonstrating operator overloading
class complex
{
    int real;
    int imaginary;
    public:
    complex(int x=0,int y=0)
    {
        real=x;
        imaginary=y;
    }
    complex operator +(complex D)
    {
        complex temp;
        temp.real=real+D.real;
        temp.imaginary=imaginary+D.imaginary;
        return temp;
    }
    void operator ++()
    {
        ++real;
        ++imaginary;
    }
   void operator ++(int)
    {
        real++;
        imaginary++;
    }
    void display()
    {
        cout<<real<<" +"<<imaginary<<"i"<<endl;
    }

};
// demonstrating class template 
template<class T>
class A
{
    T x;
    public:
    A(T x)
    {
        cout<<x<<endl;
    }
};
// demonstrating exception handling
void exception_handle()
{
int arr[5],choice,j=1;
    for(int i=1;i<=5;i++)
    {
        cout<<"enter element "<<i<<" "<<endl;
        cin>>arr[i];
    }
    cout<<"enter the postion of element to be displayed: "<<endl;
    cin>>choice;
    if(choice>5||choice<1)
      j=0;
    try
    {
        if(j)
        {
            cout<<"element at the entered position is: "<<arr[choice];
        }
        else
        {
            throw(j);
        }
    }
   catch(int k)
    {
        cout<<"array of bound exception caught, please enter a valid choice";
    }
}
int main()
{
    int choice;
    char ch;
    do
    {
        cout<<"Enter choice according to the following menu: "<<endl;
        cout<<"\n 1. demonstrate inheritance ";
        cout<< "\n 2 . demonstrate constructor and destructor";
        cout<<"\n 3. demonstrate function overloading";
        cout<<"\n 4. demonstrate operator overloading";
        cout<<"\n 5. demonstrate class template";
        cout<<"\n 6. demonstrate exception handling ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
            result s1;
            s1.cal();
            s1.display();
            break;
            }
            case 2:
            {
            time t1;
            t1.display();
            time t2(15,20);
            t2.display();
            time t3(9);
            t3.display();
            break;
            }
            case 3:
            {
            volume(3.0);
            volume(3.0,4.0);
            volume(3.5,4.5,2.0);
            break;
            }
            case 4:{
            A<int>a(3);
            A<double>b(3.5);
            break;
            }
            case 5:{
            complex A(10,20),B(15,25);
             complex C=A+B;
             C.display();
             A.operator ++();
             A.display();
             B.operator ++();
             B.display();
            break;
            }
            case 6:
            {
            exception_handle();
            break;
            }

        }
        cout<<"do you wnat to continue: y/n"<<endl;
        cin>>ch;
    }while(ch=='y');
    return 0;
}
