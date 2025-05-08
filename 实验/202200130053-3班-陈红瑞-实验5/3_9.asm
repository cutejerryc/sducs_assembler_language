TITLE TYPE_EX -- TEST TIME FOR TYPING EXERCISE
;----------------------------------------------
stack 		segment 	para 	stack 	'stack'
 			db 			256 			dup(0)
top 		label 		word
stack 		ends
;-----------------------------------------------
data 		segment 	para 	public 	'data'
buffer 		db 			16h dup(0)
bufpt1 		dw 			0
bufpt2 		dw 			0
; bufpt1 = bufpt2, the buffer is empty
kbflag 		db 			0
prompt 		db '        * PLEASE PRACTISE TYPING *',0dh,0ah,'$'
scantab 	db 0,0,'1234567890-=',8,0
 			db 'qwertyuiop[]',0dh,0
 			db 'asdfghjkl:',0,0,0,0
 			db 'zxcvbnm,./',0,0,0
 			db ' ',0,0,0,0,0,0,0,0,0,0,0,0,0
 			db '789-456+1230.'
even
oldcs9 		dw ?
oldip9 		dw ?
;----------------------------------------------------
str1 		db 'abcd efgh ijkl mnop qrst uvwx yz.'
 			db 0dh,0ah,'$'
str2 		db 'christmas is a time of joy and love.'
 			db 0dh,0ah,'$'
str3 		db 'store windows hold togs and gifts.'
 			db 0dh,0ah,'$'
str4 		db 'people send christmas cards and gifts.'
 			db 0dh,0ah,'$'
str5 		db 'santa wish all people peace on earth.'
crlf 		db 0dh,0ah,0ah,'$'
colon 		db ':','$'
even
saddr 		dw 		str1,str2,str3,str4,str5
count 		dw 		0
sec 		dw 		0
min 		dw 		0
hours 		dw 		0
save_lc 	dw 		2 dup(?)
data 		ends
;---------------------------------------------------------
code 		segment
assume 		cs:code,ds:data,es:data,ss:stack
main 		proc 	far
start:
 			mov 	ax,stack 			;set up for stack
 			mov 	ss,ax 
 			mov 	sp,offset top
;
 			push 	ds 					;save ds£º 0 for return
 			sub 	ax,ax
 			push 	ax
 			mov 	ax,data 			;set DS to data segment
 			mov 	ds,ax
 			mov 	es,ax
;
 			mov 	ah,35h 				;save interrupt vector
 			mov 	al,09h 				;of keyboard
 			int 	21h
 			mov 	oldcs9,es
 			mov 	oldip9,bx
;
 			push 	ds 					;set interrupt vector
 			mov 	dx,seg kbint 		; of kbint
 			mov 	ds,dx
 			mov 	dx,offset kbint
 			mov 	al,09h
 			mov 	ah,25h
 			int 	21h
 			pop 	ds
; 
 			mov 	ah,35h 				;save interrupt vector
 			mov 	al,1ch 				; of timer
 			int 	21h
 			mov 	save_lc,bx
 			mov 	save_lc+2, es
;
 			push 	ds 					;set interrupt vector
 			mov 	dx,seg clint 		; of clint
 			mov 	ds,dx
 			mov 	dx,offset clint
 			mov 	al,1ch
 			mov 	ah,25h
 			int 	21h
 			pop 	ds
; 
 			in 		al,21h 				;clear kbd & timer
 			and 	al,11111100b 		; mask bit
 			out 	21h,al
first:
 			mov 	ah,0 				;set video mode
 			mov 	al,3 				;80 x 25 color text
 			int 	10h
; 
 			mov 	dx,offset prompt
 			mov 	ah,9 				;display kbd message
 			int 	21h
 			mov 	si,0
next:
 			mov 	dx,saddr[si] 		;display sentence
 			mov 	ah,09h
 			int 	21h
 			mov 	count,0 			;set initial value
 			mov 	sec,0
 			mov 	min,0
 			mov 	hours,0
;
 			sti 						;set IF flag
forever:
 			call 	kbget 				;wait enter a key
 			test 	kbflag,80h
 			jnz 	endint
 			push 	ax
 			call 	dispchar 			;display the character
 			pop 	ax
 			cmp 	al,0dh
 			jnz 	forever
 			mov 	al,0ah
 			call 	dispchar 			;display CR / LF
;
 			call 	disptime 			;display typing time
;
 			lea 	dx,crlf 			;display CR / LF
 			mov 	ah,09h
 			int 	21h
; 
 			add 	si,2 				;updata pointer
 			cmp 	si,5*2 				;end of sentence ?
 			jne 	next 				;no,display next
 			jmp 	first 				;yes,display first
endint:
 			cli 						;end of typing
 			push 	ds
 			mov 	dx,save_lc
 			mov 	ax,save_lc+2
 			mov 	ds,ax
 			mov 	al,1ch 				;reset interrupt vector
 			mov 	ah,25h 				; of type 1ch
 			int 	21h
 			pop 	ds
; 
 			push 	ds
 			mov 	dx,oldip9
 			mov 	ax,oldcs9
 			mov 	ds,ax
 			mov 	al,09h 				;reset interrupt vector
 			mov 	ah,25h 				; of type 09h
 			int 	21h
 			pop 	ds
;
 			sti
 			ret 						;return to DOS
main 		endp
;-------------------------------------------------------------------
clint 		proc 	near 				;timer int routine
 			push 	ds 					;save ROM data area
 			mov 	bx,data 			;set data segment
 			mov 	ds,bx
;
 			lea 	bx,count
 			inc 	word ptr[bx] 		;increment count
 			cmp 	word ptr[bx],18 	;1 sec = 18 count
 			jne 	return
 			call 	inct 				;update sec and min
adj:
 			cmp 	hours,12 			;update hours
 			jle 	return
 			sub 	hours,12
return:
 			pop 	ds
 			sti
 			iret 						;interrupt return
clint 		endp
;------------------------------------------------------------------
inct 		proc 	near 				;update sec and min
 			mov 	word ptr[bx],0
 			add 	bx,2
 			inc 	word ptr[bx]
 			cmp 	word ptr[bx],60
 			jne 	exit
 			call 	inct
exit: 		ret 						;return to clint
inct 		endp
;-----------------------------------------------------------------
disptime 	proc 	near
;subroutine to display typing time for min:sec:msec
 			mov 	ax,min
 			call 	bindec 				;display min
; 
 			mov 	bx,0 				;display ':'
 			mov 	al,':'
 			mov 	ah,0eh
 			int 	10h
 			mov 	ax,sec 				;display sec
 			call 	bindec
;
 			mov 	bx,0 				;display ':'
 			mov 	al,':'
 			mov 	ah,0eh
 			int 	10h
 			mov 	bx,count 			;count convert to ms
 			mov 	al,55d
 			mul 	bl
 			call	bindec 				;display ms
;
 			ret 						;return to main
disptime 	endp
;------------------------------------------------------------
bindec 		proc 	near
; subroutine to convert binary in AX to decimal
 			mov 	cx,100d
 			call 	decdiv
 			mov 	cx,10d
 			call 	decdiv
 			mov 	cx,1
 			call	decdiv
 			ret 						;return to disptime
bindec 		endp
;-----------------------------------------------------------------
decdiv 	 	proc 	near
; sub_subroutine divide number in AX by CX
 			mov 	dx,0 				;number hight half
 			div 	cx
;
 			mov 	bx,0 
 			add 	al,30h 				;convert to ASCII
 			mov 	ah,0eh 				;display function
 			int 	10h
;
 			mov 	ax,dx
 			ret 						;return to bindec
decdiv 		endp
;***************************************************************
kbget 		proc 	near 				;kbd interrupt routine
 			push 	bx
 			cli 						;interrupt back off
 			mov 	bx,bufpt1 			;get pointer to head
 			cmp 	bx,bufpt2 			;test empty of buffer
 			jnz 	kbget2 				;no,fetch a character
 			cmp 	kbflag,0
 			jnz 	kbget3
 			sti 						;allow an interrupt to occur
 			pop 	bx 
 			jmp 	kbget 				;loop until something in buff
kbget2:
 			mov 	al,[buffer+bx] 		;get ascii code
 			inc 	bx 					;inc a buffer pointer
 			cmp 	bx,16 				;at end of buffer ?
 			jc 		kbget3 				;no,continue
 			mov 	bx,0 				;reset to buf beginning
kbget3:
 			mov 	bufpt1,bx 			;store value in variable
 			pop 	bx
 			ret 						;return to main
kbget 		endp
;----------------------------------------------------------------
kbint 		proc 	far 				;keyboard interrupt routine
 			push 	bx
 			push 	ax
;
 			in 		al,60h 				;read in the character
 			push 	ax 					;save it
 			in 		al,61h 				;get the control port
 			or 	 	al,80h 				;set acknowledge bit for kbd
 			out 	61h,al
 			and 	al,7fh 				;reset acknowledge bit
 			out 	61h,al
;
 			pop 	ax 					;recover scan code
 			test 	al,80h 				;is press or release code?
 			jnz 	kbint2 				;is release code,return
 			mov 	bx,offset scantab
 			xlat 	scantab 			;ascii code to AL
 			cmp 	al,0
 			jnz 	kbint4
 			mov 	kbflag,80h
 			jmp 	kbint2
kbint4:
 			mov 	bx,bufpt2 			;buffer tail pointer
 			mov 	[buffer+bx],al 		;ASCII fill in buffer
 			inc 	bx
 			cmp 	bx,16 				;is end of buffer?
 			jc 		kbint3 				;no
 			mov 	bx,0 				;reset to buf beginning
kbint3:
 			cmp 	bx,bufpt1 			;is buffer full ?
 			jz 	 	kbint2 				;yes, lose character
 			mov 	bufpt2,bx 			;save buf tail pointer
kbint2:
 			cli 
 			mov 	al,20h 				;end of interrupt
 			out 	20h,al
 			pop 	ax
 			pop 	bx
 			sti
 			iret 						;interrupt return
kbint 		endp
;-------------------------------------------------------------------------
dispchar 	proc 	near 				;(AL)=displaying char.
 			push 	bx
 			mov 	bx,0
 			mov 	ah,0eh 				;display function
 			int 	10h 				;call video routine
 			pop 	bx
 			ret
dispchar 	endp
;--------------------------------------------------------------------
code 		ends 						;end of code segment
 			end 	start