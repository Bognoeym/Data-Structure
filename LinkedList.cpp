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
    cout << "=======메뉴=======" << endl;
    cout << "1. 학생 등록" << endl;
    cout << "2. 학생 검색" << endl;
    cout << "3. 학생 목록" << endl;
    cout << "4. 학생 수정" << endl;
    cout << "5. 학생 삭제" << endl;
    cout << "6. 종료" << endl;
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

    cout << "학생 이름 입력 : ";
    cin >> Info->m_sName;
    cout << Info->m_sName << " 학생 나이 입력 : ";
    cin >> Info->m_iAge;
    cout << Info->m_sName << " 학생 주소 입력 : ";
    cin >> Info->m_sAdress;
    cout << Info->m_sName << " 학생 국어 점수 : ";
    cin >> Info->m_iKoScore;
    cout << Info->m_sName << " 학생 영어 점수 : ";
    cin >> Info->m_iEnScore;
    cout << Info->m_sName << " 학생 수학 점수 : ";
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
    cout << "학생 이름 : " << tmp->m_sName << endl;
    cout << "학생 나이 : " << tmp->m_iAge << "세" << endl;
    cout << "학생 주소 : " << tmp->m_sAdress << endl;
    cout << "국어 점수 : " << tmp->m_iKoScore << "점" << endl;
    cout << "영어 점수 : " << tmp->m_iEnScore << "점" << endl;
    cout << "수학 점수 : " << tmp->m_iMaScore << "점" << endl;
    cout << "합계 점수 : " << tmp->m_iSumScore << "점" << endl;
    cout << "평균 점수 : " << tmp->m_iAverage << "점" << endl;
    cout << "학생 등급 : " << tmp->m_cGrade << "등급" << endl;
}

void ShowInfo(Student* head)
{
    if (head == NULL)
    {
        cout << "(학생 개개인의 점수는 검색을 이용하세요.)" << endl;
        return;
    }

    cout << head->m_sName << "\t\t" << head->m_iAge << "\t\t" << head->m_sAdress << endl;
    ShowInfo(head->Link);
}

Student* Search(Student* head, string name)
{
    if (head == NULL)
    {
        cout << "검색한 학생이 존재하지 않습니다." << endl;
        return NULL;
    }
    else if (head->m_sName == name)
    {
        cout << "학생 정보 검색 완료" << endl;
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
        cout << "수정할 항목을 선택 하시오" << endl;
        cout << "1. 이름   2. 나이   3. 주소   4. 점수   5. 수정종료" << endl;
        cout << "선택 : ";
        cin >> sign;

        switch (sign)
        {
        case 1:
            cout << "현재 이름 : " << tmp->m_sName << endl;
            cout << "수정할 이름 : ";
            cin >> tmp->m_sName;
            cout << "이름 수정 완료" << endl;
            break;

        case 2:
            cout << "현재 나이 : " << tmp->m_iAge << endl;
            cout << "수정할 나이 : ";
            cin >> tmp->m_iAge;
            cout << "나이 수정 완료" << endl;
            break;

        case 3:
            cout << "현재 주소 : " << tmp->m_sAdress << endl;
            cout << "수정할 주소 : ";
            cin >> tmp->m_sAdress;
            cout << "주소 수정 완료" << endl;
            break;

        case 4:
            cout << "현재 점수" << endl;
            cout << "국어 : " << tmp->m_iKoScore << " 영어 : " << tmp->m_iEnScore << " 수학 : " << tmp->m_iMaScore << endl;
            cout << "수정할 국어 점수 : ";
            cin >> tmp->m_iKoScore;
            cout << "수정할 영어 점수 : ";
            cin >> tmp->m_iEnScore;
            cout << "수정할 수학 점수 : ";
            cin >> tmp->m_iMaScore;
            cout << "점수 수정 완료" << endl;
            break;

        case 5:
            cout << "수정을 종료합니다." << endl;
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
    cout << "학생 정보 입력 완료" << endl;
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
        cout << "삭제 완료" << endl;
        return;
    }
    else
    {
        before->Link = tmp->Link;
        delete tmp;
        cout << "삭제 완료" << endl;
        return;
    }
}

void End(Student* head)
{
    if (head == NULL)
        return;

    End(head->Link);
    delete head;
    cout << "학생 삭제 완료" << endl;
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
        cout << "입력 : ";
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
            cout << "검색할 이름 입력 : ";
            cin >> name;
            SearchInfo(Search(head, name));
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "======= Information =======" << endl;
            cout << "학생 이름" << "\t" << "학생 나이" << "\t" << "학생 주소" << endl;
            ShowInfo(head);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "수정할 학생 이름은?";
            cin >> name;
            modify(head, name);
            break;

        case 5:
            system("cls");
            cout << "삭제할 학생 이름 : ";
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