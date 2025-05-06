#include "Core.hpp"
#include <chrono>
#include <iostream>
using namespace std;

Core::Core()
{
    queue1 = nullptr;
    queue2 = nullptr;
    t1 = nullptr;
    t2 = nullptr;
    width = 0;
    height = 0;
    width2 = 0;
    height2 = 0;
    counter = 0;
    file_name1 = "";
    file_name2 = "";
}

Core::~Core()
{
}

void Core::start()
{
    //inicialize the queues so that front is nullptr
    this->queue1 = new Queue();
    this->queue2 = new Queue();
    
    InputOutput* io = nullptr;
    
    //ask for the first file name
    file_name1 = io->askName(1);
    loadImage(file_name1, 1);
    
    createT1fromI1(queue1);
    ListOfList* list1 = bstToListOfList(t1);
    createT2(list1);
    //io->printT2(t2->getRoot());
    getStats(t2, 2);//tree 2 with just image 1
    
    //ask for the second file name
    file_name2 = io->askName(2);
    loadImage(file_name2, 2);
    
    addI2toT1(queue2);
    ListOfList* list2 = bstToListOfList(t1);
    createT2(list2);
    //io->printT2(t2->getRoot());
    getStats(t2, 4);//tree 2 with image 1 and 2
    
    //Create Image Solution 1
    createS1(t1);
    
    //Create Image Solution 2
    createS2(t1);
    
    //Create Image Solution 3
    createS3(t2);
}

void Core::loadImage(string file_name, int of)
{
    //string file_name;//call IO method which shows the posible images to choose
    Image* img = new Image(file_name + ".bmp");
    cout<<"Image well created"<<endl;
    img->loadImageFromDisk();
    cout<<"Image loaded from the disk"<<endl;
    
    if(img->isValid())
    {
        cout<<"Image is valid"<<endl;
        
        for (int x=0; x<img->getWidth(); x++)
        {
            for (int y=0; y<img->getHeight(); y++)
            {
                if (of == 1)
                {
                    Pixel* pp = new Pixel(x,y,1);
            
                    // load RGB values from raw image data loaded with malloc
                    pp->getFromRaw(img->getImagePointertoInternal(),img->getWidth(),img->getHeight(),x,y); // pointer to pixel class
                    if (pp->isNotBlack()) 
                    {
                        queue1->enqueue(pp);
                        //cout<<"Is queuePx empty (0): "<<queuePx->isEmpty()<<endl;
                    }
                } 
                else
                {
                    if(of == 2)
                    {
                        Pixel* p = new Pixel(x,y,2);
            
                        // load RGB values from raw image data loaded with malloc
                        p->getFromRaw(img->getImagePointertoInternal(),img->getWidth(),img->getHeight(),x,y); // pointer to pixel class
                        if (p->isNotBlack()) 
                        {
                            queue2->enqueue(p);
                            //cout<<"Is queuePx empty (0): "<<queuePx->isEmpty()<<endl;
                        }
                    }
                }
                
                
            }
        }
        
        if(of == 1)
        {
            //save the width and height of the image in the variable of the class so that other methods have access to them
            width = img->getWidth();  
            height = img->getHeight();
        }
        else
        {
            if(of == 2)
            {
                //save the width and height of the image in the variable of the class so that other methods have access to them
                width2 = img->getWidth();  
                height2 = img->getHeight();
            }
        }
        
        
    }
    else
    {
        cout<<"Could not load the image: "<<img->getInternalError()<<endl;
    }
}

void Core::getStats(BST* t, int cod)
{
    cout<<endl<<"======================================================================"<<endl;
    Statistics* st = new Statistics();
    
    cout<<"Calculating Statistics"<<endl;
    
    auto start1 = std::chrono::high_resolution_clock::now();//start chrono
    NodeBST* me = st->maxElements(t->getRoot());//node with max elements
    auto end1 = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration1 = end1 - start1; //calculate the duration
    cout<<"Time taken to get node with max elements: "<<duration1.count()<<" seconds."<<endl;
    
    int total = st->countElements(me);//total of elements the node with max elements has
    int sum = me->getSumRGB();//the sum RGB from node with max elements
    
    auto start2 = std::chrono::high_resolution_clock::now();//start chrono
    int leaves = st->countLeaves(t->getRoot());//number of leaves
    auto end2 = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration2 = end2 - start2; //calculate the duration
    cout<<"Time taken to count leaves: "<<duration2.count()<<" seconds."<<endl;
    
    auto start3 = std::chrono::high_resolution_clock::now();//start chrono
    int depth = st->depth(t->getRoot());//depth
    auto end3 = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration3 = end3 - start3; //calculate the duration
    cout<<"Time taken to calculate depth: "<<duration3.count()<<" seconds."<<endl;
    
    auto start4 = std::chrono::high_resolution_clock::now();//start chrono
    int avg = st->avg(t->getRoot());//avg sumRGB
    auto end4 = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration4 = end4 - start4; //calculate the duration
    cout<<"Time taken to calculate average sum RGB: "<<duration4.count()<<" seconds."<<endl;
    
    auto start5 = std::chrono::high_resolution_clock::now();//start chrono
    int s5 = st->smallestSum(t->getRoot()); //minimum node
    int b5 = st->biggestSum(t->getRoot());//maximum node
    auto end5 = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration5 = end5 - start5; //calculate the duration
    cout<<"Time taken to calculate minimum and maximum nodes: "<<duration5.count()<<" seconds."<<endl;
    
    auto start6 = std::chrono::high_resolution_clock::now();//start chrono
    int maxSum = st->getMax(t->getRoot());
    auto end6 = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration6 = end6 - start6; //calculate the duration
    cout<<"Time taken to calculate minimum and maximum nodes: "<<duration6.count()<<" seconds."<<endl;
    
    InputOutput* io = new InputOutput();
    io->printStatistics(total, sum, leaves, depth, avg, cod, s5, b5, maxSum);
}

void Core::createT1fromI1(Queue* qOriginal1)
{
    cout<<"======================================================================"<<endl;
    cout<<"Creating T1"<<endl;
    auto start = std::chrono::high_resolution_clock::now();//start chrono
    //we will be using this queue as an auxiliar so that we can dequeue the original queue to ge the elements but then it will be restored
    Queue* sameQ1 = new Queue();
    
    this->t1 = new BST();//initialize the tree 1
    
    while(!(qOriginal1->isEmpty()))
    {
        Pixel* opx = qOriginal1->getFront();
        sameQ1->enqueue(opx);//enqueue the pixel in the auxiliar queue
    
        t1->insert(opx);//insert the pixels in order
        qOriginal1->dequeue();
    }
    
    //Lists of nodes from T1 Image1
    ListSum* l = bstToList(t1->getRoot());
    ListSum* r = restPixToList(l);
    InputOutput* io = new InputOutput();
    io->printListSum(l, r);
    
    //STATISTICS
    getStats(t1, 1);//tree 1 with just image 1
    
    //Restore the original queue from image 1 with sameQ1
    while(!sameQ1->isEmpty())
    {
        Pixel* samepx = sameQ1->getFront();
        qOriginal1->enqueue(samepx);
        sameQ1->dequeue();
    }
    
    auto end = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration = end - start; //calculate the duration
    cout<<"Time taken to create T1: "<<duration.count()<<" seconds."<<endl;
}

void Core::addI2toT1(Queue* qOriginal2)
{
    auto start = std::chrono::high_resolution_clock::now();//start chrono
    
    //we will be using this queue as an auxiliar so that we can dequeue the original queue to ge the elements but then it will be restored
    Queue* sameQ2 = new Queue();
    
    //Image 2: insert only the pixels which sum RGB is already in t1 (from I1)
    while(!(qOriginal2->isEmpty()))
    {
        Pixel* opx = qOriginal2->getFront();
        sameQ2->enqueue(opx);
        if(t1->search(opx->getSumRGB(), t1->getRoot())) //search the sumRGB in t1
        {
            //if sum RGB of the pixel from I2 is already in t1 (from I1), this pixel is inserted in t1
            t1->insert(opx);//this will go to Case 3: inserting the pixel into the list of an existing node
        }
        qOriginal2->dequeue();
    }
    
    //Restore the original queue from image 2 with sameQ2
    while(!sameQ2->isEmpty())
    {
        Pixel* samepx = sameQ2->getFront();
        qOriginal2->enqueue(samepx);
        sameQ2->dequeue();
    }
    
    //STATISTICS
    getStats(t1, 3); //tree 1 with image 1 and 2
    
    auto end = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration = end - start; //calculate the duration
    cout<<"Time taken to create T1: "<<duration.count()<<" seconds."<<endl;
}

ListSum* Core::bstToList(NodeBST* n)
{
    ListSum* l = new ListSum();
    preorderList(n, l);//O(n)
    return l;
}

void Core::preorderList(NodeBST* n, ListSum* l)
{
    if(n != nullptr)
    {
        l->insertLast(n->getSumRGB());//O(n)
        preorderList(n->getLeftChild(), l);
        preorderList(n->getRightChild(), l);
    }
}

ListSum* Core::restPixToList(ListSum* l)
{
    ListSum* r = new ListSum();
    for(int i = 0; i<766; i++)
    {
        if (!(l->search(i)))
        {
            //i not in T1
            r->insertLast(i); //O(n)
        }
    }
    return r;
}

ListOfList* Core::bstToListOfList(BST* t1)
{
    auto start = std::chrono::high_resolution_clock::now();//start chrono
    
    ListOfList* l = new ListOfList();
    NodeBST* temp = t1->getRoot();
    preorder(temp, l); //initial case
    
    auto end = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration = end - start; //calculate the duration
    cout<<"Time taken to create ListOfList from T1: "<<duration.count()<<" seconds."<<endl;
    
    return l;
}

void Core::preorder(NodeBST* n, ListOfList* l)
{
    if(n != nullptr) //exit case
    {
        //insert the content of the node into the element of list of list
        List* list = n->getList();
        int sum = n->getSumRGB();
        l->insert(sum, list);
        
        //Recursivity
        preorder(n->getLeftChild(), l);
        preorder(n->getRightChild(), l);
    }
}

void Core::createT2(ListOfList* list)
{
    cout<<"======================================================================"<<endl;
    cout<<"Creating T2"<<endl;
    auto start = std::chrono::high_resolution_clock::now();//start chrono
    
    //initial case
    this->t2 = new BST();
    NodeBST* node = new NodeBST();
    this->t2->setRoot(node);
    int size = list->getSize();
    ElementListOfList* header = list->getHeader();
    
    balanceRec(header, node, size);
    
    cout<<"T2 root: "<<t2->getRoot()->getSumRGB()<<endl;
    
    auto end = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration = end - start; //calculate the duration
    cout<<"Time taken to create T2: "<<duration.count()<<" seconds."<<endl;
}

int Core::getMiddle(int size)
{
    int middle = 0;
    if(size > 0) //not empty
    {
        if((size%2) == 0) //even number of elements
        {
            middle = size/2;
        }
        else
        {
            middle = (size+1)/2;
        }
    }
    return middle;
}

void Core::balanceRec(ElementListOfList* list, NodeBST* node, int size) 
{
    if (size > 1)
    {
        ElementListOfList* temp = list;
        int middle = getMiddle(size);
        for(int i=1; i<middle; i++)
        {
            temp=temp->getNext();
        }
        
        ElementListOfList* pivot = temp->getNext();
        
        if (size > 2)
        {
            //General case
            NodeBST* leftChild = new NodeBST();
            NodeBST* rightChild = new NodeBST();
        
            node->setRightChild(rightChild);
            node->setLeftChild(leftChild);
            node->setList(temp->getList());
            node->setSumRGB(temp->getSumRGB());
            
            //Recursive from the left part of the middle
            temp = nullptr;//cut the list before the middle element
            balanceRec(list, leftChild, middle-1); //does this work
                
            //Recursive from the right part of the middlee
            balanceRec(pivot, rightChild, size-middle);
        }
        else
        {
            if(size == 2)
            {
                //Case 2: 2 elements in the ListOfList
                NodeBST* rightChild = new NodeBST();
                
                node->setLeftChild(nullptr);
                node->setRightChild(rightChild);
                node->setList(temp->getList());
                node->setSumRGB(temp->getSumRGB());
                
                balanceRec(pivot, rightChild, size-middle);
            }
        } 
    }
    else
    {
        if (size == 1)
        {
            //Case 1: only 1 element in List -> leaf
            node->setList(list->getList());
            node->setSumRGB(list->getSumRGB());
            node->setRightChild(nullptr);
            node->setLeftChild(nullptr);
        }
    }
    
}

void Core::listS1(NodeBST* n, List* e)
{
    if( n != nullptr)
    {
        listS1(n->getLeftChild(), e);
        listS1(n->getRightChild(), e);
        if(n->getList()->hasMoreOnes())
        {
            ElementList* temp = n->getList()->getHeader();
            while(temp != nullptr)//O(n2)
            {
                if(temp->getPixel()->getOriginFile() == 1)
                {
                    e->insertLast(temp->getPixel());//O(n)
                }
                temp = temp->getNext();
            }
        }
    }
}

void Core::createS1(BST* t1)
{
    cout<<"======================================================================"<<endl;
    cout<<"Creating Image 1"<<endl;
    auto start = std::chrono::high_resolution_clock::now();//start chrono
    
    //Get the elements from Image 1 in T1 that will be inserted in the solution image in a list
    NodeBST* n = t1->getRoot();
    List* listT1 = new List();
    listS1(n, listT1); //O(n2)
    
    //Create the list of the size of the image with pixels
    List* s1 = new List();
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            Pixel* px = new Pixel(i,j,0,0,0,1);
            s1->insertLast(px); //O(n)
        }
    }
    
    //add elements from listT1 in the solution list
    ElementList* temp = listT1->getHeader();
    while(temp != nullptr) //O(n2)
    {
        int x = temp->getPixel()->getX();
        int y = temp->getPixel()->getY();
        int pos = (x*(height)) + y;
        
        ElementList* tempS1 = s1->findPosition(pos);//O(n)
        
        Pixel* px = temp->getPixel();
        
        //access the values
        unsigned char r = px->getR();
        unsigned char g = px->getG();
        unsigned char b = px->getB();
        
        Pixel* newPx = new Pixel(px->getX(), px->getY(), r, g, b, 1); //create a new pixel with same values
        tempS1->setPixel(newPx);
        
        temp = temp->getNext();
    }
    
    //Create the queue that will be used to create the new image
    ElementList* aux = s1->getHeader();
    Queue* qS1 = new Queue();
    while(aux != nullptr) //O(n)
    {
        qS1->enqueue(aux->getPixel());
        aux=aux->getNext();
    }
    s1->makenull();
    
    //Create the new image with the created queue
    unsigned char* imageRaw = (unsigned char *)malloc(sizeof(unsigned char) * this->width * this->height * 3);
    
    //insert each pixel from qFlip in the new image
    while(!qS1->isEmpty())
    {
        Pixel* p = qS1->getFront();
        int x = p->getX();
        int y = p->getY();
        p->setIntoRaw(imageRaw, this->width, this->height, x, y);
        qS1->dequeue();
    }
    
    Image* myImg= new Image("");
    myImg->setNewImagePointerWithOldRemoval(imageRaw,this->width,this->height);
    //saves the new image with the same file name, the counter of the operations that have been done in the execution, and the letter that represents this operation
    myImg->saveImageToDisk(file_name1 + std::to_string(this->counter) + "1.bmp"); //saves the new image to disk
    cout<<"Image 1 saved"<<endl;
    
    auto end = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration = end - start; //calculate the duration
    cout<<"Time taken to create Image Solution 1: "<<duration.count()<<" seconds."<<endl;
}

void Core::listS2(NodeBST* n, List* e)
{
    if(n != nullptr)
    {
        ElementList* temp = n->getList()->getHeader();
        while(temp != nullptr)
        {
            if(temp->getPixel()->getOriginFile() == 2)
            {
                e->insertLast(temp->getPixel());//insert each element from origin file 2 from each element in new list
            }
            temp = temp->getNext();
        }
        listS2(n->getLeftChild(), e);
        listS2(n->getRightChild(), e);
    }
}

void Core::createS2(BST* t1)
{
    cout<<"======================================================================"<<endl;
    cout<<"Creating Image 2"<<endl;
    auto start = std::chrono::high_resolution_clock::now();//start chrono
    
    //Get the elements from Image 1 in T1 that will be inserted in the solution image in a list
    NodeBST* n = t1->getRoot();
    List* listT1 = new List();
    
    listS2(n, listT1);
    
    //Create the list of the size of the image with pixels
    List* s2 = new List();
    
    for(int i = 0; i < height2; i++)
    {
        for(int j = 0; j < width2; j++)
        {
            Pixel* px = new Pixel(i,j,0,0,0,2);
            s2->insertLast(px);
        }
    }
    
    //add elements from listT1 in the solution list
    ElementList* temp = listT1->getHeader();
    while(temp != nullptr)
    {
        int x = temp->getPixel()->getX();
        int y = temp->getPixel()->getY();
        int pos = (x*(height2)) + y;
        
        ElementList* tempS2 = s2->findPosition(pos);
        
        Pixel* px = temp->getPixel();
        
        //access the values
        unsigned char r = px->getR();
        unsigned char g = px->getG();
        unsigned char b = px->getB();
        
        Pixel* newPx = new Pixel(px->getX(), px->getY(), r, g, b, 2); //create a new pixel with same values
        tempS2->setPixel(newPx);
        
        temp = temp->getNext();
    }
    
    //Create the queue that will be used to create the new image
    ElementList* aux = s2->getHeader();
    Queue* qS2 = new Queue();
    while(aux != nullptr)
    {
        qS2->enqueue(aux->getPixel());
        aux=aux->getNext();
    }
    s2->makenull();
    
    //Create the new image with the created queue
    unsigned char* imageRaw = (unsigned char *)malloc(sizeof(unsigned char) * this->width2 * this->height2 * 3);
    
    //insert each pixel from qFlip in the new image
    while(!qS2->isEmpty())
    {
        Pixel* p = qS2->getFront();
        int x = p->getX();
        int y = p->getY();
        p->setIntoRaw(imageRaw, this->width2, this->height2, x, y);
        qS2->dequeue();
    }
    
    Image* myImg= new Image("");
    myImg->setNewImagePointerWithOldRemoval(imageRaw,this->width2,this->height2);
    //saves the new image with the same file name, the counter of the operations that have been done in the execution, and the letter that represents this operation
    myImg->saveImageToDisk(file_name2 + std::to_string(this->counter) + "2.bmp"); //saves the new image to disk
    cout<<"Image 2 saved"<<endl;
    
    auto end = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration = end - start; //calculate the duration
    cout<<"Time taken to create Image Solution 2: "<<duration.count()<<" seconds."<<endl;
    
}

void Core::createS3(BST* t2)
{
    cout<<"======================================================================"<<endl;
    cout<<"Creating Image 3"<<endl;
    auto start = std::chrono::high_resolution_clock::now();//start chrono
    
    //Get the elements from Image 1 in T1 that will be inserted in the solution image in a list
    NodeBST* n = t2->getRoot();
    List* listT2 = new List();
    
    listS2(n, listT2);
    
    //Create the list of the size of the image with pixels
    List* s3 = new List();
    
    for(int i = 0; i < height2; i++)
    {
        for(int j = 0; j < width2; j++)
        {
            Pixel* px = new Pixel(i,j,0,0,0,2);
            s3->insertLast(px);
        }
    }
    
    //add elements from listT1 in the solution list
    ElementList* temp = listT2->getHeader();
    while(temp != nullptr)
    {
        int x = temp->getPixel()->getX();
        int y = temp->getPixel()->getY();
        int pos = (x*(height2)) + y;
        
        ElementList* tempS3 = s3->findPosition(pos);
        
        Pixel* px = temp->getPixel();
        
        //access the values
        unsigned char r = px->getR();
        unsigned char g = px->getG();
        unsigned char b = px->getB();
        
        Pixel* newPx = new Pixel(px->getX(), px->getY(), r, g, b, 2); //create a new pixel with same values
        tempS3->setPixel(newPx);
        
        temp = temp->getNext();
    }
    
    //Create the queue that will be used to create the new image
    ElementList* aux = s3->getHeader();
    Queue* qS3 = new Queue();
    while(aux != nullptr)
    {
        qS3->enqueue(aux->getPixel());
        aux=aux->getNext();
    }
    s3->makenull();
    
    //Create the new image with the created queue
    unsigned char* imageRaw = (unsigned char *)malloc(sizeof(unsigned char) * this->width2 * this->height2 * 3);
    
    //insert each pixel from qFlip in the new image
    while(!qS3->isEmpty())
    {
        Pixel* p = qS3->getFront();
        int x = p->getX();
        int y = p->getY();
        p->setIntoRaw(imageRaw, this->width2, this->height2, x, y);
        qS3->dequeue();
    }
    
    Image* myImg= new Image("");
    myImg->setNewImagePointerWithOldRemoval(imageRaw,this->width2,this->height2);
    //saves the new image with the same file name, the counter of the operations that have been done in the execution, and the letter that represents this operation
    myImg->saveImageToDisk(file_name2 + std::to_string(this->counter) + "3.bmp"); //saves the new image to disk
    cout<<"Image 3 saved"<<endl;
    
    auto end = std::chrono::high_resolution_clock::now();//finish chrono
    std::chrono::duration<double> duration = end - start; //calculate the duration
    cout<<"Time taken to create Image Solution 3: "<<duration.count()<<" seconds."<<endl;
    
}
    