#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
//..........positionGrids..............................
#define TOP 1
#define BOTTOM 2
#define RIGHT 3
#define LEFT 4
//........... constants ............................
const std::string Corner = "+";
const std::string horizontalWall = "---";
const std::string verticalWall = "|";
const std::string noWall = " ";
const std::string noVerticalWall = "   ";
const std::string Path = " . ";
int X_START = 0;
int Y_START = 0;
int CHAR_START = '&';
const char  cellTop = 'T';
const char  cellBottom = 'B';
const char  cellRight = 'R';
const char  cellLeft = 'L';
const char  cellMazesolver = '!'; 
//.............Global functions.....................
int getXGridSize(int row){
    return (row * 2) + 1;
}
int getYGridSize(int col){
    return (col * 2) + 1;
}

class Cell{

    public:
        Cell();
        int getYCelPos()                       { return numRows; } ;
        int getXcelPos()                       { return numCols; };
        void setYCelPos(int rowNum)            { numRows = rowNum; };
        void setXcor(int col)                  { numCols = col; };
        void setWallChar(char wallChar)        { wall = wallChar; };
        char getWallChar()                     { return wall; };

        char makeGrid(int numRows, int numCols, std::vector<Cell> Vecvisited);
        bool cellIsEqual(Cell check, std::vector<Cell> Vecvisited);

    private:
        int numRows;
        int numCols;
        char wall;
        char nextCell;
};


Cell::Cell(){}

bool Cell::cellIsEqual(Cell current, std::vector<Cell> Vecvisited)
{
    for (unsigned int i = 0; i < Vecvisited.size(); i++){
        if (Vecvisited.at(i).getYCelPos() == current.getYCelPos() && Vecvisited.at(i).getXcelPos() == current.getXcelPos()){
            return true;
        }
    }
    return false;
}
char Cell::makeGrid(int numRows, int numCols, std::vector<Cell> Vecvisited)
{
      nextCell = 'X';
    for (int i = 0; i < Vecvisited.size(); i++){
        if (Vecvisited.at(i).getYCelPos() == numRows && Vecvisited.at(i).getXcelPos() == numCols){
            nextCell = Vecvisited.at(i).getWallChar();
        }
    }
    return nextCell;
}
class Maze{

    public:
        Maze();
        bool Ended(int numCols, int numRows);
        bool visitedCell(Cell nextCell, Cell current);
        void PrintMaze(int numRows, int numCols, std::vector<Cell> gridStack, Cell fastestPosition);
        void findDirections(int numRows, int numCols);
        void FastestPath(Cell fastestPosition,int numRows, int numCols, std::vector<Cell> gridStack,  std::vector<Cell>mazePath);
    
    private:
        int numRows;
        int numCols;
        int totalGrid;
        int horizontalNoChange;
        int right;
        int left;
        int verticalNoChange;
        int top;
        int bottom;
        int Nstack;
        int gridRight;
        int gridLeft;
        int gridTop;
        int gridBottom;
        int NcurrentCor;
        int finish; 
        int visitedCells;
        int chosenCell;
        int gridX;
        int gridY;
        std::vector<Cell> cellStack;
        std::vector<Cell> notPopBack;
        std::vector<Cell> gridStack;
        std::vector<Cell> mazePath;
        std::vector<int> VisitedNeighbourCell;
        Cell current;
        Cell nextCell;
        Cell Grid;
        Cell fastestPosition;
};


Maze::Maze() {}

bool Maze::Ended(int numCols, int numRows){
    if(current.getYCelPos() == numCols - 1 && current.getXcelPos() == numRows - 1){
       return true;
    }
    else{
        return false;
    }
}
bool Maze::visitedCell(Cell current, Cell nextCell){
    if(nextCell.getYCelPos() != current.getYCelPos() || nextCell.getXcelPos() != current.getXcelPos()){
        return true;
    }
    else{
        return false;
    }
}
void Maze::PrintMaze(int numRows, int numCols, std::vector<Cell> gridStack, Cell fastestPosition){
    int gridX;
    int gridY;
    gridX = getYGridSize(numCols);
    gridY = getXGridSize(numRows);
    for (unsigned int row = 0; row < gridY; row++){
        for ( unsigned int col = 0; col < gridX; col++){
            if (col == 0 && row  == 0){
                std::cout << Corner;
            }
            else if (col == 0 && row % 2 != 0){
                std::cout << verticalWall;
            }
            else{
                if (row % 2 == 0 && col % 2 == 0){
                    std::cout << Corner;
                }
                else if (row % 2 == 0){
                    (fastestPosition.makeGrid(col, row, gridStack) == cellTop ||
                    fastestPosition.makeGrid(col, row, gridStack) == cellBottom) ?
                    std::cout << noVerticalWall : std::cout << horizontalWall;   
                }
                else if (col % 2 == 0){
                    (fastestPosition.makeGrid(col, row, gridStack) == cellRight ||
                    fastestPosition.makeGrid(col, row, gridStack) == cellLeft) ?
                    std::cout << noWall : std::cout << verticalWall;   
                }
                else{
                    (fastestPosition.makeGrid(col, row, gridStack) == cellMazesolver) ?
                     std::cout << Path : std::cout << noVerticalWall;
                }
            }
        }
        std::cout << "\n";
    }
}
void Maze::findDirections(int numRows, int numCols){
    visitedCells = 1;
    finish = 0;
    
    current.setYCelPos(X_START);
    current.setXcor(Y_START);
    current.setWallChar('!');
    cellStack.push_back(current);
    notPopBack.push_back(current);
    mazePath.push_back(current);
    do {        
        NcurrentCor = cellStack.size() - 1;
        totalGrid = numRows * numCols;
        Grid = cellStack.at(NcurrentCor);
        Grid.setYCelPos(getXGridSize(Grid.getYCelPos()));
        Grid.setXcor(getYGridSize(Grid.getXcelPos()));
        fastestPosition = Grid;
        
        horizontalNoChange = current.getYCelPos();
        right = current.getYCelPos() + 1;
        left = current.getYCelPos() - 1;
        verticalNoChange = current.getXcelPos();
        top = current.getXcelPos() - 1;
        bottom = current.getXcelPos() + 1;
        
        if (Ended( numCols,  numRows)){
            finish++;
        }
        nextCell.setYCelPos(horizontalNoChange);
        nextCell.setXcor(top);
        if (nextCell.getXcelPos() >= 0 &&
            (visitedCell( current,  nextCell)) &&
             !nextCell.cellIsEqual(nextCell, notPopBack))
                {
                VisitedNeighbourCell.push_back(TOP);
                }
        nextCell.setYCelPos(horizontalNoChange);
        nextCell.setXcor(bottom);
        if (nextCell.getXcelPos() < numRows &&
            (visitedCell( current,  nextCell)) &&
             !nextCell.cellIsEqual(nextCell, notPopBack))
                {
                VisitedNeighbourCell.push_back(BOTTOM);
                }
        nextCell.setYCelPos(right);
        nextCell.setXcor(verticalNoChange);
        if (nextCell.getYCelPos() < numCols &&
            (visitedCell( current,  nextCell)) &&
             !nextCell.cellIsEqual(nextCell, notPopBack))
                {
                VisitedNeighbourCell.push_back(RIGHT);
                }
        nextCell.setYCelPos(left);
        nextCell.setXcor(current.getXcelPos());
        if (nextCell.getYCelPos() >= 0 &&
            (visitedCell( current,  nextCell)) &&
            !nextCell.cellIsEqual(nextCell, notPopBack))
                {
                VisitedNeighbourCell.push_back(LEFT);
                }
        if (VisitedNeighbourCell.size() != 0){
            gridTop = Grid.getXcelPos()-1; 
            gridRight = Grid.getYCelPos()+1;
            gridBottom = Grid.getXcelPos()+1;            
            gridLeft = Grid.getYCelPos()-1;
        
            chosenCell = VisitedNeighbourCell.at(rand() % VisitedNeighbourCell.size());
            switch (chosenCell){
            case TOP:
                current.setXcor(top);
                current.setWallChar(cellTop);
                Grid.setXcor(gridTop);
                Grid.setWallChar(cellTop);
                gridStack.push_back(Grid);
                break;
            case BOTTOM:
                current.setXcor(bottom);
                current.setWallChar(cellBottom);
                Grid.setXcor(gridBottom);
                Grid.setWallChar(cellBottom);
                gridStack.push_back(Grid);
                break;
            case RIGHT:
                current.setYCelPos(right);
                current.setWallChar(cellRight);
                Grid.setYCelPos(gridRight);
                Grid.setWallChar(cellRight);
                gridStack.push_back(Grid);
                break;
            case LEFT:
                current.setYCelPos(left);
                current.setWallChar(cellLeft);
                Grid.setYCelPos(gridLeft);
                Grid.setWallChar(cellLeft);
                gridStack.push_back(Grid);
                break;
            default:
                break;
            }
            cellStack.push_back(current);
            notPopBack.push_back(current);
            if (finish == 0){
                mazePath.push_back(current);
            }
            visitedCells++;
        }
        else{
            cellStack.pop_back();
            if (finish == 0){
                mazePath.pop_back();
            }
            current = cellStack.back();
        }
         VisitedNeighbourCell.clear();
    }
    while(visitedCells < totalGrid);
    FastestPath(fastestPosition, numRows,  numCols, gridStack,mazePath);
}
void Maze::FastestPath(Cell fastestPosition,int numRows, int numCols, std::vector<Cell> gridStack,  std::vector<Cell>mazePath){
    
    for (unsigned int i = 0; i < mazePath.size(); i++){
        fastestPosition.setYCelPos(getXGridSize(mazePath.at(i).getYCelPos()));
        fastestPosition.setXcor(getYGridSize(mazePath.at(i).getXcelPos()));
        fastestPosition.setWallChar(cellMazesolver);
        gridStack.push_back(fastestPosition);
    }
    PrintMaze(numRows, numCols, gridStack, fastestPosition);
}


int main(int argc, char const *argv[]) {
    Maze MAZE;
    int numRows;
    int numCols;
     
  try
    {
        if ( argc > 4){
                throw std::runtime_error("Too much input given max input is: n = 3.");
                return 69;
            }
        else if (argc ==1){
                throw std::runtime_error("No input given.");
                return 69;
            }
        else if (argc ==2){
                throw std::runtime_error("Insufficient input minimum input is: n = 2.");
                return 69;
            }
        numRows = atoi(argv[1]);
        numCols = atoi(argv[2]);
        if (argc == 3){
            srand((time(0)));
            }
        else if (argc ==4){
            srand(atoi(argv[3]));
            }
    }
    catch (std::runtime_error &excpt){
        std::cout << excpt.what() << "\n";
    } 
    MAZE.findDirections( numRows,  numCols);
    return 0;
}
