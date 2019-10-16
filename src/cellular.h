#ifdef CELLULAR_H
#define CELLULAR_H

#include <random>
#include "lattice.h"

namespace Automata {
    template<class T, ::std::size_t _size, bool auto_swap = false>
    class Cellular
    {
    protected:
        std::size_t _totalSteps;
        std::size_t _currentStep;
        Lattice<T, _size> _currentLattice;
        Lattice<T, _size> _nextLattice;
        bool _hasErrorOcurred;
        explicit Cellular(std::size_t totalSteps) : 
        _totalSteps(totalSteps), _currentStep(0), _hasErrorOcurred(false){}
        
    public:
        static constexpr std::size_t size = _size;
        void execute();
        void step();
        void stop();
        void reset();
        void reset(std::size_t totalSteps);
        std::size_t currentStep() const{
            return this->_currentStep;
        }
        std::size_t totalSteps() const{
            return this->_totalSteps;
        }
    };
    
    cellular::cellular(/* args */)
    {
    }
    
    cellular::~cellular()
    {
    }
    
}

#endif