// Car example for Observer Design Pattern

#include<iostream>
#include<vector>
#include<algorithm>
class Observer;

class Car
{
private:
int position;
std::vector<Observer> observerList;

public:
    Car(/* args */);
    ~Car();
    void setPosition(int i);
    void attach(Observer& attach_obs);
    void detach(Observer& attach_obs);
    void notify();
};

Car::Car(/* args */)
{
}

Car::~Car()
{
}

void Car :: attach(Observer& attach_obs)
{
    observerList.push_back(attach_obs);
}

void Car :: detach(Observer& attach_obs)
{
    observerList.erase(std::remove(observerList.begin(),observerList.end(),attach_obs),observerList.end());
}

void Car::notify()
{
    for(auto it = observerList.begin(); it != observerList.end(); it++)
    {
        it->update();
    }
}

void Car::setPosition(int i)
{
    this->position = i;
    this->notify();
}

class Observer
{
public:
    Observer();
    ~Observer();
    virtual void update() = 0; 
};

Observer::Observer(/* args */)
{
}

Observer::~Observer()
{
}
