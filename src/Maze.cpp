#include <vector>
#include <cstdlib>
#include <cstdint>
#include <concepts>
#include <unordered_map>
#include <SFML/Graphics.hpp>

struct Tile 
{

    bool isWall; // Is tile a wall
    uint32_t status; 

};


class Maze
{
public:

    std::vector<std::vector<Tile>> tiles; // Maze tiles 

    Maze(int newrows = 1, int newcoloumns = 1)
    {
        rows = newrows;
        coloumns = newcoloumns;
        tiles.resize(rows);
        for(auto& rows : tiles)
        {
            rows.resize(coloumns);
        }
    }

    void setRows(int newrows)
    {
        rows = newrows;
    }
    void setColoumns(int newcoloumns)
    {
        coloumns = newcoloumns;
    }

    int getRows() const
    {
        return rows;
    }
    int getColoumns() const
    {
        return coloumns;
    }

private:

    int rows; // Maze size X
    int coloumns; // Maze size Y

};

class Drawer
{
public:


void addColor(uint32_t id, sf::Color color)
{
    colors.insert({id, color});
}

void drawMaze(sf::RenderWindow& window, const sf::IntRect& field, const Maze& maze)
{
    int tileHeight, tileWidth;

    tileHeight = field.height / maze.getRows();
    tileWidth = field.width / maze.getColoumns();

    for(size_t i = 0; i < maze.tiles.size(); i++)
    {
        for(size_t j = 0; j < maze.tiles[i].size(); j++)
        {
            rectangleShape.setPosition(sf::Vector2f(field.getPosition().x + i * tileWidth, field.getPosition().y + j * tileHeight));
            rectangleShape.setSize(sf::Vector2f(tileWidth, tileHeight));
            rectangleShape.setFillColor(colors[maze.tiles[i][j].status]);
            window.draw(rectangleShape);
        }
    }
}

private:

    sf::RectangleShape rectangleShape;
    std::unordered_map<uint32_t, sf::Color> colors;

};

int main(){

    const int screenHeight = 750, screenWidth = 1500;

	sf::RenderWindow app(sf::VideoMode(screenWidth, screenHeight), "", sf::Style::Default);
	app.setFramerateLimit(60);

    Maze a;
    a.tiles[1][1].isWall;

    for(int x = 0; x < a.getRows(); x++)
    {
        for(int y = 0; y < a.getColoumns(); y++)
        {
            a.tiles[x][y].isWall = false;
        }
    }

    sf::Event e;

	while (app.isOpen())
	{
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				app.close();
			}
		}
		app.clear(sf::Color(69, 6, 147));


        app.display();


    }
    //  Maze_drawer() : public Drawable;
}