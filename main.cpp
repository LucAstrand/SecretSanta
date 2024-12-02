#include <iostream>
#include "SecretSanta.h"

int main() {
    SecretSanta santa;

    // Add participants
    santa.addParticipant("Ally");
    santa.addParticipant("Lucas");
    santa.addParticipant("Ben");
    // santa.addParticipant(" ");
     

    try {
        santa.generateAssignments();
        santa.printAssignments();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}