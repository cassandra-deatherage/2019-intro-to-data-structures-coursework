//HASH TABLE IMPLEMENTATION
#include "hash_table.h"
using namespace std;


house::house()//constructor for the house object
{
    description = NULL;
    hood = NULL;
    square_feet = 0;//total square footage of home
    bedrooms = 0;//total bedrooms in home
    distance = 0;//miles from PSU
}

house::~house()
{
    if(description)
        delete []description;
    if(hood)
        delete []hood;
}
int house::display()
{
    //display the data for one house object
    cout<<'\n'<<endl;
    if(description)
        cout<<'\t'<<description<<endl;
    if(hood)
        cout<<'\t'<<hood<<endl;
    cout<<'\t'<<"Number of bedrooms :"<<endl;
    cout<<'\t'<<bedrooms<<endl;
    cout<<'\t'<<"This is the distance from PSU :"<<endl;
    cout<<'\t'<<distance<<endl;
    cout<<'\t'<<"This is the number of square_feet :"<<endl;
    cout<<'\t'<<square_feet<<endl;
    cout<<'\n'<<endl;
}
int copy(house & to_add)
{
    //copy the data from the user to a house object
    int square_feet = 0;
    int bedrooms = 0;
    int distance = 0;
    int size = 100;
    char temp_description[size];
    char temp_hood[size];
    //gather the data from the user 
    //and populate the data into the house object

    //get the value for the description (hash key)
    cout<<'\t'<<"Please enter a one word description of the house: "<<'\n'<<endl;
    cin.get(temp_description, size, '\n');
    cin.ignore(100, '\n');
    int description = strlen(temp_description);
    for (int i = 0; i < description; ++i)
    {
        temp_description[i] = tolower(temp_description[i]);
    }
    //create a dynamically allocated array 
    if(to_add.description)
        delete []to_add.description;
    to_add.description = new char[strlen(temp_description)+1];
    //copy the temp name nto the house struct
    strcpy(to_add.description, temp_description);

    //Get the value for hood
    cout<<'\t'<<"Please enter the name of the neigborhood: "<<'\n'<<endl;
    cin.get(temp_hood, size, '\n');
    cin.ignore(100, '\n');
    int hood = strlen(temp_hood);
    for (int i = 0; i < hood; ++i)
    {
        temp_hood[i] = tolower(temp_hood[i]);
    }
    //create a dynamically allocated array 
    if(to_add.hood)
        delete []to_add.hood;
    to_add.hood = new char[strlen(temp_hood)+1];
    //copy the temp name nto the house struct
    strcpy(to_add.hood, temp_hood);

    //Get the value for square feet
    cout<<'\t'<<"Please enter the number of square feet: "<<'\n'<<endl;
    cin>>square_feet;
    cin.ignore(100, '\n');
    //Copy the data into the house struct
    to_add.square_feet = square_feet; 


    //Get the value for bedrooms
    cout<<'\t'<<"Please enter the number of bedrooms: "<<'\n'<<endl;
    cin>>bedrooms;
    cin.ignore(100, '\n');

    //Copy the data into the house struct
    to_add.bedrooms = bedrooms; 



    //Get the value for distance
    cout<<'\t'<<"Please enter the number of miles from PSU: "<<'\n'<<endl;
    cin>>distance;
    cin.ignore(100, '\n');
    //Copy the data into the house struct
    to_add.distance = distance; 

    return 1;

}


hash_table::hash_table(int size)//constructor for the HT
{
    //allocate the hash table and initialize each element
    //initialize each data member
    hash_table_size = size;
    array = new node*[size];
    for(int i = 0; i < size; ++i)
    {
        array[i] = NULL;
    }
}

hash_table::~hash_table()//destructor for the HT
{
    //
    for(int i = 0; i < hash_table_size; ++i)//for each index of HT
    {
        node * temp = array[i];//hold onto the start of the list
        while(temp)//while there is something to delete
        {
            node * current = temp->next;//hold onto the next node
            delete temp;
            temp = current;
        }
    }
}


//Takes a variable from the user converts it into a value stored in index
int hash_table::hash_function(char * key)
{
    int size = strlen(key);//hold onto the length of the key
    int index = 0;// initialize the variable that holds onto
    // where the key is being stored
    for(int i = 0; i < size; ++i)
    {
        //add ach ascii value up and store it in index
        index += key[i];
    }
    index %= hash_table_size;// mod the index amount by the size
    // of the hash table to store it
    return index;

}



int hash_table::read_in()
{
    house to_add;
    int size = 30;
    char description[size];
    char hood[size];
    int square_feet;
    int bedrooms;
    int distance;

    ifstream read;
    read.open("prog3.txt");
    if(read)
    {
        read.get(description, 30, '|');
        read.ignore(30, '|');
        while(!read.eof())
        {
            read.get(hood, 30, '|');
            read.ignore(100, '|'); 

            read>>square_feet;
            read.ignore(100, '|');

            read>>bedrooms;
            read.ignore(100, '|');

            read>>distance;
            read.ignore(100, '\n');
            if(to_add.description)
                delete []to_add.description;
            if(to_add.hood)
                delete []to_add.hood;
            to_add.description = new char[strlen(description) +1];
            strcpy(to_add.description, description);
            to_add.hood = new char[strlen(hood) +1];
            strcpy(to_add.hood, hood);

            to_add.square_feet = square_feet;
            to_add.bedrooms = bedrooms;
            to_add.distance = distance;

            insert(to_add.description, to_add);

            read.get(description, 30, '|');
            read.ignore(30, '|');


        }
        read.close();
    }
    return 1;
}
//Uses the hash function to store a new variable into the head of chain
int hash_table::insert(char * description, house & to_add)
{
    int index = hash_function(description);
    node * temp = array[index];    
    array[index] = new node;
    array[index]->next = temp;
    copy_entry(array[index]->data, to_add);
    cout<< "This item is stored at index : " << index << '\n'<<endl;
    return 1;
}

int hash_table::copy_entry(house & copy_to, house & to_add)
{
    //take the values from the object created in main
    //create dynamic memory for a new node
    //store them in the list

    copy_to.description = new char[strlen(to_add.description)+1];
    strcpy(copy_to.description, to_add.description);
    copy_to.hood = new char[strlen(to_add.hood)+1];
    strcpy(copy_to.hood, to_add.hood);

    copy_to.square_feet = to_add.square_feet;
    copy_to.bedrooms = to_add.bedrooms;
    copy_to.distance = to_add.distance;
    return 1;

}


int hash_table::display_all()
{
    if(!array)
        return 0;
    for(int i = 0; i < hash_table_size; ++i)
    {
        cout<<"This is the index: " <<endl;
        display(array[i]); 
    }
    return 1;
}

int hash_table::display(node * head)
{
    if(!head)
        return 0;
    head->data.display();
    return display(head->next) +1;
    //count the number of collisions in each
}



//Using hash function determines which chain to search
int hash_table::retrieve(char * search, house & found)
{
    int success = 0;
    int index = hash_function(search);
    node * current = array[index];
    cout<< "This item is stored at the index : " << index << '\n'<<endl;

    while(current)
    {
        if(strcmp(current->data.description, search) == 0)
        {
            copy_entry(found, current->data);   
            return 1; 
        }
        current = current->next; 
    }
    return success;
}

//Using hash function determine which chain to remove
int hash_table::remove(char * search)
{
    int success = 0;
    if(!array) 
        return 0;

    int index = hash_function(search);
    /* 
    node * current = array[index];
    if(strcmp(array[index]->data.description, search) == 0)
    {

    }
    */
    cout<< "This item is stored at the index : " << index << '\n'<<endl;
    return remove_recursive(array[index], search); 

}


int hash_table::remove_recursive(node * & head, char * search)
{
        if(!head)
            return 0;
        remove_recursive(head->next, search);

        if(strcmp(head->data.description, search) == 0)
        {
           node * temp = head->next;
           delete head;
           head = temp;
        }
        return 1;
}

//complete this function later!
int hash_table::search_distance(int miles, char list[][30])
{
    int counter = 0;
    for(int h = 0; h < hash_table_size; ++h)
    {
        if(array[h])
        {
            node * head = array[h];
            while(head != NULL)
            {
                if(head->data.distance <= miles)
                {
                    strcpy(list[counter], head->data.description);
                    ++counter;
                }
                //you need a temp ptr!
                head = head->next;
            }
        }
    }
    return counter; 
}





