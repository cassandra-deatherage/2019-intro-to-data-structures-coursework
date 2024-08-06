//Prog2m.cpp (main function) 
//This file takes data from the client application and sends out messages to the user via return values from ADT functions
 
// This program is a trivia game played between two players
// The concept is that they are playing with a deck of cards
// Each card has three questions
// The first user will get a chance to answer one of the questions right
// If they get the first question wrong the next question in the queue
//      will come up, & so on until there are no more questions. 
//      if they fail 3 times the card will be pushed onto the discard stack
// If they get any of the questions on the card correct, then the card will
//      be pushed onto their correct stack
// The players take turns, one card each at a time, until the initial
//      stack of cards is empty. 
// At the end of the game the winner will be calculated based on the number
//      of correct cards in each users stack. 
// After which the users can decide if they would like to play again

#include "Prog2.h"


// In order to test the enqueue & push functions please
// change the txt file. I implemented them during the 
// read in because at the start of developing the 
// game interface that made the most sense to me

//main function to gather & return data from/to client
main()
{
    cout<<'\n'<<endl;
    cout<<'\t'<<"The way that this program is designed"<<" is that the enqueue and push take place during the read in function "<<'\n'<<'\t'<<"In order to test the enqueue and push FN's, "<<"please change the data in the txt file. "<<endl;
    cout<<'\n'<<endl;
    queue myqueue;//create an object to access the queue
    stack mystack;//create an object to access the stack
    mystack.read_in(); 
    int choice = 0; 
    do
    {
        cout<<"What would you like to do?:"
            <<"\n enter 1 to - display the stack "<<endl
            <<"\n enter 2 to - dequeue " <<endl
            <<"\n enter 3 to - peek" <<endl
            <<"\n enter 4 to - pop" <<endl
            <<"\n enter 5 to - Quit "<<endl;

        cin>>choice;
        cin.ignore(100, '\n'); 
        //--------------------------------------------------        
        if(1 == choice)//display
        {
            cout<<"This is the contents of the queue inside of the stack :) " <<endl;
            mystack.display_all(); 
        }

        if(2 == choice)//dequeue
        {
            mystack.dequeue_wrap();
        }
        
        if(3 == choice)//peek
        {
            mystack.peek();
        }

        if(4 == choice)//pop
        {
            mystack.pop();
        }

    } 
    while(choice != 5);

return 0;
}
