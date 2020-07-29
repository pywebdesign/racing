#ifndef ENTITYMANAGER
#define ENTITYMANAGER 

#include <vector> 
#include "Entity.h"
#include <memory>
#include <map>
class EntityManager
{
public:
    static EntityManager& getInstance();
    EntityManager();                    // Constructor? (the {} brackets) are needed here.
    EntityManager(EntityManager const&) = delete;              // Don't Implement
    void operator=(EntityManager const&) = delete; // Don't implement
    void Update(double t);
    template<typename T>
    std::shared_ptr<T> GetSingle(Entity::EntityType entityType) {
        auto r = Entities.equal_range(entityType);
        return std::dynamic_pointer_cast<T>(r.first->second);
    }
    struct compareEntity {
        bool operator()(const Entity::EntityType& a, const Entity::EntityType& b) const {
            return EntityManager::order[a] < EntityManager::order[b];
        }
    };
    std::multimap<Entity::EntityType, std::shared_ptr<Entity::Entity>, compareEntity> Entities;
    static std::map<Entity::EntityType, int> order;
};

#endif