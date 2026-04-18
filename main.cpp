#include <iostream>
enum studentsName
{
    kim,
    lee,
    park,
    numOfStudents
}; //enum에는 끝에 ;를 적어줘야함
void printStudentName(const studentsName name) //const를 적어줘야하나?
{
    switch(name) //switch는 {}안에 내용을 적어줘야함 break;도 넣어주기
    {
    case kim: std::cout<<"KIM,"; break;
    case lee: std::cout<<"LEE,"; break;
    case park: std::cout<<"PARK,"; break;
    default: std::cout<<"NO NAME,"; break;
    }
}
struct student
{
    studentsName name{kim};
    int id{3741200};
    int score{0};
    char grade{'F'};
};
// 열거형 studentsName 정의: kim, lee, park, numOfStudents
// printStudentName 함수 정의: 리턴은 없고, 매개변수는 studentsName형 1개
// 매개변수에 따라
// kim은 KIM, 을 출력
// lee는 LEE, 를 출력
// park은 PARK, 를 출력
// kim, lee, park이 아니면 NO NAME, 을 출력
// 구조체 student 정의 
// student 구조체는 studentsName형 name, int형 id, int형 score, char형 grade를 멤버로 갖습니다. 
// name은 kim, id는 3741200, score는 0, grade는 'F'로 디폴트값을 지정합니다.
void score2grade(const int& score, char& grade)
{
    switch(score/10)
    {
        case 10: case 9: grade='A'; break;
        case 8: grade='B'; break;
        case 7: grade='C'; break;
        case 6: grade='D'; break;
        default: grade='F'; break;
    }
}
void inputStudent(student& s)
{
    s.name=static_cast<studentsName>(rand()%numOfStudents); //s.name이 studnetsName형이므로 같은 형 변환이 필요함
    std::cout<<"Enter id:";
    std::cin>>s.id;
    std::cout<<"Enter score:";
    std::cin>>s.score;
    score2grade(s.score,s.grade);
}
void printStudent (const student& s)
{
    printStudentName(s.name);
    std::cout<<s.id<<":"<<s.score<<"("<<s.grade<<")\n";
}
    // 함수 정의 
// score2grade: 리턴 없음, 매개변수는 const int형 참조, char형 참조 (총 2개),
// int형 매개변수 값 (90이상,80이상,70이상,60이상,그외)에 따라 char형에 ('A','B','C','D','F')값을 할당
// inputStudent: 리턴은 없고, 매개변수는 student형 참조,
// student의 name은 rand()함수로 값을 넣고, student의 id, score를 입력받고, student의 grade는 3-1함수를 사용
// printStudent: 리턴은 없고, 매개변수는 const student형 참조,
// name, id: score(grade) 형식으로 출력, name은 printStudentName 함수이용
int main()
{
    student s1;
    inputStudent(s1);
    printStudent(s1);
    student s2;
    printStudent(s2); //student 구조체의 기본값
    student s3{park,3741299,98,'A'};
    printStudent(s3);
    return 0;
}
// main 구현
// 첫번째 student를 선언하고 이를 inputStudent에 인자로 넣어 호출, printStudent에 인자로 넣어 호출합니다. 
// 두번째 student를 선언하고 이를 printStudent에 인자로 넣어 호출합니다. //이때 출력되는 값은 무엇인가요?
// 세번째 student를 원하는 값을  초기화리스트로 넣어 선언하고 이를 printStudent에 인자로 넣어 호출합니다. 
// 결과창 예
// Enter id: 2600000
// Enter score: 100
// LEE, 2600000: 100(A)
// KIM, 3741200: 0(F)
// PARK, 3741299: 98(A)
