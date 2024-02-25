#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

class StudentWorld;

class Actor : public GraphObject {
public:
    Actor(int ID, int startX, int startY, int startDir, int hitPoints, StudentWorld* wrld);
    virtual ~Actor() {}
    StudentWorld* getWorld() const {return wrld;}
    virtual void doSomething() = 0;
    
    bool isAlive() const {return alive;}
    void setDead() {alive = false;}
    int getHealth() const {return health;}
    void decHealth(int p) {health-=p;}
    
    // identifier methods
    virtual bool push(int dir) {return false;}
    virtual bool canBePushed() const {return false;}
    virtual bool blocksMovement() const {return true;}
    virtual bool getDamaged() {return false;}

    virtual void getNewCoordinates(int& x, int& y, int dir) const;
    void shootPea();
private:
    StudentWorld* wrld;
    bool alive;
    int health;
};

class Avatar : public Actor {
public:
    Avatar(int startX, int startY, StudentWorld* wrld);
    ~Avatar() {}
    virtual void doSomething();
    virtual bool getDamaged();
    int getPeas() const {return peas;}
private:
    int peas;
};

class Wall : public Actor {
public:
    Wall(int startX, int startY, StudentWorld* wrld);
    ~Wall() {}
    virtual void doSomething() {}
private:
};

class Marble : public Actor {
public:
    Marble(int startX, int startY, StudentWorld* wrld);
    ~Marble() {}
    virtual void doSomething();
    virtual bool canBePushed() const {return true;}
    virtual bool push(int dir);
    virtual bool getDamaged();
private:
};

class Pit : public Actor{
public:
    Pit(int startX, int startY, StudentWorld* wlrd);
    ~Pit() {}
    virtual void doSomething();
    virtual bool blocksMovement() const {return false;}
private:
};

class Pea : public Actor{
public:
    Pea(int startX, int startY, int startDir, StudentWorld* wrld);
    ~Pea() {}
    virtual void doSomething();
    virtual bool blocksMovement() const {return false;}
private:
    bool moved;
};

class RageBot : public Actor{
public:
    RageBot(int startX, int startY, int startDir, StudentWorld* wrld);
    ~RageBot() {}
    virtual void doSomething();
    virtual bool getDamaged();
private:
    bool facingPlayer();
    int ticks;
    int currTick;
};

class Crystal : public Actor{
public:
    Crystal(int startX, int startY, StudentWorld* wrld);
    ~Crystal() {}
    virtual void doSomething();
private:
};

#endif
