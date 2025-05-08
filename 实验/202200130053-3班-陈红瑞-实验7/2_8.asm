;PROGRAM TITLE GOES HERE -- HANOI
;Solves tower of HANOI puzzle. Printout sequence of moves
; of N discs from initial spindle X to final spindle Z.
; Using spindle Y for temporery storage.
;****************************************************************
datarea 	segment 							;define data segment
 	message1 	db 		'N=?',0ah,0dh,'$'
 	message2 	db 		'What is the name of spindle X ?'
 	 			db 		0ah,0dh,'$'
 	message3 	db 		'What is the name of spindle Y ?'
 	 			db 		0ah,0dh,'$'
 	message4 	db 		'What is the name of spindle Z ?'
 	 			db 		0ah,0dh,'$'
 	flag 		dw 		0
 	constant 	dw 		10000,1000,100,10,1
 	
 	prompt 		db 		'File ?',0dh,0ah,'$'
 	input_name 	db 		'input.txt',0
 	output_name db 		'output.txt',0
 	iHandle  	dw 	 	? 							
 	oHandle  	dw 	 	? 	
 	ibuf 		db 		5 dup(?)
 	obuf 		db 		5 dup(?)
 	flag1 		db 		0
datarea 	ends
;*******************************************************************
program 	segment 							;define code segment
;----------------------------------------------------------------------
main 		proc 	far
 			assume cs:program,ds:datarea
start:
; set up stack for return
 	push 	ds
 	sub 	ax,ax
 	push 	ax
;set DS register to current data segment
 	mov 	ax,datarea
 	mov 	ds,ax
 	;是否要从文件读写
 	lea 	dx,prompt
 	mov 	ah,09h
 	int 	21h
 	
 	mov 	ah,01h
 	int 	21h
 	cmp 	al,20h
 	jne 	get_input 							;不从文件输入
 	mov 	flag1,1
 	call 	get_file
 	call 	hanoi
 	;关闭文件
 	mov 	ah,3eh
 	mov 	bx,oHandle
 	int 	21h
 	jmp 	exit

get_input: 	
;MAIN PART OF PROGRAM GOES HERE
 	lea 	dx,message1 						;N = ?
 	mov 	ah,09h
 	int 	21h
 	call 	decibin 							;read N into BX
 	call 	crlf
;
 	cmp 	bx,0 								;if N = 0,
 	jz 		exit 								;exit
; 
 	lea 	dx,message2  						;X = ?
 	mov 	ah,09h
 	int 	21h
 	mov 	ah,01h 								;read X's name into SI
 	int 	21h
 	mov 	ah,0
 	mov 	cx,ax
 	call 	crlf
; 
	lea 	dx,message3 						; Y = ?
	mov 	ah,09h
	int 	21h
	mov 	ah,01h 								;read Y's name into SI
	int 	21h
	mov 	ah,0
	mov 	si,ax
	call 	crlf
;
 	lea 	dx,message4 						; Z = ?
 	mov 	ah,09h
 	int 	21h
 	mov 	ah,01h 								;read Z's name into DI
 	int 	21h
 	mov 	ah,0
 	mov 	di,ax
 	call 	crlf
;
 	call 	hanoi 								;call HANOI(N,X,Y,Z)
;
exit:
 	ret 										;return to DOS
;
main 		endp
;----------------------------------------------------------------------
hanoi 		proc 	near 						;define subprocedure
;Solves tower of HANOI puzzle.
;Argement: (BX) = N,(CX) = X,(SI) = Y,(DI) = Z.
 	cmp 	bx,1 								;if N = 1,execute basis
 	je 		basis
 	call 	save 								;save N,X,Y,Z
 	dec 	bx
 	xchg 	si,di
 	call 	hanoi 								;call HANOI(N-1,X,Z,Y)
 	call 	restor 								;restore N,X,Y,Z
 	call 	print 								;print XNZ
 	dec 	bx
 	xchg 	cx,si 
 	call 	hanoi 								;call HANOI(N-1,Y,X,Z)
 	jmp 	return
basis:
 	call 	print 								;print X1Z
return:
 	ret 										;return
hanoi 	endp 									;end subprocedure
;----------------------------------------------------------------
print 		proc 	near
;print XNZ
 	mov 	dx,cx 								;print X
 	mov 	ah,02h
 	int 	21h
 	call 	binidec 							;print N
 	mov 	dx,di 								;print Z
 	mov 	ah,02h
 	int 	21h
 	call 	crlf 								;skip to next line
 	
 	cmp 	flag1,0
 	je 	 	exit2
	call 	write
exit2:
 	ret
print 		endp
;-------------------------------------------------------------------
save 		proc 	near
;push N,X,Y,Z onto stack
 	pop 	bp
 	push 	bx
 	push 	cx
 	push 	si
 	push 	di
 	push 	bp
 	ret
save 		endp
;--------------------------------------------------------------------
restor 		proc 	near
;pop Z,Y,X,N from stack
 	pop 	bp
 	pop 	di
 	pop 	si
 	pop 	cx
 	pop 	bx
 	push 	bp
 	ret
restor 		endp
;---------------------------------------------------------------------------
decibin 		proc 	near
;procedure to convert decimal on keybd to binary.
;result is left in BX register.
 	mov 	bx,0 								;clear BX for number
;get digit from keyboard,convert to binary
newchar:
 	mov 	ah,1 								;keyboard input
 	int 	21h 								;call DOS
 	sub 	al,30h 								;ASCII to binary
 	jl 		exit1 								;jump if < 0
 	cmp 	al,9d 								;is it > 9d?
 	jg 		exit1 								;yes,not decdigit
 	cbw 										;byte in AL to word in AX
;(digit is now in AX)
;multiply number in BX by 10 decimal.
 	xchg 	ax,bx 								;trade digit & number
 	mov 	cx,10d 								;put 10 dec in CX
 	mul 	cx 									;number times 10
 	xchg 	ax,bx 								;trade number & digit
;add digit in AX to number in BX
 	add 	bx,ax 								;add digit to number
 	jmp 	newchar 							;get next digit
exit1: 
 	ret 										;return from decibin
decibin 	endp 							 	;return from decibin proc
;-----------------------------------------------------------------------------
binidec 	proc 	near
;procedure to convert binary number in BX to decimal
; 	on console screen
 	push 	bx
 	push 	cx
 	push 	si
 	push 	di
 	mov 	flag,0
 	mov 	cx,5
 	lea 	si,constant
;
dec_div:
 	mov 	ax,bx 								;number high half
 	mov 	dx,0 								;zero out low half
 	div 	word ptr[si] 						;divide by constant
 	mov 	bx,dx 								;remainder into BX
 	mov		dl,al 								;quotient into DL
;
 	cmp 	flag,0 								;have not leading zero
 	jnz 	print1
 	cmp 	dl,0
 	je 		skip
 	mov 	flag,1
;print the contents of DL on screen
print1: 
 	add 	dl,30h 								;convert to ASCII
 	mov	 	ah,02h 								;display function
 	int 	21h 								;call DOS
skip:
 	add 	si,2
 	loop 	dec_div
 	pop 	di
 	pop 	si
 	pop 	cx
 	pop 	bx
 	ret 										;return from dec_div
binidec 	endp
;--------------------------------------------------------------------------
crlf 		proc 	near
;print carriage return and linefeed
 	mov 	dl,0ah 								;linefeed
 	mov 	ah,02h 								;display function
 	int 	21h
;
 	mov 	dl,0dh 								;carriage return
 	mov 	ah,02h 								;display function
 	int 	21h
;
 	ret
crlf 		endp
;-----------------------------------------------------------------------
get_file 	proc 	near
;从文件获取N X Y Z的值
 	mov 	ah,3dh
 	mov 	al,2
 	lea 	dx,input_name
 	int 	21h
 	mov 	iHandle,ax
 	
 	mov 	ah,3fh
 	mov 	cx,4
 	mov 	bx,iHandle
 	lea 	dx,ibuf
 	int 	21h
 	;将缓冲区的内容转换为参数
 	mov 	bx,1
 	mov 	cl,ibuf[bx]
 	xor 	ax,ax
 	mov 	al,ibuf[bx + 1]
 	mov 	si,ax
 	mov 	al,ibuf[bx + 2]
 	mov 	di,ax
 	;close file
 	mov 	ah,3eh
 	mov 	bx,iHandle
 	int 	21h
 	;设置N的值
 	xor 	bx,bx
 	mov 	bl,ibuf[bx]
 	xor 	bx,30h
 	ret
get_file 	endp
;--------------------------------------------------------------------------
write 	proc 	near
 	push 	bx
 	push 	cx
 	push 	si
 	push 	di
;set buffer
 	mov 	ax,bx
 	xor 	bx,bx
 	mov 	obuf[bx],cl
 	mov 	cx,di
 	mov 	obuf[bx+2],cl
 	xor 	ax,30h
 	mov 	obuf[bx+1],al
 	mov 	obuf[bx+3],0dh
 	mov 	obuf[bx+4],0ah
 	;打开文件
 	mov 	ah,3dh
 	mov 	al,2
 	lea 	dx,output_name
 	int 	21h
 	mov 	oHandle,ax
 	;写文件
 	mov 	ah,40h
 	mov 	cx,5
 	mov 	bx,oHandle
 	lea 	dx,obuf
 	int 	21h
 	
 	
 	pop 	di
 	pop 	si
 	pop 	cx
 	pop 	bx
 	ret
write 	endp

program 	ends 								;end of code segment
;**********************************************************************
 	end 	start 								;end assembly