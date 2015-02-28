#include "displaymap.h"
#include "map.h"
#include <QHeaderView>

DisplayMap::DisplayMap(QWidget* parent):
    QTableWidget(rows,columns,parent),
    currentmap( nullptr )
{
    setRowCount(rows);
    setColumnCount(columns);
    setGeometry(30,30,480,480);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSelectionMode(SelectionMode::SingleSelection);
    setGridStyle(Qt::DashDotLine);
    setEditTriggers(NoEditTriggers);

    horizontalHeader()->hide();
    verticalHeader()->hide();
    horizontalHeader()->setDefaultSectionSize(24);
    verticalHeader()->setDefaultSectionSize(24);
    connect(this,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(currentCellChanged(int,int)));

}

DisplayMap::~DisplayMap()
{

}

void DisplayMap::setCurrentMap(Map* map)
{
    currentmap = map;
    for(int x = 0; x < 20; ++x)
    {
        for(int y = 0; y < 20; ++y)
        {
           setItem(x, y, currentmap->getCell(x,y));
        }
    }
}

void DisplayMap::currentCellChanged(int currentRow, int currentColumn)
{
    if(currentmap){
        currentcell = currentmap->getCell(currentRow,currentColumn);
    }
}

void DisplayMap::isATV(bool checked)
{
    if(checked){
        currentcell->addVehicle(Cell::VEHICLETYPE::ATV);
    }
    else{
        currentcell->removeVehicle(Cell::VEHICLETYPE::ATV);
    }
}

void DisplayMap::isQuadcopter(bool checked)
{
    if(checked){
        currentcell->addVehicle(Cell::VEHICLETYPE::QUADCOPTER);
    }
    else{
        currentcell->removeVehicle(Cell::VEHICLETYPE::QUADCOPTER);
    }
}

void DisplayMap::isRosbee(bool checked)
{
    if(checked){
        currentcell->addVehicle(Cell::VEHICLETYPE::ROSBEE);
    }
    else{
        currentcell->removeVehicle(Cell::VEHICLETYPE::ROSBEE);
    }
}

void DisplayMap::isGrass(bool checked)
{
    if(checked){
        currentcell->setTerrainType(Cell::TERRAINTYPE::GRASS);
    }
    else{
        currentcell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}

void DisplayMap::isDirt(bool checked)
{
    if(checked){
        currentcell->setTerrainType(Cell::TERRAINTYPE::DIRT);
    }
    else{
        currentcell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}

void DisplayMap::isConcrete(bool checked)
{
    if(checked){
        currentcell->setTerrainType(Cell::TERRAINTYPE::CONCRETE);
    }
    else{
        currentcell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}

void DisplayMap::isWater(bool checked)
{
    if(checked){
        currentcell->setTerrainType(Cell::TERRAINTYPE::WATER);
    }
    else{
        currentcell->setTerrainType(Cell::TERRAINTYPE::EMPTY);
    }
}

