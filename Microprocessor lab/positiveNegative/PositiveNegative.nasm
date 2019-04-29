;Write X86/64 ALP to count number of positive and negative numbers from the array

global _start
_start:
section .text

%macro disp 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

disp msg1,lenm

mov rsi,arr

l2: 
push rsi
mov rax,[rsi]
call display
disp msg,len
pop rsi
add rsi,8
dec byte[cnt]
jnz l2

mov rsi,arr

l3: 
push rsi
bt qword[rsi],63
jc neg

inc byte[pcnt]
jmp next

neg: 
inc byte[ncnt]

next: 
pop rsi
add rsi,8
dec byte[cnt1]
jnz l3

disp positiveno,len1
mov ah,00h
mov al,byte[pcnt]
call display1
disp msg,len

disp negno,len2
mov ah,00h
mov al,byte[ncnt]
call display1
disp msg,len

mov rax,60
mov rdi,0
syscall

display:				;for 16 digit array
mov rsi, disparr+15
mov rcx,16

l1: 
mov rdx,0
mov rbx,10h
div rbx
cmp dl,09h
jbe add30
add dl,07h

add30: 
add dl,30h
mov [rsi],dl
dec rsi
dec rcx
jnz l1

mov rax,1
mov rdx,1
mov rsi,disparr
mov rdx,16
syscall
ret

display1:					;for 2 digit positive and negative count
mov rsi, disparr1+01
mov rcx,02

l4: 
mov rdx,0
mov rbx,10h
div rbx
cmp dl,09h
jbe add301
add dl,07h

add301: 
add dl,30h
mov [rsi],dl
dec rsi
dec rcx
jnz l4

mov rax,1
mov rdx,1
mov rsi,disparr1
mov rdx,16
syscall
ret


section .data
arr dq 1234567812345678h, 8765432112345678h, 8111111111111111h, 2222222222222222h, 3333333333333333h
cnt db 5
cnt1 db 5
msg: db " ",10
len: equ $-msg
msg1: db "The numbers in the array are: ",10
lenm: equ $-msg1
positiveno: db "Total number of positive numbers: "
len1: equ $-positiveno
negno: db "Total number of negative numbers: "
len2: equ $-negno


section .bss
disparr resb 16
disparr1 resb 16
pcnt resb 1
ncnt resb 1

%ifdef COMMENT
The numbers in the array are: 
1234567812345678 
8765432112345678 
8111111111111111 
2222222222222222 
3333333333333333 
Total number of positive numbers: 03 
Total number of negative numbers: 02 
%endif































