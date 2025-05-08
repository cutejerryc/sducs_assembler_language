; Use 8253 to implement songs from 1 to 8

; Other keys to exit

data segment 
message db 'Use 1 ... 8 to play the music','$'
 frequ dw 262, 294, 330, 347, 392, 440, 494, 524
data ends
code segment
 assume cs:code, ds:data
start:
 mov ax, data
 mov ds, ax
 
 lea dx, message
 mov ah, 09h
 int 21h
 
 mov al, 10110110b
 out 43h, al ;set the control
 
next: mov ah, 7
 int 21h
 
 cmp al, '1'
 jb exit
 cmp al, '8'
 ja exit
 ;get the frequency of the number
 sub al, 30h
 mov ah, 0
 mov bx, ax
 sub bx, 1
 shl bx, 1
 mov cx, frequ[bx]
 ;get the counter
 mov ax, 34dch
        mov dx, 12h ;DX:AX=1234DCH=1193180D
        div cx
 mov bx, ax
   ;set the counter
 
 mov ax, bx
        out 42h, al ;send the lower
        mov al, ah
        out 42h, al ;send th higner
       
 
 in al, 61h ;set the 0 and 1 as '1'
 or al, 03h
 out 61h, al
 
 mov cx, 0ffffh
delay: mov dx, 03h
dec_dx: dec dx
        jnz dec_dx
        loop delay
       
        in al, 61h
        and al, 11111100b
        out 61h, al ;open the voice
     
 jmp next
exit:
 mov ah, 4ch
 int 21h 
code ends
end start