;Write 80387 ALP to plot Sine Wave. Access video memory directly for plotting.


.model small
.stack 100
.data
msg db 10,13,'---------------THIS IS SINE WAVE------------------$'

x dd 00
xad dd 3.0
one80 dd 180.0
thirty dd 30.0
fifty dd 50.0
xcursor dd 00
ycursor dt 00
count dw 360
x1 dw 0

.code
.386
main:

mov ax,@data
mov ds,ax

mov ah,00
mov al,6
int 10h

up1:
finit
Fldpi
Fdiv one80
Fmul x
Fsin
Fmul thirty

Fld fifty
Fsub ST,ST(1)

Fbstp ycursor
lea si,ycursor

mov ah,0ch
mov al,01h
mov bh,0h
mov cx,x1
mov dx,[si]
int 10h

inc x1
Fld x
Fadd xad
Fst x
dec count
jnz up1

mov ah,09h
lea dx,msg
int 21h

mov ah,4ch
int 21h
end main
