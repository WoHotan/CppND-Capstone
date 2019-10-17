#ifndef AUTOMATON_GASAUTOMATA_H
#define AUTOMATON_GASAUTOMATA_H

#include <opencv2/opencv.hpp>
#include <string>
#include "cellular.h"

namespace Automaton {
    using dataType = unsigned short;
    class GasAutomaton : public CellularAutomaton<dataType, 400>
    {
    private:
        enum Direction : unsigned {
          Northwest  = 0, North, Northeast, East, Southeast, South, Southwest, West, Solid
      };
        cv::Mat frame;
        cv::VideoWriter writer;
        std::string outputPath;
        void init() noexcept override;
        void applyRule() override;
        void draw() override;
        template<unsigned n>
        inline constexpr void set(unsigned x, unsigned y, bool value = true){
            static_assert(n < bitsInDataType, "Invalid offset");
            if(value){
              _nextLattice(x, y) |= (1U << n);
            }
            else{
                _nextLattice(x, y) &= ~(1U << n);
            }
            
        }

        template<unsigned n>
        inline constexpr bool get(unsigned x, unsigned y){
            static_assert(n < bitsInDataType, "Invalid offset for byte");
            if(value){
                _nextLattice(x, y) |= (1U << n);
            }
            else{
              _nextLattice(x, y) &= ~(1U << n);
            }
            
        }

        template<unsigned n>
        inline constexpr bool get(unsigned x, unsigned y) {
            static_assert(n < bitsInDataType, "Invalid offset for byte");
            return (_currentLattice(x, y) & (1U << n)) > 0;
        }

    public:
        static constexpr auto bitsInDataType = sizeof(dataType) << 3UL;
        GasAutomaton(size_t totalSteps, std::string outputPath);
        virtual ~GasAutomaton() noexcept;
    };
}
#endif