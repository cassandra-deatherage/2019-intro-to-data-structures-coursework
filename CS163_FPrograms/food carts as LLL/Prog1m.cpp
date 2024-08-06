// Cassandra Deatherage 
// CS163 Fall Program 1 
// 10/06/19
// Prog 1 Main.cpp (prog1m.cpp)

// The purpose of this .cpp is to gather data from
// the user that populates a data structure (LLL)
// The second feature of this .cpp is to catch 
// return values for each function call to report
// success or failure

// Each food cart holds a:
// name
// location
// type of food
// customer review
// top 3 favorite foods in order of preference

#include "Prog1.h"
using namespace std;

//main function to gather & return data from/to client
main()
{
    // Get access to the list of functions in my class
    cartManager to_do;
    cart to_add;
    Food to_replace;

    int size = 50;
    char temp_name[size];
    char temp_location[size];
    char temp_type[size];
    char temp_review[size];
    char temp_top1[size];// index 1 food
    char temp_top2[size];// index 2 food
    char temp_top3[size];// index 3 food
    char temp_cart[size]; //temp name of cart to search
    char temp_replace[size]; //temp name of food to add
    int temp_choice; // index of array to change
    int choice = 0;// users choice of array index to access

    // Ask the user what they would like to do
    do
    {
        cout<<"Please enter your choice"
            <<"\n 1 -to add a new food cart"
            <<"\n 2 -to change a top 3 food"
            <<"\n 3 -to display all carts"
            <<"\n 4 -to display all carts by food type"
            <<"\n 5 -to remove a top 3 food"
            <<"\n 6 -to remove a food cart"
            <<"\n 7 -to quit"<<endl;
        cin>>choice;
        cin.ignore(100, '\n'); 
        //--------------------------------------------------        
        if(1 == choice)//insert a cart
        {
            //Gather all of the data to insert
            //Copy the data from the temp variable
            //into a dynamically allocated array
            //Cart name  
            cout<<"Please enter the cart name"<<endl;
            cin.get(temp_name, size, '\n');
            cin.ignore(100, '\n');
            int name = strlen(temp_name);
            for(int i = 0; i < name; ++i)
            {
                temp_name[i] = tolower(temp_name[i]);
            }
            //create a dynamically allocated array 
            if(to_add.name) 
                delete []to_add.name;
            to_add.name = new char[strlen(temp_name)+1];            //copy the temp name into the cart struct 
            strcpy(to_add.name, temp_name);  

            //Cart location
            cout<<"Please enter the cart location (example: park blocks) "<<endl;
            cin.get(temp_location, size, '\n');
            cin.ignore(100, '\n');
            int location = strlen(temp_location);
            for(int i = 0; i < location; ++i)
            {
                temp_location[i] = tolower(temp_location[i]);
            }
            if(to_add.location) 
                delete []to_add.location; 
            to_add.location = new char[strlen(temp_location)+1];           
            strcpy(to_add.location, temp_location);
            //(  destination /   source  ) 

            //Food type 
            cout<<"Please enter the type of food (example: chinese) "<<endl;
            cin.get(temp_type, size, '\n');
            cin.ignore(100, '\n');
            int type = strlen(temp_type);
            for(int i = 0; i < type; ++i)
            {
                temp_type[i] = tolower(temp_type[i]);
            }
            if(to_add.type)
                delete []to_add.type; 
            to_add.type = new char[strlen(temp_type)+1];           
            strcpy(to_add.type, temp_type);

            //Cart Review   
            cout<<"Please enter a brief review: "<<endl;
            cin.get(temp_review, size, '\n');
            cin.ignore(100, '\n'); 
            int review = strlen(temp_review);
            for(int i = 0; i < review; ++i)
            {
                temp_review[i] = tolower(temp_review[i]);
            }
            if(to_add.review)
                delete []to_add.review;
            to_add.review = new char[strlen(temp_review)+1];           
            strcpy(to_add.review, temp_review);

            //2D ARRAY
            //Gather the data for top 3 foods

            //Cart top 3 foods

            cout<<"Please enter the top three foods items in order of preference: "<<endl;
            //get the first item 
            cout<<" 1. : "<<endl;
            cin.get(temp_top1, size, '\n');
            cin.ignore(100, '\n');
            int top1 = strlen(temp_top1);
            for(int i = 0; i < top1; ++i)
            {
                temp_top1[i] = tolower(temp_top1[i]);
            }
 
            if(to_add.top3[0])
                delete []to_add.top3[0];
            to_add.top3[0] = new char[strlen(temp_top1)+1];            
            strcpy(to_add.top3[0], temp_top1);

            //get the second item            
            cout<<" 2. : "<<endl;
            cin.get(temp_top2, size, '\n');
            cin.ignore(100, '\n');
            int top2 = strlen(temp_top2);
            for(int i = 0; i < top2; ++i)
            {
                temp_top2[i] = tolower(temp_top2[i]);
            }
            if(to_add.top3[1])
                delete []to_add.top3[1];
            to_add.top3[1] = new char[strlen(temp_top2)+1];            
            strcpy(to_add.top3[1], temp_top2);

            //get the third item 
            cout<<" 3. : "<<endl;
            cin.get(temp_top3, size, '\n');
            cin.ignore(100, '\n');
            int top3 = strlen(temp_top3);
            for(int i = 0; i < top3; ++i)
            {
                temp_top3[i] = tolower(temp_top3[i]);
            }
 
            if(to_add.top3[2])
                delete []to_add.top3[2];
            to_add.top3[2] = new char[strlen(temp_top3)+1];
            strcpy(to_add.top3[2], temp_top3);

            //Catch insert function return value and 
            //define success or failure

            to_do.insert(to_add);
        }
// end gather data------------------------------------

//CHANGE A TOP 3 ITEM--------------------------------  
        if(2 == choice)
        {
            //get the name of the food cart
            cout<<"Which food cart would you like to add a top 3 food for? : "<<endl;
            cin.get(temp_cart, size, '\n');
            cin.ignore(100, '\n');
            int tname = strlen(temp_cart);
            for(int i = 0; i < tname; ++i)
            {
                temp_cart[i] = tolower(temp_cart[i]);
            }
            if(to_replace.name)
                delete []to_replace.name;
            to_replace.name = new char[strlen(temp_cart)+1];
            strcpy(to_replace.name, temp_cart);
            //get the location of the food
            cout<<"Which top 3 food would you like to replace? (please enter: 1, 2, or 3 :"<<endl;
            cin>>temp_choice;
            cin.ignore(100, '\n');
            to_replace.choice = temp_choice;
            //get the new favorite to add     
            cout<<"Please enter the name of the favorite food: "<<endl; 
            cin.get(temp_replace, size, '\n');
            cin.ignore(100, '\n');
            int t_replace = strlen(temp_replace);
            for(int i = 0; i < t_replace; ++i)
            {
                temp_replace[i] = tolower(temp_replace[i]);
            }
            if(to_replace.food)
                delete []to_replace.food;
            to_replace.food = new char[strlen(temp_replace)+1];
            strcpy(to_replace.food, temp_replace);

            int result = to_do.replace_food(to_replace);
            if(result == 1)
            {
                cout<<"The food was added successfuly!"<<endl;
            }
            else
            {
                cout<<'\n'<<endl;
                cout<<'\t'<<"There was no match for that cart "<<endl;
                cout<<'\n'<<endl; 

            }

        }


        // display all function------------------------------

        if(3 == choice)
        {
            cout<<"These are the carts in your list: "<<endl;
            to_do.displayAll();
        }

        // end display all-------------------------

        // display all carts by food type--------------------

        if(4 == choice)
        {
            cout<<"What type of food are you hungry for? : "<<endl;
            cin.get(temp_name, size, '\n');
            cin.ignore(100, '\n');
            int length = strlen(temp_name);
            for(int i = 0; i < length; ++i)
            {
                temp_name[i] = tolower(temp_name[i]);
            }
            //call the fn!
            int success = to_do.displayType(temp_name);
            if(success == 0)
            {
                cout<<'\n'<<endl;
                cout<<'\t'<<"The type: "<< temp_name <<"could not be found in the list of food carts "<<endl;
                cout<<'\n'<<endl;
            }
        }

        // end display all carts by food type----------------

        // remove a top 3 food------------------------------
        if(5 == choice)
        {
            //get the name of the food cart
            cout<<"Which food cart would you like to remove a top 3 food for? : "<<endl;
            cin.get(temp_cart, size, '\n');
            cin.ignore(100, '\n');
            int length = strlen(temp_cart);
            for(int i = 0; i < length; ++i)
            {
                temp_cart[i] = tolower(temp_cart[i]);
            }
            if(to_replace.name)
                delete []to_replace.name;

            to_replace.name = new char[strlen(temp_cart)+1];
            strcpy(to_replace.name, temp_cart);
            //get the location of the food
            cout<<"Which top 3 food would you like to remove? (please enter: 1, 2, or 3): "<<endl;
            cin>>temp_choice;
            cin.ignore(100, '\n');
            to_replace.choice = temp_choice;

            int success = to_do.deleteFood(to_replace);
            if(success == 0)
            {
                cout<<'\n'<<endl;
                cout<<'\t'<<"The type: "<< temp_name <<"could not be found in the list of food carts "<<endl;
                cout<<'\n'<<endl;

            }
        }
// end remove a top 3 food---------------------------

// Remove a cart from the list----------------------
        if(6 == choice)
        {
            //get the name of the food cart
            cout<<"Enter the name of the food cart you would like to remove? : "<<endl;
            cin.get(temp_cart, size, '\n');
            cin.ignore(100, '\n');
            int length = strlen(temp_cart);
            for(int i = 0; i < length; ++i)
            {
                temp_cart[i] = tolower(temp_cart[i]);
            }
            int success = to_do.deleteCart(temp_cart);
            if(success == 0)
            {
                cout<<'\n'<<endl;
                cout<<"The cart could not be found "<<endl;
                cout<<'\n'<<endl;
            }
        }


// end remove cart from list-----------------------
// end do while loop --------------------------------
    }while(choice != 7); 



    return 0;
};



