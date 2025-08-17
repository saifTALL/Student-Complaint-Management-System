#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
void arrayPart() {
    int roll [6];
    int i;
    for (i=0; i<6; i++) {
        printf("ENTER ROLL NUMBER FOR STUDENTS %d\n",i+1);
        scanf("%d",&roll[i]);
    }
    printf("LIST OF ROLL NUMBERS \n");
    for(i=0; i<6; i++) {
        printf("%d\n",roll[i]);
    }

}
struct Node {
    int roll;
    char name[50];
    struct Node* next;
};

struct Node* addStudent(struct Node* head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter roll number ");
    scanf("%d",&newNode->roll);
    getchar();
    printf("Enter name:");
    fgets(newNode->name,sizeof(newNode->name),stdin);
    newNode->name[strcspn(newNode->name,"\n")]=0;
    newNode->next =NULL;
    if (head==NULL) {
        head=newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL)
            temp=temp->next;
        temp->next = newNode;
    }
    return head;
}
struct Node* deleteStudent(struct Node* head) {
    int roll;
    printf("Enter roll number to delete\n");
    scanf("%d",&roll);
    struct Node *temp=head;
    struct Node *prev =NULL;
    while(temp != NULL && temp->roll!= roll) {
        prev=temp;
        temp=temp->next ;
    }
    if (temp==NULL) {
        printf("Student not found\n");
        return head;
    }
    if (prev==NULL) {
        head=head->next ;
    } else {
        prev->next=temp->next ;
    }
    free(temp);
    printf("Student delete\n");
    return head;
}
void displayList(struct Node *head) {
    if (head==NULL) {
        printf("No student to display \n");
        return;
    }
    struct Node* temp=head;
    printf("Student List\n");
    while(temp != NULL) {
        printf("roll : %d,name:%s\n",temp->roll,temp->name );
        temp=temp->next;
    }
}
void linkedListpart() {
    struct Node* head=NULL;
    int choice ;
    do {

        printf("\nLinked List Menu:\n1. Add Student \n2.Delete Student\n3. Display Student \n4. Exit\nEnter choice:");
        scanf("%d",&choice );
        switch(choice ) {
        case 1:
            head= addStudent(head);
            break;
        case 2:
            head= deleteStudent(head);
            break;
        case 3:
            displayList(head);
            break;
        case 4:
            printf("Invalid choice\n");
            break;
        }
    } while (choice !=4);
}
int queue [MAX];
int front = -1, rear = -1;
void enqueue() {
    int student ;
    if (rear==MAX-1) {
        printf("Queue is Full!\n");
        return;
    }
    printf("Enter student roll number to enqueue");
    scanf("%d",&student );
    if (front == -1)
        front = 0;

    queue [++rear]=student ;
    printf("Student %d added to queue\n",student );
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Student %d removed from queue.\n",queue [front++]);

}
void displayQueue() {
    if (front==-1 || front>rear) {
        printf("Queue is Empty \n");
        return;
    }
    printf("Students in queue:");
    for (int i=front ; i<=rear; i++)
        printf("%d",queue[i]);
    printf("\n");
}
void queuePart() {
    int choice ;
    do {
        printf("\nQueue Menu:\n1.Enqueue Student\n2.Dequeue Student \n3.Display queue\n4.Exit\nEnter choice");
        scanf("%d",&choice );
        switch(choice ) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            break;


        default:
            printf("Invalid choice \n");
        }
    } while(choice !=4);
}
int stack [MAX];
int top = -1;
void push(int student ) {
    if (top == MAX-1) {
        printf("Stack is Full\n");
        return;
    }
    stack[++top]=student ;
    printf("Student %d pushed to stack \n",student );
}
int pop() {
    if (top == -1) {
        printf("Stack is Empty \n");
        return -1;
    }
    return stack[top--];
}
void displayStack() {
    if (top == -1) {
        printf("Stack is Empty\n ");
        return ;
    }
    printf("Student in stack");
    for (int i=top; i>=0; i--)
        printf("%d",stack[i]);
    printf("\n");
}
void stackPart() {
    int choice, roll;
    do {
        printf("\nStack Menu:\n1. Push Student \n2. Pop Student (Undo)\n3.Display Stack\n4. Exit\nEnter choice:");
        scanf("%d",&choice );
        switch(choice ) {
        case 1:
            printf("Enter student roll to push:");
            scanf("%d",&roll);
            push(roll);
            break;
        case 2:
            roll=pop();
            if(roll!=-1)
                printf("Undo removed student %d from stack \n",roll);
            break;
        case 3:
            displayStack();
            break;
        case 4:
            break;

        default:
            printf("Invalid choice \n");
        }
    } while(choice != 4);
}
int main () {
    int choice ;
    do {
        printf("MENU:\n");
        printf("1.Array Part\n");
        printf("2.Linked List Part\n");
        printf("3.Queue Part\n");
        printf("4.Stack Part\n");
        printf("5.Exit\n");
        printf("Enter choice :\n");
        scanf("%d",&choice );
        switch(choice ) {
        case 1:
            arrayPart();
            break;
        case 2:
            linkedListpart();
            break;
        case 3:
            queuePart();
            break;
        case 4:
            stackPart();
            break;
        case 5:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice \n");
        }
    }   while (choice != 5);
    return 0;
}
