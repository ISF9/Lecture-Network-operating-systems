Программа (2/3) четвёртой лекции

Сначала программа создаёт массив файловых дескрипторов. После этого приложение проверит корректность ввода и сообщит об ошибке если нужно. Затем программа вызовет fork() для получения PID'а дочернего процесса. Дальше приложение проверит только что полученный PID. У дочернего элемента этот идентификатор равен нулю. Далее родительский процесс пишет что-либо в канал, а дочерний читает. Таким образом реализуется общение между процессами с помощью канала.

![lec(2of3)](https://user-images.githubusercontent.com/75760796/169100087-df69b9df-1035-473f-a29f-92189c551ac2.jpg)
