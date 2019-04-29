;Write X86/64 ALP to convert 4-digit Hex number into its equivalent BCD number and 5-digit
;BCD number into its equivalent HEX number. Make your program user friendly to accept the
;choice from user for:
;(a) HEX to BCD b) BCD to HEX (c) EXIT.
;Display proper strings to prompt the user while accepting the input and displaying the result.
;(wherever necessary, use 64-bit registers)


global _start
_start:
section .text

%macro accept 2
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro disp 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

menu_label:
	disp menu,menulen
	disp cho,lenc
	
	accept choice,02
	mov al,byte[choice]
	
	cmp al,31h
	je bcd_hex
	
	;cmp al,32h
	;je hex_bcd
	
	cmp al,33h
	je exit

bcd_hex:
	mov bx,0000h
	mov [res],bx
	disp msg1,len1			;enter the number
	mov rsi,arr
	a3:	
		push rsi
		accept num,01		;[num]->al->sub 30H
		call convert_hex		;to convert to HEX (original number)
		pop rsi
		mov bx,[rsi]
		mul bx
		add [res],ax		;ans stored in ax
		add rsi,02
		dec byte[cnt]
		jnz a3
	
	disp res1,lres
	mov ax,[res]
	call display_hex			;to display the HEX output
	disp msg,len
	accept num,01
	jmp menu_label



hex_bcd:
	disp msg1,len1
	accept num,02
	call convert
	mov [no1],al
	
	accept num,03
	call convert		;to convert to original form
	mov [no2],al
	
	mov rsi,arr
	mov ah,[no1]
	mov al,[no2]
	
	r2:	mov bx,[rsi]
		mov dx,0
		div bx
		mov [rem],dx
		mov [t1],al
		
		push rsi
		call display_bcd		;[t1]->al-> add30 -> al ->[t1] -> disp t1,01		display the output BCD number
		pop rsi
		mov ax,[rem]
		add rsi,2
		dec byte[cnt1]
		jnz r2
	disp msg,len
	jmp menu_label


exit:
	mov rax,60
	mov rdi,0
	syscall

convert:
	mov rsi,num
	mov al,[rsi]
	cmp al,39h
	jle a1
	sub al,07h
	a1: 	sub al,30h
		rol al,04
		mov bl,al
		inc rsi
		
		mov al,[rsi]
		cmp al,39h
		jle a2
		sub al,07h
	a2: 
	sub al,30h
	add al,bl
ret


display_hex:			;(conventional display procedure)
	mov rsi, disparr+03
	mov rcx,04
	l4: 	mov rdx,0
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
		jnz l4
	mov rax,1
	mov rdx,1
	mov rsi,disparr
	mov rdx,04
	syscall
ret

display_bcd:
	mov al,[t1]
	add al,30h
	mov [t1],al
	disp t1,01

ret

convert_hex:
	mov al,[num]
	sub al,30h
ret

section .data

arr dw 2710h,03E8H,0064h,000Ah,0001h
cnt db 05
cnt1 db 05

menu: db "MENU for conversion: ",10
      db "1. BCD to Hex",10
      db "2. Hex to BCD",10
      db "3. Exit",10
menulen: equ $-menu

cho: db "Enter your choice: "
lenc: equ $-cho

msg: db " ",10
len: equ $-msg

msg1: db "Enter the number: "
len1: equ $-msg1

res1: db "Result: "
lres: equ $-res1

section .bss

disparr resb 02
choice resb 02
num resb 03
no1 resb 02
no2 resb 02	
t1 resb 02
rem resb 01
res resb 04



%ifdef COMMENT
MENU for conversion: 
1. BCD to Hex
2. Hex to BCD
3. Exit
Enter your choice: 1
Enter the number: 65535
Result: FFFF 
MENU for conversion: 
1. BCD to Hex
2. Hex to BCD
3. Exit
Enter your choice: 2
Enter the number: FFFF
65535 
MENU for conversion: 
1. BCD to Hex
2. Hex to BCD
3. Exit
Enter your choice: 3
%endif















