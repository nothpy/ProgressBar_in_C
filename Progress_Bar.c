#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

const int BAR_LENGTH = 20; // progress bar length
const int MAX_TASK = 10; // total task

typedef struct
{
    int id ;
    int progress;
    int step; // step can be different to all task
} Task;

void print_bar(Task task);
void clear_screen();

int main()
{
    Task task[MAX_TASK];
    srand(time(NULL));

    for(int i=0; i< MAX_TASK ; i++)
    {
        task[i].id = i+1;
        task[i].progress = 0;
        task[i].step = rand()%5 + 1 ; // random number assign between 1 to 5 . these generate random number only when do seeding from
        //srand(time(NULL)) otherwise it generate always same number .To srand(time(NULL)) we are add time.h header file
    }

    int task_incomplete =1;
    while(task_incomplete)
    {
        task_incomplete = 0;
        clear_screen();
        for(int i =0;i<MAX_TASK; i++)
        {
            task[i].progress += task[i].step;
            if(task[i].progress > 100)
            {
                task[i].progress = 100;
            }
            else if(task[i].progress < 100)
            {
                task_incomplete = 1 ;
            }
            print_bar(task[i]);
        }
        sleep(1);// sleep for 1 second
    }
    printf("All tasks completed!\n");
    return 0;
}

void clear_screen()
{
    #ifdef _Win32
      system("cls");
    #else
       system("clear");
    #endif // _Win32
}

void print_bar(Task task)
{
    int bars_to_show = (task.progress*BAR_LENGTH) / 100;
    printf("Task %d: [", task.id);
    for(int i =0; i< BAR_LENGTH ;i++)
    {
        if(i<bar_to_show){
            printf("=");
        }
        else{
            printf(" ")
        }
    }
    printf("] %d%\n", task.progress);
}

