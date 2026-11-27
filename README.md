# Ticket Reservation System
Data Structures Term Project

## Team
- Adam Farag: Waitlist (queue)
- Lisa: Ticket purchase / reservation

## What it does
Customers can buy tickets for a movie showing. Each showing
has a set number of seats. If the showing is sold out,
customers are added to a waitlist (queue). When someone
cancels, the first person on the waitlist gets the seat.

## Data structure used
Queue (first in, first out), built ourselves as a
linked list (no built-in C++ queue).

## Waitlist features (done)
- add: add a customer to the waitlist
- next: give the next person the open spot
- show: print everyone on the waitlist
- position: check someone's spot in line
- handles an empty waitlist without crashing

## How to run
g++ main.cpp -o main
.\main.exe
