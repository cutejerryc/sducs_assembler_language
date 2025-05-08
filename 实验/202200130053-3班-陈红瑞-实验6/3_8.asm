TITLE WSPP --- Program of word process function
; 		for insert, left and right
;---------------------------------------------------
dseg 		segment 						;define data segment
 	kbd_buf 		db 	96 	dup(' ') 		;input buffer
 	cntl 			db 	16 	dup(0) 			;char number of rows
 	bufpt 			dw 	0 					;buffer head pointer
 	buftl 			dw 	0 					;buffer tail pointer
 	colpt 			db 	0 					;current col pointer
 	rowpt 			db 	0 					;current row pointer
 	rowmx 			dw 	0 					;maxium row number
dseg 		ends
;----------------------------------------------------------
;定义宏，根据当前的光标的行和列来设置光标位置
curs 		macro 	row,col 				;position cursor macro
 			mov 	dh,row
 			mov 	dl,col
 			mov 	bh,0
 			mov 	ah,2
 			int 	10h
 			endm
;----------------------------------------------------------------
cseg 		segment 						;define code segment
main 		proc 		far
assume 		cs:cseg,ds:dseg,es:dseg
start:
 			push 	ds 						;save for return to DOS
 			sub 	ax,ax
 			push 	ax
 			mov 	ax,dseg 				;dseg addr into ds,es
 			mov 	ds,ax
 			mov 	es,ax
;
 			mov 	buftl,0 				;initialize pointers
 			mov 	colpt,0
 			mov 	rowpt,0
 			mov 	bufpt,0
 			mov 	rowmx,0
 			mov 	cx,length cntl 			;initialize cntl area
 			mov 	al,0
 			lea 	di,cntl
 			cld
 			rep 	stosb
;
 			mov 	ah,6 					;clear screen
 			mov 	al,0
 			mov 	cx,0
 			mov 	dh,24
 			mov 	dl,79
 			mov 	bh,07
 			int 	10h
 			curs 	0,0 					;place cursor at (0,0)
read_k:
 			mov 	ah,0 					;read char from kbd
 			int 	16h 					;call ROM routine
 			cmp 	al,1bh 					;is escape ?
 			jnz 	arrow
 			ret 							;yes, return to DOS
arrow:
 			cmp 	ah,4bh  				;is left arrow ?
 			jz 	 	left 					;yes,moving cursor
 			cmp 	ah,4dh 					;is right arrow?
 			jz 		right 					;yes
;-------------------------------------------------------------------
inst: 		jmp 	ins_k
left: 		jmp 	left_k
right: 		jmp 	right_k
;---------------------------------------------------------------------
ins_k: 										;insert a character
 			mov 	bx,bufpt
 			mov 	cx,buftl
 			cmp 	bx,cx 					;bufpt == buftl ?
 			je 		km 						;yes,char into buffer
 			lea 	di,kbd_buf 				;no,buffer move
 			add 	di,cx 					; a byte backward
 			mov 	si,di
 			dec 	si
 			sub 	cx,bx
 			std
 			rep 	movsb
km:
 			mov 	kbd_buf[bx],al 			;char into buffer
 			inc 	bufpt 					;inc head pointer
 			inc 	buftl 					;inc tail pointer
 			cmp 	al,0dh 					;insert a CR ?
 			jnz 	kn 						;no
 			lea 	si,cntl 				;yes,move the count
 			add 	si,rowmx 				; of each row
 			inc 	si 						; backword
 			mov 	di,si
 			inc 	di
 			mov 	cx,rowmx
 			sub 	cl,rowpt
 			std
 			rep 	movsb
;
 			mov 	bl,rowpt 				;adjust the counts
 			xor 	bh,bh 					; of current row
 			mov 	cl,colpt 				; and next row
 			mov 	ch,cntl[bx]
 			sub 	ch,colpt
 			mov 	cntl[bx],cl
 			mov 	cntl[bx+1],ch
;
 			mov 	ax,rowmx 				;clear displaying row
 			mov 	bh,07 					;use scroll function
 			mov 	ch,rowpt
 			mov 	dh,24
 			mov 	cl,0
 			mov 	dl,79
 			mov 	ah,6
 			int 	10h
 
  			inc 	rowpt 					;point to next row
  			inc 	rowmx 					;inc max row count
  			mov 	colpt,0 				;point to 0 column
  			jmp 	short kp
kn:
 			mov 	bl,rowpt
 			xor 	bh,bh
 			inc 	cntl[bx] 				;inc current row count
 			inc 	colpt 					;point to next column
kp:
 			call 	dispbf 					;display input buffer
 			curs 	rowpt,colpt 			;position the cursor
 			jmp 	read_k
left_k:
 			cmp 	colpt,0 				;is at 0 column ?
 			jnz 	k2 						;no
 			cmp 	rowpt,0 				;is at 0 row ?
 			jz 	 	lret 					;yes,cursor is unmove
 			dec 	rowpt 					;point to upper row
 			mov 	al,rowpt
 			lea 	bx,cntl
 			xlat 	cntl
 			mov 	colpt,al 				;point to tail of row
 			jmp 	k3
k2: 		dec 	colpt 					;dec column pointer
k3: 		dec 	bufpt 					; dec buffer point
 			curs 	rowpt,colpt 			;position cursor
lret: 		jmp 	read_k
right_k:
 			mov 	bx,bufpt 				;is at tail of file ?
 			cmp 	bx,buftl
 			je 		rret 					;yes,cursor unmoved
 			inc 	colpt 					;point to next column
 			cmp 	kbd_buf[bx],0dh 		;is CR ?
 			jnz 	k4 						;no
 			inc 	rowpt 					;yes,point to next row
 			mov 	colpt,0 				; and 0 column
k4: 		inc 	bufpt 					;adjust buffer pointer
 			curs 	rowpt,colpt 			;position cursor
rret: 		jmp 	read_k
;--------------------------------------------------------------------
;将缓冲区的所有字符从头开始依次输出，如果是回车键就输出CRLF
dispbf 		proc 	near 					;display char of buffer
 			mov 	bx,0
 			mov 	cx,96
 			curs 	0,0 					;光标从左上角开始
disp: 		mov 	al,kbd_buf[bx]
 			push 	bx
 			mov 	bx,0700
 			mov 	ah,0eh
 			int 	10h 					;call ROM routine
 			pop 	bx
 			cmp 	al,0dh 					;is CR ?
 			jnz 	kk
 			mov 	al,0ah 					;yes,display LF
 			mov 	ah,0eh
 			int 	10h 					;video call
kk: 		inc 	bx
 			loop 	disp
 			ret
dispbf 		endp
;---------------------------------------------------------------------
main 		endp 							;end main part of program
;-----------------------------------------------------------------------
cseg 		ends
 			end 	start 					;end assembly