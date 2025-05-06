#include "InputOutput.hpp"

#include <iostream>
using namespace std;

InputOutput::InputOutput()
{
}

InputOutput::~InputOutput()
{
}

string InputOutput::askName(int num)
{
    /*ask for the name of the image file that must be executed
     * returns a string
     */
    string file_name;
    if(num == 1)
    {
        cout<<"Tell me the first file name without the extension: "<<endl;
        cin>>file_name;
    }
    else
    {
        if (num == 2)
        {
            cout<<"Tell me the second file name without the extension: "<<endl;
            cin>>file_name;
        }
    }
    
    
    return file_name;
}

void InputOutput::printStatistics(int total, int sum, int leaves, int depth, int avg, int cod, int smaller, int bigger, int maxSum)
{
    cout<<"======================================================================"<<endl;
    if(cod == 1)
    {
        //T1 with Image 1
        cout<<"STATISTICS from T1 with Image 1"<<endl;
        cout<<"T1 has "<<leaves<<" leaves"<<endl;
        cout<<"The node with maximum elements has a sum RGB value of "<<sum<<" and has a total of "<<total<<" elements (pixels)"<<endl;
        cout<<"The maximun height of T1 (depth) is "<<depth<<endl;
        cout<<"The average sum of RGB values from all nodes in T1 is "<<avg<<endl;
        cout<<"The nodes sum RGB values are between "<<smaller<<" and "<<bigger<<endl;
        cout<<"The maximum sum of nodes in T1 such that no two nodes are adjacent is: "<<maxSum<<endl;
        cout<<"======================================================================"<<endl;
    }
    else
    {
        if(cod == 2)
        {
            //T2 with Image 1
            cout<<"STATISTICS from T2 with Image 1"<<endl;
            cout<<"T2 has "<<leaves<<" leaves"<<endl;
            cout<<"The node with maximum elements has a sum RGB value of "<<sum<<" and has a total of "<<total<<" elements (pixels)"<<endl;
            cout<<"The maximun height of T2 (depth) is "<<depth<<endl;
            cout<<"The average sum of RGB values from all nodes in T2 is "<<avg<<endl;
            cout<<"The nodes sum RGB values are between "<<smaller<<" and "<<bigger<<endl;
            cout<<"The maximum sum of nodes in T2 such that no two nodes are adjacent is: "<<maxSum<<endl;
            cout<<"======================================================================"<<endl;
        }
        else
        {
            if(cod == 3)
            {
                //T1 with Image 1 and Image 2
                cout<<"STATISTICS from T1 with Image 1 and Image 2"<<endl;
                cout<<"T1 has "<<leaves<<" leaves"<<endl;
                cout<<"The node with maximum elements has a sum RGB value of "<<sum<<" and has a total of "<<total<<" elements (pixels)"<<endl;
                cout<<"The maximun height of T1 (depth) is "<<depth<<endl;
                cout<<"The average sum of RGB values from all nodes in T1 is "<<avg<<endl;
                cout<<"The nodes sum RGB values are between "<<smaller<<" and "<<bigger<<endl;
                cout<<"The maximum sum of nodes in T1 such that no two nodes are adjacent is: "<<maxSum<<endl;
                cout<<"======================================================================"<<endl;
            }
            else
            {
                if(cod == 4)
                {
                    //T2 with Image 1 and Image 2
                    cout<<"STATISTICS from T2 with Image 1 and Image 2"<<endl;
                    cout<<"T2 has "<<leaves<<" leaves"<<endl;
                    cout<<"The node with maximum elements has a sum RGB value of "<<sum<<" and has a total of "<<total<<" elements (pixels)"<<endl;
                    cout<<"The maximun height of T2 (depth) is "<<depth<<endl;
                    cout<<"The average sum of RGB values from all nodes in T2 is "<<avg<<endl;
                    cout<<"The nodes sum RGB values are between "<<smaller<<" and "<<bigger<<endl;
                    cout<<"The maximum sum of nodes in T2 such that no two nodes are adjacent is: "<<maxSum<<endl;
                    cout<<"======================================================================"<<endl;
                }
            }
        }
    }
}

void InputOutput::printListSum(ListSum* l, ListSum* r)
{
    cout<<endl<<"======================================================================"<<endl;
    cout<<"LIST WITH NODES FROM TREE 1 IMAGE 1"<<endl;
    ElementListSum* temp1 = l->getHeader();
    while (temp1 != nullptr)
    {
        cout<<temp1->getSum()<<", ";
        temp1 = temp1->getNext();
    }
    
    cout<<endl<<"======================================================================"<<endl;
    cout<<"LIST WITH NODES NOT IN TREE 1 IMAGE 1"<<endl;
    ElementListSum* temp2 = r->getHeader();
    while (temp2 != nullptr)
    {
        cout<<temp2->getSum()<<", ";
        temp2=temp2->getNext();
    }
}

void InputOutput::printT2(NodeBST* n)
{
    cout<<"============================================="<<endl;
    cout<<"T2 in inorder"<<endl;
    inorderT2(n);
}

void InputOutput::inorderT2(NodeBST* n)
{
    if(n != nullptr)
    {
        inorderT2(n->getLeftChild());
        cout<<n->getSumRGB()<<endl;
        inorderT2(n->getRightChild());
    }
}