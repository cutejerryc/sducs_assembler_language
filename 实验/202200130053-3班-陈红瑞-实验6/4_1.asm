data segment
 	Pgsize 		dw 		?
 	buf_size 	db 		80
 	s_buf 		db 		?
 	buf 		db 		200 	dup(?)
 	cur 		dw 		?
 	handle 		dw 		?
;+++++++++++++++++++++++++++++++++++
 	act_size 	dw 		? 			;用于记录实际读取到缓冲区的字符数量
;+++++++++++++++++++++++++++++++++++++
 	mess_getname  		db 		0dh,0ah,'    Please input filename: $'
 	mess_err1 			db 		0ah,0dh,'    Illegal filename ! $'
 	mess_err2 			db 		0ah,0dh,'    File not found ! $'
 	mess_err3 			db 		0ah,0dh,'    File read error ! $'
 	mess_psize 			db 		0ah,0dh,'    Page Size : $'
 	crlf 				db 		0ah,0dh,'$'
 	mess_star 			db 		0ah,0dh,'******************************'
 	 					db 		0ah,0dh,'$'
data ends
 
code segment
 	assume ds:data,cs:code
 
main proc far
start:
 	push 	ds
 	sub 	ax,ax
 	push 	ax
 	mov 	ax,data
 	mov 	ds,ax
 
  	mov 	Pgsize,12 				;each page 12 lines.
  	mov 	cur,200 				;File data buffer is empty.
  	call 	getline 				;Get file name.
  	call 	openf 					;open the file, (ax) = 0 means no such file
  	or 	 	ax,ax
  	jnz 	display
  	mov 	dx,offset mess_err2
  	mov 	ah,09h
  	int 	21h 					;(ax) = 0: no such file.
 
    jmp 	file_end
display:
 	mov 	cx,Pgsize
show_page:
 	call 	read_block 				;read a line from handle to buf
 	or 		ax,ax
 	jnz 	next2
 
  	mov 	dx,offset mess_err3
  	mov 	ah,09h
  	int 	21h 					;(ax) = 0: error in read.
  	jmp 	file_end
next2:
 	call 	show_block 				;display a line in buf,(bx) returned 0
 	 								; means that the file reach its end.
 	or 		bx,bx
 	jz 		file_end 				;(bx) = 0: at the end of file.
 	or 		cx,cx
 	jnz 	show_page 				;(cx) <> 0: not the last line of a page.
 	mov 	dx,offset mess_star
 	mov 	ah,09h
 	int 	21h 					;At the end of a page,print a line of *.
; the current page has been on screen, and followed by a line of stars.
; the following part get the command from keyboard:
wait_space:
 	mov 	ah,1
 	int 	21h
 	cmp 	al,' '
 	jnz 	psize
 	jmp 	display
psize:
 	cmp 	al,'p'
 	jnz 	wait_space
 	call 	change_psize
here:
 	mov 	ah,1
 	int 	21h
 	cmp 	al,' '
 	jnz 	here 					; stick here to wait for space.
 	jmp 	display
file_end:
 	ret
main endp
;************************************************************************
;***********************************************************************
change_psize 	proc near
 	push 	ax
 	push 	bx
 	push 	cx
 	push 	dx
 	mov 	dx,offset mess_psize
 	mov 	ah,09h
 	int 	21h 					;print the promt line
 
  	mov 	ah,01
  	int 	21h 					;get the new num of page size
  	cmp 	al,0dh
  	jz 		illeg
  	sub 	al,'0'
  	mov 	cl,al
getp:
 	mov 	ah,1
 	int  	21h
 	cmp 	al,0dh
 	jz 		pgot
 	sub 	al,'0'
 	mov 	dl,al
 	mov 	al,cl
 	mov 	cl,dl 					; exchange al and cl
 
  	mov 	bl,10
  	mul 	bl
  	add 	cl,al
  	jmp 	getp
pgot:
 	mov 	dl,0ah
 	mov 	ah,2
 	int 	21h 					; output 0ah to complete the RETURN.
 
  	cmp 	cx,0
  	jle 	illeg
  	cmp 	cx,24
  	jg 	 	illeg
  	mov 	Pgsize,cx 				;be sure the new page size in (0..24) region.
illeg:
 	mov 	dl,0ah
 	mov 	ah,2
 	int 	21h 					;output 0ah to complete the RETURN
 	pop 	dx
 	pop 	cx
 	pop 	bx
 	pop 	ax
 	ret
change_psize endp
;****************************************************************************
;****************************************************************************
openf proc near
 	push 	bx
 	push 	cx
 	push 	dx
 	mov 	dx,offset buf
 	mov 	al,0
 	mov 	ah,3dh
 	int 	21h
 	mov 	handle,ax
 	mov 	ax,1
 	jnc 	ok
 	mov 	ax,0
ok:
 	pop 	dx
 	pop 	cx
 	pop 	bx
 	ret
openf 	endp
;*************************************************************************
;***********************************************************************
getline proc near
 	push 	ax
 	push 	bx
 	push 	cx
 	push 	dx
 	mov 	dx,offset mess_getname
 	mov 	ah,09h
 	int 	21h 					; promt user to input file name
 
  	mov 	dx,offset buf_size
  	mov 	ah,0ah
  	int 	21h 					;funetion call of buffer input
  
   	mov 	dx,offset crlf
   	mov 	ah,09h
   	int 	21h 					;return.
   
    mov 	bl,s_buf
    mov 	bh,0
    mov 	[buf+bx],0 				; put 0 int the end of file name
   
    pop 	dx
    pop 	cx
    pop 	bx
    pop 	ax
    ret
getline 	endp
;******************************************************************
;*****************************************************************
read_block proc near
 	push 	bx
 	push 	cx
 	push 	dx
 	cmp 	cur,200
 	jnz 	back
; if no more chars in buf can be displayed
; then read another 200 chars:
 	mov 	cx,200
 	mov 	bx,handle
 	mov 	dx,offset buf
 	mov 	ah,3fh
 	int  	21h
 	mov 	act_size,ax
 	mov 	cur,0
 	mov 	ax,1
 	jnc 	back
 	mov 	cur,200
 	mov 	ax,0
back:
 	pop 	dx
 	pop 	cx
 	pop 	bx
 	ret
read_block endp
;********************************************************************
;*******************************************************************
show_block proc near
 	push 	ax
 	push 	dx
 	mov 	bx,cur
loop1:
 	cmp 	bx,200
 	jl 		lp
 	jmp 	exit 					;if buf is empty then return.
lp:
 	mov 	dl,buf[bx] 		 		;else show the current char.
;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 	cmp 	bx,act_size 			;search the file end
 	jge 	exit_eof
;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 	inc 	bx
 	inc 	cur
 	mov 	ah,02
 	int 	21h
 	cmp 	dl,0ah
 	jz 	 	exit_ln 				;if the char shown is RETURN.
 	 								;then exit. A line has been on screen.
 	jmp 	loop1
exit_eof:
 	mov 	bx,0
exit_ln:
 	dec 	cx
exit:
 	pop 	dx
 	pop 	ax
 	ret
show_block endp
;**********************************************************************
code ends
end start