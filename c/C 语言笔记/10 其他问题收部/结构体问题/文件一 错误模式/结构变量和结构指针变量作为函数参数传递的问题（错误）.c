//结构变量和结构指针变量作为函数参数传递的问题（错误）
/*思考  为什么把struct Student 当成变量类型，让return 返回一个大的变量，编译没错误，但不能运行，为什么？？？？*/
#include <stdio.h>
#include<string.h>

struct Student
{
	int age;
	char sex;
	char name[100];
};//分号不能忘

struct Student InputStudent(void);
void OutputStudent(struct Student s2); 

int main ()
{
struct Student st;

st = InputStudent();
OutputStudent(st);

return 0;
}

struct Student InputStudent()
{
	struct Student s1
  s1.age=10;
  strcpy(s1.name,"张三");
  //s1.name="张三";这样写是错误的，涉及到字符串的处理
  s1.sex='F';

  return s1;
}

void OutputStudent(struct Student s2)
{
printf("%d %s %c",s2.age,s2.name,s2.sex);
}

