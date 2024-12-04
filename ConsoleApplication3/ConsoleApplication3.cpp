#include <iostream>

using namespace std;

class Auto {
    int doors;
    int wheels;
    int speed;
    int color;
    static enum Colors {
        red,
        green,
        blue
    };
public:
    Auto() {
        doors = 4;
        wheels = 4;
        speed = 10;
        color = 1;
    }

    Auto(int doors, int wheels, int speed, int color) {
        this->doors = doors;
        this->wheels = wheels;
        this->speed = speed;
        this->color = color;
    }

    Auto(const Auto& other) {
        this->doors = other.doors;
        this->wheels = other.wheels;
        this->speed = other.speed;
        this->color = other.color;
    }

    void setDoors(int value) {
        doors = value;
    }

    void setWheels(int value) {
        wheels = value;
    }

    void setSpeed(int value) {
        speed = value;
    }

    void setColor(int value) {
        color = color;
    }

    int getWheels() {
        return wheels;
    }
    int getDoors() {
        return doors;
    }
    int getSpeed() {
        return speed;
    }
    int getColor() {
        return color;
    }

    static int GetColorFromValue(int value) {
        if (value == 0) {
            return Colors::red;
        }
        else if (value == 1) {
            return Colors::green;
        }
        else {
            return Colors::blue;
        }
    }

    static void SetColorFromValue(int colorValue, Auto& other) {
        other.color = colorValue;
    }

    void PrintInfo() {
        cout << "Doors: " << doors << endl;
        cout << "Wheels: " << wheels << endl;
        cout << "Speed: " << speed << endl;
        cout << "Color: " << color << endl;
    }
};

class Parking {
    Auto* cars;
    static int amountOfCars;
public:
    Parking() {
        cars = new Auto[amountOfCars];
    }

    void Add(Auto obj) {
        Auto* tempArr = new Auto[amountOfCars];

        for (int i = 0; i < amountOfCars; i++) {
            tempArr[i] = cars[i];
        }

        delete[] cars;
        AddCarsAmount();
        cars = new Auto[amountOfCars];

        for (int i = 0; i < amountOfCars - 1; i++) {
            cars[i] = tempArr[i];
        }

        cars[amountOfCars - 1] = obj;
    }

    void DeleteCar() {
        Auto* tempArr = new Auto[amountOfCars - 1];

        for (int i = 0; i < amountOfCars - 1; i++) {
            tempArr[i] = cars[i];
        }

        delete[] cars;
        RemoveCar();
        for (int i = 0; i < amountOfCars; i++) {
            cars[i] = tempArr[i];
        }
    }

    void PrintCars() {
        for (int i = 0; i < amountOfCars; i++) {
            cars[i].PrintInfo();
        }
    }

    static void AddCarsAmount() {
        amountOfCars++;
    }

    static void RemoveCar() {
        amountOfCars--;
    }
};

int Parking::amountOfCars = 1;

int main() {
    Parking obj;

    obj.PrintCars();

    Auto secAuto = Auto(2, 4, 10, 2);

    obj.Add(secAuto);
    obj.PrintCars();

    obj.DeleteCar();
    obj.PrintCars();

    obj.AddCarsAmount();
}