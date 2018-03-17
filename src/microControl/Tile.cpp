#include "Tile.h"

Tile::Tile(){
}
Tile::Tile(byte identity){
    this->identity = identity;
}

bool Tile::isRamp(){
    byte result = identity & isRampMask;
    return result != 0;
}

bool Tile::wallExists(Direction side){
    byte result;
    switch(side){
       	case Up:
           result = identity & wallUpMask;
           break;
           
        case Down:
            result = identity & wallDownMask;
            break;

        case Left:
            result = identity & wallLeftMask;
            break;

        case Right:
            result = identity & wallRightMask;
            break;
    }
    return result != 0;
}

bool Tile::setWall(Direction side, bool value){
    switch(side){
        case Up:
            if(value)
                identity = identity | wallUpMask;
            else 
                identity = identity & ~wallUpMask;
            break;
           
        case Down:
            if(value)
                identity = identity | wallDownMask;
            else 
                identity = identity & ~wallDownMask;
            break;

        case Left:
            if(value)
                identity = identity | wallLeftMask;
            else 
                identity = identity & ~wallLeftMask;
            break;

        case Right:
            if(value)
                identity = identity | wallRightMask;
            else
                identity = identity & ~wallRightMask;
            break;
    }
}

Color Tile::getColor(){
    if(identity & isBlackMask != 0){
        return Black;
    }
    if(identity & isCheckpointMask != 0){
        return Silver;
    }
    return White;
}