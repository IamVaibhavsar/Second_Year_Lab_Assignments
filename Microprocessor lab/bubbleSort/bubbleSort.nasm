%include"macro.nasm"

;Write X86 program to sort the list of integers in ascending/descending order. Read the input
;from the text file and write the sorted data back to the same text file using bubble sort

global _start
_start:

section .text

pop rcx         ;3
pop rcx         ;assg8.asm
pop rcx         ;t3.txt

mov [filename],rcx
fopen [filename]
cmp rax,-1H
je error
mov [filehandle],rax
fread [filehandle],buffer,buf_len
dec rax
mov [ac_buf_len],rax

display buffer,[ac_buf_len]

call bubble_sort

fwrite [filehandle],buffer,[ac_buf_len]

fclose [filehandle]


jmp exit
error:
		display msg2,len2
exit:
mov rax,60
mov rdi,0
syscall

bubble_sort:
	mov cl,byte[ac_buf_len]
	mov [cnt1],cl					;cnt1=total no. of elements
	
	ol:
		mov cl,byte[ac_buf_len]
		dec cl					;no of passes
		mov [cnt2],cl				;cnt2=number of elements-1
		
		mov rsi,buffer
		mov rdi,buffer
		inc rdi
	
	il:
		mov al,[rsi]
		mov bl,[rdi] 
		cmp al,bl
		jbe l1
		
		mov [rsi],bl				;swapping 
		mov [rdi],al
		
		l1:
			inc rsi
			inc rdi
		
		dec byte[cnt2]
		jnz il
		dec byte[cnt1]
		jnz ol

ret

section .data
msg2 db 10,"file opening is unsuccessful"
len2 equ $-msg2

section .bss
filename resb 100
buffer resb 100
buf_len resb 100
ac_buf_len resb 100
filehandle resb 100
cnt1 resb 50
cnt2 resb 50

