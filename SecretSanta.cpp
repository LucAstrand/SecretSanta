// secret_santa.cpp
#include "SecretSanta.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

SecretSanta::SecretSanta() : rng(std::random_device{}()) {}

void SecretSanta::addParticipant(const std::string& name) {
    participants.push_back(name);
}

void SecretSanta::validateAssignments() {
    // Ensure no one gets themselves
    for (const auto& assignment : assignments) {
        if (assignment.first == assignment.second) {
            throw std::runtime_error("Invalid assignment: Someone got themselves");
        }
    }
}

void SecretSanta::generateAssignments() {
    if (participants.size() < 2) {
        throw std::runtime_error("Not enough participants");
    }

    // Create a copy of participants to assign gifts to
    std::vector<std::string> receivers = participants;
    
    do {
        // Reset assignments
        assignments.clear();
        
        // Shuffle the receivers
        std::shuffle(receivers.begin(), receivers.end(), rng);

        // Assign gifts
        for (size_t i = 0; i < participants.size(); ++i) {
            if (participants[i] != receivers[i]) {
                assignments[participants[i]] = receivers[i];
            }
        }
    } while (assignments.size() != participants.size());

    validateAssignments();
}

void SecretSanta::printAssignments() const {
    std::cout << "Secret Santa Assignments:\n";
    std::cout << "----------------------\n";
    for (const auto& assignment : assignments) {
        std::cout << assignment.first << " gets a gift for " << assignment.second << std::endl;
    }
}