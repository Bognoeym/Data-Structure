#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string m_sName;
    int m_iAge;
    string m_sAdress;
    int m_iKoScore;
    int m_iEnScore;
    int m_iMaScore;
    int m_iSumScore;
    int m_iAverage;
    char m_cGrade;
    Student* Link;
};

void Menu()
{
    cout << "=======�޴�=======" << endl;
    cout << "1. �л� ���" << endl;
    cout << "2. �л� �˻�" << endl;
    cout << "3. �л� ���" << endl;
    cout << "4. �л� ����" << endl;
    cout << "5. �л� ����" << endl;
    cout << "6. ����" << endl;
}

char GetGrade(int score)
{
    char grade;
    if (score <= 100 && score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'F';

    return grade;
}

Student* SetInfo()
{
    Student* Info = new Student;

    cout << "�л� �̸� �Է� : ";
    cin >> Info->m_sName;
    cout << Info->m_sName << " �л� ���� �Է� : ";
    cin >> Info->m_iAge;
    cout << Info->m_sName << " �л� �ּ� �Է� : ";
    cin >> Info->m_sAdress;
    cout << Info->m_sName << " �л� ���� ���� : ";
    cin >> Info->m_iKoScore;
    cout << Info->m_sName << " �л� ���� ���� : ";
    cin >> Info->m_iEnScore;
    cout << Info->m_sName << " �л� ���� ���� : ";
    cin >> Info->m_iMaScore;

    Info->m_iSumScore = Info->m_iKoScore + Info->m_iEnScore + Info->m_iMaScore;
    Info->m_iAverage = Info->m_iSumScore / 3;
    Info->m_cGrade = GetGrade(Info->m_iAverage);
    Info->Link = NULL;

    return Info;
}

void SearchInfo(Student* Info)
{
    Student* tmp = Info;
    if (tmp == NULL)
        return;

    cout << "======= Information =======" << endl;
    cout << "�л� �̸� : " << tmp->m_sName << endl;
    cout << "�л� ���� : " << tmp->m_iAge << "��" << endl;
    cout << "�л� �ּ� : " << tmp->m_sAdress << endl;
    cout << "���� ���� : " << tmp->m_iKoScore << "��" << endl;
    cout << "���� ���� : " << tmp->m_iEnScore << "��" << endl;
    cout << "���� ���� : " << tmp->m_iMaScore << "��" << endl;
    cout << "�հ� ���� : " << tmp->m_iSumScore << "��" << endl;
    cout << "��� ���� : " << tmp->m_iAverage << "��" << endl;
    cout << "�л� ��� : " << tmp->m_cGrade << "���" << endl;
}

void ShowInfo(Student* head)
{
    if (head == NULL)
    {
        cout << "(�л� �������� ������ �˻��� �̿��ϼ���.)" << endl;
        return;
    }

    cout << head->m_sName << "\t\t" << head->m_iAge << "\t\t" << head->m_sAdress << endl;
    ShowInfo(head->Link);
}

Student* Search(Student* head, string name)
{
    if (head == NULL)
    {
        cout << "�˻��� �л��� �������� �ʽ��ϴ�." << endl;
        return NULL;
    }
    else if (head->m_sName == name)
    {
        cout << "�л� ���� �˻� �Ϸ�" << endl;
        return head;
    }
    else
        return Search(head->Link, name);
}

void modify(Student* head, string name)
{
    Student* tmp = Search(head, name);
    int sign;

    if (tmp == NULL)
        return;

    while (1)
    {
        system("cls");
        SearchInfo(tmp);
        cout << endl;
        cout << "������ �׸��� ���� �Ͻÿ�" << endl;
        cout << "1. �̸�   2. ����   3. �ּ�   4. ����   5. ��������" << endl;
        cout << "���� : ";
        cin >> sign;

        switch (sign)
        {
        case 1:
            cout << "���� �̸� : " << tmp->m_sName << endl;
            cout << "������ �̸� : ";
            cin >> tmp->m_sName;
            cout << "�̸� ���� �Ϸ�" << endl;
            break;

        case 2:
            cout << "���� ���� : " << tmp->m_iAge << endl;
            cout << "������ ���� : ";
            cin >> tmp->m_iAge;
            cout << "���� ���� �Ϸ�" << endl;
            break;

        case 3:
            cout << "���� �ּ� : " << tmp->m_sAdress << endl;
            cout << "������ �ּ� : ";
            cin >> tmp->m_sAdress;
            cout << "�ּ� ���� �Ϸ�" << endl;
            break;

        case 4:
            cout << "���� ����" << endl;
            cout << "���� : " << tmp->m_iKoScore << " ���� : " << tmp->m_iEnScore << " ���� : " << tmp->m_iMaScore << endl;
            cout << "������ ���� ���� : ";
            cin >> tmp->m_iKoScore;
            cout << "������ ���� ���� : ";
            cin >> tmp->m_iEnScore;
            cout << "������ ���� ���� : ";
            cin >> tmp->m_iMaScore;
            cout << "���� ���� �Ϸ�" << endl;
            break;

        case 5:
            cout << "������ �����մϴ�." << endl;
            return;
        }
        system("pause");
    }
}

Student* LinkSearch(Student* head, Student* Search)
{
    if (head == NULL)
        return NULL;

    if (head == Search)
        return head;
    else if (head->Link == Search)
        return head;
    else
        LinkSearch(head->Link, Search);
}

void insert(Student** head)
{
    Student* NewNode, * tmp = NULL;
    NewNode = SetInfo();
    NewNode->Link = NULL;
    if (*head == NULL)
    {
        *head = NewNode;
    }
    else
    {
        tmp = LinkSearch(*head, NULL);
        tmp->Link = NewNode;
    }
    cout << "�л� ���� �Է� �Ϸ�" << endl;
}

void Delete(Student** head, string name)
{
    Student* tmp = Search(*head, name), * before;

    if (tmp == NULL)
        return;

    before = LinkSearch(*head, tmp);
    if (before == tmp)
    {
        *head = tmp->Link;
        delete tmp;
        cout << "���� �Ϸ�" << endl;
        return;
    }
    else
    {
        before->Link = tmp->Link;
        delete tmp;
        cout << "���� �Ϸ�" << endl;
        return;
    }
}

void End(Student* head)
{
    if (head == NULL)
        return;

    End(head->Link);
    delete head;
    cout << "�л� ���� �Ϸ�" << endl;
}

void main()
{
    Student* head = NULL;
    int sign;
    string name;

    while (1)
    {
        system("cls");
        Menu();
        cout << "�Է� : ";
        cin >> sign;

        switch (sign)
        {
        case 1:
            system("cls");
            insert(&head);
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "�˻��� �̸� �Է� : ";
            cin >> name;
            SearchInfo(Search(head, name));
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "======= Information =======" << endl;
            cout << "�л� �̸�" << "\t" << "�л� ����" << "\t" << "�л� �ּ�" << endl;
            ShowInfo(head);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "������ �л� �̸���?";
            cin >> name;
            modify(head, name);
            break;

        case 5:
            system("cls");
            cout << "������ �л� �̸� : ";
            cin >> name;
            Delete(&head, name);
            system("pause");
            break;

        case 6:
            End(head);
            return;
        }
    }
}