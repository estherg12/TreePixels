#ifndef CORE_HPP
#define CORE_HPP
#include <chrono>
#include <iostream>
using namespace std;
#include "Pixel.hpp"
#include "Image.hpp"
#include "InputOutput.hpp"
#include "Queue.hpp"
#include "NodeBST.hpp"
#include "BST.hpp"
#include "List.hpp"
#include "ElementList.hpp"
#include "ListSum.hpp"
#include "ElementListSum.hpp"
#include "ElementQueue.hpp"
#include "ListOfList.hpp"
#include "ElementListOfList.hpp"
#include "Statistics.hpp"

class Core
{
    Queue* queue1 = nullptr;
    Queue* queue2 = nullptr;
    BST* t1 = nullptr;
    BST* t2 = nullptr;
    int width = 0;
    int height = 0;
    int width2 = 0;
    int height2 = 0;
    int counter = 0;
    string file_name1;
    string file_name2;
    
    int getMiddle(int size);
public:
    Core();
    ~Core();
    void start();
    void loadImage(string file_name, int of);
    
    void getStats(BST* t, int cod);//Statistics
    
    //Create T1
    void createT1fromI1(Queue* q1);//from I1
    void addI2toT1(Queue* q2);//add pixels from I2
    
    //Get the lists of the sum RGB that are and aren't on t1 before inserting the pixels of I2
    ListSum* bstToList(NodeBST* n);//O(n)
    void preorderList(NodeBST* n, ListSum* l);//O(n)
    ListSum* restPixToList(ListSum* l); //O(n)
    
    //go through t1 and inserting the content of each node into a List
    ListOfList* bstToListOfList(BST* tree);//gets a tree and creates a list of list with same info
    void preorder(NodeBST* n, ListOfList* l);
    
    //create t2 from the List
    void createT2(ListOfList* l);
    void balanceRec(ElementListOfList* l, NodeBST* n, int s);
    
    void listS1(NodeBST* n, List* e);
    void createS1(BST* t1);
    
    void listS2(NodeBST* n, List* e);
    void createS2(BST* t1);
    
    void createS3(BST* t2);
};

#endif // CORE_HPP
