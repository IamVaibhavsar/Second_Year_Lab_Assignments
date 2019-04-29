global _start
_start:

section .text

mov rax,1
mov rdi,1
mov rsi,msg
mov rdx,len
syscall

mov rsi,arr
mov rax,[rsi]
call display

mov rax,60
mov rdi,0
syscall

display:
mov rsi,disparr+15
mov rcx,16
l1:
mov rdx,0
mov rbx,10h
div rbx

cmp dl,09h
jbe add30
add dl,07

add30:
add dl,30h
mov [rsi],dl
dec rsi
dec rcx
jnz l1

mov rax,1
mov rdi,1
mov rsi,disparr
mov rdx,16
syscall
ret

section .data
msg:db"the no is:",10
len:equ $-msg
arr dq 1234567812345678h
section .bss
disparr resb 16

/*
o/p:
superuser@superuser-HP-Compaq-dx7400-Microtower:~$ cd Desktopsuperuser@superuser-HP-Compaq-dx7400-Microtower:~/Desktop$ nasm -f elf64 -o assgb.o assgb.nasm 
superuser@superuser-HP-Compaq-dx7400-Microtower:~/Desktop$ ld -o v assgb.osuperuser@superuser-HP-Compaq-dx7400-Microtower:~/Desktop$ ./v
the no is:
1234567812345678
superuser@superuser-HP-Compaq-dx7400-Microtower:~/Desktop$ 
*/

