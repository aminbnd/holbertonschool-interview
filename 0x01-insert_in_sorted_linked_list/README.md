# 0x01. Insert in sorted linked list
## Problem:
* You are not allowed to google anything
* Whiteboard first<br><br>
Write a function in C that inserts a number into a sorted singly linked list.<br><br>
* Prototype: listint_t *insert_node(listint_t **head, int number);
* Return: the address of the new node, or NULL if it failed
## Expected output
```
carrie@ubuntu:0x01$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
carrie@ubuntu:0x01$ ./insert
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
carrie@ubuntu:0x01$
```