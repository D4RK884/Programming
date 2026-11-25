# Лабораторная работа 9. Git. Отчёт на оценку 4

Работа выполнена в ветке `mybranch`, в файле `lab9_git/sort.c`. Файл `sort.c` и ветка `mybranch` были созданы ещё в части на оценку 3.

## Шаг 1. Переключение на ветку mybranch

```bash
git switch mybranch
git status
```

![git switch](screenshots/grade4/s01a_switch.png)

![git status](screenshots/grade4/s01b_status.png)

Я на ветке `mybranch`, она синхронизирована с `origin/mybranch`.

## Шаг 2. Добавляем main() в sort.c

![sort.c с main](screenshots/grade4/s02_sort_main.png)

Содержимое `sort.c` заменено: сверху функция сортировки `bubble_sort`, ниже `main()` с массивом `int a[] = {4, 2, 0};` и вызовом сортировки.

## Шаг 3. git diff

```bash
git diff lab9_git/sort.c
```

![git diff](screenshots/grade4/s03_diff.png)

`git diff` сравнивает рабочую папку с индексом. Файл ещё не добавлен в stage, поэтому показаны все правки: старая функция (`-`) заменена новым кодом (`+`). Строки `:...skipping...` появились из-за постраничного просмотра.

## Шаг 4. git diff --staged

```bash
git diff --staged
```

![git diff --staged, пусто](screenshots/grade4/s04_diff_staged_empty.png)

Вывод пустой. `git diff --staged` сравнивает индекс с последним коммитом, а в индексе пока ничего нет.

## Шаг 5. Добавляем sort.c в stage

```bash
git add lab9_git/sort.c
```

![git add](screenshots/grade4/s05_add.png)

## Шаг 6. git diff после add

```bash
git diff lab9_git/sort.c
```

![git diff пустой](screenshots/grade4/s06_diff_empty.png)

Вывод пустой: рабочая папка совпадает с индексом, сравнивать нечего.

## Шаг 7. git diff --staged после add

```bash
git diff --staged lab9_git/sort.c
```

![git diff --staged](screenshots/grade4/s07_diff_staged.png)

Теперь виден весь diff: это изменения, которые попадут в следующий коммит (индекс против последнего коммита).

## Шаг 8. Удаляем число из массива

![массив {4, 2}](screenshots/grade4/s08_edit_array.png)

В `main()` массив теперь `int a[] = {4, 2};`, число `0` удалено.

## Шаг 9. git diff

```bash
git diff lab9_git/sort.c
```

![git diff](screenshots/grade4/s09_diff.png)

Показана только последняя правка: строка `{4, 2, 0}` (`-`) заменена на `{4, 2}` (`+`). Это разница между рабочей папкой и индексом. (`^M` в конце строки это символ CRLF.)

## Шаг 10. git diff --staged

```bash
git diff --staged lab9_git/sort.c
```

![git diff --staged](screenshots/grade4/s10_diff_staged.png)

Вывод длинный, как на шаге 7: в индексе лежит версия, добавленная до удаления числа, то есть с массивом `{4, 2, 0}`.

## Шаг 11. Что происходит

У файла `sort.c` теперь две разные версии изменений. В индексе лежит версия с `{4, 2, 0}` (она добавлена командой `git add`). В рабочей папке лежит более новая версия с `{4, 2}`. `git diff` показывает разницу между рабочей папкой и индексом (удаление числа), а `git diff --staged` показывает разницу между индексом и последним коммитом (весь `main()`). Если сейчас сделать коммит, в него попадёт версия из индекса, то есть с `{4, 2, 0}`, а удаление числа останется незакоммиченным.

## Шаг 12. git status: sort.c дважды

```bash
git status
```

![git status](screenshots/grade4/s12_status_twice.png)

`lab9_git/sort.c` встречается два раза: зелёным в «Changes to be committed» (версия в индексе) и красным в «Changes not staged for commit» (версия в рабочей папке).

## Шаг 13. git restore --staged

```bash
git restore --staged lab9_git/sort.c
```

![git restore --staged](screenshots/grade4/s13_restore_staged.png)

Файл убран из индекса. Правки в самом файле при этом сохранились.

## Шаг 14. git status после restore --staged

![git status](screenshots/grade4/s14_status.png)

Теперь `sort.c` один раз, только в «Changes not staged for commit». Раздела «Changes to be committed» больше нет.

## Шаг 15. Индексируем и коммитим

```bash
git add lab9_git/sort.c
git commit -m "Add main to sort.c"
```

![add и commit](screenshots/grade4/s15_commit.png)

В коммит попала версия с массивом `{4, 2}`. Добавлял я только `sort.c`, а не `git add .`, чтобы в коммит не попали `lab2`-`lab8`.

## Шаг 16. Журнал

```bash
git log --oneline
```

![git log --oneline](screenshots/grade4/s16_log.png)

Наверху новый коммит `Add main to sort.c` (`HEAD -> mybranch`). `origin/mybranch` находится на один коммит позади, потому что я ещё не делал push.

## Шаги 17-18. Добавляем printf и смотрим файл

В `main()` перед `return 0;` добавлена строка `printf("hello git\n");`.

```bash
cat lab9_git/sort.c
```

![cat sort.c](screenshots/grade4/s18_cat_printf.png)

В файле видна строка с `printf`.

## Шаг 19. git status

```bash
git status
```

![git status](screenshots/grade4/s19_status.png)

`lab9_git/sort.c` изменён, но не добавлен в stage. Также git пишет, что ветка опережает `origin/mybranch` на 1 коммит.

## Шаги 20-21. git restore и содержимое sort.c

```bash
git restore lab9_git/sort.c
cat lab9_git/sort.c
```

![restore и cat](screenshots/grade4/s20_21_restore_cat.png)

`git restore` откатил файл к состоянию последнего коммита. Строка с `printf` пропала.

## Шаг 22. git status после restore

```bash
git status
```

![git status](screenshots/grade4/s22_status.png)

`lab9_git/sort.c` в списке изменённых больше нет. Незакоммиченных правок в нём не осталось.

## Шаг 23. Push ветки

```bash
git push
```

## Ветки и ff-merge

Этот блок выполнен на ветке `main`, потому что в конце нужно влить изменения в главную ветку.

### Шаг 1. Создаём greeting.txt и коммитим

```bash
touch lab9_git/greeting.txt
git add lab9_git/greeting.txt
git commit -m "Add file greeting.txt"
```

![создание greeting.txt](screenshots/grade4/b01_greeting_create.png)

Файл создан пустым. В `git status` он был в «Untracked files», после `git add` и `git commit` попал в историю.

### Шаг 2. Добавляем слово hello

```bash
echo "hello" > lab9_git/greeting.txt
git add lab9_git/greeting.txt
git commit -m "Add content to greeting.txt"
```

![hello в greeting.txt](screenshots/grade4/b02_greeting_hello.png)

В файл записано `hello`, изменение закоммичено вторым коммитом.

### Шаги 3-4. Создаём ветку feature/uppercase и переключаемся на неё

```bash
git branch feature/uppercase
git switch feature/uppercase
```

![создание ветки и переключение](screenshots/grade4/b03_branch_switch.png)

`git branch` создал ветку, но не переключился на неё. Переключение сделал `git switch`.

### Шаг 5. git status

```bash
git status
```

![git status на feature/uppercase](screenshots/grade4/b05_status_feature.png)

Первая строка вывода `On branch feature/uppercase`: я на новой ветке.

### Шаги 6-7. Меняем hello на HELLO и коммитим

Содержимое `greeting.txt` заменено на `HELLO`.

```bash
git add lab9_git/greeting.txt
git commit -m "Hello в верхнем регистре"
```

![коммит HELLO](screenshots/grade4/b07_commit_uppercase.png)

Коммит создан в ветке `feature/uppercase`: она указана в квадратных скобках.

### Шаг 8. git branch

```bash
git branch
```

![git branch](screenshots/grade4/b08_branch.png)

Звёздочка стоит у `feature/uppercase`, значит, это текущая ветка. В списке также `main` и `mybranch`.

### Шаг 9. git log --oneline --graph --all

```bash
git log --oneline --graph --all
```

![git log --graph --all](screenshots/grade4/b09_log_graph.png)

`feature/uppercase` на один коммит впереди `main`. Ветки пока не разошлись, поэтому линия графа прямая.

### Шаги 10-11. Переключаемся на main и смотрим файл

```bash
git switch main
cat lab9_git/greeting.txt
```

![switch main и cat](screenshots/grade4/b10_11_switch_main_cat.png)

В `main` файл содержит `hello` строчными: изменение сделано в другой ветке и сюда ещё не слито. Первая команда `cat greeting.txt` не сработала из-за пути: файл лежит в папке `lab9_git`.

### Шаг 12. Сравниваем ветки

```bash
git diff main feature/uppercase
```

![git diff между ветками](screenshots/grade4/b12_diff.png)

Единственное различие между ветками: строчное `hello` (`-`) заменено на заглавное `HELLO` (`+`).

### Шаг 13. Объединяем ветки

```bash
git merge feature/uppercase
```

![git merge feature/uppercase](screenshots/grade4/b13_merge_ff.png)

Слияние прошло как fast-forward: после создания `feature/uppercase` в `main` не было новых коммитов, поэтому git просто передвинул указатель `main` вперёд. Отдельный коммит слияния не создавался.

### Шаг 14. Содержимое файла после слияния

```bash
cat lab9_git/greeting.txt
```

![cat после слияния](screenshots/grade4/b14_cat_upper.png)

Теперь в `main` файл содержит `HELLO`.

### Шаг 15. Удаляем ветку feature/uppercase

```bash
git branch -d feature/uppercase
git branch
```

![удаление ветки](screenshots/grade4/b15_branch_delete.png)

Ветка удалена, потому что её изменения уже есть в `main`. Остались `main` и `mybranch`.

### Шаг 16. Сливаем mybranch в main (с конфликтом)

```bash
git merge mybranch
```

![git merge mybranch](screenshots/grade4/b16_merge_conflict.png)

Ветки разошлись, поэтому слияние не fast-forward. Git автоматически слил все файлы, кроме корневого `README.md`: его строка менялась и в `main` (на сайте GitHub), и в `mybranch`. Возник конфликт.

В VSCode файл выглядел так:

![маркеры конфликта](screenshots/grade4/b16_conflict_markers.png)

Между `<<<<<<< HEAD` и `=======` версия из `main`, между `=======` и `>>>>>>> mybranch` версия из `mybranch`. Я выбрал «Принять текущее изменение», маркеры исчезли:

![конфликт разрешён](screenshots/grade4/b16_conflict_resolved.png)

Затем файл добавлен в индекс и слияние закоммичено:

```bash
git add README.md
git commit --no-edit
```

### Шаг 17. git log --oneline --graph --all

```bash
git log --oneline --graph --all
```

![журнал после слияния](screenshots/grade4/b17_log_merge.png)

Наверху коммит слияния `Merge branch 'mybranch'` с двумя родителями. На графе видно, что `main` и `mybranch` разошлись после коммита `izm nazv README.md`, а теперь сходятся в одном коммите. Строка `:...skipping...` появилась из-за постраничного просмотра.

### Шаг 18. Push ветки main

```bash
git push
```

![git push main](screenshots/grade4/b18_push.png)

Ветка `main` отправлена на GitHub (`main -> main`): ушли коммиты с `greeting.txt` и коммит слияния.

### Шаг 19. Документ с результатами

Отчёт добавлен в репозиторий и запушен.

