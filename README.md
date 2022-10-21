## Общие требования
1. В данной работе вы не должны использовать любые контейнеры STL;
2. Класс должен быть копируемым и непосредственно управлять выделяемым ресурсом;
3. Класс должен предоставлять операторы сравнения на равенство и неравенство. Сравнение
вещественных чисел должно происходить с контролируемой точностью, которая задаётся, например,
статическим полем класса;
4. Класс должен перегружать оператор вывода;
5. В случае некорректности аргументов должны кидаться исключения. К некорректным ситуациям
относятся обращение по несуществующему индексу, вызов операции сложения для двух векторов
разного размера и тому подобное;
6. Весь ввод-вывод должен осуществляться исключительно через std::cin и std::cout, без
использования (явного или неявного) си-шных потоков stdin и stdout.

## Вариант
Класс векторов вещественных чисел произвольного размера

Как минимум, предоставить:
1) Оператор [] для чтения/записи элемента вектора по указанному индексу;
2) Операторы сложения и вычитания векторов;
3) Оператор умножения, выполняющий скалярное произведение векторов;
4) Оператор умножения вектора на скаляр (обеспечить коммутативность);
5) Оператор деления вектора на скаляр.
