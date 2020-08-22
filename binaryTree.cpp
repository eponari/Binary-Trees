#include <iostream>
#include "treeClass.h"

using namespace std;
int main(){
  Tree myTree;
  myTree.insertion(4);
  myTree.insertion(2);
  myTree.insertion(1);
  myTree.insertion(3);
  myTree.insertion(5);
  myTree.insertion(9);
  myTree.insertion(7);
  myTree.insertion(8);
  cout<<"The average depth of the tree is "<<myTree.averageDepth()<<"\n";
  cout<<"The longest path of the tree is "<<myTree.findLongestRoute()<<"\n";
  cout<<"The shortest path of the tree is "<<myTree.findShortestRoute()<<"\n";
  cout<<"The largest sum of a path in the tree is "<<myTree.largestPathSum()<<"\n";	
  cout<<"The smallest sum of a path in the tree is "<<myTree.smallestPathSum()<<"\n";
}
