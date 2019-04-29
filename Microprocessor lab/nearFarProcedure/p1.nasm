%include "macro.nasm"

;Write X86 ALP to find, a) Number of Blank spaces b) Number of lines c) Occurrence of a
;particular character. Accept the data from the text file. The text file has to be accessed during
;Program_1 execution and write FAR PROCEDURES in Program_2 for the rest of the
;processing. Use of PUBLIC and EXTERN directives is mandatory.



global _start

_start :
global buff,abufflen
extern proc1

section .text 
pop rcx
pop rcx
pop rcx				;we will get filename in rcx by popping 3 times

mov [filename],rcx
fopen [filename]
cmp rax,-1H
je error
mov [filehandler],rax

fread [filehandler],buff,bufflen
dec rax
mov [abufflen],rax

call proc1
jmp exit

error : display errormsg,errorlen

exit :
fclose [filehandler]
mov rax,60
mov rdi,0
syscall


section .data

errormsg db "File is Empty",10
errorlen: equ $-errormsg

section .bss
filename resb 64
filehandler resb 16
buff resb 64
bufflen resb 64
abufflen resb 64









