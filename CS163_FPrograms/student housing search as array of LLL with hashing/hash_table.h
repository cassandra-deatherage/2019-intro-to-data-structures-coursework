//HASH TABLE HEADER FILE

#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
using namespace std;


struct house//hold all of the data for a house 
{
    //this house entry supports:
    //a description of the house 
    //the neighborhood
    //the square feet
    //the number of bedrooms
    //the distance from PSU
    house();
    ~house();
    char * description;//hash key
    char * hood;
    int square_feet;
    int bedrooms;
    int distance;
    int display();
};


//This class manages the data structure for the hash table. 
//The data structure for the hash table is an array of pointers to a LLL

struct node
{
    house data;//all the info for one house
    node * next;
};

//Create a table ADT (works by using the value of the data 
//instead of the position of where it is located

class hash_table
{
    public:
        hash_table(int size = 11);// constructor (use a prime number for hashtable size)
        ~hash_table(void); 
        int insert(char * description, house & to_add);
        int retrieve(char * search, house & found);
        int hash_function(char * key);
        int display_all();
        int copy_entry(house & copy_to, house & to_add);  
        int remove(char * search);
        int remove_recursive(node * & head, char * search);
        int search_distance(int miles, char list[][30]);

        int read_in();
    private:
        node ** array;//dynamically allocated array of head ptrs
        int display(node * head);

        int hash_table_size;
};

int copy(house & to_add);// 











