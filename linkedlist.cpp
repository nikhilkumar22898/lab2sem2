//include library
#include<iostream>
using namespace std;
//making of linked list
class Node{
	public:
		   //declaring datadata
		   int data;
		   //pointers next and previous
		   Node * next;
		   Node * prev;
		   //const to make values to null
		   Node(){
                  next=NULL;
		  prev=NULL;
		          }
};

class Dlinkedlist{
	             public:
                 Node * head;
	             Dlinkedlist(){
                 head=NULL;
	             }
    void insert(int val){

	             //create  node
	             Node * temp=new Node;
	             temp->data=val;
	             //for empty node and if not applying conditions
	if(head==NULL){
                 head = temp;
                  }
	else{
            Node * current=head;
            while(current->next!=NULL)
			current=current->next;
			current->next=temp;
			temp->prev=current;
	}
}
    //for inserting at specific position
	void insertAt(int val,int pos){
						          Node *current=head;
						          int i=1;
						          while(i<pos-1){
							                     i++;
				                                 current=current->next;
						                         }
						          Node *temp= new Node;
						          temp->data=val;
						          temp->next=current->next;
						          current->next=temp;
						          temp->prev=current;
						          temp->next->prev=temp;
                                  }
        //for excluding at the ends
		void delete1(){

			           Node * current=head;
			           while(current->next->next!=NULL){
				       current=current->next;
			           }
			          Node * tail=current->next;
                      current->next=NULL;
			          delete tail;
		              }
        //for deleting at specific positioin
		void deleteat(int pos){
			                  Node * current=head;
			                  int i=1;
			                  while(i<pos-1){
                                            current=current->next;
                                            i++;
                                            }
                              Node * temp=current->next;
                              current->next=current->next->next;
                              current->next->prev=current;
                              delete temp;
		}

		//to count the items
		void countitems(){
			             Node* current=head;
                         int i=1;
                         while(current->next!=NULL){
				         current=current->next;
				         i++;
                         }
			             cout<<"The number of items are "<<i<<endl;
		                 }
    //for displaying
	void display(){
                  Node *current= head;
		          Node *last;
		          //to print in order
		          while (current!=NULL){
			      cout<<current->data<<"->";
                  // bring last to end of  list using curr
			      last=current;
			      current=current->next;
		          }
		          cout<<"NULL";
                  cout<<endl;
	              // print in reverse order
	              while(last!=NULL){
		          cout<<last->data<<"->";
                  last=last->prev;
	              }
	              cout<<"NULL";
                  cout<<endl;
                  }
};
//declaring main function
int main(){
	Dlinkedlist L1;
	L1.insert(10);
	L1.insert(11);
	L1.insert(12);
	L1.insert(14);
	L1.insert(15);
	L1.insert(16);
	L1.insert(17);
	L1.display();
	L1.insertAt(13,4);
	L1.display();
	L1.delete1();
	L1.display();
	L1.deleteat(5);
	L1.display();
	L1.countitems();
	//closing the function
	return 0;
}
