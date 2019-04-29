;Write 80387 ALP to obtain: i) Mean ii) Variance iii) Standard Deviation 


data segment

msg db 10,"Mean$"
msg1 db 10,"Variance$"
msg2 db 10,"Standard Deviation$"

no1 dd 3.5
no2 dd 5.5
no3 dd 7.5
n dd 3.0

temp1 dd ?
temp2 dd ?
temp3 dd ?

m dd ?
V dd ?
d dd ?
data ends

code segment
assume cs:code,ds:data

start:
mov ax,data
mov ds,ax

Finit

Fld no1
Fadd no2
Fadd no3
Fdiv n
FST m

mov ah,09h
lea dx,msg
int 21h

lea si,m
mov ch,04h
a1:
mov al,[si+3]
call display1
dec si
dec ch
jnz a1


Fld no1
Fsub m
FST temp1
Fmul temp1
FST temp1

Fld no2
Fsub m
FST temp2
Fmul temp2
FST temp2

Fld no3
Fsub m
FST temp3
Fmul temp3
FST temp3

Fld temp1
Fadd temp2
Fadd temp3

Fld temp1
fadd temp2
fadd temp3

Fdiv n
FST V

mov ah,09h
lea dx,msg1
int 21h

lea si,V
mov ch,04h
a4:
mov al,[si+3]
call display1
dec si
dec ch
jnz a4

Fld V
Fsqrt
FST d

mov ah,09h
lea dx,msg2                                      
int 21h

lea si,d
mov ch,04h
a5:
mov al,[si+3]
call display1
dec si
dec ch
jnz a5

mov ah,4ch
int 21h

display1 proc near
mov bl,al
and al,0F0h
rol al,04
cmp al,09h
jle a2
add al,07h
a2:
add al,30h
mov ah,02h
mov dl,al
int 21h

mov al,bl
and al,0Fh
cmp al,09h
jle a3
add al,07h
a3:
add al,30h
mov ah,02h
mov dl,al
int 21h
ret

display1 endp
code ends
end start




