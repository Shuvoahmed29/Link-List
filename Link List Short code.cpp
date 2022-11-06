#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int cunt = 0;
struct Node
{
    int data;
    Node *link;
};

// Insert Custom........
struct Node *insertCustom(Node *head, int data, int index)
{
    Node *newNode = new Node;
    Node *ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->link;
    }
    newNode->data = data;
    cunt++;
    newNode->link = ptr->link;
    ptr->link = newNode;
    return head;
}

// Delete Custom........
struct Node *deleteCustom(Node *head, int index)
{
    Node *ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->link;
    }
    ptr->link = ptr->link->link;
    if (cunt < 0)
        cunt = 0;
    else
        cunt--;
    return head;
}
// Print Link List........
void display(Node *head)
{
    Node *ptr = head->link;
    if (cunt <= 0)
        cout << "The List is empty" << endl;
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }
}

int main()
{
    Node *head = new Node;
    head->link = NULL;

    while (1)
    {
        system("CLS");
        cout << "Currtent list!!" << endl;
        display(head);
        cout << "\nEnter I for insert element.\n";
        cout << "Enter D for delete element.\n";
        cout << "Enter any for exit.\n";
        cout << "Enter your choice: ";
        char ch;
        cin >> ch;

        if (ch == 'I' || ch == 'i')
        {
            system("CLS");
            cout << "Currtent list!!" << endl;
            display(head);
            if (cunt == 0)
            {
                cout << "Enter an element for insert: ";
                int element;
                cin >> element;
                insertCustom(head, element, 1);
            }
            else
            {
                cout << "\nEnter F for insert first.\n";
                cout << "Enter L for insert last.\n";
                cout << "Enter N for insert at n'th Position.\n";
                cout << "Enter your choice: ";
                char insert;
                cin >> insert;
                if (insert == 'F' || insert == 'f')
                {
                    cout << "Enter an element for insert first: ";
                    int element;
                    cin >> element;
                    insertCustom(head, element, 1);
                }
                else if (insert == 'L' || insert == 'l')
                {
                    cout << "Enter an element for insert last: ";
                    int element;
                    cin >> element;
                    insertCustom(head, element, cunt + 1);
                }
                else if (insert == 'N' || insert == 'n')
                {
                    cout << "Enter index number to insert: ";
                    int idx;
                    cin >> idx;
                    cout << "Enter an element for insert " << idx << " position: ";
                    int element;
                    cin >> element;
                    insertCustom(head, element, idx);
                }
                else
                    cout << "Invalid input!! TRY AGAIN.";
            }
        }

        else if (ch == 'D' || ch == 'd')
        {
            system("CLS");
            cout << "Currtent list!!" << endl;
            display(head);
            cout << "\nEnter F for delete first.\n";
            cout << "Enter L for delete last.\n";
            cout << "Enter N for delete at n'th Position.\n";
            cout << "Enter your choice: ";
            char del;
            cin >> del;

            if (cunt == 0)
            {
                cout << "\nThere is no element to delete.\n";
                Sleep(2000);
            }
            else if (del == 'F' || del == 'f')
                deleteCustom(head, 1);
            else if (del == 'L' || del == 'l')
                deleteCustom(head, cunt);
            else if (del == 'N' || del == 'n')
            {
                cout << "Enter index number to delete: ";
                int idx;
                cin >> idx;
                deleteCustom(head, idx);
            }
            else
                cout << "Invalid input!! TRY AGAIN.";
        }

        else
            break;
    }
}