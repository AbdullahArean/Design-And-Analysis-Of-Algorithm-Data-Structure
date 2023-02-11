#include <bits/stdc++.h>
using namespace std;
#define DIV ' '
int check_priority(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '/' || ch == '*')
        return 3;
    else if (ch == '-')
        return 2;
    else if (ch == '+')
        return 1;
    else
        return -1;
}

string infToPost(string infix)
{
    stack<char> stack1;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9')
        {
            postfix += ch;
            if (i != infix.length() - 1 && (infix[i + 1] >= '0' && infix[i + 1] <= '9'))
                continue;
            postfix += DIV;
        }
        else if (ch == '(')
            stack1.push('(');
        else if (ch == ')')
        {
            while (stack1.top() != '(')
            {
                postfix += stack1.top();
                postfix += DIV;
                stack1.pop();
            }
            stack1.pop();
        }
        else
        {
            while (!stack1.empty() && check_priority(infix[i]) <= check_priority(stack1.top()))
            {
                postfix += stack1.top();
                postfix += DIV;
                stack1.pop();
            }
            stack1.push(ch);
        }
    }
    while (!stack1.empty())
    {
        postfix += stack1.top();
        postfix += DIV;
        stack1.pop();
    }

    postfix.pop_back();

    return postfix ;
}
void postfixtoeval(string pofx)
{  
    //cout<<pofx<<endl;
    bool flag=0;                       /* Main Program */
  char ch;
  stack<double>s;
  int i=0;
  double op1,op2;
  while( (ch=pofx[i++]) != '\0')
  {
    if(isdigit(ch)) s.push(ch-'0'); /* Push the operand */
    else if(ch==DIV)
      flag=0;
    else
    {        /* Operator,pop two  operands */
      flag=0;        
      op2= s.top(); s.pop();
      op1= s.top(); s.pop();
      switch(ch)
      {
        case '+':s.push(op1+op2);break;
        case '-':s.push(op1-op2);break;
        case '*':s.push(op1*op2);break;
        case '/':s.push(op1/op2);break;
        case '^':s.push(pow(op1,op2)); break;
      }
    }
  }
  printf("%0.4lf\n",s.top());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("inp.txt","r",stdin); freopen("output.txt","w",stdout);

    string infix;
    cin >> infix;
    postfixtoeval( infToPost(infix));

    return 0;
}