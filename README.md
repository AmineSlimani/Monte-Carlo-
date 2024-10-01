# Monte Carlo Simulation of Spin Systems for MnAs

This repository contains a C program that implements a Monte Carlo simulation for studying spin-2 systems with two nearest neighbors in the material MnAs. The code simulates the behavior of spins in a 3D lattice using the Metropolis algorithm to calculate thermodynamic properties such as magnetization, susceptibility, and heat capacity.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
- [Output](#output)
- [Critical Exponent Calculation](#critical-exponent-calculation)
- [License](#license)

## Features

- Simulates 3D spin systems (spin-2) with two nearest neighbors.
- Computes thermodynamic properties:
  - Magnetization
  - Susceptibility
  - Heat capacity
- Outputs results to data files for further analysis.

## Requirements

To compile and run the program, you will need:

- A C compiler (e.g., GCC)
- Standard C libraries

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/AmineSlimani/Monte_Carlo_Simulation.git
   cd Monte_Carlo_Simulation
   ```

2. Compile the Monte Carlo simulation code:
   ```bash
   gcc -o monte_carlo monte_carlo.c -lm
   ```

3. Run the Monte Carlo simulation:
   ```bash
   ./monte_carlo
   ```

4. The output files will be generated in the format `mc{L}.dat` (e.g., `mc4.dat`, `mc8.dat`, etc.) containing the simulation results for each lattice size.

## Output

The program generates output files that contain the following columns:

- Temperature \( T \)
- Average magnetization per spin
- Magnetic susceptibility per spin
- Heat capacity per spin
- Universal quantity

Each data file corresponds to a different lattice size, allowing for comparison of results across different scales.

## Critical Exponent Calculation

This section describes a separate C program that takes the output from the Monte Carlo simulation and computes the critical exponents for the spin-2 system in the material MnAs.

### Overview

The program reads predefined arrays for lattice sizes, magnetization, susceptibility, and heat capacity, and then calculates the natural logarithm of these values. The results are saved to a file called `exp.dat`.

### Output

The program generates a file named `exp.dat` containing the following columns:

- Logarithm of lattice size \( L \)
- Logarithm of magnetization \( M \)
- Logarithm of susceptibility \( X \)
- Logarithm of heat capacity \( C_v \)

This data can be used for further analysis of critical behavior and to extract critical exponents.

### Usage

1. Include this program in your project directory.
2. Compile it:
   ```bash
   gcc -o critical_exponents critical_exponents.c -lm
   ```
3. Run the program:
   ```bash
   ./critical_exponents
   ```
4. The output file `exp.dat` will be created in the same directory.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
