%include "macro.nasm"
global _main 
_main:
global proc1
extern buff,abufflen

section .text

proc1 :
 display buff,[abufflen]		; to rsi
 display msg1,len1			;enter the character to search:
 
 accept char2,2				;to bl
 mov bl,[char2]
 mov rsi,buff

n1: 
 mov al,[rsi]				;buff->rsi->al
 cmp al, 0Ah				;new line
 je enter1
 
 cmp al,20H					;spaces
 je space1
 
 cmp al,bl					;No. of occurance
 je ccount
 jmp n2

enter1: 
 inc byte[lcnt]			;to al
 jmp n2

space1:
 inc byte[scnt]			;to al
 jmp n2

ccount:
 inc byte[ccnt]			;to al
 jmp n2

n2:
 inc rsi
 dec byte[abufflen]
 jnz n1
 
 display dispmsg1,displen1
 mov al,byte[lcnt]
 call displayproc
 
 display dispmsg2,displen2
 mov al,byte[scnt]
 call displayproc
 
 display dispmsg3,displen3
 mov al,byte[ccnt]
 call displayproc
 
ret

displayproc:
mov rsi,disparr+1
mov rcx,2
l1:mov rdx,0H
   mov rbx,10H
   div rbx
   cmp dl,09H
   jle l2
   add dl,07H

l2:add dl,30H
   mov [rsi],dl
   dec rsi
   dec rcx
   jnz l1
   
   mov rax,1
   mov rdi,1
   mov rsi,disparr
   mov rdx,2
   syscall
   ret

section .data

msg1: db "",10
      db "Enter the Char to be search : "
      len1: equ $-msg1

dispmsg1: 
          db "Number of Lines in the File : ",
          displen1: equ $-dispmsg1 

dispmsg2: db "",10
          db "Number of Blank Spaces in the File : ",
          displen2: equ $-dispmsg2 

dispmsg3: db "",10
          db "Number of times Char occuring in the File : ",
          displen3: equ $-dispmsg3
	    db "",10
	    db "",10  
      
section .bss
lcnt resb 10
scnt resb 10
ccnt resb 10
disparr resb 2
char2 resb 2


