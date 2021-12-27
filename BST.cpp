#include <iostream>
#include <vector>

class BST{
    public:
        BST();
        ~BST();
        void insertKey(int newKey);
        bool hasKey(int searchKey);
        std::vector<int> inOrder();
        int getHeight();
    private:
      class NodeOfTree {
         public:
            NodeOfTree();
            ~NodeOfTree();
            int nodeKey;
            NodeOfTree* leftNode;
            NodeOfTree* rightNode;

            NodeOfTree* insertKey(NodeOfTree* node, int newKey);
            bool hasKey(NodeOfTree* node, int searchKey);
            int getHeight(NodeOfTree* node);
            std::vector<int> inOrder(NodeOfTree* node, std::vector<int>& nodeData);
      };
      NodeOfTree* binarytree;
};

BST::BST(){
    binarytree = nullptr;
}

BST::~BST(){
   if ( binarytree != nullptr ){
        delete binarytree;
   }
}

void BST::insertKey(int newKey) {
   binarytree = binarytree->insertKey(binarytree, newKey);
}

bool BST::hasKey(int searchKey){
   return binarytree->hasKey(binarytree, searchKey);
}

std::vector<int> BST::inOrder() {
   std::vector<int> OrderdNums;
   return binarytree->inOrder(binarytree, OrderdNums);
}

int BST::getHeight() {
   return binarytree->getHeight(binarytree);
}

BST::NodeOfTree::NodeOfTree() {
}

BST::NodeOfTree::~NodeOfTree() {
   if ( leftNode != nullptr ){ 
      delete leftNode;
   }
   if ( rightNode != nullptr ){
       delete rightNode;
   }

}

BST::NodeOfTree* BST::NodeOfTree::insertKey(NodeOfTree* node, int newKey){
   if(node == nullptr) {
      NodeOfTree* memorynode = new BST::NodeOfTree();
      memorynode->nodeKey = newKey;
      memorynode->leftNode = nullptr;
      memorynode->rightNode = nullptr;
      node = memorynode;

   }
   else if (newKey < node->nodeKey){
      node->leftNode = insertKey(node->leftNode, newKey);
   }
   else if (newKey > node->nodeKey){
      node->rightNode = insertKey(node->rightNode, newKey);
   }
   return node;
}

bool BST::NodeOfTree::hasKey(NodeOfTree* node, int searchKey) { 
   if(node == nullptr){
      return false;
   }
   else if(searchKey < node->nodeKey){
      return node->hasKey(node->leftNode, searchKey);
   }
   else if(searchKey > node->nodeKey){
      return node->hasKey(node->rightNode, searchKey);
   }
   else{
      return true;
   }
}

int BST::NodeOfTree::getHeight(NodeOfTree* node) {
   int leftNvalue;
   int rightNvalue;

   if(node == nullptr){
      return 0;
   }
   else{
      leftNvalue = getHeight(node-> leftNode); 
      rightNvalue = getHeight(node-> rightNode);

      if(leftNvalue > rightNvalue){
         return leftNvalue + 1;
      }
      else{
         return rightNvalue + 1;
      }
   }
}

std::vector<int> BST::NodeOfTree::inOrder(NodeOfTree * node, std::vector<int>& nodeData) 
{
   if(node != nullptr) {
      inOrder(node->leftNode, nodeData);
      nodeData.push_back(node->nodeKey);
      inOrder(node->rightNode, nodeData);
   }
   return nodeData;
}

void printTreeInOrder(BST& binarytree) 
{
   std::vector<int> nodeData = binarytree.inOrder();
   std::cout << "The numbers in sorted order:";
   for (int i = 0; i < nodeData.size(); i++) 
   {
      std::cout << " " << nodeData.at(i);
   }
   std::cout << "\n";
}

int main() 
{
   BST binarytree;
   std::string isInTree;

   std::cout << "Enter the numbers to be stored (end with a letter): \n";
   int numInput;
   
   while(std::cin >> numInput) 
   {
      binarytree.insertKey(numInput);
   }
   std::cin.clear(); 
   std::cin.ignore();

   std::cout << "Which number do you want to look up? \n";
   std::cin >> numInput;

   if(binarytree.hasKey(numInput))
   {
      isInTree = "yes";
   }
   else{
      isInTree = "no";
   }

   std::cout << numInput << " is in the tree: " << isInTree << "\n";
   printTreeInOrder(binarytree);

   std::cout << "Height of the tree: " << binarytree.getHeight() << "\n";

   return 0;
}