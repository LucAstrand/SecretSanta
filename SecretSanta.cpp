// secret_santa.cpp
#include "SecretSanta.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <filesystem>

// SecretSanta::SecretSanta() : rng(std::random_device{}()) {}

SecretSanta::SecretSanta() 
    : rng(std::random_device{}() ^ 
          (std::mt19937::result_type)std::chrono::steady_clock::now().time_since_epoch().count()) {}


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

// void SecretSanta::printAssignmentsDebug() const {
//     std::cout << "Secret Santa Assignments:\n";
//     std::cout << "----------------------\n";
//     for (const auto& assignment : assignments) {
//         std::cout << assignment.first << " gets a gift for " << assignment.second << std::endl;
//     }
// }

void SecretSanta::printAssignments() const {
    std::string folderName = "SecretSantaAssignments";

    std::filesystem::create_directory(folderName);

    for (const auto& assignment : assignments) {
        std::string filename = folderName + "/" + assignment.first + "_assignment.txt";

        std::ofstream outFile(filename);

        if (outFile.is_open()) {
            outFile << "Hello " << assignment.first << "!\n";
            outFile << "You are the Secret Santa for " << assignment.second << ".\n";
            outFile << "Keep it a secret and enjoy the holiday spirit!\n";
            outFile.close(); 
        } else {
            std::cerr << "Error: Could not create file for " << assignment.first << std::endl;
        }
    }
}