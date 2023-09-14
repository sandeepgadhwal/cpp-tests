

#include <iostream>
// #include <cmath>

using namespace std;

class Car{
    public:
        int id;
        string name;
        void printSelf() {
            cout << "Car: " << this->id << " " << this->name ;
        }
        Car(){
            cout << "Blank Initialization\n";
        }
        Car(int id){
            this->id = id;
        }
        Car(int id, string name){
            this->id = id;
            this->name = name;
        }
        void setPass(int pass){
            this->pass = pass;
        }
        bool correctPass(int input){
            return this->pass == input;
        }
    protected:
        int getPass(){
            return this->pass;
        }
    private:
        int pass;
};

class Ev: public Car{
    public:
        void setCharge(int charge){
            this->charge=charge;
        }
        
        void printSelf() {
            Car::printSelf();
            cout << "Ev Charge: " << this->charge;
        }
    protected:
        int charge=0;
};

int main() 
{
    cout << "Hello from Sandeep";
    cout << endl;

    Car a;
    a.printSelf();

    Car(1).printSelf();

    Car(3, "Totyota").printSelf();
    cout << "\n";

    Car b = Car();
    b.setPass(100);
    cout << b.correctPass(100) << " " << b.correctPass(200);
    cout << "\n";

    Ev ev = Ev();
    ev.setCharge(87);
    ev.printSelf();

    cout << "\n";
    return 0;
}