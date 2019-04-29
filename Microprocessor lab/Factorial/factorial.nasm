%include "macro1.nasm"

;Write x86 ALP to find the factorial of a given integer number on a command line by using
;recursion. Explicit stack manipulation is expected in the code.

global _start:
_start:

section .text

disp m1,c1			;Enter the number:"
accept num,03
call convert
mov [no],al			;add al, bl of convert procedure

cmp al,01h
ja f1				;jump if above (for n greater than 1)
disp m2,l2			; (if n=0 and n=1)	is the Factorial of number",
jmp Exit

f1:
mov rcx,rax			
dec rcx

f2:
push rax
dec rax
cmp rax,01
ja f2

f3:
pop rbx
mul rbx
dec rcx 
jnz f3

call displayproc
disp m2,l2			;_____ is the Factorial of number",

Exit:	mov rax,60
	mov rdi,0
	syscall



convert:
mov rsi,num			;num is accepted from user
mov al,[rsi]
cmp al,39h
jle sub30
sub al,07h

sub30:	
	sub al,30h
	rol al,04
	mov bl,al
	inc rsi
	
	mov al,[rsi]
	cmp al,39h
	jle a3
	sub al,07h
	
a3:	sub al,30h
	add al,bl
ret

displayproc:
mov rsi,disparr+3
mov rcx,4

l3:
mov rdx,0
mov rbx,10h
div rbx
cmp dl,09h
jbe l1
add dl,07h

l1:
add dl,30h
mov [rsi],dl
dec rsi
dec rcx
jnz l3

disp disparr,4
ret

section .data
m1 db 10,"Enter the number:"
c1 equ $-m1

m2 db " is the Factorial of number",10
l2 equ $-m2

m3 db 10
c3 equ $-m3

section .bss
num resb 03
no resb 02
disparr resb 16




