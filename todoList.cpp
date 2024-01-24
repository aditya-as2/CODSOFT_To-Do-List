#include <bits/stdc++.h>
using namespace std;

class ToDoList
{
private:
    int sno;
    string tname;
    string date;
    string status;

public:
    void menu();
    void add();
    void mark();
    void view();
    void del();
};

void ToDoList ::menu()
{
m:
    int choice;

    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t                 To-Do List                \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";

    cout << "\t\t\t\t\t|   1) Add task        |\n";
    cout << "\t\t\t\t\t|                      |\n";
    cout << "\t\t\t\t\t|   2) Change status   |\n";
    cout << "\t\t\t\t\t|                      |\n";
    cout << "\t\t\t\t\t|   3) View list       |\n";
    cout << "\t\t\t\t\t|                      |\n";
    cout << "\t\t\t\t\t|   4) Delete task     |\n";
    cout << "\t\t\t\t\t|                      |\n";
    cout << "\t\t\t\t\t|   5) Exit            |\n";
    cout << "\t\t\t\t\t                        \n";

    cout << "\n\t\t\t\t Please enter your choice: ";
    cin >> choice;

    cout << "\n\n";

    switch (choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            mark();
            break;
        }
        case 3:
        {
            view();
            break;
        }
        case 4:
        {
            del();
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            cout << "\n\n\t\t\t\tPlease select from the above options!\n\n";
            break;
        }
    }
    goto m;
}

void ToDoList :: add(){
    fstream data;
    int c;
    string stat="Pending";
    string n;
    string d;
    string s;

    cout <<"\n\t\t\t\t_________________________\n";
    cout <<"                  \n";
    cout <<"\n\t\t\t\t     -Add new task-    \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t_________________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter task name: ";
    cin>>tname;
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter date: ";
    cin>>date;
    cout <<"                  \n";

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<1<<" "<<tname<<" "<<date<<" "<<stat<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>d>>s;
        while (!data.eof())
        {
            data>>c>>n>>d>>s;
        }
        c++;
        data.close();
        data.open("database.txt",ios::app|ios::out);
        if(c>20){
            c=1;
        }
        data<<c<<" "<<tname<<" "<<date<<" "<<stat<<"\n";
        data.close();
        
    }
    cout<<"\n\t\t\t\t Task added successfully!\n\n";
}

void ToDoList :: mark(){
    fstream data,data1;
    int sno;
    int tkey;
    int token=0,c;
    string s,d;
    string n;

    cout <<"\t\t\t\t_____________________\n";
    cout <<"                  \n";
    cout <<"\n\n\t\t\t\t -Mark complete- \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t_____________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter task sno.: ";
    cin>>tkey;
    cout <<"                  \n";

    data.open("database.txt",ios::in);
    if(!data){
        cout << "\t\t\t\t Database doesn't exist!\n\n";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>sno>>tname>>date>>status;
        while(!data.eof()){
            if (tkey==sno)
            {
                c=sno;
                n=tname;
                d=date;
                cout<<"\n\n\t\t\t\t Enter status: ";
                cin>>s;

                data1<<" "<<c<<" "<<n<<" "<<d<<" "<<s<<"\n";

                cout << "\n\n\t\t\t\t status changed successfully!\n\n";
                token++;
            }
            else{
                data1<<" "<<sno<<" "<<tname<<" "<<date<<" "<<status<<"\n";
            }
            data>>sno>>tname>>date>>status;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n\t\t\t\t Task not found!\n\n";
        }
    }
}

void ToDoList :: view(){
    fstream data;

    data.open("database.txt",ios::in);

    if(!data){
        cout<<"\n\n\t\t\t\t Empty database!\n\n";
    }
    else{
        cout << "\n\n\t\t____________________________________Task list____________________________________\n\n";
        cout<<"\t\t\tS No.\t\tTask Name\t\tDue Date\t\tStatus";
        cout << "\n\t\t_________________________________________________________________________________\n\n";
        data>>sno>>tname>>date>>status;

        while (!data.eof())
        {
            cout<<"\t\t\t"<<sno<<"\t\t"<<tname<<"\t\t\t"<<date<<"\t\t\t"<<status<<"\n";
            data>>sno>>tname>>date>>status;

        }
        data.close();
        cout << "\n\n";
    }
}

void ToDoList :: del(){
    fstream data,data1;

    int tkey;
    int token=0;

    cout <<"\t\t\t\t_________________\n";
    cout <<"                  \n";
    cout <<"\n\n\t\t\t\t   -Delete Task-   \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t_________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter task sno.: ";
    cin>>tkey;
    cout <<"                  \n";

    data.open("database.txt",ios::in);
    if(!data){
        cout << "\t\t\t\t Database doesn't exist!\n\n";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>sno>>tname>>date>>status;
        while(!data.eof()){
            if (tkey==sno)
            {
                cout<<"\n\n\t\t\t\t Task deleted successfully!\n\n";
                token++;
            }
            else{
                data1<<" "<<sno<<" "<<tname<<" "<<date<<" "<<status<<"\n";
            }
            data>>sno>>tname>>date>>status;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n\t\t\t\t Task not found!\n\n";
        }
    }
}

int main()
{   
    ToDoList t;
    t.menu();
    return 0;
}
