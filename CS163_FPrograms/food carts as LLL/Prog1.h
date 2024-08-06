// Cassandra Deatherage
// CS163 Fall Program 1  
// 10/06/19
// Prog1.h / CLASS HEADER/ PROTOTYPE DECLARATIONS 
// The purpose of this program is to design an ADT
// that manages the data collected from a user. 
// The required functions are:
// 1. Add a cart
// 2. Remove a cart
// 3. Display all carts
// 4. Display all carts by type
// 5. Remove a top 3 favorite food 
// 6. Add a top 3 food
// 9. A main menu that populates data & catches
//    - return values for each function call


#include <iostream>
#include <cctype>
#include <cstring>

//to hold all of the data for a food cart
struct cart //object is to_add
{
    int size = 3;

    cart();
    ~cart();
    char * name;
    char * location;
    char * type;
    char * review;
    //array of pointers to arrays that
    //hold a character string of each fav item
    char ** top3;
    //variable for changing the top 3 item

};


//Data structure to add a food item
struct Food //object is: to_replace
{
    Food();
    ~Food();
    char * name;
    char * food;
    int choice;
};

//Data structure to populate multiple carts
struct node
{
    cart data;
    node * next;
};

//To manage the data kept in my list of carts
class cartManager
{
    public:
        cartManager();
        ~cartManager();
        bool displayAll(); 
        int insert(cart & to_add);
        int deleteCart(char * name);
        int displayType(char * type);
        int deleteFood(Food & to_replace);
        int replace_food(Food & to_add);
    private:
        node * head;
        int insert(node * & head, cart & to_add); 
        bool displayAll(node * head);
        int displayType(node * head, char * type);
        int clear(node * head);
        int deleteCart(node * & head, char * name); 


};




    
