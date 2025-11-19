#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;

Node *create(Node *head){
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(head==NULL){
    head=newnode;
        scanf("%d",&newnode->data);
    newnode->next=head;
    }
    else{
        Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        scanf("%d",&newnode->data);
        temp->next=newnode;
        newnode->next=head;
    }

return head;
}

void printll(Node *head){
    Node *temp=head;
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("%d\n",head->data);
}

Node *insert_front(Node *h,int newval){

    Node *newnode=(Node*)malloc(sizeof(Node));
newnode->data=newval;
    if(h==NULL){
        h=newnode;
        newnode->next=h;
    }
Node *temp=h;
while(temp->next!=h){
    temp=temp->next;
}
temp->next=newnode;
newnode->next=h;
h=newnode;
return h;
}

Node *insert_rear(Node *h,int newval){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=newval;
    if(h==NULL){
        h=newnode;
        newnode->next=h;
    }
    Node *temp=h;
    while(temp->next!=h){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=h;
    return h;
}

Node *insert_pos(Node *h,int newval,int pos){
    if(pos==1){
    h=insert_front(h,newval);
    }
    else{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=newval;
    Node *temp=h;
    for(int i=1;i<pos-1;i++){
            temp=temp->next;}
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return h;
}

Node *delete_front(Node *h){
    if(h==NULL){
        printf("List is empty\n");
        return h;
    }
    Node *temp=h;
    while(temp->next!=h){
        temp=temp->next;
    }
    Node *todelete=h;
    temp->next=h->next;
    h=h->next;
    free(todelete);
    return h;
}

Node *delete_rear(Node *h){
    if(h==NULL){
        printf("List is empty\n");
        return h;
    }
    Node *temp=h;
    Node *prev;
    while(temp->next->next!=h){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=h;
    return h;
}

Node *delete_pos(Node *h,int pos){
    if(h==NULL){
        printf("List is empty\n");
        return h;
    }
    if(pos==1){
        h=delete_front(h);
    }
    else{
    Node *temp=h;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    Node *del_ptr=temp->next;
    temp->next=del_ptr->next;
    free(del_ptr);
    }
    return h;
}

Node *delete_key(Node *h,int val){
    if(h==NULL){
        printf("List is empty\n");
        return h;
    }
    Node *temp=h;
    int pos=1;
    while(temp->next!=h){
        if(temp->data==val){
            h=delete_pos(h,pos);
            return h;
        }
        temp=temp->next;
        pos++;
    }
    return h;
}

Node *search(Node *h,int val){
    if(h==NULL){
        printf("List is empty\n");
        return h;
    }
    Node *temp=h;
    int pos=1;
    while(temp->next!=h){
        if(temp->data==val){
            printf("Value found at pos %d\n",pos);
            return h;
        }
        temp=temp->next;
        pos++;
    }printf("Value not found\n");
    return h;
}

Node *ordered_list(Node *h,int newval){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=newval;
    if(h==NULL){ // empty list
        h=newnode;
        newnode->next=h;
        return h;
    }
    if(newval<h->data){ // specail case for front insertion
        h=insert_front(h,newval);
        return h;
    }
    Node *temp=h; // general case
    while(temp->next!=h && temp->next->data<newval){
        temp=temp->next;
    }
       newnode->next=temp->next;
    temp->next=newnode; 
    return h;
}

Node *reverse(Node *h){
    if(h==NULL){
        printf("List is empty\n");
        return h;
    }
    Node *prev=NULL;
    Node *current=h;
    Node *next;
    Node *tail=h;
    do{
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }while(current!=h);
    tail->next=prev;
    h=prev;
    return h;
}

void copy_list(Node *h){
    if(h==NULL){
        printf("List is empty\n");
        return;
    }
    Node *newhead=NULL; // new copied list head
    Node *temp=h;
    do{
        newhead=insert_rear(newhead,temp->data);
        temp=temp->next;
    }while(temp!=h);
    printf("Copied List: ");
    printll(newhead);   
}
//---------------------------------------MAIN()-------------------------------------------------------------------------
int main(){
    int n;
    int newval,pos;
    Node *head=NULL;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter n%d: ",i+1);
        head=create(head);
    }

    int choice;
    while(choice!=-1){
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter val: "); scanf("%d",&newval);
            head=insert_front(head,newval);break;
            
            case 2:
            printf("Enter val: "); scanf("%d",&newval);
            head=insert_rear(head,newval);break;
            
            case 3:
            printf("Enter val and pos: ");
            scanf("%d %d",&newval,&pos);
            head=insert_pos(head,newval,pos);break;
            
            case 4:
            head=delete_front(head);break;
            
            case 5:
            head=delete_rear(head);  break; 
                   
            case 6:
            printf("Enter pos: "); scanf("%d",&pos);
            head=delete_pos(head,pos); break;
            
            case 7:
            printf("Enter val to delete: "); scanf("%d",&newval);
            head=delete_key(head,newval);break;
        
            case 8:
            printf("Enter val to search: "); scanf("%d",&newval);
            head=search(head,newval);break;
            
            case 9:
            printf("Enter val to insert in order: "); scanf("%d",&newval);
            head=ordered_list(head,newval);break;
            
            case 10:
            head=reverse(head); break; 

            case 11:
            copy_list(head); break;    

            case 12: printll(head); break;
            case -1:return 0;
        }
    }

}