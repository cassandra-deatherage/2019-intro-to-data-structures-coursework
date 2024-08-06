//Prog2i.cpp (implementation)
//This file holds all of the function 
//definitions for program 2

#include "Prog2.h"
//This is the class that holds all of the FN's for 
//the queue. In this program the queue is a CLL, 
//with each node housing a question & an answer
//I have designed each queue to hold a maximum of //3 questions/answers to simplify the testing process 
queue::queue() 
{

    rear = NULL;

}


queue::~queue()
{
    while(dequeue() != 0)
    {
        //keeps calling dequeue until dequeue
        //returns a 1.
    }
}


//There are two constructor for the q-node
//One takes in the data from the txt file & allocates
//memory for them:
q_node::q_node(char * q_temp, char * a_temp)
{
    next = NULL;
    //allocate space for a q & a
    question = new char[strlen(q_temp)+1];
    strcpy(question, q_temp);
    //copy the data in from the txt file
    answer = new char [strlen(a_temp)+1];
    strcpy(answer, a_temp);
}


//This one takes an obj of my q_node to access the 
//memory that was just created and store it into 
//the new q_node structure 
q_node::q_node(q_node & q_obj)
{ 
    next = NULL;
    //allocate space for a q & a
    question = new char[strlen(q_obj.question)+1];
    strcpy(question, q_obj.question);
    //copy the data in from the txt file
    answer = new char [strlen(q_obj.answer)+1];
    strcpy(answer, q_obj.answer);
}



q_node::~q_node()
{
    if(question) 
        delete []question;
    if(answer)
        delete []answer;
}



s_node::s_node()
{
    top_index = 0;
    MAX = 3;//three index per array per s_node.. 
    //go through each index & set ptr to NULL
    array = new queue*[MAX];
    for(int i = 0; i < MAX; ++i)
    {
        array[i] = NULL;
    }
    next = NULL;
}


s_node::~s_node()
{
    if(array == NULL)
        return;
    for(int i = 0; i < MAX; ++i)
    {
        delete array[i];
        array[i] = NULL;
    }
    delete[] array;
}


stack::stack()
{
    head = NULL;
}


stack::~stack()
{
    if(!head) return;

    while(pop() != 0) 
    {
        //keeps calling pop until 
        //pop returns a 1
    }
}


int stack::read_in()
{
    queue * myqueue = new queue;
    int count = 0; 
    char question [200];
    char answer [200];
    ifstream read;
    read.open("prog2.txt");
    if(read)
    {
        read.get(question, 200, ',');
        read.ignore(200, ',');
        while(!read.eof())
        {
            read.get(answer, 200, '\n');
            read.ignore(200, '\n');
            //testing..
            //cout<< question <<endl;
            //cout<< answer <<endl;
            myqueue->enqueue(question, answer);
            ++count;
            if(count == 3)//3 Q's & A's
            {
                cout<<"display the queue : "<<endl;
                myqueue->display_all_wrap();
                //take the queue obj & push 
                push(*myqueue);
                count = 0;
                myqueue = new queue;
            }
            //realized after testing that
            //this would only read in 60% of the file
            //myqueue->enqueue(question, answer);
            //++count;
            read.get(question, 200, ',');
            read.ignore(200, ',');
        }
        read.close();
    }
    //testing the read in fn:
    cout<<"display the stack" <<endl;
    display_all();
}


//Queue Class - ENQUEUE FN
int queue::enqueue(char * question, char * answer)
{
    q_node * temp = new q_node(question, answer);
    if(!rear)// no list, create a new list 
    {
        rear = temp;
        rear->next = rear;
        return 1;
    }
    temp->next = rear->next;//otherwise add a new node
    rear->next = temp;
    rear = temp;
    return 1;
}


//the dequeue fn has to be called by the
//stack class in order to have 
//access to the data at the top
//index

//Queue Class - DEQUEUE FN
int queue::dequeue()
{
        //remove a question from the queue
        if(!rear) return 0;
        if(rear == rear->next)//if there is only one node 
        {
            delete rear;
            rear = NULL;
            return 1;
        }
        //otherwise hold onto the list & delete
        q_node * temp = rear->next;
        rear->next = temp->next; 
        delete temp;
        temp = NULL;
        return 1;
}


int stack::dequeue_wrap()
{
    if(head->array[0])//if the array exists
        head->array[0]->dequeue(); 
}


//Queue Class - DISPLAY ALL FN WRAPPER
int queue::display_all_wrap()
{
    if(!rear) return 0;
    display_all(rear->next);
}


//Queue Class - DISPLAY ALL FN RECURSIVE
int queue::display_all(q_node * current)
{
    if(current == rear)
    {
        cout<< current->question <<endl;
        cout<< current->answer <<endl; 
        return 1; 
    }
    cout<< current->question <<endl;
    cout<< current->answer <<endl; 
    display_all(current->next);
    return 0;
}


//Stack Class - PUSH FN
int stack::push(queue & myqueue)
{
    if(!head)//create a new list
    { 
        head = new s_node();
        head->array[head->top_index] = &myqueue;
        ++head->top_index;
        cout<<head->top_index<<endl;
        head->next = NULL;
        return 1;
    }
    if(head->top_index < head->MAX)//if array isn't full
    {
        head->array[head->top_index] = &myqueue;
        ++head->top_index;
        cout<<head->top_index<<endl;
        return 1;
    }
    if(head->top_index == head->MAX)//if array is full
    {
        //this is diff from lab
        //via s_node in my
        //program resets 
        //top_index to 0
        //head->top_index = 0;
        s_node * temp = new s_node();//new node
        temp->array[head->top_index] = &myqueue;
        ++head->top_index;
        cout<<head->top_index<<endl;
        temp->next = head;
        head = temp; 
        return 1;
    }
    
}


int stack::display_all()
{
    if(!head) return 0;
    s_node * current = head;
    while(current)
    {
        for(int i = 0; i < current->MAX; ++i)
        {
            if(current->array[i])
                current->array[i]->display_all_wrap();
        }
        current = current->next;
    }
    return 1;
}


//This function has to be called
//by the stack class in order to 
//have access to the data at top

//fn to display a question to a user // peek!
int queue::display_question()
{
    if(!rear) return 0;
    if(rear->next)
    {
        //display the question!
        cout<<'\n'<<endl;
        cout<<"The first question in the queue is : "<<endl; 
        cout<<'\n'<<endl;
        cout<<'\t'<<rear->next->question <<endl;
        cout<<'\n'<<endl;
        cout<<"The first answer in the queue is : "<<endl;
        cout<<'\n'<<endl;
        cout<<'\t'<<rear->next->answer<<endl;
        cout<<'\n'<<endl;
        return 1; 
    }
}


//PEEK 
//to the user (top of stack/ & first question in queue)
int stack::peek()
{
    if(!head) return 0;
    if(head->array[0])//if the array exists
    //access the top index and call queue disp. fn
        head->array[0]->display_question(); 
}


//POP
//I got confused about how to implement pop in this
//program, because in lab we used pop simply to
//get rid of a node after it's array was empty, 
//but in this game it didn't make sense to pop after 
//one index because there were still cards left to 
//play.. in the rest of the index's
//In the game instructions it says
//to pop a card and push it onto a users correct stack,
//or the discard stack.. but logically that would mean
//that the only way to do so would be to have one index
//in each array holding a queue of 3 cards, which 
//kind of defeats the purpose of having instant access
//to an array.. so after multiple conversations and 
//attempts at implementing this correctly I wasn't able
//to make it function the way I was hoping in the 
//time allotted. I didn't develop my concept of how
//this data structure was supposed to function 
//well enough before starting implementation, & even 
//when I tried to get help from tutors for debugging, 
//we didn't have enough time to complete the
//the debugging process so I just tried to implement
//this the best I could based on the guidance I
//received. 


//pop is used to remove an entire s_node, and it's
//attached array of queue's, after the last item in the CLL has been removed.
int stack::pop()
{
    if(!head) return 0;//if the list is empty
    cout<<" top index is: "<<endl; 
    cout<<head->top_index<<endl;
    //decrement top_index
    --head->top_index;
    cout<<head->top_index<<endl;
    //delete the queue 
    delete []head->array[head->top_index];
    
    //hold onto the list and delete the first node 
    s_node * temp = head->next;
    delete head;
    head = temp;
    return 1;
}


