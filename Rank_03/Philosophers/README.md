# Philosophers

## Description
This project involves simulating the dining philosophers problem. Philosophers, represented as threads or processes, sit at a round table, where they alternate between eating, thinking, and sleeping. The goal is to prevent deadlocks and starvation while ensuring that each philosopher can eat without conflict.

## Structure
- **philo**: Program simulating philosophers using threads and mutex.
- **philo_bonus**: Program simulating philosophers using processes and semaphore.

## Mandatory Part
### philo
- Simulates philosophers using threads and mutex.
- Each philosopher is a thread.
- One fork between each philosopher, protected by a mutex.
- Philosophers must follow the specified rules: eating, thinking, or sleeping without conflicts.
- Program arguments: `number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`.

## Bonus Part
### philo_bonus
- Simulates philosophers using processes and semaphore.
- Each philosopher is a process.
- All forks are in the middle of the table, represented by a semaphore.
- Philosophers must follow the specified rules without conflicts.
- Program arguments: `number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`.

## Usage
Both programs share the same usage format:
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
./philo_bonus [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]


## Compilation
Run `make` in the respective directories to compile each program.

## External Functions
Both programs use standard C functions such as `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`. Additionally, `philo_bonus` uses `fork`, `kill`, `exit`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`.

## Norm Compliance
Ensure compliance with the project's norms regarding leaks, crashes, undefined behavior, and coding standards.

## Note
Philosophers may seem peaceful, but in this simulation, philosophy can be deadly!
