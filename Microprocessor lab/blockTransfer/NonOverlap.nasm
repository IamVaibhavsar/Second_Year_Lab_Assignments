;Non- Overlap block tranfer without string and with string

global _start
_start:

%macro disp 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro accept 2
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .text
menu:
	disp msg2,len2
	disp msg,len
	accept choice,02

mov al,byte[choice]
cmp al,31h
je without_string
cmp al,32h
je with_string
cmp al,33h
je exit

without_string:
	mov rsi,sarr
	mov rdi,darr

	a1:
		mov al,[rsi]
		mov [rdi],al
		inc rsi
		inc rdi
		dec byte[cnt]
		jnz a1
	
	disp msg1,len1
	
	mov rsi,darr

	a2:
		mov rax,[rsi]
		push rsi
		call displayproc
		pop rsi
		inc rsi
		dec byte[cnt1]
		jnz a2
	
	jmp menu

with_string:
	mov rsi,sarr
	mov rdi,darr

	CLD
	mov rcx,05
	rep movsb 
	
	disp msg1,len1
	mov rsi,darr

	a3:
		mov rax,[rsi]
		push rsi
		call displayproc
		pop rsi
		inc rsi
		dec byte[cnt2]
		jnz a3
	jmp menu

exit:
	mov rax,60
	mov rdi,0
	syscall

displayproc:	;display procedure for displaying darr

mov rsi,disparr+1
mov rcx,2
l4:mov rdx,0
   mov rbx,10h
   div rbx
   cmp dl,09h
   jle l5
   add dl,07h
l5:add dl,30h
   mov [rsi],dl
   dec rsi
   dec rcx
   jnz l4
   mov rax,1
   mov rdi,1
   mov rsi,disparr
   mov rdx,2
   syscall
   
ret


section .data

sarr db 01H,02H,03H,04H,05H
darr db 00H,00H,00H,00H,00H
cnt db 05
cnt1 db 05
cnt2 db 05

msg db "Menu",10
    db "1.Without_string",10
    db "2.with_string",10
    db "3.Exit",10
    db 10, "Enter choice",10
len equ $-msg

msg1 db 10,"Elements copied in destination array:"
len1 equ $-msg1

msg2 db "  ",10
len2 equ $-msg2

section .bss

disparr resb 02
choice resb 02


%ifdef COMMENT
Menu
1.Without_string
2.with_string
3.Exit

Enter choice
1

Elements copied in destination array:0102030405  
Menu
1.Without_string
2.with_string
3.Exit

Enter choice
2

Elements copied in destination array:0102030405  
Menu
1.Without_string
2.with_string
3.Exit

Enter choice
3

%endif

