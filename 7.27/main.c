/* 7.27
 * Carbon Footprint Calculator
 * This program will use arrays of function pointers to calculate the
 * carbon footprint of a building, a car, and a bicycle then display
 * the results based on user input */

#include <stdio.h>

// function prototypes
void building();
void car();
void bicycle();

int main() {

    // array to store three void functions
    void (*fArr[3])() = {building, car, bicycle};

    // display menu
    printf("-----------CARBON EMISSIONS CALCULATOR----------\n0 Building\n"
           "1 Car\n2 Bicycle\n3 Quit\nEnter type of carbon footprint to calculate: ");

    int choice = 0;
    scanf_s("%d", &choice);

    // while choice is between 0 and 3
    while (choice >= 0 && choice <3) {

        // call function array
        (*fArr[choice])();


        printf("\n\n-----------CARBON EMISSIONS CALCULATOR----------\n0 Building\n"
               "1 Car\n2 Bicycle\n3 Quit\nEnter type of carbon footprint to calculate: ");

        // get next choice from user
        scanf_s("%d", &choice);
    }

    return 0;

}  // end main


// function to calculate the carbon footprint of a building
void building() {

    double years = 0.0;

    //print data on consumption and emissions factors
    printf("\nElectricity consumption: 100,000 kWh/year");
    printf("\nNatural gas consumption: 50,000 m^3 per year");
    printf("\nElectricity emissions factor: 0.5 kg CO2/kWh");
    printf("\nNatural gas emissions factor: 2.0 kg CO2/m^3");

    // prompt user for number of years
    printf("\nEnter number of years: ");
    scanf_s("%lf", &years);

    // calculate electricity and natural gas emissions
    double elecEmissions = (100000 / years) * .5;
    double gasEmissions = (50000 / years) * 2;

    // add electricity and natural gas emissions
    double total = elecEmissions + gasEmissions;

    // print results
    printf("\nBuilding carbon footprint: %.2lf kg CO2/%.2lf years", total, years);

}

// function to calculate the carbon footprint of a car
void car() {

    double distance = 0.0;

    // display emissions factor data
    printf("\nCar emissions factor: 216.11 g CO2/km");
    printf("\nEnter distance (km): ");
    scanf_s("%lf", &distance);

    // calculate emissions
    double emissions = (216.11 * distance);

    // determine whether units should be g or kg
    // display results
    if (emissions < 1000) {
        printf("\nCar carbon footprint: %.2lf g CO2 / %.2lf", emissions, distance);
    }
    else {
        emissions /= 1000;
        printf("\nCar carbon footprint: %.2lf kg CO2 / %.2lf", emissions, distance);
    }

}

// function to calculate the carbon footprint of a bicycle
void bicycle() {

    double distance = 0.0;

    // display emissions factor data
    printf("\nBicycle emissions factor: 5 g CO2/km");
    printf("\nEnter distance (km): ");
    scanf_s("%lf", &distance);

    // calculate emissions
    double emissions = (5 * distance);

    // determine whether units should be g or kg
    // display results
    if (emissions < 1000) {
        printf("\nBicycle carbon footprint: %.2lf g CO2 / %.2lf", emissions, distance);
    }
    else {
        emissions /= 1000;
        printf("\nBicycle carbon footprint: %.2lf kg CO2 / %.2lf", emissions, distance);
    }
}