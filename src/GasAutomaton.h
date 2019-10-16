#ifndef AUTOMATA_GASAUTOMATA_H
#define AUTOMATA_GASAUTOMATA_H

#include <opencv2/opencv.hpp>
#include <string>
#include "cellular.h"

namespace Automata {
    using dataType = unsigned short;
    class GasAutomaton : public Cellular<dataType, 400>
    {
    private:
        /* data */
    public:
        GasAutomaton : public Cellular(/* args */);
        ~GasAutomaton : public Cellular();
    };
    
    GasAutomaton : public Cellular::GasAutomaton(/* args */)
    {
    }
    
    GasAutomaton : public Cellular::~GasAutomaton()
    {
    }
    
}
#endif