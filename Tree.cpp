#include <iostream>
using namespace std;

#define CHECK 0
#define GET 1

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void Menu()
{
    cout << "1. data 추가" << endl;
    cout << "2. data 삭제" << endl;
    cout << "3. preorder" << endl;
    cout << "4. inorder" << endl;
    cout << "5. postorder" << endl;
    cout << "6. data 검색" << endl;
    cout << "7. 종료" << endl;
}

Node* Search(Node* root, int data, int flag)
{
    if (root == NULL)
        return root;
    if (root->data == data)
    {
        if (flag == CHECK)
        {
            cout << data << "는 존재합니다." << endl;
            return root;
        }
        else if (flag == GET)
            return root;
    }
    else if (data < root->data)
        return Search(root->left, data, flag);
    else if (data > root->data)
        return Search(root->right, data, flag);
}

void SaveData(Node* root, Node* newnode)
{
    if (newnode->data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = newnode;
            return;
        }
        else
            SaveData(root->left, newnode);
    }
    else if (newnode->data > root->data)
    {
        if (root->right == NULL)
        {
            root->right = newnode;
            return;
        }
        else
            SaveData(root->right, newnode);
    }
}

Node* Insert(Node* root, int data)
{
    if (Search(root, data, CHECK) != NULL)
        return root;
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    if (root == NULL)
        root = NewNode;
    else
        SaveData(root, NewNode);
    return root;
}

void PreOrder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    if (root->left != NULL)
        PreOrder(root->left);
    if (root->right != NULL)
        PreOrder(root->right);
}

void InOrder(Node* root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        InOrder(root->left);
    cout << root->data << " ";
    if (root->right != NULL)
        InOrder(root->right);
}

void PostOrder(Node* root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        PostOrder(root->left);
    if (root->right != NULL)
        PostOrder(root->right);
    cout << root->data << " ";
}

void AllDelete(Node* root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        AllDelete(root->left);
    if (root->right != NULL)
        AllDelete(root->right);
    cout << root->data << " ";
    delete root;
    cout << "삭제완료" << endl;
}

Node* GetParents(Node* root, Node* delData)
{
    if (root == delData)
        return root;
    if (root->left == delData || root->right == delData)
        return root;
    else
    {
        if (delData->data < root->data)
            GetParents(root->left, delData);
        else if (delData->data > root->data)
            GetParents(root->right, delData);
    }
}

Node* minNode(Node* parent, Node* right, Node* delData)
{
    if (right->left == NULL)
    {
        if (parent == delData)
            parent->right = right->right;
        else
            parent->left = right->right;
        return right;
    }
    else
    {
        if (parent == delData)
            return minNode(parent->right, right->left, delData);
        else
            return minNode(parent->left, right->left, delData);
    }
}

Node* SetMin(Node* parents, Node* delData, Node* min) {

    if (parents == delData)
        parents = min;
    else if (parents->left == delData)
        parents->left = min;
    else
        parents->right = min;

    min->left = delData->left;
    min->right = delData->right;
    return parents;
}

Node* DataDelete(Node* root, int data)
{
    Node* delData = Search(root, data, GET);
    if (delData == NULL)
        return root;
    Node* parents = GetParents(root, delData);
    if (delData->left == NULL && delData->right == NULL)
    {
        if (root == delData)
            root = NULL;
        else if (parents->left == delData)
            parents->left = NULL;
        else
            parents->right = NULL;
        delete delData;
    }
    else if (delData->left != NULL && delData->right == NULL)
    {
        if (root == delData)
            root = delData->left;
        else if (parents->left == delData)
            parents->left = delData->left;
        else
            parents->right = delData->left;
        delete delData;
    }
    else if (delData->left == NULL && delData->right != NULL)
    {
        if (root == delData)
            root = delData->right;
        else if (parents->left == delData)
            parents->left = delData->right;
        else
            parents->right = delData->right;
        delete delData;
    }
    else if (delData->left != NULL && delData->right != NULL)
    {
        Node* min = minNode(delData, delData->right, delData);
        root = SetMin(parents, delData, min);
        delete delData;
    }
    return root;
}

void main()
{
    Node* root = NULL;
    int data;
    int sign;

    while (1)
    {
        system("cls");
        Menu();
        cout << "입력 : ";
        cin >> sign;

        switch (sign)
        {
        case 1:
            cout << "data 입력 : ";
            cin >> data;
            root = Insert(root, data);
            system("pause");
            break;

        case 2:
            cout << "삭제할 데이터 입력 : ";
            cin >> data;
            root = DataDelete(root, data);
            system("pause");
            break;

        case 3:
            PreOrder(root);
            system("pause");
            break;

        case 4:
            InOrder(root);
            system("pause");
            break;

        case 5:
            PostOrder(root);
            system("pause");
            break;

        case 6:
            cout << "data 입력 : ";
            cin >> data;
            Search(root, data, CHECK);
            system("pause");
            break;

        case 7:
            AllDelete(root);
            system("pause");
            return;
        }
    }
}