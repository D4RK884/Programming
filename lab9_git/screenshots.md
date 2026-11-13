# Скриншоты к лабораторной работе 9

Ветка master в этом репозитории называется main.

## Часть 1. Коммиты

### Пункт 1. На какой ветке мы находимся
![пункт 1](images/p1.png)

`git status` показывает текущую ветку: main.

### Пункт 2. Журнал коммитов
![пункт 2](images/p2.png)

Так выглядит `git log`: список коммитов с хешем, автором, датой и сообщением.

### Пункты 3-4. Создан sort.c, состояние git status
![пункты 3-4](images/p3-4.png)

Файл sort.c создан, но Git его ещё не отслеживает (Untracked files).

### Пункты 5-6. Файл добавлен в stage
![пункты 5-6](images/p5-6.png)

После `git add sort.c` файл попал в Changes to be committed.

### Пункты 7-8. Коммит файла
![пункты 7-8](images/p7-8.png)

После `git commit` рабочая директория чистая: nothing to commit, working tree clean.

### Пункты 9-10. Добавлен комментарий в файл
![пункты 9-10](images/p9-10.png)

Файл изменён, но не добавлен в stage: Changes not staged for commit, modified: sort.c.

### Пункты 11-12. Изменение добавлено в stage
![пункты 11-12](images/p11-12.png)

После `git add sort.c` изменение подготовлено к коммиту (Changes to be committed).

### Пункты 13-15. Ещё одно изменение, коммит, статус и журнал
![пункты 13-15](images/p13-15.png)

![пункт 15, журнал](images/p15-log.png)

После коммита `git status` показывает новые правки, а в `git log` видны оба коммита по sort.c.

### Пункт 16. Последнее изменение добавлено и закоммичено
![пункт 16](images/p16.png)

### Пункт 17. Отправка на удалённый репозиторий
![пункт 17](images/p17.png)

`git push` отправил коммиты на GitHub.

## Часть 2. Ветки

### Пункты 1-2. Создание ветки mybranch
![ветки, пункты 1-2](images/br_p1-2.png)

`git branch mybranch` создаёт ветку, `git branch` показывает список, текущая ветка отмечена звёздочкой.

### Пункты 3-4. Переключение на mybranch
![ветки, пункты 3-4](images/br_p3-4.png)

После `git switch mybranch` в `git status` меняется первая строка: On branch mybranch.

### Пункты 4-5. git status на main
![ветки, пункты 4-5](images/br_p4-5-main.png)

На main первая строка: On branch main. Остальной вывод одинаковый, потому что в mybranch ещё нет новых коммитов. Перед продолжением мы вернулись на mybranch.

### Пункты 6-7. Файл file1.txt и коммит
![ветки, пункты 6-7](images/br_p6-7.png)

Создан file1.txt с именем, файл добавлен и закоммичен в ветке mybranch.

### Пункт 8. Граф коммитов в mybranch
![ветки, пункт 8](images/br_p8.png)

`git log --oneline --graph`: ветка mybranch указывает на новый коммит.

### Пункты 9-10. Возврат на main
![ветки, пункты 9-10](images/br_p9-10.png)

После `git switch main` в журнале нет коммита с file1.txt: он остался только в mybranch.

### Пункт 11. Файл file2.txt в main
![ветки, пункт 11](images/br_p11.png)

Создан file2.txt и закоммичен в ветке main.

### Пункт 12. Граф всех веток
![ветки, пункт 12](images/br_p12.png)

`git log --oneline --graph --all`: у main и mybranch теперь разные коммиты, история разошлась.

### Пункты 13-14. Возврат на mybranch, пропал ли file2.txt
![ветки, пункты 13-14](images/br_p13-14.png)

Да, file2.txt пропал: он был закоммичен только в main, поэтому в mybranch его нет.

### Пункт 15. Разница между ветками
![ветки, пункт 15](images/br_p15.png)

`git diff mybranch main` показывает различия между ветками: file1.txt есть только в mybranch, file2.txt только в main.

### Пункт 17. Две ветки на GitHub
После `git push -u origin mybranch` и `git push` на github.com отображаются обе ветки: main и mybranch.
