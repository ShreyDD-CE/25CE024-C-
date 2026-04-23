#include <iostream>
using namespace std;

// ===============================
// 🔹 Base Class: Fuel
// ===============================
class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f) : fuelType(f) {}

    void displayFuel() const {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// ===============================
// 🔹 Base Class: Brand
// ===============================
class Brand {
protected:
    string brandName;

public:
    Brand(string b) : brandName(b) {}

    void displayBrand() const {
        cout << "Brand: " << brandName << endl;
    }
};

// ===============================
// 🔹 Derived Class: Car
// ===============================
class Car : public Fuel, public Brand {
private:
    int carID;

public:
    Car(int id, string f, string b)
        : Fuel(f), Brand(b), carID(id) {}

    int getID() const {
        return carID;
    }

    void displayCar() const {
        cout << "\n--- Car Details ---\n";
        cout << "Car ID: " << carID << endl;
        displayBrand();
        displayFuel();
    }
};

// ===============================
// 🔍 Search Car by ID
// ===============================
Car* findCar(Car* arr[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (arr[i]->getID() == id)
            return arr[i];
    }
    return nullptr;
}

// ===============================
// 🔹 MAIN
// ===============================
int main() {
    int n;

    cout << "Enter number of cars: ";
    cin >> n;

    // ===============================
    // 🔸 Dynamic Queue-like Handling
    // ===============================
    cout << "\n--- Dynamic Processing (Service Queue) ---\n";

    Car** cars = new Car*[n];

    int id;
    string fuel, brand;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for car " << i + 1 << ":\n";

        cout << "Car ID: ";
        cin >> id;

        cout << "Fuel Type: ";
        cin >> fuel;

        cout << "Brand Name: ";
        cin >> brand;

        cars[i] = new Car(id, fuel, brand);
    }

    // Sequential processing (like queue)
    cout << "\n--- Processing Cars ---\n";
    for (int i = 0; i < n; i++) {
        cars[i]->displayCar();
    }

    // Search
    int searchID;
    cout << "\nEnter Car ID to search: ";
    cin >> searchID;

    Car* result = findCar(cars, n, searchID);

    if (result) {
        cout << "\nCar Found:\n";
        result->displayCar();
    } else {
        cout << "Car not found.\n";
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        delete cars[i];
    }
    delete[] cars;

    // ===============================
    // 🔸 Static Storage
    // ===============================
    cout << "\n--- Static Storage ---\n";

    const int MAX = 3;
    Car staticCars[MAX] = {
        Car(1, "Petrol", "Toyota"),
        Car(2, "Diesel", "Hyundai"),
        Car(3, "Electric", "Tesla")
    };

    for (int i = 0; i < MAX; i++) {
        staticCars[i].displayCar();
    }

    return 0;
}