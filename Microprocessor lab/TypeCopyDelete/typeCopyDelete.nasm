%include"macro.nasm"

;Write X86 menu driven Assembly Language Program (ALP) to implement OS (DOS) commands TYPE, COPY and DELETE using file operations. 
;User is supposed to provide command line arguments in all cases.

global _start
_start:
section .text

menu:
	display msg4,len4
	display msg1,len1
	
	read choice,02
	mov al,byte[choice]
	
	cmp al,31H
	je typec
	
	cmp al,32H
	je copyc
	
	cmp al,33H
	je deletec
	
	cmp al,34H
	je exit
	
	typec:
		pop rcx         			;3
		pop rcx         			;assg6.asm
		pop rcx         			;t1.txt
		mov [filename1],rcx
		fopen [filename1]
		cmp rax,-1H
		je error
		mov [filehandle1],rax
		
		fread [filehandle1],buffer,buf_len
		dec rax
		mov [ac_buf_len],rax
		
		display buffer,[ac_buf_len]
		jmp menu
		
	copyc:
		pop rcx       		;t2.txt
		mov [filename2],rcx
		fopen [filename2]
		cmp rax,-1H
		je error
		mov [filehandle2],rax
		
		fwrite [filehandle2],buffer,[ac_buf_len]
		fclose [filehandle1]
		fclose [filehandle2]
		jmp menu
	
	deletec:
		fdelete [filename1]
		cmp rax,-1H
		je delete_error
		jmp menu
	
	error:
		display msg2,len2
		
	delete_error:
		display msg3,len3
	
	exit:
		mov rax,60
		mov rdi,0
		syscall
		
section .data

msg1 db "Menu",10
     db "1.Type",10
     db "2.Copy",10
     db "3.Delete",10
     db "4.Exit",10
     db "Enter choice",10
len1 equ $-msg1

msg2 db 10,"file opening is unsuccessful"
len2 equ $-msg2

msg3 db 10,"file deletion is unsuccessful"
len3 equ $-msg3

msg4 db "",10
len4 equ $-msg4

section .bss
filename1 resb 100
filename2 resb 100
buffer resb 100
buf_len resb 100
ac_buf_len resb 100
filehandle1 resb 100
filehandle2 resb 100
choice resb 02	
	
	

