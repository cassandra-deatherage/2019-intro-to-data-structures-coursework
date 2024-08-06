// Prog 2.h file 

using namespace std;
#include <fstream>
#include <cstring>
#include <iostream>
//Struct & Class declarations, function prototypes

//A container for the trivia questions
//and a ptr to the next question in the queue
//A container to hold the CLL of questions
//holds the members for the queue ADT
struct q_node
{
    //this holds one q & a 
    q_node(char * q, char * a);
    q_node(q_node & q_obj);//to pass the data from the first constructor
    ~q_node();
    char * question = NULL;
    char * answer = NULL;
    q_node * next = NULL;
};

class queue
{ 
    public:
        queue();
        ~queue();
        int enqueue(char * question, char * answer);
        int dequeue();
        int display_question(); 
        int display_all_wrap();
        int display_all(q_node * current);        
        int set_q_node(queue & q_obj);  
        //int copy(char * question, char * answer);
    private: 
        //the qa is the node that points to the first question! 
        q_node * rear;

};

struct s_node
{
    s_node();
    ~s_node();
    s_node * next; 
    queue ** array;
    int top_index = 0;
    int MAX = 0;
};

//holds the members for the stack ADT
class stack
{
    public:
        stack();
        ~stack();
        int read_in();
        int push(queue & myqueue);
        int dequeue_wrap(); 
        int peek();
        int display_all();
        int pop();
        
    private:
        //this is the pointer to the LLL holding my dynamic array
        s_node * head; 
};





