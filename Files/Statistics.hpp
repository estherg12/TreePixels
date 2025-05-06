#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include "Pixel.hpp"
#include "Image.hpp"
#include "InputOutput.hpp"
#include "Queue.hpp"
#include "NodeBST.hpp"
#include "BST.hpp"
#include "List.hpp"
#include "ElementList.hpp"
#include "ElementQueue.hpp"
#include "ListOfList.hpp"
#include "ElementListOfList.hpp"

#include <chrono>
#include <iostream>
using namespace std;

class Statistics
{
public:
    Statistics();
    ~Statistics();
    
    int countLeaves(NodeBST* n);//O(n)
    bool isLeaf(NodeBST* n);
    
    NodeBST* maxElements(NodeBST* n);//O(n)
    int countElements(NodeBST* n);
    
    int depth(NodeBST* n);//O(n)
    
    int avg(NodeBST* n);
    int avgRec(NodeBST* n);
    int countNodes(NodeBST* n);
    
    int smallestSum(NodeBST* n);
    int biggestSum(NodeBST* n);
    
    int getMaxSum(NodeBST* n);
    int getMax(NodeBST* n);
};

#endif // STATISTICS_HPP
