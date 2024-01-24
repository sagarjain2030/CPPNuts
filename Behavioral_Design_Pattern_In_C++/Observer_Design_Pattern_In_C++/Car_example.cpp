// Car example for Observer Design Pattern

#include<iostream>
#include<vector>
#include<algorithm>
#include <memory>
class Car
{
        int position;
        std::vector<class Observer*> observerList;
    public:
        int getPosition()
        {
            return position;
        }
        void setPosition(int newPosition)
        {
            position = newPosition;
            notify();
        }
        void attach(Observer *obs)
        {
            observerList.push_back(obs);
        }
        void detach(Observer *obs)
        {
            observerList.erase(std::remove(observerList.begin(),observerList.end(),obs),observerList.end());
        }
        void notify();
};

class Observer
{
    Car *_car;
public:
    Observer(Car *car)
    {
        _car = car;
        _car->attach(this);
    }
    virtual void update() = 0; 
    Car* getCar()
    {
        return _car;
    }
};

void Car::notify()
{
    for(int i = 0; i < observerList.size(); i++)
    {
        observerList[i]->update();
    }
}

class LeftObserver:public Observer
{
    public:
        LeftObserver(Car* car): Observer(car){}
        void update()
        {
            int pos = getCar()->getPosition();
            if(pos == -1)
                std::cout<<"Car is in left position"<<std::endl;
        }
};

class RightObserver:public Observer
{
    public:
        RightObserver(Car* car): Observer(car){}
        void update()
        {
            int pos = getCar()->getPosition();
            if(pos == 1)
                std::cout<<"Car is in right position"<<std::endl;
        }
};

class MiddleObserver:public Observer
{
    public:
        MiddleObserver(Car *car): Observer(car){}
        void update()
        {
            int pos = getCar()->getPosition();
            if(pos == 0)
                std::cout<<"Car is in middle position"<<std::endl;
        }
};

// -1 0 1 ==> available positions
// -1 ==> Driving in left lane
// 0 ==> Driving in middle lane
// 1 ==> Driving in right lane

int main()
{
    Car *car = new Car();
    LeftObserver leftObserver(car);
    MiddleObserver middleObserver(car);
    RightObserver rightObserver(car);

    std::cout<<"hit l & r button to move car.Press b to leave."<<std::endl;
    char pressedButton;
    bool breakLoop = false;
    while(!breakLoop)
    {
        std::cin>>pressedButton;
        switch(pressedButton)
        {
            case 108:
            {
                if(car->getPosition() == 1)
                    car->setPosition(0);
                else
                    car->setPosition(-1);
                break;
            }
            case 114:
            {
                if(car->getPosition() == -1)
                    car->setPosition(0);
                else
                    car->setPosition(1);
                break;
            }
            case 98:
            {
                breakLoop = true;
            }
            default:
            {
                std::cout<<"Please drive carefully"<<std::endl;
            }
        }
    }
    std::cout<<"Bye..."<<std::endl;
    return 0;
}