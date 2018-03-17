
#ifndef __MAP_HEADER_
#define __MAP_HEADER_

#include "Tile.h"
#include "Coord.h"
#include "Path.h"
#include <ArduinoSTL.h>
using namespace std;


class Map{
public:
	Map(Tile initialTile);
	void addColumn(Direction side);
	void addRow(Direction side);
	Tile& getTileAt(Coord coord);
	void setTileAt(Coord coord, Tile newTile);
	Coord getRobotCoord();
	void setRobotCoord(Coord coord);
	void expandMap();
	Path getPathTo(Coord targetCoord);
	uint8_t getWidth();
	uint8_t getHeight();
private:
	vector<vector<Tile>> tileMap;
	Coord robotCoord;
	Direction robotDirection;

};
#endif

