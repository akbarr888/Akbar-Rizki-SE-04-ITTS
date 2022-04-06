#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createList(int x, Node *addr = NULL)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void printAll(Node *list1)
{
    while (list1 != NULL)
    {
        cout << list1->data << " ";
        list1 = list1->next;
    }
}

void createList(Node **output)
{
    Node *temp = *output;
    temp = NULL;
}

bool isEmpty(Node *list1)
{
    if (list1 = NULL)
        return 1;
    return 0;
}

void insertFirst(Node **list1, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = *list1;
    *list1 = temp;
}

void insertAfter(Node *oldlist, Node *newlist)
{
    newlist->next = oldlist->next;
    oldlist->next = newlist;
}

void insertLast(Node **list1, int x)
{
    Node *temp = *list1;
    Node *insert = createList(x);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = insert;
}

void deleteFirst(Node **list1)
{
    Node *temp = *list1;
    if (isEmpty(temp))
        return; // jika tidak ada data didalam list maka tidak melakukan apapun
    *list1 = temp->next;

    temp->next = NULL;
    delete temp;
}

void deleteAfter(Node *list1, Node *list_to_remove)
{
    while (list1->next != list_to_remove)
    {
        list1 = list1->next;
    }

    list1->next = list_to_remove->next;
    list_to_remove->next = NULL;

    delete list_to_remove;
}

void deleteLast(Node **list1)
{
    Node *last = *list1;
    Node *beforeLast = NULL;
    if (last->next == NULL)
        deleteFirst(list1); // jika hanya ada 1 data maka lakukan deleteFirst
    if (isEmpty(last))
        return; // jika tidak ada data didalam list maka tidak melakukan apapun

    while (last->next != NULL)
    {
        beforeLast = last;
        last = last->next;
    }

    beforeLast->next = NULL;

    delete last;
}

void concat(Node *list1, Node *list2)
{

    while (list1->next != NULL)
    {
        list1 = list1->next;
    }

    list1->next = list2;
}

int main()
{
    Node *list1 = createList(30);

    insertFirst(&list1, 10);
    insertFirst(&list1, 60);
    insertFirst(&list1, 80);
    insertLast(&list1, 70);
    insertLast(&list1, 90);

    // expect 80,60,10,30,70,90
    std::cout << "create list1, insertFirst and insertLast:\n";
    std::cout << "expect 80,60,10,30,70,90\n";
    printAll(list1);

    Node *newNode = createList(45);

    Node *temp = list1;
    temp = temp->next;

    insertAfter(temp, newNode);

    // expect 80, 60, 45, 10, 30,70, 90
    std::cout << "\n\ninsertAfter:\n";
    std::cout << "expect 80,60,45,10,30,70,90\n";
    printAll(list1);

    deleteFirst(&list1);
    deleteFirst(&list1);
    deleteLast(&list1);

    // expect 45, 10, 30, 70
    std::cout << "\n\ndeleteFirst and deleteLast:\n";
    std::cout << "expect 45,10,30,70\n";
    printAll(list1);

    temp = list1;
    temp = temp->next->next;

    deleteAfter(list1, temp);

    // expect 45,10,70
    std::cout << "\n\ndeleteAfter:\n";
    std::cout << "expect 45,10,70\n";
    printAll(list1);

    Node *list2 = createList(45);

    insertFirst(&list2, 70);
    insertLast(&list2, 30);

    // expect 70,45,30
    std::cout << "\n\ncreate list2:\n";
    std::cout << "expect 70,45,30\n";
    printAll(list2);

    concat(list1, list2);

    // expect 45,10,70,70,45,30
    std::cout << "\n\nconcat list1 with list2:\n";
    std::cout << "expect 45,10,70,70,45,30\n";
    printAll(list1);

    return 0;
}
