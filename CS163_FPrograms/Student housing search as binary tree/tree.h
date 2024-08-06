//tree.h
//Program 4
//this is the file for struct and class declarations
//and member function prototypes
//Cassandra Deatherage
//CS 163 Fall 
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
//#include <cstdlib>

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


struct node{
    
    house data;
    node * left;
    node * right;
};
/*
1.insert fn D
2. Search for a place by the name (supply matching information back to the client program that matches the search key supplied, through the argument list)
3. Remove by name D
4. Remove all by location D
5. Display all matches for a location D
6. Display all (in sorted order!) D
7. Get_Height D
8. Is_Efficient 
*/
class manager{
    
    public:
       manager();
       ~manager();
       int read_in();
       int remove_all();// done 
       int insert(house & to_add);//done
       int display();//display a single house entry
       int search_by_name(char * search, house & found);
       int remove_name(char * key);//call delete fn
       int remove_location(char * key);//call delete fn
       int remove();//deletes a node in the tree
       int display_locations(char * key);
       int display_all();//display all L to R//done
       int get_height();//done
       int copy_entry(house & copy_to, house & to_add);
       int is_efficient();//algorithm done
  
    private:
        node * root;
        int insert(node * & root, house & to_add);
        int in_order(node * root);//display in order
        int get_height(node * root);//done
        //remove fn to be called on by all remove fns
        int remove(node * & root); 
        int display_locations(node * & root, char * key);
        int remove_all(node *  & root);//delete tree
        int remove_location(node * & root, char * key);
        int remove_name(node * & root, char * key);
        int search_by_name(node * root, char * search, house & found);
        bool is_efficient(node * root);
};
 int copy(house & to_add);


