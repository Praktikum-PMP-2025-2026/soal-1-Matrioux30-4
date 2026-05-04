#include <stdio.h>
#include <stdlib.h>

struct operasi{
    int operator[30];
    int nilai[30];
};

struct Node {
    int data;
    struct Node *prev, *next;
};

struct myDeque {
    struct Node *front, *rear;
    int size;
};

struct myDeque* createMyDeque(){
    struct myDeque* dq = (struct myDeque*)malloc(sizeof(struct myDeque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

int isEmpty(struct myDeque* dq) {return dq->front == NULL;}

int getSize(struct myDeque* dq){return dq->size;}

void insertFront(struct myDeque* dq, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dq->front;
    
    if(isEmpty(dq)) dq ->front = dq->rear = newNode;
    else{
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

void insertRear(struct myDeque* dq, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(dq)){
        newNode->prev = NULL;
        dq->front = dq->rear = newNode;
    }else{
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

void tampilkan(struct myDeque* dq){
    if (dq == NULL){
        printf("LIST EMPTY");
        return;
    }

    struct Node *current = dq->front;
    printf("LIST ");
    while(dq != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

int indexof(struct myDeque* dq, int value){
    struct Node *current = dq->front;
    int index = 0;

    while (current != NULL){
        if(current->data == value){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void Delete(struct myDeque *dq, int value){
    struct Node *current = dq->front;
    int index = indexof(dq, value);

    for (int i=0; i<index-1; i++){
        current = current->next;
    }

    struct Node *temp = current->next;
    current->next = temp->next;
}

int main(){
    struct myDeque* dq = createMyDeque();
    int N;
    scanf("%d", &N);
    struct operasi* oppo;

    for (int i=0; i<N; i++){
        scanf("%d", &oppo->operator[i]);
        scanf("%d", &oppo->nilai[i]); 
    }

    for (int i=0; i<N; i++){
        switch(oppo->operator[i]){
            case 1:
                insertFront(dq, oppo->nilai[i]);
                continue;
            case 2:
                insertRear(dq, oppo->nilai[i]);
                continue;
            case 3:
                Delete(dq, oppo->nilai[i]);
                continue;
            case 4:
                int idx = indexof(dq, oppo->nilai[i]);
                if(idx == -1){
                    printf("NOT FOUND\n");
                }else{
                    printf("FOUND %d\n", idx);
                }
                continue;
        }
    }
    tampilkan(dq);
}
