#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void taskA(){
    for(int i=0;i<10;i++){
        sleep(1);
        printf("TASK A:%d",i);
        fflush(stdout);
    }
}
void taskB(){
    for(int i=0;i<10;i++){
        sleep(1);
        printf("TASK B:%d",i);
        fflush(stdout);
    }
}
int main(){
    th
    thread t1(taskA);
    thread t2(taskB);
    return 0;
}