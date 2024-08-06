//main.cpp
//program 5
//Cassandra Deatherage
//CS 163 Fall 
#include "adj_list.h"
using namespace std;
task_manager  my_tasks;
task to_add, an_entry;
char title[100], connected[100];

int main()
{
    task_manager  my_tasks;
    task to_add, an_entry;
    char title[100], connected[100];
    my_tasks.read_in();

    int choice = -1;
    while(choice != 0)
    {
        cout<<'\t'<<"Please enter your choice : "<<endl;
        cout<<'\t'<<"Type 1 to insert a new task : "<<endl;
        cout<<'\t'<<"Type 2 to create connections between tasks : "<<endl;
        cout<<'\t'<<"Type 3 to display remaining tasks :"<<endl;
        cout<<'\t'<<"Type 4 to display all tasks : "<<endl;
        cout<<'\t'<<"Type 0 to quit : "<<endl;
        cin>>choice;
        cin.ignore(100, '\n');

        if(choice == 1)//insert a new task
        {
            int again = -1;
            do
            {
                cout <<"Please enter the title of a task : ";
                cin.get(title, 100); cin.ignore(100,'\n');
                cout<<'\t'<<"To enter a task type 0 : "<<endl;
                cout<<'\t'<<"If you are done entering tasks type 1 : "<<endl;
                cin>>again;
                cin.ignore(100, '\n');
 
                //copy(title);
                //insert it into the graph
                my_tasks.insert(title);

            }while(again == 0);

        }
        if(choice == 2)//add connections
        {
            cout <<'\t'<<"Enter two titles that are related (connected): "<<endl;
            cin.get(title, 100); cin.ignore(100,'\n');
            cin.get(connected, 100); cin.ignore(100,'\n');
            my_tasks.insert_edge(title, connected);
            //my_tasks.insert_edge(connected, title); 
        }
        if(choice == 3)//display a path
        {
            cout <<"Enter a title you would like to display all of the edges for : ";
            cin.get(title, 100); cin.ignore(100,'\n');
            //call the display connections function 
            my_tasks.display_adjacent(title); 
        }
        if(choice == 4)//display adjacent
        {
            char key_value[20];
            cout<<'\t'<<"Enter a key value to search :"<<endl;
            cin.get(key_value, 100);
            cin.ignore(100, '\n');

            cout<<'\t'<<"This is the contents of the table :"<<endl;

            //call the display all function
            //my_tasks.display_adjacent(key_value); 
            my_tasks.display_all(); 
        }

    }
    return 0;
}

