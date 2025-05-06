#include "Statistics.hpp"
#include <chrono>
#include <iostream>
#include <algorithm>
using namespace std;

Statistics::Statistics()
{
}

Statistics::~Statistics()
{
}

int Statistics::countLeaves(NodeBST* n)
{
    int result = 0;
    if (n != nullptr)
    {
        if(isLeaf(n)) //O(n)
        {
            result++; //counter of the leaves
        }
        else
        {
            result = countLeaves(n->getLeftChild()) + countLeaves(n->getRightChild()); //recursivity
        }
    }
    return result;
}

bool Statistics::isLeaf(NodeBST* n)
{
    bool result = false;
    if((n->getLeftChild() == nullptr) && (n->getRightChild() == nullptr))
    {
        //if the node has no right or left child is a leaf
        result = true;
    }
    return result;
}

NodeBST* Statistics::maxElements(NodeBST* n)
{
    NodeBST* result = n;
    if (n != nullptr)
    {
        int res = countElements(n);
        
        NodeBST* nL = maxElements(n->getLeftChild());
        NodeBST* nR = maxElements(n->getRightChild());
        
        if((nL != nullptr) && (nR != nullptr))
        {
            int resL = countElements(nL);
            int resR = countElements(nR);
            
            if(resL > resR)
            {
                if(resL > res)
                {
                    result = nL;
                }
            }
            else
            {
                if(resR > resL)
                {
                    if (resR > res)
                    {
                        result = nR;
                    }
                }
            }
        }
        
        else
        {
            if(nL != nullptr)
            {
                int resL = countElements(nL);
                
                if(resL > res)
                {
                    result = nL;
                }
            }
            
            if(nR != nullptr)
            {
                int resR = countElements(nR);
                
                if (resR > res)
                {
                    result = nR;
                }
            }
        }
    }
    return result;
}

int Statistics::countElements(NodeBST* n)
{
    int counter = 0;
    ElementList* temp = n->getList()->getHeader();
    while(temp != nullptr)
    {
        counter++;
        temp = temp->getNext();
    }
    return counter;
}

int Statistics::depth(NodeBST* n)
{
    int result = 0;
    
    if(n != nullptr)
    {
        int lDepth = depth(n->getLeftChild());
        int rDepth = depth(n->getRightChild());
        result = max(lDepth, rDepth) +1;
    }
    
    return result;
}

int Statistics::avg(NodeBST* n)
{
    int result = 0;
    if(n != nullptr)
    {
        int total = avgRec(n);
        int nodes = countNodes(n);
        result = total / nodes;
    }
    return result;//initial case
}

int Statistics::avgRec(NodeBST* n)
{
    int result = 0;
    if (n != nullptr)
    {
        result = n->getSumRGB() + avgRec(n->getLeftChild()) + avgRec(n->getRightChild());
    }
    return result; //return the total sum of the sumsRGB
}

int Statistics::countNodes(NodeBST* n)
{
    int result = 0;
    if(n != nullptr)
    {
        int l = countNodes(n->getLeftChild());
        int r = countNodes(n->getRightChild());
        
        result = 1 + l + r;
    }
    return result;
}

int Statistics::smallestSum(NodeBST* n)
{
    int result = 0;
    if(n != nullptr)
    {
        if(n->getLeftChild() != nullptr)
        {
            smallestSum(n->getLeftChild());
        }
        else
        {
            result = n->getSumRGB();
        }
    }
    return result;
}

int Statistics::biggestSum(NodeBST* n)
{
    int result = 0;
    if(n != nullptr)
    {
        if(n->getRightChild() != nullptr)
        {
            biggestSum(n->getRightChild());
        }
        else
        {
            result = n->getSumRGB();
        }
    }
    return result;
}

int Statistics::getMaxSum(NodeBST* n)
{
    int result = 0;
    
    if(n != nullptr)
    {
        //n is current node
        int incl = n->getSumRGB();
        
        if(n->getLeftChild() != nullptr)
        {
            //if left child exists, sum contribution
            incl += getMaxSum(n->getLeftChild()->getLeftChild()) + getMaxSum(n->getLeftChild()->getRightChild());
        }
        
        if(n->getRightChild() != nullptr)
        {
            //If right child exists, sum contribution
            incl += getMaxSum(n->getRightChild()->getLeftChild()) + getMaxSum(n->getRightChild()->getRightChild());
        }
        
        //Calculate the maximum sum
        int excl = 0;
        
        if(n->getLeftChild() != nullptr)
        {
            excl += getMaxSum(n->getLeftChild());
        }
        
        if(n->getRightChild() != nullptr)
        {
            excl += getMaxSum(n->getRightChild());
        }
        
        result = max(incl, excl);
    }
    return result;
}

int Statistics::getMax(NodeBST* n)
{
    int result = 0;
    if(n != nullptr)
    {
        result = getMaxSum(n);
    }
    return result;
}