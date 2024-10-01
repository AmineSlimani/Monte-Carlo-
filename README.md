# Monte Carlo Simulation of Spin Systems

This repository contains a C program that implements a Monte Carlo simulation for studying spin systems. The code simulates the behavior of spins in a 3D lattice using the Metropolis algorithm to calculate thermodynamic properties such as magnetization, susceptibility, and heat capacity.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
- [Output](#output)
- [Results](#results)

## Features

- Simulates 3D spin systems with lattice sizes \( L = 4, 8, 16, \) and \( 32 \).
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

2. Compile the code:
   ```bash
   gcc -o monte_carlo monte_carlo.c -lm
   ```

3. Run the program:
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

## Results

After running the simulation, you can analyze the output data to understand the behavior of the spin system at different temperatures. Use your favorite data analysis tools (e.g., Python with Matplotlib, R) to visualize the results.

