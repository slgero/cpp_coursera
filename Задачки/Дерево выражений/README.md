# Дерево выражений

В этой задаче мы воспользуемся умным указателем unique_ptr для управления временем жизни дерева полиморфных объектов. А конкретнее, будем работать с деревом арифметического выражения. Узлами дерева будут числа и операции.

Например, выражение "2*(3+4)" будет представлено вот таким деревом:

![Alt-текст](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/EeaWw_ZJEeilxxL_ZeRz_A_75fbca3acbde22cfd3e622279aadab79_tree.png?expiry=1558051200000&hmac=xKVTcVDG9IK9iwkYygB34yOhNn_qUAliOesWfKdSOLI)

В программе узлы дерева представляются объектами типов, унаследованных от интерфейса Expression, который объявлен в файле Common.h. У интерфейса есть два метода:

* Evaluate() возвращает численное значение выражения. Для нашего примера это будет 14.
* ToString() форматирует выражение как строку. Для простоты реализации, чтобы не учитывать приоритеты операций, каждый узел берётся в скобки. То есть для нашего примера этот метод вернёт "(2)*((3)+(4))".

Так как Expression — это абстрактный класс, работать с ним можно только через указатель или ссылку. Чтобы не заниматься ручным управлением памятью, будем использовать умный указатель unique_ptr. Чтобы не загромождать код выражениями unique_ptr<Expression>, в файле Common.h для этого выражения предоставлен синоним ExpressionPtr.

Дерево создаётся с помощью функций, объявленных далее в файле Common.h:

* Value() возвращает дерево из одного узла, представляющего целое число.
* Sum() возвращает новое дерево, которое представляет сумму двух переданных выражений.
*Product() возвращает новое дерево, которое представляет произведение двух переданных выражений.

Таким образом, следующий код создаст дерево для выражения "2*(3+4)":

```cpp
Product(Value(2), Sum(Value(3), Value(4)));
```
На проверку пришлите cpp-файл, который

* подключает заголовочный файл Common.h
* содержит реализацию функций Product(), Value() и Sum()

Заготовка решения содержится в файле main.cpp

## Заготовка решения

[Common.h](https://github.com/slgero/cpp_coursera/blob/master/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%BA%D0%B8/%D0%94%D0%B5%D1%80%D0%B5%D0%B2%D0%BE%20%D0%B2%D1%8B%D1%80%D0%B0%D0%B6%D0%B5%D0%BD%D0%B8%D0%B9/%D0%97%D0%B0%D0%B3%D0%B0%D1%82%D0%BE%D0%B2%D0%BA%D0%B8%20%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D1%8F/Common.h)

[main.cpp](https://github.com/slgero/cpp_coursera/blob/master/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%BA%D0%B8/%D0%94%D0%B5%D1%80%D0%B5%D0%B2%D0%BE%20%D0%B2%D1%8B%D1%80%D0%B0%D0%B6%D0%B5%D0%BD%D0%B8%D0%B9/%D0%97%D0%B0%D0%B3%D0%B0%D1%82%D0%BE%D0%B2%D0%BA%D0%B8%20%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D1%8F/main.cpp)

## Подсказки

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся решить задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но сначала обязательно попробуйте решить задачу без подсказок.

[Подсказка 1](https://d3c33hcgiwev3.cloudfront.net/V6IquPbhEei5Kg7DUflKxA_57ce4310f6e111e882cf5b014df25ce8__________-1.pdf?Expires=1558051200&Signature=FGPuDI83-GUrol8-Wokn~yQ~-8wNuA6C9VLSCKOjWGHj2KcmhseLpAhhRSGw~NzAwgQB7t39BzMhDHij5cy~kUoz74EDX5tfXOExVESdrP~yuRYNa2-QHcuqcC9D4AIJXSQWVN5mXtn0rZtRf68z5ukFFb1bzUInSaKNxCH7nWc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[Подсказка 2](https://d3c33hcgiwev3.cloudfront.net/V6TpavbhEeiAgQrXx6bp4g_57ce6a20f6e111e88717b75766913400__________-2.pdf?Expires=1558051200&Signature=d1qi~Ti2Uc0llTkdZJTJyQItS3LpGUqBA62lm9xsYFRWiVqjHxVVp8pBzW5oD~10sRtiXGz4FgUvm2gjlqgKHVRuoq82I89GHnhyB5row9ryA~WZpJn92jxs8z1YYJoYLaQh6qlmmB5cCiYzyIKqyLU3d1P9AUYAu~O~f7F02cQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)



