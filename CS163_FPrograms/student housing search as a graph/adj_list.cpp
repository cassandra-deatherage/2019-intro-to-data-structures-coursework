//adj_list.cpp
//program 5
//Cassandra Deatherage
//CS 163 Fall 
#include "adj_list.h"
using namespace std;

task::task(char * title)
{
    //takes the data from main and does a deep 
    //copy into the data structure! 
    if(title)
    {
        this->title = new char[strlen(title)+1]; 
        strcpy(this->title, title);
    }
    else
        this->title = NULL;
}
task::task()//constructor for the house object
{
    title = NULL;
}

task::~task()//destructor for the house obj
{
    if(title)
        delete []title;//deallocate desc memory
}


vertex::vertex()
{
    data = NULL;
    head = NULL;
}

vertex::~vertex()
{
    if(data)
        delete data;
    node * temp = head;
    while(temp)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

task_manager::task_manager(int size)
{
    //Allocate the adjacency list and set each
    //head pointer to NULL
    //char * adj_list = new char [list_size];
    // vertex * adj_list = new vertex [list_size];
    
    adj_list = new vertex [size];
    list_size = size;
}
task_manager::~task_manager()
{
    delete []adj_list;

}


int task_manager::read_in()
{
    int size = 30;
    char title[size];  
    char title2[size]; 
    ifstream read;
    read.open("prog5.txt");
    if(read)
    {
        read.get(title, 30, '\n');
        read.ignore(30, '\n');
        while(!read.eof()&& strcmp(title, "|"))
        {
            insert(title);

            read.get(title, 30, '\n');
            read.ignore(30, '\n');

        }
        read.get(title, 30, ',');
        read.ignore(30, ',');
        while(!read.eof())
        {
            read.get(title2, 30, '\n');
            read.ignore(30, '\n');

            insert_edge(title, title2);
            read.get(title, 30, ',');
            read.ignore(30, ',');

        }

        read.close();
    }
    return 1;
}


//Store the vertex at this locaation.
int task_manager::insert(char * title)
{
    //find the first task  that is null
    for(int i = 0; i < list_size; ++i)
    {
        if(adj_list[i].data == NULL)
        {
            adj_list[i].data = new task(title);
            return 1;
            //ptr artithmetic 
            //*(adj_list+i).(*entry).copy_entry(to_add);
            //copy_entry.adj_list[
        }
    }
return -1;
}

//Attach an edge to a vertex
int task_manager::insert_edge(char * current_vertex, char * to_attach)
{
    
    //Attach this vertices edge to the specified vertex
    int first = find_location(current_vertex);
    int second = find_location(to_attach);
    if(first == -1) 
        return 0;
    if(second == -1)
        return 0;
    node * temp = adj_list[first].head;
    adj_list[first].head = new node;
    //what if there is only one item?
    adj_list[first].head->next = temp;
    adj_list[first].head->adjacent = &adj_list[second];
 
    return 1;
}

//iterative display a path
/*
//Display a path
int task_manager::display_adjacent(char * key_value)
{
    //see if key is in the list
    //if it is go to that index
    //display all of the vertices in that list
    int found = find_location(key_value);
    if(found == -1)
        return 0;
    node * current = adj_list[found].head;
    while(current != NULL) 
    {
        cout<<current->adjacent->data->title<<endl;
        current = current->next; 
    }
    return 0;
}
*/


//display a path recursive
int task_manager::display_adjacent(char * key_value)
{
    //see if key is in the list
    //if it is go to that index
    //display all of the vertices in that list
    int found = find_location(key_value);
    if(found == -1)
        return 0;

    node * head = adj_list[found].head;
    //cout<<head->adjacent->data->title<<endl; 
    if(head)
    { 
        vertex * vcurrent = head->adjacent;
        displayll(vcurrent);
    }
    return 0;
}


int task_manager::displayll(vertex * vcurrent)
{
    if(!vcurrent)
        return 0;
    
    cout<<vcurrent->data->title<<endl;
    
    if(vcurrent->head) 
        displayll(vcurrent->head->adjacent);
    
    return 1;
}

bool task::compare(char * key_value)
{
    if(!key_value || !title)
        return false;
    if(strcmp(key_value, title) == 0)
        return true;
    return false;
}


int task_manager::display_all()
{
    if(!adj_list)
        return 0;
    int count = 0;
    for(int i = 0; i < list_size; ++i)
    {
        if(adj_list[i].data)
        {
            ++count;
            cout<<adj_list[i].data->title<<": ";
            display_list(adj_list[i].head);
            cout<<endl;
        }
    }
    return count;
}
int task_manager::display_list(node * head)
{
    if(!head) 
        return 0;
    cout<<head->adjacent->data->title << "  ";
    return display_list(head->next) + 1;
}


//Find a location in the graph
//This is a helper function for
//all of the other member functions!
int task_manager::find_location(char * key_value)
{
    //return the location of this particular key value 
    for(int i = 0; i < list_size; ++i)
    {
        if(adj_list[i].data)
        {
            bool found = adj_list[i].data->compare(key_value);
            if(found)
                return i;
        }
    }
   
return -1;
}






