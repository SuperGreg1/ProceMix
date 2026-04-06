#include <vector>

class Maze
{
public:

    std::vector<std::vector<bool>> tiles; // Maze tiles 

    Maze(int newSizeX, int newSizeY)
    {
        sizeX = newSizeX;
        sizeY = newSizeY;
    }

    void setSizeX(int newSizeX)
    {
        sizeX = newSizeX;
    }
    void setSizeY(int newSizeY)
    {
        sizeY = newSizeY;
    }

    int getSizeX()
    {
        return sizeX;
    }
    int getSizeY()
    {
        return sizeY;
    }

private:

    int sizeX; // Maze size X
    int sizeY; // Maze size Y

};