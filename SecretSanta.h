#ifndef SECRET_SANTA_H
#define SECRET_SANTA_H

#include <vector>
#include <string>
#include <unordered_map>
#include <random>

class SecretSanta {
private:
    std::vector<std::string> participants;
    std::mt19937 rng;
    std::unordered_map<std::string, std::string> assignments;

    void validateAssignments();

public:
    SecretSanta();
    
    void addParticipant(const std::string& name);
    void generateAssignments();
    void printAssignments() const;
};

#endif // SECRET_SANTA_H