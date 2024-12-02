# Secret Santa Assignment Generator

## Overview

This C++ application generates random Secret Santa gift assignments for a group of participants, ensuring that:
- No participant is assigned to buy a gift for themselves
- Each participant is assigned exactly one gift recipient

## Features

- Add multiple participants
- Randomized gift assignments
- Error handling for insufficient participants
- Robust assignment generation algorithm

## Prerequisites

- C++ Compiler (G++ recommended)
- C++11 or later standard support

## Installation

1. Clone the repository:
```bash
git clone git@github.com:LucAstrand/SecretSanta.git
cd SecretSanta
```

2. Compile the project:

```bash
g++ -std=c++17 SecretSanta.cpp main.cpp -o SecretSanta
```

## Usage

To run the program use:

```bash
./SecretSanta
```

## Customizing the participants

Edit the `main.cpp` file to add or remove participants:

```cpp
    SecretSanta santa;
    santa.addParticipant("Ally");
    santa.addParticipant("Lucas");
    santa.addParticipant("Ben");
    //add participants here...
```

## Example output 

```bash
Secret Santa Assignments:
----------------------
Ally gets a gift for Lucas
Lucas gets a gift for Ben
Ben gets a gift for Ally
```