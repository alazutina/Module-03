### Проект - Work-stealing деки в двухуровневой памяти. Минимизация средних затрат на перераспределение ###

#### Описание проекта ####
Рассмотрена задача оптимального управления work-stealing деком в двухуровневой памяти. Работа выполнена в рамках гранта РФФИ. Опубликована статья.

#### Задача ####
Предполагается, что известны вероятности параллельных операций с деком и размер быстрой памяти. Задача состоит в нахождении оптимального числа элементов с двух сторон дека, которые при перераспределении дека должны быть оставлены в быстрой памяти.
В качестве критерия оптимальности рассмотрены минимальные средние затраты на перераспределение памяти. Такой критерий позволяет учитывать конкретные скорости доступа к уровням памяти и применять разработанные методы к разным сочетаниям быстрой и медленной памяти. 

#### Реализация ####

Построены математическая и имитационные модели, описывающие работу деков. Разработаны алгоритм и программы вычисления вычисления оптимального математического ожидания и среднего времени работы дека. Написаны соответсвующие программы.

#### Математическая модель ####

Построена математическая модель, описывающая поведение дека в двухуровневой памяти, в виде случайного блуждания по целочисленной пирамиде с отражающими и поглощающими экранами. Доказана теорема в виде матрицы переходных вероятностей поглащающей цепи Маркова. Разработаны алгоритм и программы вычисления математического ожидания.

#### Имитационная модель ####

Реализована имитационную модель по методу Монте-Карло. Входные параметры модели: размер быстрой памяти и вероятности работы с деком. Отрезок от 0 до 1 делится в соответствии с вероятностями. С помощью датчика случайных определяется вероятность и то, какая операция произошла. Считается время до перераспределения. Количество экспериментов 1 000 000. Вычисляеется среднее время до перераспределения.

#### Стек технологий ####
C, компилятор gcc
