

//declare process and scheduler class here

#include <iostream>
#include <array>
#include <vector>
#include <random>
//#include <map>

//process class
class Process 
{
    private:
        // create variable for unique ids for the next process
        static int nextId;
        //proces id
        int id;
        //# of tickets in each process 
        int tickets;

    public:
        //intialize the first process with value 0
        Process(int tickets = 0);
        //gets the process id
        int getId() const;
        //gets the number of tickets for the corresponding class
        int getTickets() const;
        //changes the number of tickets in a process if needed 
        void setTickets(int newTickets);
};

//scheduler class 
class Scheduler 
{
    private:
        //create mutiple process array and rand number generation, intitialize scheduler() for main
        std::vector<Process> processes;
	//rand num generator
        std::default_random_engine generator;

    public:
        Scheduler();
        void addProcess(const Process& process);
        Process selectNextProcess();
};