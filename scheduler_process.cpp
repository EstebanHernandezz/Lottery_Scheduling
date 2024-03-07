

#include <iostream>
#include <array>
#include <vector>
#include <random>
//#include <map>
#include "classes.h"

int Process::nextId = 1;

//intialize tickets and ids to process,increment for each process -> 1,2,3...
Process::Process(int tickets)
{
    id = nextId++;
    this->tickets = tickets;
}


int Process::getId() const 
{
    return id;
}

int Process::getTickets() const 
{
    return tickets;
}

void Process::setTickets(int newTickets) 
{
    tickets = newTickets;
}

//intialize random number generation
Scheduler::Scheduler() : generator(std::random_device()()) {}

//adding a new process
void Scheduler::addProcess(const Process& process) 
{
    processes.push_back(process);
}

//gets the number of tickets in the lottery
Process Scheduler::selectNextProcess() 
{
    int totalTickets = 0;
    for (const auto& process : processes) 
    {
        totalTickets += process.getTickets();
    }
    
    //generate a random int from 1 to total num of tickets
    //this is the winning ticket
    std::uniform_int_distribution<int> distribution(1, totalTickets);
    int winningTicket = distribution(generator);
    int currentTicket = 0;
    
    for (const auto& process : processes) 
    {
        currentTicket += process.getTickets();
        
        //if the current ticket is greater than or equal to the random selected winning ticket
        //return the process containing the current ticket
        if (currentTicket >= winningTicket) 
        {
            return process;
        }
    }
}