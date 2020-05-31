#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
public:
    Entity() {}
    virtual ~Entity() {}

    virtual void Update() = 0;
    
    // position
    float x, y;
    
    // dimension
    float width, height;
};

#endif