#include <iostream>
#include "GasAutomaton.h"

int main(int argc, char* argv[]) {
    unsigned iterations = 3000;
    if(argc > 1){
        iterations = std::stoi(argv[1]);
    }
    std::cout << "Starting GasAutomaton!" << std::endl;
    Automaton::GasAutomaton gasAutomaton(iterations, "./gasAutomaton.avi");
    gasAutomaton.execute();
    return 0;
}