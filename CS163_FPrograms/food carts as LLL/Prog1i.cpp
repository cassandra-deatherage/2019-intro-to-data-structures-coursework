// Cassandra Deatherage
// 10/08/19
// Prog1i.cpp/ Implementation
// CS163 Fall Program 1
// 10/06/19
// Prog 1 Implementation.cpp (prog1i.cpp)

// Each food cart holds a:
// name
// location
// type of food
// customer review
// top 3 favorite foods in order of preference

#include "Prog1.h"
using namespace std;

//constructor /destructor for my cart
cart::cart()
{
    size = 3;
    name = NULL;
    location = NULL;
    type = NULL;
    review = NULL;
    top3 = new char * [size];

}

cart::~cart()
{
    if(name)
    {
        delete []name;
        name = NULL;
    }
    if(location)
    {
        delete []location;
        location = NULL;
    }
    if(type)
    {
        delete []type;
        type = NULL;
    }
    if(review)
    {
        delete []review;
        review = NULL;
    }
    for(int i = 0; i < size; ++i)
    {
        if(top3[i])
                delete []top3[i];
    }

    delete []top3;
}
//const dest for cart
Food::Food()
{
    choice = 0;
    name = NULL;
    food = NULL;
}

Food::~Food()
{
    if(name)
    {
        delete []name;
        name = NULL;
    }
    if(food)
    {
        delete []food;
        food = NULL;
    }
}

//constructor /destructor for my class

cartManager::cartManager()
{
    head = NULL;
}

cartManager::~cartManager()
{
    clear(head);
}

//DESTROY LIST
int cartManager::clear(node * head)
{
    if(!head)
        return 0;
    int total_deleted = clear(head->next);
    head->next = NULL;
    delete head;
    return total_deleted +1;
}

// insert a new cart into the LLL wrapper fn
int cartManager::insert(cart & to_add)
{
    insert(head, to_add);
}
// insert cart into the LLL 
int cartManager::insert(node * & head, cart & to_add)
{
    //if there is no list create one 
    if(!head)
    {
        //grab the data from main for the name
        head = new node;
        head->data.name = new char[strlen(to_add.name)+1];
        strcpy(head->data.name, to_add.name);

        //grab the data from main for the location
        head->data.location = new char[strlen(to_add.location)+1];
        strcpy(head->data.location, to_add.location);

        //grab the data from main for the type of cart
        head->data.type = new char[strlen(to_add.type) +1];
        strcpy(head->data.type, to_add.type);

        //grab the data from main for the review
        head->data.review = new char[strlen(to_add.review)+1];
        strcpy(head->data.review, to_add.review);

        //prevent accessing memory that isn't mine. 
        head->next = NULL;

        //fav food #1
        head->data.top3[0] = new char[strlen(to_add.top3[0])+1];
        strcpy(head->data.top3[0], to_add.top3[0]);

        //fav food #2
        head->data.top3[1] = new char[strlen(to_add.top3[1])+1];
        strcpy(head->data.top3[1], to_add.top3[1]);

        //fav food #3
        head->data.top3[2] = new char[strlen(to_add.top3[2])+1];
        strcpy(head->data.top3[2], to_add.top3[2]);

        //prevent accessing memory that isn't mine. 
        head->next = NULL;

        return 1;
    }

    //If there is a list add a new cart in alph order::

    if(strcmp(to_add.name, head->data.name)<0)
    {
        node * temp = new node;
        temp->next = head;
        temp->data.name = new char[strlen(to_add.name)+1];
        strcpy(temp->data.name, to_add.name);

        //add the rest of the data to the temp node

        //grab the data from main for the location
        temp->data.location = new char[strlen(to_add.location)+1];
        strcpy(temp->data.location, to_add.location);

        //grab the data from main for the type of cart
        temp->data.type = new char[strlen(to_add.type) +1];
        strcpy(temp->data.type, to_add.type);

        //grab the data from main for the review
        temp->data.review = new char[strlen(to_add.review)+1];
        strcpy(temp->data.review, to_add.review);

        //Add the three top foods to the 2D array
        //store the top 3 fav foods
        //in the list of arrays

        //fav food #1
        temp->data.top3[0] = new char[strlen(to_add.top3[0])+1];
        strcpy(temp->data.top3[0], to_add.top3[0]);

        //fav food #2
        temp->data.top3[1] = new char[strlen(to_add.top3[1])+1];
        strcpy(temp->data.top3[1], to_add.top3[1]);

        //fav food #3
        temp->data.top3[2] = new char[strlen(to_add.top3[2])+1];
        strcpy(temp->data.top3[2], to_add.top3[2]);

        head = temp;

        //prevent accessing memory that isn't mine. 

        return 2; //successfully added!
    }
    //the data is larger than so 
    //traverse to the next node to insert
    else
        cartManager::insert(head->next, to_add);

    // Iterative insert function // Not using 
    /* else
       {
       previous = head;
       current = head->next;
       while(current && strcmp(current->name, temp)<0)
       {
       current = current->next;
       previous = previous->next;
       }
       previous->next = new cart;
       previous->next->name = new char[strlen(temp)+1];
       strcpy(previous->next->name, temp);
       previous->next->next = current;
       return true;
       }*/

}
//display all wrapper
bool cartManager::displayAll()
{
    displayAll(head);
}
//recursive display al  function
bool cartManager::displayAll(node * head)
{
    if(!head)
        return 0;
    cout<<" Food cart name: "<<endl;
    cout<<'\t'<<head->data.name<<endl;

    cout<<" Location: "<<endl;
    cout<<'\t'<<head->data.location<<endl;

    cout<<" Type: "<<endl;
    cout<<'\t'<<head->data.type<<endl;

    cout<<" Food cart review: "<<endl;
    cout<<'\t'<<head->data.review<<endl;

    //display the top 3 foods!
    cout<<" The 3 favorite foods in order: "<<endl;
    cout<<'\t'<<"1. : "<<endl;
    cout<<'\t'<<'\t'<<head->data.top3[0]<<endl; 
    cout<<'\t'<<"2. : "<<endl;
    cout<<'\t'<<'\t'<<head->data.top3[1]<<endl;
    cout<<'\t'<<"3. : "<<endl;
    cout<<'\t'<<'\t'<<head->data.top3[2]<<endl;
    cout<<"\n"<<endl;

    displayAll(head->next);
    return 1;

}
// REPLACE FOOD FN
//search for a food cart & replace a top 3 favorite item
int cartManager::replace_food(Food & to_replace)
{
    //allocate the data from main to the variable
    int choice = to_replace.choice;

    //create a temp pointer to hold onto head
    node * current = head;
    //check to see if there is a list
    if(!current)return 0;
    //if there is a list search for the food cart 
    while(current)
    {
        if(strcmp(current->data.name, to_replace.name)==0)
        {
            //store the data for choice
            if(to_replace.choice == 1)
                choice = 0; 
            if(to_replace.choice == 2)
                choice = 1; 
            if(to_replace.choice == 3)
                choice = 2; 

            //delete the item in the correct index
            if(current->data.top3[choice])
            {  
                delete current->data.top3[choice];
                current->data.top3[choice] = new char[strlen(to_replace.food)+1];
                strcpy(current->data.top3[choice], to_replace.food);
            }     
            return 1;
        }
        else
            current = current->next; } 
    return 0; 
}
//----------------------------------------------------
//DISPLAY ALL BY TYPE OF FOOD 

//display by type wrapper
int cartManager::displayType(char * type)
{
    return displayType(head, type);
}
//recursive display al  function
int cartManager::displayType(node * head, char * type)
{
    if(!head)
        return 0;
    if(strcmp(head->data.type, type) == 0)
    {
        cout<<" Food cart name: "<<endl;
        cout<<'\t'<<head->data.name<<endl;

        cout<<" Location: "<<endl;
        cout<<'\t'<<head->data.location<<endl;

        cout<<" Type: "<<endl;
        cout<<'\t'<<head->data.type<<endl;

        cout<<" Food cart review: "<<endl;
        cout<<'\t'<<head->data.review<<endl;

        //display the top 3 foods!
        cout<<" The 3 favorite foods in order: "<<endl;
        cout<<'\t'<<"1. : "<<endl;
        cout<<'\t'<<'\t'<<head->data.top3[0]<<endl; 
        cout<<'\t'<<"2. : "<<endl;
        cout<<'\t'<<'\t'<<head->data.top3[1]<<endl;
        cout<<'\t'<<"3. : "<<endl;
        cout<<'\t'<<'\t'<<head->data.top3[2]<<endl;
        cout<<"\n"<<endl;
         
    }
    return displayType(head->next, type);

}
//END DISPLAY BY TYPE OF FOOD--------------------------

//DELETE FOOD ITEM IN LIST OF FAVORITE FOODS----------- 
int cartManager::deleteFood(Food & to_replace)
{
    //allocate the data from main to the variable
    int choice = to_replace.choice;

    //create a temp pointer to hold onto head
    node * current = head;
    //check to see if there is a list
    if(!current)return 0;
    //if there is a list search for the food cart 
    while(current)
    {
        if(strcmp(current->data.name, to_replace.name)==0)      
        {
            //create a local variable to store
            //a blank space for the empty top food
            char remove [2] = " ";

            //convert the data for choice to
            //correct index
            if(to_replace.choice == 1)
                choice = 0; 
            if(to_replace.choice == 2)
                choice = 1; 
            if(to_replace.choice == 3)
                choice = 2; 

            //delete the item in the correct index
            if(current->data.top3[choice])
            {  
                delete current->data.top3[choice];
            }     
            //re-allocate space for a new string
            current->data.top3[choice] = new char[strlen(remove)+1];
            //copy the new item into the index
            strcpy(current->data.top3[choice], remove);
            return 1;
        }
        else
            current = current->next; 
    } 
    return 0; 
}


//END DELETE FOOD ITEM FN-----------------------------

//REMOVE A FOOD CART----------------------------------
//wrapper
int cartManager::deleteCart(char * name)
{
    return deleteCart(head, name);
}
//recursive delete cart function
int cartManager::deleteCart(node * &head, char * name)
{
    if(!head)
        return 0; 
 
    if(strcmp(head->data.name, name) == 0)
    {
        node * temp = head;
        head = head->next;
        delete temp;
        return 1;
    }


    return deleteCart(head->next, name);

}
//END DELETE FOOD CART FN------------------------------


