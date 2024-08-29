class Vehicle {

void drive(Vehicle v) {

System.out.print("Vehicle");

}

}


class Car extends Vehicle { void drive(Car c) { System.out.print("Car"); }


}

12

class Bike extends Car { void drive(Bike b) { System.out.print("Bike"); }

}


public class Main {

public static void main(String[] args) {

Vehicle vehicle1 = new Vehicle();

Car car = new Car();

Bike bike = new Bike();

Bike bike1 = new Bike();

bike1.drive(vehicle1);

bike1.drive(car);

bike1.drive(bike);
}}