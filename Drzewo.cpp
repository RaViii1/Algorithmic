#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <string>

struct node{
int key;
node* parent;
node* left;
node* right;
};


using namespace std;

bool is_Empty(node *root);
node* make_node(int value);
void add_node(int value, node*&root);
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);
void delete_node(node *&root,node *delete_node);
node* find_node(node *root,int value);
void remove_tree_nodes(node *&root);
node* find_successor(node *n);

int main()
{
    node* root;
    root=nullptr;


    bool exit=false;

    while (exit==false)
        {
            cout << "MENU GLOWNE DRZEWA:"<<endl;
            cout << ""<<endl;
            cout << "1. IsEmpty? "<<endl;
            cout << "2. Dodanie wezla "<<endl;
            cout << "3. Findnode"<<endl;
            cout << "4. Preorder"<<endl;
            cout << "5. Inorder"<<endl;
            cout << "6. Postorder"<<endl;//
            cout << "7. Usuniecie wezla o podanej wartosci "<<endl;
            cout << "8. Usuniecie calego drzewa"<<endl;
            cout << "9. Wyjdz z programu" <<endl;


            cout << "--------------------------------------"<<endl;


            cout << ""<<endl;
            cout << "Wybor: ";
    int zad;
    cin>>zad;
    switch(zad){


case 1:
{
    if(is_Empty(root))  cout << "Drzewo jest puste" << endl << endl;
        else cout << "Drzewo nie jest puste" << endl << endl;
        //system("pause");
        //system("cls");
        break;

}
case 2:
{
    int value;
    cout<<"Wprowadz liczbe ktora ma byc dodana do drzewa"<<endl;
    cin>>value;
    if(find_node(root,value)==nullptr)
    {
        inorder(root);
        add_node(value,root);
        cout<<"Inorder: "<<endl;
        inorder(root);
    }
    else
    {
        cout<<"Podana wartosc znajduje sie w drzewie"<<endl;
    }
        //system("pause");
        //system("cls");
break;
}
case 3:
{
    int value;
    cout<<"Wprowadz liczbe ktora chcesz wyszukac"<<endl;
    cin>>value;
    if(find_node(root,value)!=nullptr)
       {
        cout<<"Podana liczba znajduje sie w drzewie"<<endl;
    }
    else
    {
        cout<<"Nie znaleziono liczby w drzewie"<<endl;
    }
break;
}
case 4:
    {
        if(!is_Empty(root))
        {
            cout<<"\nPreorbder: "<<endl;
            preorder(root);
        }else{
            cout << "drzewo jest puste!"<<endl;
        }
break;
    }
case 5:
    {
        if(!is_Empty(root))
        {
            cout<<"\nInorder: "<<endl;
            inorder(root);
        }else{
            cout << "drzewo jest puste!"<<endl;
        }

break;
    }
case 6:
    {
        if(!is_Empty(root))
        {
            cout<<"\nPostorder: "<<endl;
            postorder(root);
        }else{
            cout << "drzewo jest puste!"<<endl;
        }
break;
    }
case 7:
    {
        inorder(root);
        int liczba;
        cout<<"Wprowadz wartosc wezla ktory chcesz usunac"<<endl;
        cin>>liczba;
        if(find_node(root,liczba)==nullptr)
            {
                cout<<"Nie ma takiej wartosci w drzewie"<<endl;
            }
        else
            {
            cout<<"Usuniecie"<<endl;
         delete_node(root,find_node(root,liczba));
            inorder(root);
            }
        break;
    }
case 8:
    {
        if(!is_Empty(root))
        {
            remove_tree_nodes(root);
            cout<<"Usunieto drzewo"<<endl;
        }else{
        cout << "drzewo jest juz puste!"<<endl;
        }
        break;
    }
case 9:
    {
         exit=true;
        break;
    }
default:
    {
        cout<<"Zly numer zadania!"<<endl;
        break;
    }
        }
    }
    return 0;
}

bool is_Empty(node *root)
{
    if(root) return false;
    else return true;
}
node* make_node(int value)
{
    node *n = new node;
    n->key=value;
    n->left=nullptr;
    n->right=nullptr;
    n->parent=nullptr;
    return n;
}
void add_node(int value, node*&root)
{
    if (root==nullptr)
    {
        root=make_node(value);
        return;
    }
    node *temp = root;
    while(true)
    {
        if (value>=temp->key)
        {
            if(temp->right==nullptr)
            {
                temp->right=make_node(value);
                temp->right->parent=temp;
                return;
            }
            else{
                temp=temp->right;
            }
        }
        else
        {
            if(temp->left==nullptr)
            {
                temp->left=make_node(value);
                temp->left->parent=temp;
                return;
            }
            else
            {
                temp=temp->left;
            }
        }
    }
}

void inorder(node *root)
{
    if(root!=nullptr)
    {
       inorder(root->left);
       cout<<root->key<<endl;
       inorder(root->right);
    }
}

void preorder(node *root)
{
    if(root!=nullptr)
    {
        cout<<root->key<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<endl;
    }
}

node* find_successor(node *n)
{
    if(n->right!=nullptr)
    {
        n=n->right;
    while(n->left!=nullptr)
    {
        n=n->left;
    }
    return n;
    }
    node *temp=n->parent;
    while(temp!=nullptr&&temp->left!=n)
    {
        n=temp;
        temp=temp->parent;
    }
    return temp;
}

void delete_node(node *&root,node *delete_node)
    {
        node *temp1;
        node *temp2;
    if(delete_node->left==nullptr||delete_node==nullptr)
    {
     temp1=delete_node;
    }
    else
    {
        temp1=find_successor(delete_node);
        }
    if(temp1->left!=nullptr)
    {
        temp2=temp1->left;
    }
    else
    {
        temp2=temp1->right;
    }
    if(temp2!=nullptr)
    {
        temp2->parent=temp1->parent;
    }
    if(temp1->parent==nullptr)
    {
        root=temp2;
    }
    else
    {
        if(temp1==temp1->parent->left)
        {
            temp1->parent->left=temp2;
        }
        else
        {
            temp1->parent->right=temp2;
        }
    }
    if(temp1!=delete_node)
    {
        delete_node->key=temp1->key;
    }
        delete  temp1;
}

node* find_node(node *root, int value)
{
    while (root!=nullptr)
    {
        if(root->key==value)
        {
            return root;
        }
        if(value>root->key)
        {
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return nullptr;
}

void remove_tree_nodes(node *&root)
{
    if(root!=nullptr)
    {
        remove_tree_nodes(root->left);
        remove_tree_nodes(root->right);
        delete  root;
root=nullptr;
    }
}
