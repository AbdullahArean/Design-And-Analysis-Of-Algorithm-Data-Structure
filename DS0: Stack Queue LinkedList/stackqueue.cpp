#include <iostream>
#include <cmath> //Used For Power Function to evaluate Postfix
using namespace std;

class Noded
{
public:
	double data;
	Noded *next;
	Noded()
	{
		data = 0;
		next = NULL;
	}
	Noded(double data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class Linkedlistd
{
private:
	Noded *head;
	int Listlen;

public:
	Linkedlistd()
	{
		head = NULL;
		Listlen = 0;
	}
	int Length()
	{
		return this->Listlen;
	}
	void InsertNode(double data, int position)
	{
		
			Noded *newNode = new Noded(data);
			if (head == NULL)
			{
				newNode->next = NULL;
				head = newNode;
			}
			else if (position == 0)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				Noded *temp = head;
				for (int i = 0; i < position - 1; i++)
				{
					temp = temp->next;
					if (temp == NULL)
					{
						printf("\ncan't insert as position is out of range\n");
						return;
					}
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
			Listlen++;
		
	}
	void PrintList()
	{
		Noded *temp = head;
		if (head == NULL)
		{
			cout << "List empty" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void DeleteNode(int position)
	{
		Noded *temp1 = head, *temp2 = NULL;
		if (this->Listlen == 0)
		{
			cout << "List empty!" << endl;
			return;
		}
		if (this->Listlen <= position)
		{
			cout << "Index out of range!"
				 << endl;
			return;
		}
		if (position == 0)
		{
			head = head->next;
			delete temp1;
			return;
		}
		while (position-- > 0)
		{

			temp2 = temp1;
			temp1 = temp1->next;
		}

		temp2->next = temp1->next;

		delete temp1;
		this->Listlen--;
		return;
	}
	Noded *Returnhead() { return head; }
};
class Stackd
{
private:
	Linkedlistd stacklist;

public:
	Stackd()
	{
		Linkedlistd stacklist = Linkedlistd();
	}
	void Push(double num)
	{
		stacklist.InsertNode(num, 0);
	}
	double Pop()
	{
		double firstelement = stacklist.Returnhead()->data;
		stacklist.DeleteNode(0);
		return firstelement;
	}
	double Top()
	{
		if (IsEmpty())
		{
			printf("Stack Is Empty!\n");
			return 0;
		}
		return stacklist.Returnhead()->data;
	}
	bool IsEmpty()
	{
		if (stacklist.Returnhead() == NULL)
			return 1;
		return 0;
	}
	void Print()
	{
		stacklist.PrintList();
	}
};
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class Linkedlist
{
private:
	Node *head;
	int Listlen;

public:
	Linkedlist()
	{
		head = NULL;
		Listlen = 0;
	}
	int Length()
	{
		return this->Listlen;
	}
	void InsertNode(int data, int position)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			newNode->next = NULL;
			head = newNode;
		}
		else if (position == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			Node *temp = head;
			for (int i = 0; i < position - 1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
				{
					printf("\ncan't insert as position is out of range\n");
					return;
				}
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		Listlen++;
	}
	void PrintList()
	{
		Node *temp = head;
		if (head == NULL)
		{
			cout << "List empty" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
	void DeleteNode(int position)
	{
		Node *temp1 = head, *temp2 = NULL;
		if (this->Listlen == 0)
		{
			cout << "List empty!" << endl;
			return;
		}
		if (this->Listlen <= position)
		{
			cout << "Index out of range!"
				 << endl;
			return;
		}
		if (position == 0)
		{
			head = head->next;
			delete temp1;
			return;
		}
		while (position-- > 0)
		{

			temp2 = temp1;
			temp1 = temp1->next;
		}

		temp2->next = temp1->next;

		delete temp1;
		this->Listlen--;
		return;
	}
	Node *Returnhead() { return head; }
};
class Stack
{
private:
	Linkedlist stacklist;
	int len;

public:
	Stack()
	{
		Linkedlist stacklist = Linkedlist();
		len = 0;
	}
	void Push(char num)
	{
		stacklist.InsertNode(num, 0);
		len++;
	}
	char Pop()
	{
		char firstelement = stacklist.Returnhead()->data;
		stacklist.DeleteNode(0);
		len--;
		return firstelement;
	}
	char Top()
	{
		if (IsEmpty())
		{
			printf("Stack Is Empty!\n");
			return 0;
		}
		return stacklist.Returnhead()->data;
	}
	bool IsEmpty()
	{
		if (stacklist.Returnhead() == NULL)
			return 1;
		return 0;
	}
	void Print()
	{
		stacklist.PrintList();
	}
	int Length()
	{
		return len;
	}
};
class Queue
{
private:
	Linkedlist queuelist;

public:
	Queue()
	{
		Linkedlist queuelist = Linkedlist();
	}
	void Enqueue(int num)
	{
		int len = queuelist.Length();
		queuelist.InsertNode(num, len);
	}
	int Dequeue()
	{
		int firstelement = queuelist.Returnhead()->data;
		queuelist.DeleteNode(0);
		return firstelement;
	}
	int Front()
	{
		if (IsEmpty())
		{
			printf("Stack Is Empty!\n");
			return 0;
		}
		return queuelist.Returnhead()->data;
	}
	bool IsEmpty()
	{
		if (queuelist.Returnhead() == NULL)
			return 1;
		return 0;
	}
	void Print()
	{
		queuelist.PrintList();
	}
};
void reverse(string &str)
{
	int n = str.length();

	// Swap character startin g from two
	// corners
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}
int getPriority(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
string infixToPostfix(string s)
{

	Stack st;
	string res;

	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			res += ch;
		else if (ch == '(')
			st.Push('(');
		else if (ch == ')')
		{
			while (st.Top() != '(')
			{
				res += st.Top();
				st.Pop();
			}
			st.Pop();
		}
		else if (ch == '{')
			st.Push('{');
		else if (ch == '}')
		{
			while (st.Top() != '{')
			{
				res += st.Top();
				st.Pop();
			}
			st.Pop();
		}
		else if (ch == '[')
			st.Push('[');
		else if (ch == ']')
		{
			while (st.Top() != '[')
			{
				res += st.Top();
				st.Pop();
			}
			st.Pop();
		}
		else
		{
			while (!st.IsEmpty() && (getPriority(s[i]) <= getPriority(st.Top())))
			{
				res += st.Top();
				st.Pop();
			}
			st.Push(ch);
		}
	}
	while (!st.IsEmpty())
	{
		res += st.Top();
		st.Pop();
	}

	return res;
}
string infixToPrefix(string infix)
{
	int l = infix.size();
	reverse(infix);
	for (int i = 0; i < l; i++)
	{

		if (infix[i] == '(')
		{
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')')
		{
			infix[i] = '(';
			i++;
		}
	}
	string prefix = infixToPostfix(infix);
	reverse(prefix);
	return prefix;
}
float scanNum(char ch)
{
	int value;
	value = ch;
	return float(value - '0');
}
int isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1;
	return -1;
}
int isOperand(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;
	return -1;
}
double operation(double a, double b, char op)
{

	if (op == '+')
		return b + a;
	else if (op == '-')
		return b - a;
	else if (op == '*')
		return b * a;
	else if (op == '/')
		return b / a;
	else if (op == '^')
		;
	return pow(b, a);
	return -1;
}
double postfixEval(string postfix)
{
	double a, b;
	Stackd stk;
	string::iterator it;

	for (it = postfix.begin(); it != postfix.end(); it++)
	{
		if (isOperator(*it) != -1)
		{
			a = stk.Top();
			stk.Pop();
			b = stk.Top();
			stk.Pop();
			stk.Push(operation(a, b, *it));
		}
		else if (isOperand(*it) > 0)
		{
			stk.Push(scanNum(*it));
		}
	}
	return stk.Top();
}
bool isparanthesesok(string arr)
{
	Stack Container;
	int i = 0;
	while (arr[i] != '\n' && arr[i] != '\0')
	{

		if (arr[i] == ']' && Container.Top() == '[')
			Container.Pop();
		else if (arr[i] == '}' && Container.Top() == '{')
			Container.Pop();
		else if (arr[i] == ')' && Container.Top() == '(')
			Container.Pop();
		else if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
			Container.Push(arr[i]);

		i++;
	}
	if (Container.IsEmpty())
		return true;
	else
		return false;
}
int maxdepth(string arr)
{
	int maxdept = 0, i = 0;
	Stack Container;

	while (arr[i] != '\n' && arr[i] != '\0')
	{

		if (arr[i] == ']' && Container.Top() == '[')
		{
			if (Container.Length() > maxdept)
				maxdept = Container.Length();

			Container.Pop();
		}
		else if (arr[i] == '}' && Container.Top() == '{')
		{
			if (Container.Length() > maxdept)
				maxdept = Container.Length();

			Container.Pop();
		}
		else if (arr[i] == ')' && Container.Top() == '(')
		{
			if (Container.Length() > maxdept)
				maxdept = Container.Length();
			Container.Pop();
		}
		else if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
			Container.Push(arr[i]);

		i++;
	}

	return maxdept;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string UserInput;
	cin >> UserInput;
	cout << infixToPostfix(UserInput) << endl;
	cout << postfixEval(infixToPostfix(UserInput)) << endl;
	//cout<<isparanthesesok(UserInput)<<endl;
	//cout<<maxdepth(UserInput)<<endl;
	return 0;
}
