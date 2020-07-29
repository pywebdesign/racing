#include "EntityManager.h"

EntityManager& EntityManager::getInstance()
{
    static EntityManager    instance; // Guaranteed to be destroyed.
                          // Instantiated on first use.

    return instance;
}


std::map<Entity::EntityType, int> EntityManager::order = {
        {Entity::EntityType::Camera , 1},
        {Entity::EntityType::Terrain , 2},
        {Entity::EntityType::NPC , 3},
        {Entity::EntityType::Enemy , 4},
        {Entity::EntityType::Player , 5}
};
EntityManager::EntityManager()
{
    //initialize order

}



void EntityManager::Update(double t)
{
    //reverse loop
    for (auto entity = Entities.rbegin(); entity != Entities.rend(); entity++ ) {
        entity->second->update(t);
    }
}


