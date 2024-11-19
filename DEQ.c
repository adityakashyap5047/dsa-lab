#include<stdio.h> 
#include<conio.h> 
#define SIZE 20 
typedef struct dq_t 
{ 
int front,rear; 
int item[SIZE]; 
}deque; 
/********** Function Declaration begins **********/ 
void create(deque *); 
void display(deque *); 
void insert_rear(deque *, int); 
void insert_front(deque *, int); 
int delete_front(deque *, int); 
int delete_rear(deque *, int); 
/********** Function Declaration ends **********/ 
void main() 
{ 
int x,data,ch; 
deque DQ; 
clrscr(); 
create(&DQ); 
printf("\n\t\t Program shows working of double ended queue"); 
do 
{ 
printf("\n\t\t Menu"); 
printf("\n\t\t 1: insert at rear end"); 
printf("\n\t\t 2: insert at front end"); 
printf("\n\t\t 3: delete from front end"); 
printf("\n\t\t 4: delete from rear end"); 
printf("\n\t\t 5: exit. "); 
printf("\n\t\t Enter choice : "); 
scanf("%d",&ch); 
switch(ch) 
{ 
case 1: 
if (DQ.rear >= SIZE) 
{ 
printf("\n Deque is full at rear end"); 
continue; 
} 
else 
{ 
printf("\n Enter element to be added at rear end : "); 
scanf("%d",&data); 
insert_rear(&DQ,data); 
printf("\n Elements in a deque are : "); 
display(&DQ); 
continue; 
} 
case 2: 
if (DQ.front <=0) 
{ 
printf("\n Deque is full at front end"); 
continue; 
} 
else 
{ 
printf("\n Enter element to be added at front end : "); 
scanf("%d",&data); 
insert_front(&DQ,data); 
printf("\n Elements in a deque are : "); 
display(&DQ); 
continue; 
} 
case 3: 
x = delete_front(&DQ,data); 
if (DQ.front==0) 
{ 
continue; 
} 
else 
{ 
printf("\n Elements in a deque are : "); 
display(&DQ); 
continue; 
} 
case 4: 
x = delete_rear(&DQ,data); 
if (DQ.rear==0) 
{ 
continue; 
} 
else 
{ 
printf("\n Elements in a deque are : "); 
display(&DQ); 
continue; 
} 
case 5: printf("\n finish"); return; 
} 
}while(ch!=5); 
getch(); 
} 
/********** Creating an empty double ended queue **********/ 
/********** Function Definition begins **********/ 
void create(deque *DQ) 
{ 
DQ->front=0; 
DQ->rear =0; 
} 
/********** Function Definition ends **********/ 
/********** Inserting element at rear end **********/ 
/********** Function Definition begins **********/ 
void insert_rear(deque *DQ, int data) 
{ 
if ((DQ->front == 0) &&(DQ->rear == 0)) 
{ 
DQ->item[DQ->rear] = data; 
DQ->rear = DQ->rear +1; 
} 
else 
{ 
DQ->item[DQ->rear] = data; 
DQ->rear = DQ->rear +1; 
} 
} 
/********** Function Definition ends **********/ 
/********** Deleting element from front end **********/ 
/********** Function Definition begins **********/ 
int delete_front(deque *DQ, int data) 
{ 
if ((DQ->front == 0) && (DQ->rear == 0)) 
{ 
printf("\n Underflow"); 
return(0); 
} 
else 
{ 
data = DQ->item[DQ->front]; 
printf("\n Element %d is deleted from front :",data); 
DQ->front = DQ->front +1; 
} 
if (DQ->front==DQ->rear) 
{ 
DQ->front =0; 
DQ->rear = 0; 
printf("\n Deque is empty (front end)"); 
} 
return data; 
} 
/********** Function Definition ends **********/ 
/********** Inserting element at front end **********/ 
/********** Function Definition begins **********/ 
void insert_front(deque *DQ, int data) 
{ 
if(DQ->front > 0) 
{ 
DQ->front = DQ->front-1; 
DQ->item[DQ->front] = data; 
} 
} 
/********** Function Definition ends **********/ 
/********** Deleting element from rear end **********/ 
/********** Function Definition begins **********/ 
int delete_rear(deque *DQ, int data) 
{ 
if (DQ->rear == 0) 
{ 
printf("\n Underflow"); 
return(0); 
} 
else 
{ 
DQ->rear = DQ->rear -1; 
data = DQ->item[DQ->rear]; 
printf("\n Element %d is deleted from rear: ",data); 
} 
if (DQ->front==DQ->rear) 
{ 
DQ->front =0; 
DQ->rear = 0; 
printf("\n Deque is empty(rear end)"); 
} 
return data; 
} 
/********** Function Definition ends **********/ 
/********** Displaying elements of DEQUE **********/ 
/********** Function Definition begins **********/ 
void display(deque *DQ) 
{ 
int x; 
for(x=DQ->front;x<DQ->rear;x++) 
{ 
printf("%d\t",DQ->item[x]); 
} 
printf("\n\n"); 
} 
/********** Function Definition ends **********/ 