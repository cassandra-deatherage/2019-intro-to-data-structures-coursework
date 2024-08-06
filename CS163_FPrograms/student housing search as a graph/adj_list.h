//adj_list.h
//program 5
//Cassandra Deatherage
//CS 163 Fall 
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

//data for each individual task



struct task
{
    task(char * title);
    task();
    ~task();
    char * title;
    bool compare(char * key_value); 

};

//
struct vertex
{
    vertex();
    ~vertex(); 
    task * data;
    struct node * head;//edge list
};

struct node
{
    //the pointer to the next task 
    vertex * adjacent;
    //the pointer to the next node at index[i] 
    node * next;
};

class task_manager
{
    public:
        task_manager(int size = 20);
        ~task_manager();
        int read_in();
        int insert(char * title);
        int find_location(char * key_value);
        int insert_edge(char * current_vertex, char * to_attach);
        int display_adjacent(char * key_value);
        int display_all();
        
    private:
        vertex * adj_list;
        int list_size;
        int displayll(vertex * vcurrent);
        int display_list(node * head);
};


