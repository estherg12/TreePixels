#ifndef INPUTOUTPUT_HPP
#define INPUTOUTPUT_HPP

#include "ListSum.hpp"
#include "ElementListSum.hpp"
#include "NodeBST.hpp"

#include <string>
using std::string;

#include <iostream>
using namespace std;

class InputOutput
{
public:
    InputOutput();
    ~InputOutput();
    string askName(int num);
    
    void printStatistics(int total, int sum, int leaves, int depth, int avg, int t, int smaller, int bigger, int maxSum);
    
    void printListSum(ListSum* l, ListSum* r);
    
    void printT2(NodeBST* n);
    void inorderT2(NodeBST* n);

};

#endif // INPUTOUTPUT_HPP
