// Header file
#include<cstdio>
#include<cstdlib>
class time{
    struct process{
        int time;
        process *next;
    };
    process *head;
    process *tail;
    public:
    time(){
        head=NULL;
    }
    // Function prototypes
    int insertprocess(int);
    int execute(int);
    void display();
};