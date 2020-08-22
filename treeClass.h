#include <iostream>
using namespace std;

struct treeNode{
    int value;
    treeNode* left=NULL;
    treeNode* right=NULL;
    treeNode(int value){
        this->value=value;
    }
};

class Tree{
    private:
        static treeNode* root;
    public:
        //Constructor
        Tree(){
          root=NULL;
        }
        //every function below follows a partition and recursive solution to each problem.
        void insertion(int value,treeNode* currentRoot=root){
          //if we find a NULL value means that we have a free space and we can insert a treeNOde
          if(currentRoot==NULL){
              *currentRoot=treeNode(value);
              return;
          }
          //In binary trees we ignore the same value twice
          else if((*currentRoot).value==value){
              return;
          }
          //search for free place according to value
          else if(value<(*currentRoot).value){
              insertion(value,((*currentRoot).left));
          }
          else{
              insertion(value,((*currentRoot).right));
          }        
        }
        //counts nodes in our tree
        int countNodes(treeNode* currentRoot=root){
          if(currentRoot==NULL){
            return 0;
          }
          return 1+countNodes(currentRoot->left)+countNodes(currentRoot->right);
        }
        //counts nodes that don't have any child node
        int countLeaves(treeNode* currentRoot=root){
          if(currentRoot==NULL){
            return 0;
          }
          if(currentRoot->left==NULL&&currentRoot->right==NULL){
            return 1;
          }
          return countLeaves(currentRoot->left)+countLeaves(currentRoot->right);
        }
        //finds the sum of all leaf treeNodes
        int sumOfLeaves(treeNode* currentRoot=root){
          if(currentRoot==NULL){
            return 0;
          }
          if(currentRoot->left==NULL&&currentRoot->right==NULL){
            return currentRoot->value;
          }
          return countLeaves(currentRoot->left)+countLeaves(currentRoot->right);
        }
        //returns the length of the longest route to take in our binary tree from root to leaf
        int findLongestRoute(treeNode* currentRoot=root){
          if(currentRoot==NULL){
            return 0;
          }
          return 1+max(findLongestRoute(currentRoot->left),findLongestRoute(currentRoot->right));
        }

        //returns the length of the shortest route to take in our binary tree from root to leaf
        int findShortestRoute(treeNode* currentRoot=root){
          if(currentRoot==NULL){
            return 0;
          }
          return 1+max(findShortestRoute(currentRoot->left),findShortestRoute(currentRoot->right));
        }
        //finds the path with the maximum sum of treeNodes
        int largestPathSum(treeNode* currentRoot=root){
          if(currentRoot==NULL){
            return 0;
          }
          return currentRoot->value+max(largestPathSum(currentRoot->left),largestPathSum(currentRoot->right));
        }
        
        //finds the path with the minimum sum of treeNodes
        int smallestPathSum(treeNode* currentRoot=root){
          if(currentRoot==NULL){
            return 0;
          }
          return currentRoot->value+min(smallestPathSum(currentRoot->left),smallestPathSum(currentRoot->right));
        }
        //returns the sum of the depths of each treeNode
        int findCumulativeDepth(treeNode* currentRoot=root,int depth=0){
          if(currentRoot==NULL){
            return 0;
          }
          return depth+findCumulativeDepth(currentRoot->left,depth+1)+findCumulativeDepth(currentRoot->right,depth+1);
        }
        //uses 2 functions above to find the average depth in the Tree
        double averageDepth(){
          int totalNodes=countNodes();
          if(totalNodes==0){
            return 0;
          }
          return findCumulativeDepth()/totalNodes;
        }
};

treeNode* Tree::root=NULL;
