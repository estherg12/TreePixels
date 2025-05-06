# TreePixels
Image Manipulation with BST

The program will execute two phases.
1. The first phase will allow to the user to input two image names that will be used for input, and will load these images, each one in one queue of pixel objects. All pixel objects must include a field (named sumRGB) with sum of the values of R, G and B attributes of the pixel.

2. The second phase will be in charge of executing some task in background, producing some time measures along the process and printing some statistical data.

These task are grouped in three groups. Time consumption must be printed for the whole phase, for every group and for every task. 
  Group 1: Image 1 trees. Using the values of the queue from file 1, a binary ordered tree (named T1) have to be created using the sumRGB value as ordering criteria. Pixels with the same value will be stored in a list associated with the tree node with that sumRGB value. All nodes will contain a field originFile with value 1.
    • After creating the tree and printing the time dedicated to it, some statistical values must be calculated and printed: maximum tree depth, node with the maximum number of elements and others considered.
    • After statistical data, two list of numbers must be printed, a list with the values from 0 to 765 that have a node in the list, and the list of values that do not have a node. Using the values of the tree T1, a binary balanced ordered tree (named T2) have to be created using the sumRGB value as ordering criteria. All nodes will contain a field originFile with value 1.
    • After creating the tree and printing the time dedicated to it, some statistical values must be calculated and printed: maximum tree depth, node with the maximum number of elements and others considered.

  Group 2: Image 2 addition. Using the values of the queue from file 2, more pixels will be added to the binary ordered tree (named T1) and the binary balanced ordered tree (named T2). The nodes will be added to the list of pixels of existing nodes. If one pixel from file 2 contains a sumRGB value that is not yet on the trees, it will be discarded. All nodes will contain a field originFile with value 2.
  After modifying the tree and printing the time dedicated to it, some statistical values must be calculated and printed: maximum tree depth (should remain the
same), node with the maximum number of elements and others considered.

  Group 3: output files. An image of same dimensions as image 1 will be generated and saved on disk. This image will contains only the pixels found in nodes of the tree T1 where there are more pixels with a value 1 in originFile and the rest of the pixels with black color. An image of same dimensions as image 2 will be generated and saved on disk. This image will contains only the pixels found in nodes of the tree T1 and the rest of the pixels with black color. An image of same dimensions as image 2 will be generated and saved on disk. This image will contains only the pixels found in nodes of the tree T2 and the rest of the pixels with black color.

  As final reflection, groups have to propose reasoning about the time consumption of every operation, enhancements to the process, types of trees or any other aspect of this program that they considered. Time measures can help to identify the aspects that could be candidates for enhancement.

