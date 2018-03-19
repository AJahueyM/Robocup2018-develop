#include "Map.h"

Map::Map(Tile initialTile){
	tileMap.push_back(vector<Tile>());
	tileMap[0].push_back(initialTile);
}

void Map::addColumn(Direction side){

}

void Map::addRow(Direction side){

}

Tile& Map::getTileAt(Coord coord){
	return tileMap[coord.getY()][coord.getX()];
}

void Map::setTileAt(Coord coord, Tile newTile){
	tileMap[coord.getY()][coord.getX()] = newTile;

}

Coord Map::getRobotCoord(){
	return this->robotCoord;
}

void Map::expandMap(){
	Serial.print("X:");
	Serial.print(getRobotCoord().getX());
	Serial.print("Y:");
	Serial.println(getRobotCoord().getY());

	if(getRobotCoord().getX()  == getWidth() - 1){
		if(!getTileAt(getRobotCoord()).wallExists(Right)){
			for(int i = 0; i < tileMap.size(); ++i){
				tileMap[i].push_back(Tile());
			}
		}
	}

	if(getRobotCoord().getX() == 0){
		if(!getTileAt(getRobotCoord()).wallExists(Left)){
			for(int i = 0; i < tileMap.size(); ++i){
				tileMap[i].insert(tileMap[i].begin(),Tile());
			}
			Coord newRobotCoord = getRobotCoord();
			newRobotCoord.setX(1);
			setRobotCoord(newRobotCoord);
		}
	}

	if(getRobotCoord().getY() == 0){
		if(!getTileAt(getRobotCoord()).wallExists(Down)){
			vector<Tile> newRow;
			for(int i = 0; i < tileMap[0].size(); ++i){
				newRow.push_back(Tile());
			}
     		tileMap.insert(tileMap.begin(), newRow);
			Coord newRobotCoord = getRobotCoord();
			newRobotCoord.setY(1);
			setRobotCoord(newRobotCoord);
		}
	}

	if(getRobotCoord().getY() == getHeight() - 1){
		if(!getTileAt(getRobotCoord()).wallExists(Up)){
			vector<Tile> newRow;
			tileMap.push_back(newRow);
		}
	}
}

void Map::setRobotCoord(Coord coord){
	this->robotCoord = coord;
}

Path Map::getPathTo(Coord targetCoord){

}

uint8_t Map::getWidth(){
	return tileMap[0].size();
}

uint8_t Map::getHeight(){
	return tileMap.size();
}
