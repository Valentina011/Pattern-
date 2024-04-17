//Builder pattern
#include <iostream>
#include <string>
class Coffee {
public:
    void Set_Espresso(int espresso){
        this->espresso = espresso;
    }
    void Set_Milk(int milk){
        this->milk = milk;
    }
    void displayCoffee() const
    {
        std::cout << "Espresso in ml: " << espresso << std::endl;
        std::cout << "Milk in ml: " << milk << std::endl;
    }
private:
    int espresso;
    int milk;
};

class Builder {
public:
    virtual void buildespresso() = 0;
    virtual void buildmilk() = 0;
    virtual Coffee getCoffee() const = 0;
};

class CappuccinoBuilder: public Builder{
public:
    void buildespresso() override
    {
        coffee.Set_Espresso(60);
    }
    void buildmilk() override
    {
        coffee.Set_Milk(120);
    }
    Coffee getCoffee() const override { return coffee; }
private:
    Coffee coffee;
};

class make_coffee{
public:
    void makeCoffee(Builder& builder)
    {
        builder.buildespresso();
        builder.buildmilk();
    }
};

int main(){
    make_coffee Cook;

    CappuccinoBuilder cappuccino;
    Cook.makeCoffee(cappuccino);
    Coffee cappuccinoCoffee = cappuccino.getCoffee();
    cappuccinoCoffee.displayCoffee();

    return 0;
}