;Write a TSR to generate the pattern of the frequency tones by reading the Real Time Clock (RTC).

code segment
assume cs:code
org 100h
jmp initze
savint dd ?
msg db 10,13,'$'
hour db ?
min db ?
sec db ?

testnum:push ax
        push bx
        push cx
        push dx
        push cs
        push es
        push si
        push di
        call time
exit:pop di
        pop si
        pop es
        pop ds
        pop dx
        pop cx
        pop bx
        pop ax
        jmp cs:savint
convert proc
        and al,0f0h
        ror al,4
        add al,30h
        mov ah,02h
        mov dl,al
        int 21h
        mov al,dh
        and al,0fh
        add al,30h
        mov ah,02h
        mov dl,al
        int 21h
        ret
        endp
time proc
mov ah,02h
int 1ah
mov hour,ch
mov min,cl
mov sec,dh
mov al,hour
mov dh,hour
call convert
mov ah,02h
mov dl,':'
int 21h
mov al,min
mov dh,min
call convert
mov ah,02h
mov dl,':'
int 21h
mov al,sec
mov dh,sec
call convert
mov ah,09h
lea dx,msg
int 21h
call tone
ret
endp

tone proc
mov al,182
out 43h,al
mov ax,4560
out 42h,al
mov al,ah
out 42h,al
in al,61h
or al,00000011b
out 61h,al
mov bx,1255

.pause1:
mov cx,65535

.pause2:
dec cx
jne .pause2
dec bx
jne .pause1
in al,61h
and al,11111100b
out 61h,al
ret
endp


initze proc
push cs
pop ds
cli
mov ah,35h
mov al,08h
int 21h

mov word ptr savint,bx
mov word ptr savint+2,es
mov ah,25h
mov al,08h
mov dx,offset testnum
int 21h
mov ah,31h
mov dx,offset initze
sti
int 21h
endp
code ends
end




