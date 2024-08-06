//main.cpp
//this is the file to implement all of 
//the member functions for the tree
//Cassandra Deatherage
//CS 163 Fall
//in this program we are using the same concepts from
//the last program in order to implement a BST. 

//The ADT is a table (sort using the value of the data)
//The BST needs to have left & right pointers
#include "tree.h"
using namespace std;

int main()
{
    //create objects of the class
    //call the member functions

    manager my_table; // (table ADT)
    house to_add;
    my_table.read_in(); 
    int choice = -1;
    while(choice != 0)
    {
        cout<<'\t'<<"Please enter your choice :"<<endl;
        cout<<'\t'<<"To insert a new home enter 1 :"<<endl;
        cout<<'\t'<<"To search for homes based on description type 2 :"<<endl;
        cout<<'\t'<<"To remove a neighborhood from your search type 3 :"<<endl;
        cout<<'\t'<<"To remove based on description type 4 :"<<endl;
        cout<<'\t'<<"To display by location type 5 :"<<endl;
        cout<<'\t'<<"To display all type 6 :"<<endl;
        cout<<'\t'<<"To check the height type 7 :"<<endl;
        cout<<'\t'<<"To check the efficiency type 8 :"<<endl;
        cout<<'\t'<<"To quit type 0 :"<<endl;


        cin>>choice;
        cin.ignore(100, '\n');

        if(choice == 1)//insert a new home
        {
            copy(to_add);
            my_table.insert(to_add);
            to_add.display();  
        }
        if(choice == 2)//search by description
        {
            int size = 100;
            house found;
            //search by description
            char search[size]; 
            cout<<'\t'<<"Please enter the description of the type of house you're looking for : "<<endl; 
            cin.get(search, size, '\n');
            cin.ignore(100, '\n');
            //create a lower case argument to search for
            for(int i = 0; i < size; ++i)
            {
            search[i] = tolower(search[i]);
            }

            int success = my_table.search_by_name(search, found);

            if(success == 1)
            {

            cout<<'\n'<<endl;
            cout<<"There is a house that fits that description : "<<endl;
            cout<<'\t'<<"Description: "<<found.description<<endl;
            cout<<'\t'<<"Neighborhood: "<<found.hood<<endl;
            cout<<'\t'<<"Square feet: "<<found.square_feet<<endl;
            cout<<'\t'<<"Number of Bedrooms: "<<found.bedrooms<<endl;
            cout<<'\t'<<"Distance from PSU: "<<found.distance<<" miles from PSU "<<endl;
            cout<<'\n'<<endl;

            }
            else
            cout<<'\t'<<"No match was found "<<endl;
            cout<<'\n'<<endl; 
        }
        if(choice == 3)//remove by neighborhood
        {
            //grab the data for removal match 
            int size = 100;
            char key[size];
            cout<<'\n'<<endl; 
            cout<<'\t'<<"Please enter the neighborhood you would like to remove from the list: "<<endl;
            cin.get(key, size, '\n');
            cin.ignore(100, '\n');
            //lower case the data so it will 
            //match the list
            for(int i = 0; i < size; ++i)
            {
                key[i] = tolower(key[i]);
            }
            int count = my_table.remove_location(key);
            cout<<'\n'<<endl;
            cout<<'\t'<<"The total number of houses removed was "<< count <<endl;
            cout<<'\n'<<endl;
        }
        if(choice == 4)//remove by description
        {
            //grab the data for removal match 
            int size = 100;
            char key[size];
            cout<<'\n'<<endl; 
            cout<<'\t'<<"Please enter the description of the house you want to remove: "<<endl;
            cin.get(key, size, '\n');
            cin.ignore(100, '\n');
            //lower case the data so it will 
            //match the list
            for(int i = 0; i < size; ++i)
            {
                key[i] = tolower(key[i]);
            }
            int count = my_table.remove_name(key);
            cout<<'\n'<<endl;
            cout<<'\t'<<"The total number of houses removed was "<< count <<endl;
            cout<<'\n'<<endl;
        }
        if(choice == 5)//display by neighborhood
        {
            //grab the data for display match 
            int size = 100;
            char key[size];
            cout<<'\n'<<endl; 
            cout<<'\t'<<"Please enter the neighborhood you would like to see properties for: "<<endl;
            cin.get(key, size, '\n');
            cin.ignore(100, '\n');
            //lower case the data so it will 
            //match the list
            for(int i = 0; i < size; ++i)
            {
                key[i] = tolower(key[i]);
            }
            my_table.display_locations(key);
            cout<<'\n'<<endl;
        }
        if(choice == 6)//display all
        {
        //display everything
        int total_houses = my_table.display();
        cout<<"There are "<< total_houses <<" in the list"<<endl; 
        }
        if(choice == 7)//check height 
        {
            cout<<'\n'<<endl;
            cout<<'\t'<<"This is the height of the tree : "<<endl;
            cout<<'\n'<<endl;
            
            int height = my_table.get_height();
            cout<< height <<endl;
            if(height == 0)
            cout<<'\t'<<"The tree is empty: "<<endl;
            else 
            cout<<'\t'<<"This is the height of the tree : "<<endl;
            cout<<'\n'<<endl;
 
        }
        if(choice == 8)//check efficiency
        {
            cout<<'\n'<<endl;
            cout<<'\n'<<endl;
            int efficient = my_table.is_efficient();
            if(efficient == false)
                cout<<'\t'<<"The tree is not efficient "<<endl;
            else 
                cout<<'\t'<<"The tree is efficient "<<endl;
            cout<<'\n'<<endl;
            cout<<'\n'<<endl;

        }

    }
    return 0;
}







