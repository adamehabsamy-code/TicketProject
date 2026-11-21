# Ticket Reservation System
Data Structures Term Project

## Team
- Adam Farag: Waitlist (queue)
- Lisa: Ticket purchase / reservation

## What it does
Customers can buy tickets. If tickets are sold out,
they are added to a waitlist (queue). When a spot opens,
the first person on the waitlist gets it.

## Data structure used
Queue (first in, first out): the first person
to join the waitlist is the first to get a spot.

## Waitlist features (done)
- add: add a customer to the waitlist
- next: give the next person the open spot
- show: print everyone on the waitlist
- position: check someone's spot in line
- handles an empty waitlist without crashing

## How to run
g++ main.cpp -o main
.\main.exe
