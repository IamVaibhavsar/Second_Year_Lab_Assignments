;Overlap block tranfer without string and with string

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

mov rsi,arr1
mov rdi,arr1
add rsi,09
add rdi,13

a1:
	mov al,[rsi]
	mov [rdi],al
	dec rsi 
	dec rdi
	dec byte[cnt1]
	jnz a1

disp msg1,len1
mov rsi,arr1

a2:
	mov rax,[rsi]
	push rsi
	call displayproc
	pop rsi
	inc rsi
	dec byte[cnt2]
	jnz a2

jmp menu

with_string:

mov rsi,arr2
mov rdi,arr2
add rsi,09
add rdi,13
STD 
mov rcx,10
rep movsb
disp msg1,len1
mov rsi,arr2
a3:
		mov rax,[rsi]
		push rsi
		call displayproc
		pop rsi
		inc rsi
		dec byte[cnt3]
		jnz a3

jmp menu
	
exit:
mov rax,60
mov rdi,0
syscall

displayproc:	;display procedure for displaying arr

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

arr1 db 01H,02H,03H,04H,05H,06H,07H,08H,09H,0AH,0BH,0CH,0DH,0EH,0FH
arr2 db 01H,02H,03H,04H,05H,06H,07H,08H,09H,0AH,0BH,0CH,0DH,0EH,0FH
cnt1 db 10
cnt2 db 15
cnt3 db 15

msg db "Menu",10
    db "1.Without_string",10
    db "2.with_string",10
    db "3.Exit",10
    db "Enter choice",10
len equ $-msg

msg1 db 10,"Elements copied in array:",10
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

Elements copied in array:
010203040102030405060708090A0F  
Menu
1.Without_string
2.with_string
3.Exit
Enter choice
2

Elements copied in array:
010203040102030405060708090A0F  
Menu
1.Without_string
2.with_string
3.Exit
Enter choice
3
%endif

