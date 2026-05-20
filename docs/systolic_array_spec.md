# Systolic Array Spec

The Systolic Array is a 16x16 mesh of Processing Elements (PEs) using weight-stationary dataflow. Weights are pre-loaded into each PE before compute begins and remain stationary throughout. Activations flow left to right through the rows (pre-skewed by the Systolic Data Setup), and partial sums flow top to bottom through each column, draining out the bottom into the Accumulator Bank.

Each PE each cycle:
- Receives an activation element from the left, passes it right
- Multiplies it by its stored weight
- Adds the result to the partial sum received from above, passes the new partial sum down