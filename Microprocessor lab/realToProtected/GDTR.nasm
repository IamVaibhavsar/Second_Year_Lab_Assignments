;Write X86/64 ALP to switch from real mode to protected mode and display the values of
;GDTR, LDTR, IDTR, TR and MSW Registers.

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
	
	smsw eax			; smsw
	mov [cro_data],eax
	bt eax,00			;PE(Protection Enable) present in CR0, PE=1 then protection mode otherwise real mode(PE=0)
	jc prot_mode		;PE=1 switch to protected mode
	
	disp realmsg,reallen
	jmp exit
	
	prot_mode:	disp protmsg,protlen
			disp cr0msg,cr0len
			mov ax,[cro_data+2]
			call display
			mov ax,[cro_data]
			call display
	disp msg,len
	disp ldtrmsg,ldtrlen
	sldt [ldtrdata]			;sldt
	mov ax,[ldtrdata]
	call display
	
	disp msg,len
	disp gdtrmsg,gdtrlen
	sgdt [gdtrdata]			;sddt
	mov ax,[gdtrdata+4]
	call display
	mov ax,[gdtrdata+2]
	call display
	mov ax,[gdtrdata] 
	call display
	
	disp msg,len
	disp idtrmsg,idtrlen
	sidt [idtrdata]			;sidt
	mov ax,[idtrdata+4]
	call display
	mov ax,[idtrdata+2]
	call display
	mov ax,[idtrdata]
	call display
	
	disp msg,len
	disp trmsg,trlen
	str [trdata]			;str
	mov ax,[trdata]
	call display
	disp msg,len
	
	exit: mov rax,60
		mov rdi,0
		syscall
		
	display:
		mov rsi, disparr+03
		mov rcx,04
		
		l4: 
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
		jnz l4
		
		mov rax,1
		mov rdx,1
		mov rsi,disparr
		mov rdx,04
		syscall
		ret
section .data
	msg: db "",10
	len: equ $-msg
	
	realmsg: db "System is in real mode",10
	reallen: equ $-realmsg
	
	protmsg: db "System is in protected mode",10
	protlen: equ $-protmsg
	
	cr0msg: db "Value in CR0/MSW: "
	cr0len: equ $-cr0msg
	
	ldtrmsg: db "Value in LDTR: "
	ldtrlen: equ $-ldtrmsg
	
	gdtrmsg: db "Value in GDTR: "
	gdtrlen: equ $-gdtrmsg
	
	idtrmsg: db "Value in IDTR: "
	idtrlen: equ $-idtrmsg
	
	trmsg: db "Value in TR: "
	trlen: equ $-trmsg
	
section .bss
	disparr resb 02
	cro_data resb 10
	ldtrdata resb 10
	gdtrdata resb 10
	idtrdata resb 10
	trdata resb 10
	

	
	
	
	
