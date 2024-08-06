//run the compile
#include "hash_table.h"
using namespace std;



int main()
{
    hash_table my_table;
    house to_add;
    my_table.read_in(); 
    int choice = -1;
    while(choice != 0)
    {
        cout<<'\t'<<"Please enter your choice :"<<endl;
        cout<<'\t'<<"To insert a new home enter 1 :"<<endl;
        cout<<'\t'<<"To search for homes based on description type 2 :"<<endl;
        cout<<'\t'<<"To find a home near PSU type 3 :"<<endl;
        cout<<'\t'<<"To remove based on description type 4 :"<<endl;
        cout<<'\t'<<"To display all of the available homes type 5 :"<<endl;

        cin>>choice;
        cin.ignore(100, '\n');

        if(choice == 1)
        {
            copy(to_add);
            my_table.insert(to_add.description, to_add);
        }
        if(choice == 2)
        {
            int size = 100;
            house found;
            //search by description
            char search[size]; 
            cout<<"Please enter the description of the type of house you're looking for : "<<endl; 
            cin.get(search, size, '\n');
            cin.ignore(100, '\n');
            //create a lower case argument to search for
            for(int i = 0; i < size; ++i)
            {
                search[i] = tolower(search[i]);
            }
            
            int success = my_table.retrieve(search, found);
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
                cout<<"No match was found "<<endl;
        }
        if(choice == 3)
        {
            char list[25][30];

            //remove by a distance
            int miles;
            cout<<'\n'<<endl; 
            cout<<"What is the max distance from PSU you would like to be? (enter in numeric format) : "<<endl;
            cin>>miles;
            cin.ignore(100, '\n');
            int count = my_table.search_distance(miles, list);
            cout<<'\t'<<"These are the houses within the range of miles you requested: "<<endl; 
            for(int i = 0; i <count; ++i)
            {
                cout<<'\t'<<list[i]<<endl;
            }
        }
        if(choice == 4)
        {
            int size = 100;
            //search by description
            char search[size];
            //remove by the description (keyword)
            cout<<'\n'<<endl; 
            cout<<"Please enter the description of the houses you want to remove: "<<endl;
            cin.get(search, size, '\n');
            cin.ignore(100, '\n');
            //create a lower case argument to search for
            for(int i = 0; i < size; ++i)
            {
                search[i] = tolower(search[i]);
            }
            int success = my_table.remove(search);
            if(success == 1)
            {
                cout<<'\n'<<endl;
                cout<<"All of the houses of that description have been removed "<<endl;
                cout<<'\n'<<endl;

            }
 
        }
        if(choice == 5)
        {
            //display everything
            int collisions = my_table.display_all();
            cout<<"There are "<< collisions <<" collisions in the hash table "<<endl; 
        }

    }
return 0;
}

