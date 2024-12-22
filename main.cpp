#include <iostream>
#include "SecretSanta.h"

int main() {
    SecretSanta santa;

    // Add participants
    santa.addParticipant("Ally");
    santa.addParticipant("Lucas");
    santa.addParticipant("Adrien");
    santa.addParticipant("Angad");
    santa.addParticipant("Blaise");
    santa.addParticipant("Daniel");
    santa.addParticipant("Hanna");
    santa.addParticipant("Hugo");
    santa.addParticipant("Julija");
    santa.addParticipant("Louise");


    try {
        santa.generateAssignments();
        santa.printAssignments();
        // santa.printAssignmentsDebug();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}