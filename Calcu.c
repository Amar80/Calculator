#include<stdio.h>
#include<math.h>
#define SIZE 50

int calculator();
double evaluate (char []);
char Isdigit(char);
int pre(char);
double cal(char , double , double );






int calculator()
{
    char expression[SIZE];
    double result;

    printf("\n\t\t********** ENTER THE VALUE **********\n\n\t\t\t\t "); 
    scanf(" %[^\n]", expression);
    
    result = evaluate(expression);
    
    if ((result==0)||(result))
            printf("\n\t\t\tTotal  :  %.1lf\n", result);
                          
}


double evaluate(char expr[])
{
    double numbers[SIZE]; 
    int num_arr = 0;
    char operators[SIZE]; 
    int op_arr = 0;
    char numbuf[SIZE]; 
    int nbi = 0;
    char ch; 
    int  i = 0;

    while ((ch = expr[i]) != 0)
     {
        if (Isdigit(ch)) 
        {
            numbuf[nbi++] = ch;
            if (!Isdigit(expr[i+1])) 
            {
                numbuf[nbi]=0; 
                nbi=0;
                sscanf(numbuf,"%lf",&numbers[num_arr++]); 
            }
        }
        else
        {
           
            operators[op_arr++]=ch;          
        }
        i++;
    }
    
    while (op_arr > 0)
    {
        numbers[num_arr-2]=cal(operators[op_arr-1],numbers[num_arr-2],numbers[num_arr-1]);
        op_arr--; 
        num_arr--;
    }
    return numbers[0];
}

char Isdigit(char ch) 
{
            return ch= (ch >= '0' && ch <= '9') ? 1 :  0;
}

int pre(char op)
{
   
    switch (op) 
    {
             case '+':
             case '-':
                 return 0;
        
             case '*':
             case '/':
                 return 1;
       
    }
    
}

double cal(char Operator, double left_operand, double right_operand) 
{
    
    switch (Operator)
    {
             case '*':
                          return left_operand * right_operand;
        
             case '/':
                          return left_operand / right_operand;
        
             case '+':
                          return left_operand + right_operand;
        
             case '-':
                          return left_operand - right_operand;
        
            default:
             {
                           printf("\n\t\t\t ________________");
                           printf("\n\t\t\t| WRONG OPERATOR |\n");
                          
             }
             
      }
    
}


int main()
{   
     char ch;
     
    do
    {        
            calculator();
            printf("\n\t\t\t ________________");
            printf("\n\t\t\t|CONTINUE : Y\\N ?|\n\t\t\t\t");
            
            scanf(" %c",&ch);
         
     }while(ch=='Y'||ch=='y');
     
    return 0;
}


