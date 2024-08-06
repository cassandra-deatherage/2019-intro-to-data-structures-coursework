//tree.cpp
//this is the file to prompt data
//from the user and call member functions
//Cassandra Deatherage
//CS 163 Fall
#include "tree.h"
using namespace std;

house::house()//constructor for the house object
{
    description = NULL;
    hood = NULL;
    square_feet = 0;//total square footage of home
    bedrooms = 0;//total bedrooms in home
    distance = 0;//miles from PSU
}

house::~house()//destructor for the house obj
{
    if(description)
        delete []description;//deallocate desc memory
    if(hood)
        delete []hood;//deallocate hood memory
}



//Functions related to the manager class
manager::manager()
{
    root = NULL;
}

manager::~manager()
{
    remove_all();
}



int manager::read_in()
{
    house to_add;
    int size = 30;
    char description[size];
    char hood[size];
    int square_feet;
    int bedrooms;
    int distance;

    ifstream read;
    read.open("prog4.txt");
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

            insert(to_add);

            read.get(description, 30, '|');
            read.ignore(30, '|');


        }
        read.close();
    }
    return 1;
}
//remove everything in the tree
int manager::remove_all()
{
    return remove_all(root);
}

int manager::remove_all(node * & root)
{
    if(!root)
        return 0;
    int count = remove_all(root->left) + remove_all(root->right);
    ++count;
    delete root;
    return count;
}



//wrapper for remove by description
int manager::remove_name(char * key)
{
    return remove_name(root, key);
}
//remove a house by description
int manager::remove_name(node * & root, char * key)
{
    if(!root)
        return 0;
    int count = 0;
    int match = strcmp(root->data.description, key);
    if(match == 0) 
    {
       remove(root);
       ++count;
    }
    else if(match > 0) 
    {
        remove_name(root->left, key);
    }
    else
        remove_name(root->right, key);
    
    return count;
    
}



//wrapper for calling routine
int manager::remove_location(char * key)
{
    return remove_location(root, key);
}
//remove all by location
int manager::remove_location(node * & root, char * key)
{
    if(!root)
        return 0;
    int count = remove_location(root->left, key) + remove_location(root->right, key);
    if(strcmp(key, root->data.hood) == 0) 
    {
        ++count;
        remove(root);
    }
    return count;
}


//wrapper for calling routine
int manager::display_locations(char * key)
{
    return display_locations(root, key);
}
//display all by location
int manager::display_locations(node * & root, char * key)
{
    if(!root)
        return 0;
    int count = display_locations(root->left, key) + display_locations(root->right, key);
    if(strcmp(key, root->data.hood) == 0) 
    {
        ++count;
        root->data.display();
    }
    return count;
}


//prompt user for data for a new house object
//and make fill in a temporary house object
//to pass into my data structure
int copy(house & to_add)
{
    int square_feet = 0;
    int bedrooms = 0;
    int distance = 0;
    int size = 100;
    char temp_description[size];
    char temp_hood[size];

    //get the value for the description
    // ** This is the search key! **
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
    //copy the temp name into the house struct
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
    //copy the temp name into the house struct
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


    
//take the values from the object created in main
//create dynamic memory for a new node
//store them in the list
int manager::copy_entry(house & copy_to, house & to_add)
{
    copy_to.description = new char[strlen(to_add.description)+1];
    strcpy(copy_to.description, to_add.description);
    copy_to.hood = new char[strlen(to_add.hood)+1];
    strcpy(copy_to.hood, to_add.hood);

    copy_to.square_feet = to_add.square_feet;
    copy_to.bedrooms = to_add.bedrooms;
    copy_to.distance = to_add.distance;
   
    return 1;
}


//This insert takes in data from the user 
//and inserts it into the list
int manager::insert(house & to_add)
{
    return insert(root, to_add);
}

int manager::insert(node * & root, house & to_add)
{
    if(!root)
    {
        root = new node; 
        copy_entry(root->data, to_add);
        root->left = NULL; 
        root->right = NULL;
    }
    else if(strcmp(root->data.description, to_add.description)>0)
        insert(root->left, to_add); 
    else insert(root->right, to_add);
    
    return 0; 
}



//displays the data for one house
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
    return 0;
}



//displays all of the houses inserted in the tree
int manager::display()
{
    return in_order(root);
}
int manager::in_order(node * root)
{
    if(!root)
        return 0;
    int count = in_order(root->left); 
    root->data.display();
    ++count;
    count += in_order(root->right);
    return count;
}


// I got stuck on the removal functionn and did not have
// time to finish this search function!!


//search for data by description and return through
//the argument list
int manager::search_by_name(char * search, house &found)
{
    return search_by_name(root, search, found);
}
int manager::search_by_name(node * root, char * search, house & found)
{
    if(!root)
        return 0;
    int index = 0; 
    node * current = array[index];
    

    int match = strcmp(root->data.description, search);
    if(match == 0) 
    {
       copy_entry(found, root->data);
       return 1;

    }
    else if(match > 0) 
    {
        search_by_name(root->left, search, found);
    }
    else
        search_by_name(root->right, search, found);
    
}



int manager::get_height()
{
    return get_height(root);    
}

int manager::get_height(node * root)
{
   if(!root)
       return 0;
   int left = get_height(root->left);
   int right = get_height(root->right); 
   if(left < right)
       return 1 + right;
   else
       return 1 + left;
}



//BST removal algorithm
int manager::remove()
{
     //empty tree
    if(!root) 
        return 0;
    return remove(root);
}

int manager::remove(node * & root)
{

    //write the algorithm for each removal case
    //in a BST, then call on this fn in each 
    //of the other removal fns
    if(!root)
        return 0;
    //LEAF
    if(root->left == NULL && root->right == NULL)
    {
        delete []root->data.description;
        delete []root->data.hood;
        delete root;
        root = NULL;
    }
    //Internal node w/ 1 child (left)
    else if(root->left && !root->right)
    {
        node * temp = root->left;
        delete []root->data.description;
        delete []root->data.hood;
        delete root;
        root = temp;
    }
    //Internal node w/ 1 child (right)
    else if(root->right && !root->left)
    {
        node * temp = root->right;
        delete []root->data.description;
        delete []root->data.hood;
        delete root;
        root = temp;
    }
    //Internal node w/ 2 children
    //but the right child has no left children
    else if(root->right->left == NULL)
    {
        //if it is null then root->right
        //is the successor
        delete []root->data.description;
        delete []root->data.hood;
        node * hold = root->right;
        delete root;
        root = hold;
    }
    //Internal node w/ 2 children
    //Find the inorder successor
    else if(root->right->left != NULL)
    {
        node * previous = root;
        node * current = root->right;

        while(current->left != NULL)
        {
            previous = current;
            current = current->left;
        }
        //not sure which way is correct access
        //delete []root->data.description;
        delete []root->data.description; 
        delete []root->data.hood;
        copy_entry(root->data, current->data);
        previous->left = current->right;
        delete current;
    }
    return 0;
    
}

int manager::is_efficient()
{
    return is_efficient(root);
}

bool manager::is_efficient(node * root)
{
    if(!root)
        return true;
    if(abs(get_height(root->left) - get_height(root->right)) <= 1)
    {
        return is_efficient(root->left) && is_efficient(root->right);
    }
    else 
        return false;
}

































