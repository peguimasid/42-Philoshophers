<h1 align="center">Welcome to Philosophers 👋</h1>
<p>🤔 Solving the famous Dining Philosophers problem and discover concurrent programming by using threads and mutexes</p>

---

- Status: Finished
- Result: 100%

---

## Install

```sh
git clone https://github.com/peguimasid/42-Philosophers.git philosophers
```

## Usage

1. Run `cd philo` and `make` to compile program

2. Run the program passing the params `./philo num_of_philo time_to_die time_to_eat time_to_sleep num_times_must_eat`

### Examples
```js
./philo 1 200 200 200 // Não tem garfos suficientes então retorno erro
./philo 2 800 200 200 // ninguém morre
./philo 5 800 200 200 // ninguém morre
./philo 5 800 200 200 7 // a simulação para quando cada philo comeu 7 vezes
./philo 4 410 200 200 // ninguém morre
./philo 4 310 200 200 // um filósofo morre
./philo 4 500 200 1.2 // argumento inválido
./philo 4 0 200 200 // argumento inválido
./philo 4 -500 200 200 // argumento inválido
./philo 4 500 200 2147483647 // um filo morre após 500 ms
./philo 4 2147483647 200 200 // ninguém morre
./philo 4 214748364732 200 200 // argumento inválido
./philo 4 200 210 200 // um philo morre, você deve exibir a morte antes de 210 ms
```

## Author

👤 **Guilhermo Masid**

- Github: [@peguimasid](https://github.com/peguimasid)
- LinkedIn: [@guilhermo-masid](https://linkedin.com/in/guilhermo-masid-494677b8)

## Show your support

Give a ⭐️ if this project helped you!
