%macro fopen 1 
	mov rax, 2
	mov rdi, %1		;variable of filename
	mov rsi, 2		; 2 for R/W mode and 0 for read-only mode	1 for write mode
	mov rdx, 0777o	; 0777o(octal number)	permissions- read write and execute
	syscall		;returns rax=filehandle and if rax=-1 then error in opening file
%endmacro

%macro fclose 1
	mov rax, 3	
	mov rdi, %1		;filehandle
	syscall
%endmacro

%macro fdelete 1
	mov rax, 87
	mov rdi, %1		;filename
	syscall
%endmacro

%macro fread 3 
	mov rax, 0
	mov rdi, %1		;filehandle (source)
	mov rsi, %2		;buffer (destination)
	mov rdx, %3		;buffer_length
	syscall		; returns rax= total actual size of file
%endmacro

%macro fwrite 3 
	mov rax, 0
	mov rdi, %1		;filehandle (destination)
	mov rsi, %2		;buffer (source)
	mov rdx, %3		;buffer_length
	syscall
%endmacro


%macro display 2  
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

%macro accept 2 
	mov rax, 0
	mov rdi, 0
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro



;function numbers
;0-read/accept
;1-write
;2-fopen
;3-fclose
;87-delete













