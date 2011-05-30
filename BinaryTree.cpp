#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
};

void PrintArray(vector<int> array)
{
	int sizeArray = array.size();
	for(int i = 0;i<sizeArray;i++)
	{
		cout<<array[i] << "\t";
	}
	cout << endl;
}

void swap(node *& data1 ,node *& data2)
{
	node* temp;
	temp = data1;
	data1 = data2;
	data2 = temp;
}

node * NewNode(int data)
{
	node * newNode = new node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void Insert(node *& root , int data)
{
	if(root == NULL)
	{
		root = NewNode(data);
		return;
	}
	
	else
	{
		if(data < root->data) 
		{
			Insert(root->left,data);
		}
		else if(data > root->data)
		{
			Insert(root->right,data);
		}
	}
}

node * Build123()
{
	node * root = NewNode(4);
	Insert(root,1);
	Insert(root,3);
	Insert(root,0);
	Insert(root,6);
	Insert(root,5);
	Insert(root,7);
	Insert(root,10);
	return root;
}

int size(node * root)
{
	if (root == NULL) return 0;
	static int count = 0;
	if (root!=NULL)
		{
			size(root->right);
			count ++;
			size(root->left);
		}
	return count;
}

int MaxDepth(node * root)
{
	if(root == NULL) return 0;
	if (size(root->left)>size(root->right))
		return (1+MaxDepth(root->left));
	else return (1+MaxDepth(root->right));
}
	 
void Inorder(node *& root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		cout << root->data <<endl;
		Inorder(root->right);
	}
}

int HasPathSum(node * root, int sum)
{
	if(root == NULL)
		return(sum == 0);
	else
	{
		int subSum = sum - (root->data);
		return (HasPathSum(root->left,subSum)||HasPathSum(root->left,subSum));
	}
}

void PrintPaths(node * root ,vector<int> Path)
{
	if(root == NULL){
		PrintArray(Path); 
		return;
	}
	Path.push_back(root->data);
	//if(root->left == NULL && root->right == NULL) PrintArray(Path);
	
		PrintPaths(root->left,Path);
		PrintPaths(root->right,Path);	
}

void Mirror(node *& root)
{
	if(root == NULL) return;
	else
	{
		Mirror(root->left);
		Mirror(root->right);
		swap(root->left,root->right);
		return;
	}
}

void DoubleTree(node *& root)
{
	if(root == NULL)return;
	else{
		node * temp = NewNode(root->data);
		temp ->left = root->left;
		root ->left = temp;
		DoubleTree(temp->left);
		DoubleTree(root->right);
	}
}

bool SameTree(node *root1, node *root2)
{
	if(root1==NULL && root2 ==NULL) return true;
	else{
		if(root1->data == root2->data)
		{
			return(SameTree(root1->left,root2->left)&&SameTree(root1->right,root2->right));
		}
	}
	return false;
}

void ZigZag(node * root)
{
	bool leftToRight = false;
	stack<node *> * currentLevel = new stack<node *>;
	stack<node *> * nextLevel = new stack<node *>;
	currentLevel -> push(root);
	while(!(currentLevel -> empty()))
	{
		node * temp = (node *)currentLevel -> top();
		currentLevel -> pop();
		if(leftToRight)
		{
			nextLevel -> push(temp->right);
			nextLevel -> push(temp->left);
		}
		else{
			nextLevel -> push(temp->left);
			nextLevel -> push(temp->right);
		}
		cout << temp -> data;	
		if(currentLevel -> empty())
		{
			leftToRight = !leftToRight;
			stack<node *> * tempStack = currentLevel;
			currentLevel = nextLevel;
			nextLevel = tempStack;
		}
	}
}	
				
int main()
{
	node * root = Build123();
	cout << "the count is "<< size(root)<<endl;
	Inorder(root);
	cout << "Max Depth is " << MaxDepth(root)<<endl;
	node * root1 = Build123();
	//Mirror(root);
	//cout<<SameTree(root1,root);
	ZigZag(root1);
	cout<<endl;
	return 0;
}	
