#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct task
{
    int id;
    char name[100];
    int p; //1= high 2=medium 3=low
    char dead[20];
    int com; //0= pending 1=complete
}t;
struct task tasks[MAX]; //creat an array
int count=0;

void add(){
  t.id=count+1;
  printf("Enter Task name:");
  scanf(" %[^\n]",t.name);
  printf("Enter priority(1=High,2=Medium 3=Low):");
  scanf("%d",&t.p);
  printf("Enter deadline:");
  scanf("%s",&t.dead);
  t.com=0;
  tasks[count]=t;
  count++;
  printf("Task Added Successfully\n");
} 
void display(){
    if(count==0){
        printf("No task available\n");
        return;
    }
    printf("\nTask list:\n");
    for(int i=0;i<count;i++){
        printf("ID:%d | Task:%s | Priority:%d | Deadline:%s | Status:%s\n",
        tasks[i].id,
        tasks[i].name,
        tasks[i].p,
        tasks[i].dead,
        tasks[i].com? "Completed" : "Pending");

    }
}
void sort(){
    struct task temp;
    for(int i=0;i<count;i++){
       for(int j=i+1;j<count;j++){
        if(tasks[i].p>tasks[j].p){ 
        temp=tasks[i];
        tasks[i]=tasks[j];
        tasks[j]=temp;
        }
       }
    }
}
void com(){
    int id;
    printf("Enter task id to mark complete:");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(tasks[i].id==id){
            tasks[i].com=1;
            printf("Task complete\n");
            return;
        }
    }
    printf("Task not found\n");
}
int main(){
    int choice;
    for(;;){
        printf("\nSMART TASK MANAGER\n");
        printf("1 Add Task\n");
        printf("2 View Tasks\n");
        printf("3 Sort Tasks by Priority\n");
        printf("4 Mark Task Completed\n");
        printf("5 Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);
         switch(choice) {

            case 1:
                add();
                break;

            case 2:
                display();
                break;

            case 3:
                sort();
                printf("Tasks sorted by priority\n");
                break;

            case 4:
                com();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
