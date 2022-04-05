# Akbar-Rizki-SE-04-ITTS

#include<iostream>

struct node{
    int data;
    node *next;
};

void insertFirst(node **list1, int x){
    node *temp = new node(); //membuat temp
    temp->data = x; //x dimasukkan ke temp
    temp->next = *list1; //list dimasukkan ke temp

    *list1 = temp;

}

void insertAfter(node *oldlist, node *newlist){
    newlist->next = oldlist->next;
    oldlist->next = newlist;
}

void insertLast(node *list1, int x){
    node *list1_temp = list1;

    while(list1_temp->next != NULL){
        list1_temp = list1_temp->next;
    }
    node *temp = new node();
    temp->data = x;
    temp->next = NULL;

    list1_temp->next = temp;
}

void printAll(node *list1){
    while(list1 != NULL){
        std::cout<<list1->data<< " ";
    list1 = list1->next;
    }
    std::cout<< "\n";
}


void deleteFirst(node **list1){
    node *temp = *list1;
    *list1 = temp->next;

    temp->next = NULL;

}

void deleteAfter(node *list1, node *list2){
    if(list1 != list2){
    node *temp = list1;
    while(temp->next != list2){
        temp = temp->next;
    }
    temp->next = list2->next;
    }
}

void deleteLast(node *list1){
    node *temp = list1;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    temp->next = NULL;
}



int main(){
    node *list1 = NULL;
    insertFirst(&list1, 10);
    insertFirst(&list1, 20);
    insertLast(list1, 30);

    std::cout<< "insert first and insert last : \n";
    std::cout<< "expect 20,10,30\n";
    printAll(list1);

    node *temp = new node();
    temp->data = 50;
    temp->next = NULL;

    insertAfter(list1->next, temp);
    std::cout<< "insert after: \n";
    std::cout<< "expect 20, 10, 50, 30\n";

    printAll(list1);

    deleteFirst(&list1);
    deleteFirst(&list1);
    deleteLast(list1);

    std::cout<< " delete first and delete last :\n";
    std::cout<< "expect 50\n";

    printAll(list1);

    insertFirst(&list1, 90);
    insertFirst(&list1, 80);

    std::cout<< "insert first :\n";
    std::cout<< "expect 80, 90, 50\n";
    printAll(list1);

    deleteAfter(list1, list1->next->next);
    std::cout<< "delete after : \n";
    std::cout<< "expect 80,90\n";
    printAll(list1);

    return 0;
}
