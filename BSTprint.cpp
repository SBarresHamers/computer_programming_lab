#include <iostream>
#include <vector>
#include <iomanip>


const std::string verticalWall = "|";
const char horizontalWall = '-';
const char noWall = ' ';
const std::string noSpace = "";
const std::string initialValue = "&";


class BST {
   public:
      BST();
      ~BST();

      void insertKey(int newKey) { BstPrettyprint = BstPrettyprint->insertKey(BstPrettyprint, newKey); };
      bool hasKey(int searchKey) { return BstPrettyprint->hasKey(BstPrettyprint, searchKey); };
      std::vector<int> inOrder() { std::vector<int> nodeData; return BstPrettyprint->inOrder(BstPrettyprint, nodeData); };
      int getHeight()            {return BstPrettyprint->getHeight(BstPrettyprint); };
      void prettyPrint();

   private:
        int height;
        int width;
        int rootOffset;
        int depth = 0;
        
      class Grid {
         public:
            Grid(int  rowNum, int  columns, const std::string characterValue);
            std::string& at( int  row, int  column)                              {return nodeData.at(row).at(column); };
            void newAt(const std::string inputString, int row, int column)       {nodeData.at(row).at(column) = inputString; };
            int rowNum() const                                                   {return nodeData.size(); } ;
            int columns() const                                                  {return nodeData.at(0).size(); };

         private:
            std::vector< std::vector<std::string> > nodeData;
      };

      class nodeOfTree {
         public:
            nodeOfTree();
            ~nodeOfTree();

            nodeOfTree* leftNode;
            nodeOfTree* rightNode;

            nodeOfTree* insertKey(nodeOfTree* node, int newKey);
            bool hasKey(nodeOfTree* node, int searchKey);
            int getHeight(nodeOfTree* node);
            std::vector<int> inOrder(nodeOfTree* node, std::vector<int>& nodeData);
            void treeToGrid(Grid* grid, nodeOfTree* node, int depth, int nSet);
            int rightOffset(nodeOfTree * node);
            int leftOffset(nodeOfTree * node);
            int countChildren(nodeOfTree * node);
            void GridOutput(Grid* grid);
            int setWidht(int column) {return (1+(5*column)); }

            int nodeKey;
            int nLset;
            int nRset;
            int highLeft = 0;
            int highRight = 0;
            int numChilderen= 0;
            
            std::string output;
      };
      nodeOfTree* BstPrettyprint;
      Grid* grid;
};

BST::BST() {
   BstPrettyprint = nullptr;
   grid = nullptr;
}

BST::~BST() {
   if ( BstPrettyprint != nullptr ){
        delete BstPrettyprint;
   }
   if ( grid != nullptr ){
        delete grid;
   }
}

void BST::prettyPrint() {
    height = getHeight();
    width = inOrder().size();

    grid = new Grid(height, width, initialValue);

    rootOffset = BstPrettyprint->countChildren(BstPrettyprint->leftNode);
    BstPrettyprint->treeToGrid(grid, BstPrettyprint, depth, rootOffset);
    BstPrettyprint->GridOutput(grid);
}

BST::Grid::Grid(int rowNum, int columns, std::string characterValue){
    if ( (rowNum == 0) || (columns == 0) ) {
       exit(0);
      }
    nodeData.resize(rowNum);
    for (int row=0; row<rowNum; row++){
        nodeData.at(row).resize(columns, characterValue);
    }
}

BST::nodeOfTree::nodeOfTree() {}

BST::nodeOfTree::~nodeOfTree() {
   if ( leftNode != nullptr ){ 
       delete leftNode;
   }
   if ( rightNode != nullptr ){ 
       delete rightNode;
   }
}

BST::nodeOfTree* BST::nodeOfTree::insertKey(nodeOfTree * node, int newKey) {
   if(node == nullptr) {
      nodeOfTree * memoryNode = new BST::nodeOfTree();
      memoryNode->nodeKey = newKey;
      memoryNode->leftNode = nullptr;
      memoryNode->rightNode = nullptr;
      node = memoryNode;
   }
   else if(newKey < node->nodeKey){
      node->leftNode = insertKey(node->leftNode, newKey);
   }
   else if(newKey > node->nodeKey){
      node->rightNode = insertKey(node->rightNode, newKey);
   }
   return node;
}

bool BST::nodeOfTree::hasKey(nodeOfTree * node, int searchKey) {
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

int BST::nodeOfTree::getHeight(nodeOfTree * node) {
   if(node == nullptr){
      return 0;
    }
   else{
      if(getHeight(node-> leftNode) > getHeight(node-> rightNode)){
         return getHeight(node-> leftNode) + 1;
      }
      else{
         return getHeight(node-> rightNode)+ 1;
      }
   }
}

std::vector<int> BST::nodeOfTree::inOrder(nodeOfTree * node, std::vector<int>& nodeData) {
   if(node != nullptr) {
      inOrder(node->leftNode, nodeData);
      nodeData.push_back(node->nodeKey);
      inOrder(node->rightNode, nodeData);
   }
   return nodeData;
}

int BST::nodeOfTree::countChildren(nodeOfTree * node) {
   if(node == nullptr){
      return 0;
   }
   numChilderen = countChildren(node->leftNode)+countChildren(node->rightNode) + 1;
   return numChilderen;
}

int BST::nodeOfTree::leftOffset(nodeOfTree * node) {
    int numLeft = 0;
   if(node == nullptr){
      return 0;
      }
   if(node->rightNode != nullptr)
   {
       numLeft = countChildren(node->rightNode);
      return numLeft;
   }
   return 0;
}

int BST::nodeOfTree::rightOffset(nodeOfTree * node) {
   if(node == nullptr)
      return 0;
   if(node->leftNode != nullptr)
      return countChildren(node->leftNode);
   return 0;
}

void BST::nodeOfTree::treeToGrid(Grid* grid, nodeOfTree* node, int depth, int nSet) {
   if(node != nullptr) {
      grid->newAt(std::to_string(node->nodeKey), depth, nSet);

      nLset = node->leftOffset(node->leftNode);
      treeToGrid(grid, node->leftNode, depth+1, (nSet-nLset-1));

      nRset = node->rightOffset(node->rightNode);
      treeToGrid(grid, node->rightNode, depth+1, (nSet+nRset+1));
   }
}

void BST::nodeOfTree::GridOutput(Grid* grid) {
   int column = grid->columns();
   int rownum = grid->rowNum();
   

   for (int row=0; row<rownum; row++){
      std::cout << std::setfill(horizontalWall) << std::setw(setWidht(column)) << noSpace << "\n";
      std::cout << verticalWall;
      for (int col=0; col<column; col++){
         std::string value = grid->at(row,col);
         if(value != initialValue){
             output = value;
         }
         else{
             output = noSpace;
         }
         std::cout << std::setfill(noWall) << std::setw(4) << output << verticalWall;
      }
      std::cout << "\n";
   }
   std::cout << std::setfill(horizontalWall) << std::setw(setWidht(column)) << noSpace << "\n";
}

void printTreeInOrder(BST& BstPrettyprint) {
   std::vector<int> nodeData = BstPrettyprint.inOrder();
   for (int i = 0; i < nodeData.size(); i++) {
      std::cout << " " << nodeData.at(i);
   }
   std::cout << "\n";
}

int main() {
   int nodeKey;
   BST BstPrettyprint;

   std::cout << "Enter the numbers to be stored: ";
  
   while(std::cin >> nodeKey)
   BstPrettyprint.insertKey(nodeKey);
   std::cin.clear(); 

   std::cout << "\n";
   std::cout << "The numbers in sorted order:";

   printTreeInOrder(BstPrettyprint);
   BstPrettyprint.prettyPrint();
   
   return 0;
}
