#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	node * next;
};

void Push(node *& head , int data)
{
	node * newOne = new node;
	newOne -> data = data;
	newOne -> next = head;
	head = newOne;

}

bool IsEmpty(node * head)
{
	return (head == NULL);
}

void BuildList(node *& head)
{
	Push(head,1);
	Push(head,2);
	Push(head,3);
}

void PrintList(node * head)
{
	if(head == NULL)
	{
		perror("the List is empty...\n");
		return;
	}
	node * temp = head;
	node * next;
	while(temp!=NULL)
	{
		next = temp->next;
		cout<<temp->data;
		temp = next;
		cout<<"\n";	
	}
}

int Length(node * head)
{
	int count = 0;
	node * temp = head;
	if(head == NULL) return 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count ;
}

void DeleteList(node *&head)
{
	if(head == NULL)
	{
		perror("Deleting from am empty list\n");
	}
	else 
	{
		node * cur = head;
		node * temp ;
		while(cur != NULL)
		{
			temp = cur->next;
			delete cur;
			cur = temp;
		}
		head = NULL;
	}
}

int Pop(node *& head)
{
	if(!IsEmpty(head))
	{
		node * temp = head;
		int data = temp->data;
		head = head->next;
		data = temp->data;
		delete temp;
		return data;
	}
	else perror("the List is empty.. ");
}

void InsertNth(node *& head,int index,int value)
{
	if (index == 0 )
		Push(head,value);
	else
	{
		int count = 1 ;
		node *temp = head;
		while(count!=index)
		{
			temp = temp->next;
			count ++;
		}
		Push(temp->next, value);
	}
}

void SortedInsert(node *& head,int value)
{
	node * temp = head;
	while (temp != NULL && temp -> data <value)
	{
		temp = temp->next;
	}
	if(temp == head)
	{
		Push(head,value);
	}
	else{
		node * prev = head;
		while(prev->next != temp)prev = prev->next;
		Push(prev->next,value);
	} 
}

void Append(node *& head1,node *& head2)
{
	node *temp = head1;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = head2;
	head2 = NULL;
}

void InsertSort(node *& head)
{
	node * temp = head;
	node * current = temp->next;
	node * result = NULL;
	Push(result ,temp->data);
	node * next = NULL;
	while(current)
	{
		next = current->next;
		SortedInsert(result,current->data);
		current = next;
	}
	DeleteList(temp);
	head =result;
}

void MoveNode(node *& head1, node *& head2)
{
	Push(head1 , Pop(head2));
}
	
node * FrontBackSplit(node *&head)
{
	node * slow = head;
	node * fast = head;
	while(fast->next !=NULL && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	node * newHead = slow->next;
	slow->next = NULL;
	return newHead;
}

node * AlternatingSplit(node *&head)
{
	node * odd = head;
	node * even = odd->next;
	node * newHead = even;
	while(odd->next && even ->next)
	{
		odd->next = even->next;
		even->next = odd->next->next;
		odd = odd->next;
		even = even->next;
	}
	odd->next = NULL;
	return newHead;
}
//void FrontBackSplit(
void Reverse(node *& head)
{
	node * first = head;
	if (head == NULL) return;
	node * rest = first->next;
	if (rest == NULL) return;
	Reverse(rest);
	cout<<first->data<<"\t"<<rest->data<<endl;
	first->next->next = first;
	first ->next = NULL;
	head = rest;
}

node * SortedMerge(node *head1, node * head2)
{
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	node * result = NULL;
	node * temp1 = head1;
	node * temp2 = head2;
	if(temp1->data < temp2->data)
	{
  	Push(result,temp1->data);
		temp1 = temp1->next;
 }
	else{
  	Push(result,temp2->data);
		temp2 = temp2->next;
 }
	node * tail = result;
	while(temp1 && temp2)
	{
   	if(temp1->data < temp2->data)
		{
		Push(tail->next,temp1->data);
		temp1 = temp1->next;
		tail = tail->next;	
	}
		else{
    Push(tail->next,temp2->data);
		temp2 = temp2->next;
		tail = tail->next;
  }
 }
	while(temp1){
		Push(tail->next,temp1->data);
		temp1 = temp1->next;
		tail = tail->next;
	}
	while(temp2){
		Push(tail->next,temp2->data);
		temp2 = temp2->next;
		tail = tail->next;
	}
	return result;
}

void MergeSort(node *&head)
{
	if(head->next == NULL)return;
	node * newHead = FrontBackSplit(head);
	MergeSort(newHead);
	MergeSort(head);
	head = SortedMerge(head,newHead);
}	

node * SortedIntersect(node * head1,node *head2)
{
	node * temp1 = head1;
	node * temp2 = head2;
	node * result = NULL;
	while(temp1)
	{
		if(temp1 == NULL || temp2 == NULL)break;
		if(temp1->data == temp2->data){
			Push(result,temp1->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if(temp1->data < temp2->data)
		{
			temp1= temp1->next;
		}
		else (temp2 = temp2->next);
	}
	return result;
}
		
int main()
{
	node * head = NULL,*head1 = NULL;
	InsertNth(head,0,1);
	InsertNth(head,1,5);
	SortedInsert(head,3);
	SortedInsert(head,-1);
	SortedInsert(head,2);
	SortedInsert(head,9);
	SortedInsert(head,8);
	//BuildList(head1);
	SortedInsert(head,6);
	InsertSort(head);
	//Pop(head);
	//PrintList(head);
	//cout<<endl;	
	//PrintList(head);	
	//cout<<endl;
	//PrintList(newHead);
	//cout<<endl;
	//Append(head,newHead);
	//Reverse(head);	
	SortedInsert(head,4);
	//PrintList(head);
	//cout<<endl;
	node * newHead = AlternatingSplit(head);
	//Pop(newHead);
	//Pop(newHead);
	//DeleteList(newHead);
	//PrintList(head);
	//cout<<endl;
	//PrintList(newHead);
	//cout<<endl;
	//Reverse(newHead);
	//Append(head,newHead);
	//PrintList(head);
	//cout<<endl;
	//node * result = SortedMerge(newHead,head);
	//PrintList(result);
	//MergeSort(head);i
	SortedInsert(newHead,-1);
	SortedInsert(newHead,2);
	//PrintList(head);
	//cout<<endl;
	//PrintList(newHead);
	Reverse(newHead);
	cout<<endl;
	PrintList(newHead);
	cout<<endl;
	MergeSort(newHead);
	PrintList(newHead);
	return 0;

}
