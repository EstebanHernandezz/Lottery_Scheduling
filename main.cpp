

#include <iostream>
#include <vector>
#include <map>
#include "classes.h"

int main()
{
    Scheduler scheduler;

    //10 tickets
    scheduler.addProcess(Process(10));
    //20 tickets
    scheduler.addProcess(Process(20));
    //30 tickets -> add more processes later 
    scheduler.addProcess(Process(30));
    //40 tickets
    scheduler.addProcess(Process(40));
    //50 tickets
    scheduler.addProcess(Process(50));

    Process winner = scheduler.selectNextProcess();
    std::cout << "Process: " << winner.getId() << " wins the lottery!" << "\n"; 

    return 0;
}