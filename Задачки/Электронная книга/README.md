# Электронная книга

*Вам даны задача и её решение — верное, но не удовлетворяющее заданным ограничениям на время работы.
Переработайте это решение и сдайте в систему.*

## Условие

Разработайте систему стимулирования чтения электронных книг. 
Для простоты будем считать, что книга всего одна, но её одновременно читают много людей.
Необходимо следить за прогрессом чтения у всех пользователей и выводить мотивирующие уведомления. 
А именно, ваша программа должна обрабатывать следующие события:
* __READ user page__ — сохранить факт того, что пользователь под номером user дочитал книгу до страницы page. 
Если ранее такой пользователь не встречался, необходимо его добавить. 
Гарантируется, что в рамках одного пользователя номера страниц в соответствующих ему событиях возрастают.

* __CHEER user__ — сообщить пользователю user, какая доля существующих пользователей (не считая его самого) прочитала меньшую часть книги,
чем он. Если этот пользователь на данный момент единственный, доля считается равной 1.
Если для данного пользователя пока не было ни одного события READ, доля считается равной 0,
а сам пользователь не учитывается при вычислении долей для других пользователей до тех пор, пока для него не случится событие READ.

## Формат входных данных
В первой строке вводится количество запросов Q — натуральное число, не превосходящее 10^6. В следующих Q строках в соответствии с описанным выше форматом вводятся запросы. Гарантируется, что все вводимые числа целые и положительные,
при этом номера пользователей не превосходят 10^5, а номера страниц не превосходят 1000.

## Формат выходных данных
Для каждого запроса CHEER user выведите единственное вещественное число от 0 до 1 — долю пользователей, прочитавших меньше страниц, чем user. Формат вывода этого числа должен быть в точности таким же, как в опубликованном ниже медленном решении.

## Ограничения
4 секунды на выполнение всех запросов. Все описанные в условии гарантии действительно справедливы для всех тестов, на которых будет запускаться ваша программа. Проверять корректность тестов не нужно.

## Пример

*Ввод*

```
12
CHEER 5
READ 1 10
CHEER 1
READ 2 5
READ 3 7
CHEER 2
CHEER 3
READ 3 10
CHEER 3
READ 3 11
CHEER 3
CHEER 1
```

*Вывод*

```
0
1
0
0.5
0.5
1
0.5
```
*Комментарии к примеру:*

Пользователь 5 не учитывается при вычислении долей, потому что для него не произошло ни одного события **READ**.

Пользователь 1 изначально был единственным, но в конце его обогнал 3-й, но не обогнал 2-й, поэтому он оказался продуктивнее 50 % пользователей.

Пользователь 3 изначально обгонял только 2-го и потому получал долю 50 %, но в конце обогнал 1-го и получил долю 100 %.

## [Правильное, но медленное решение](https://d3c33hcgiwev3.cloudfront.net/7YdiJmS5EeiQ1RJfHSpJKg_ee2eec2064b911e8a488d1e3a26d9d2c_slow.cpp?Expires=1557878400&Signature=jOU2FUlYh0~WdpFiY~joUYmrXiKpOAxbajXeI8yQ~kX3QR7jQb1EX0xE76X03mpYaQgGFRswJNylkce6CoIcOS9aLTGL4tkCZSlgxZhpPb6FbcuW0EJrTGDLzU7DcKJlp0CWJQjuyOqkN6uuT0ZB4f8WjATjDekse7teYHbSru8_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

## Подсказки
Если задача вызывает непреодолимые трудности, вы можете воспользоваться подсказками. Они помогут быстрее сдать задачу, но в итоге вы получите меньше пользы от процесса поиска решения.

Не нужно открывать все подсказки сразу. Используйте их последовательно.
[1](https://d3c33hcgiwev3.cloudfront.net/4f6F9efeEei5Kg7DUflKxA_e26cfeb0e7de11e880463dc9adc4d9bc_ebook-1.pdf?Expires=1557878400&Signature=gnqnKuuf~GH4rwtPr~unkDnW~EkoXTTpIutHaEypz894nLt0eikHyaGOO3pxf-zKKRSegNyv5lC5nBrCEGwGBcte96TcJhEGPN1hDkYVEyFfOYVZQkIzsPc8PnaXyYQa2nD7Y-c4Ty-qetD7mkoYC4RGiOZ~1h4FegKGQ6j5Wuc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
[2](https://d3c33hcgiwev3.cloudfront.net/4f6tLefeEeilxxL_ZeRz_A_e27478c0e7de11e89bf1032d5d05de4f_ebook-2.pdf?Expires=1557878400&Signature=NW5iRa505TVTrUPAkvudBM1pNXallxIeaZz9lvMZmsL3Njr0jO3LsF5yYqi5iBCCz-MHYOKEPaq7ZklEFoIfXVFg5dIz4A4SeTYl4m19BqcL2Q3rY4O8n97NUUtMDZN~Qms5kJwbAWNqfWMQyNKhuHHFBFDUp~L864HpmxI3dVE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
[3](https://d3c33hcgiwev3.cloudfront.net/4f9JAufeEeiaxBKyA9PBAg_e26f48a0e7de11e8b9ee51de5db3cbe5_ebook-3.pdf?Expires=1557878400&Signature=Y5Cxms0g6cWdkS0Rpo8WSFROMmj0iJjbTuEJOKLD1e~O11mSvUd7htG~hs8s441xjxax~gLgZkT2g~3gtxURvEtRRaBXKXwHvHUSQXejt-kfzWSAKquFPJZxtoq0YQmnKWJvZovzI7J~wbai7sTul39g1vM5rkxOfYSfk0HrcTE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
[4](https://d3c33hcgiwev3.cloudfront.net/4f9JAefeEeiaxBKyA9PBAg_e2727cf0e7de11e8ba36791774dc29a3_ebook-4.pdf?Expires=1557878400&Signature=gh0guq6LWjFqBqc9LdV4zdjlMQ~20tfDFQAfEItcDnSuZ4JfPxZQ32UchXjktmpL-22wUxr2iPtwVXSasgxJdyExKSbb5enI68-yj3h0jIgFFhft4XUqvrCGRHiAQktPYIYc2~Sb99laQbf-ZJN2Hm1yATaQUaCtqnlY7OhKCL8_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
[5](https://d3c33hcgiwev3.cloudfront.net/4gQEgefeEeiTKQ5ajE7PqA_e26ed370e7de11e88c94d51cedeec544_ebook-5.pdf?Expires=1557878400&Signature=cvpugW9Q~eb2yotnI8iQoh49-L1O~as002owTS~66TtvzxLsHpJOto8qNVel2sRSmf6tSunp1Z~jiFOhjkAIRNDs2aknPoHeJ-CsTmRyFsLZo8QSo7D5ygRLa4WfNxFaU04pzEZX2V6r64nkMRGlncCszYELuQhoicG3z9~DjKI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
