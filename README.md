# CPPND: Capstone Hello World Repo

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

A Simple cellular automaton in C++ 17 with OpenCV

When run the application, `./GasAutomaton 3000`, it will generate a record video in current directory, "GasAutomaton" is the application name you run, and the "3000" is the steps program
run, you can specify other values that you want the enter. After progam run complete, open the video to check the status.

A cellular automaton is a dynamic system defined in a cell space composed of cells with discrete finite states and evolved in discrete time dimensions according to certain local rules.

Here is the lattice gas automaton model, in which the particles on each grid move or move in multiple directions, where the two-digit number is used to represent the grid information. Initializing the particles is like a fluid, while staying active, by swapping the state, flowing to the gap, to achieve the effect of simulating the fluid.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
  
  * openCV 

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./GasAutomaton. `  `./GasAutomaton  5000`(argument).

## Loops, Functions, I/O

1. The project demonstrates an understanding of C++ functions and control structures.
`GasAutomaton.cpp`

2. The project accepts user input and processes the input.
    main.cpp, can input argument to application
    `int main(int argc, char* argv[]) {
        unsigned iterations = 3000;
        if(argc > 1){
            iterations = std::stoi(argv[1]);
        }
        std::cout << "Starting GasAutomaton!" << std::endl;
        Automaton::GasAutomaton gasAutomaton(iterations, "./gasAutomaton.avi");
        gasAutomaton.execute();
        return 0;
    }`
## Object Oriented Programming

1. The project uses Object Oriented Programming techniques.
   ` lattice.h`

2. Classes use appropriate access specifiers for class members.
`lattice.h  
private:
alignas(_align) T data[height * width];`

3. Class constructors utilize member initialization lists.
`cellular.h`

4. Classes follow an appropriate inheritance hierarchy.
`GasAutomaton.h`


5. Derived class functions override virtual base class functions.
`GasAutomaton.h
void init() noexcept override;
void applyRule() override;
void draw() override;`

6. Templates generalize functions in the project.
`GasAutomaton.h`

## Memory Management

The project uses move semantics to move data, instead of copying it, where possible.
`Automaton::GasAutomaton::GasAutomaton(size_t totalSteps, std::string outputPath) :
    CellularAutomaton(totalSteps), outputPath(std::move(outputPath)) {
    this->init();
}`
