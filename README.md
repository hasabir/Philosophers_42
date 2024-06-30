# Philosophers

Philosophers is a project that simulates the classic "Dining Philosophers" problem using threads and mutexes. The goal is to model the behavior of philosophers who alternately eat, think, and sleep while sharing a limited number of forks. This project explores the challenges of synchronization and resource sharing in a concurrent programming environment.

---

## Features
- **Thread Creation**: Each philosopher is represented by a thread.
- **Mutexes**: Use mutexes to manage the state of forks and prevent data races.
- **Simulation**: Simulate the philosophers' behavior of eating, thinking, and sleeping.
- **Error Handling**: Ensures robust error handling to avoid unexpected quits and memory leaks.

### Simulation Rules
- Philosophers sit at a round table with a large bowl of spaghetti in the middle.
- They alternately eat, think, or sleep.
- Philosophers need two forks to eat, taking their right and left forks.
- After eating, they put down their forks and start sleeping. Once awake, they start thinking again.
- The simulation stops when a philosopher dies of starvation.
- Philosophers don’t speak with each other and don’t know if another philosopher is about to die.
- Philosophers should avoid dying at all costs.

### Program Arguments
The program should take the following arguments:
- `number_of_philosophers`: The number of philosophers and forks.
- `time_to_die` (in milliseconds): Time a philosopher can live without eating.
- `time_to_eat` (in milliseconds): Time a philosopher spends eating.
- `time_to_sleep` (in milliseconds): Time a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops.

#Usage
```bash
cd philo
make
./philo <number_of_philosophers> <time_to_die> <time_to_sleep> <number_of_times_each_philosopher_must_eat>
```
## Compilation

To compile Philosophers, use the provided Makefile. The Makefile includes the following rules:
- `all`: Compile the source files.
- `clean`: Remove object files.
- `fclean`: Remove all generated files.
- `re`: Recompile the project.

---

## Programming Languages:
<p align="left">
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="C" width="40" height="40"/>
</p>

---


## Acknowledgments

- [42 School](https://42.fr/)

---
