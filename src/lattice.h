#ifndef AUTOMATON_LATTICE_H
#define AUTOMATON_LATTICE_H

#include <cstddef>
#include <algorithm>

namespace Automaton{
    template<class T, std::size_t _width, std::size_t _height = _width, std::size_t _align = 0>
    struct Lattice
    {
      public:
          static constexpr auto height = _height;
          static constexpr auto width = _width;

          T& operator()(std::size_t x, std::size_t y){
              auto index = (y * width) + x;
              if ((x >= width) || (y >= height)){
                  throw std::out_of_range("out of range");
              }
              return data[index];
          }

          T operator()(std::size_t x, std::size_t y) const{
              auto index = (y * width) + x;
              if((x >= width) || (y >= height)){
                  throw std::out_of_range("out of range");
              }
              return data[index];
          }

          void swap(Lattice& other){
              std::swap(data, other.data);
          }
      private:
          alignas(_align) T data[height * width];
    };
    
}
#endif