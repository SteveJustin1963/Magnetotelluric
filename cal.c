#include <stdio.h>
#include <math.h>

int main(void) 
{
    // Variables
    double L = 1.0; // Length of wire (m)
    double A = 0.01; // Cross-sectional area of wire (m²)
    double R = 1.0; // Resistance of wire (Ω)
    double epsilon0 = 8.85e-12; // Electric permittivity (C²/Nm²)
    double mu0 = 4*M_PI*1e-7; // Permeability of free space (N/A²)
    
    // Calculate charge density
    double rho = R/L; // (Ω/m)
    
    // Calculate electric field at the surface of the ground
    double E = -pow(rho,2)/epsilon0; // (N/C)
    
    // Calculate magnetic field at the surface of the ground
    double J = rho/mu0; // (A/m²)
    double B = J+mu0*E; // (T)
    
    // Print results
    printf("The electric field at the surface of the ground due to the wire is %.2e N/C.\n", E); 
    printf("The magnetic field at the surface of the ground due to the wire is %.2e T.\n", B); 
    
    return 0;
}

==============
  #include <math.h>

double calculateChargeDensity(double resistance, double length, double crossSectionalArea) {
    return resistance * length / crossSectionalArea;
}

double calculateElectricField(double chargeDensity, double electricPermittivity) {
    return -chargeDensity / electricPermittivity;
}

double calculateMagneticField(double currentDensity, double permeability, double electricField, double time) {
    return currentDensity * permeability + permeability * electricField / time;
}

int main() {
    double resistance = 1.0; // Ohms
    double length = 1.0; // meters
    double crossSectionalArea = M_PI * pow(0.01, 2); // meters^2
    double electricPermittivity = 8.85e-12; // C^2/Nm^2
    double permeability = 4 * M_PI * 1e-7; // N/A^2
    double time = 1.0; // seconds

    double chargeDensity = calculateChargeDensity(resistance, length, crossSectionalArea);
    double electricField = calculateElectricField(chargeDensity, electricPermittivity);
    double currentDensity = chargeDensity / permeability;
    double magneticField = calculateMagneticField(currentDensity, permeability, electricField, time);

    printf("Electric field: %.2e N/C\n", electricField);
    printf("Magnetic field: %.2e T\n", magneticField);

    return 0;
}
