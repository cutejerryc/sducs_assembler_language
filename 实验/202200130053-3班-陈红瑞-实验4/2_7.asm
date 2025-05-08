;PROGRAM TITLE GOES HERE -- SCREMP
;Enter hours & rate, display wage
;******************************************
stacksg 	segment 	para stack 'stack'
 	dw 		32 dup(?)
stacksg 	ends
;******************************************
datasg 		segment 	para 'data'
 	hrspar 		label 		byte 			;Hours parameter list;
 	maxhlen 	db 			6 				;-------------------
 	acthlen 	db 			?
 	hrsfld 		db 			6 dup(?)
;
 	ratepar 	label 		byte 			;Rate parameter list
 	maxrlen 	db 			6 				;-------------------
 	actrlen 	db 			?
 	ratefld 	db 			6 dup(?)
;
  	messg1 		db 			'Hours worked? ','$'
  	messg2 		db 			'Rate of pay? ','$'
  	messg3 		db 			'Wage = ','$'
  	ascwage 	db 			14 dup(30h),13,10,'$'
;
 	messg4 		db 			13,10,'Overflow! ',13,10,'$'
 	adjust 		dw 			?
 	binval 		dw 			0
 	binhrs 		dw 			0
 	binrate 	dw 			0
 	col 		db 			0
 	decind 		db 			0
 	mult10 		dw 			01
 	nodec 		dw 			0
 	row 		db 			0
 	shift 		dw 			?
 	tenwd 		dw 			10
 	tempdx 		dw 			?
 	tempax 		dw 			?
datasg 		ends
;*******************************************
codesg 		segment 	para 		'code'
;-----------------------------------------------
begin 		proc 		far 				;main part of program
 			assume cs:codesg,ds:datasg,ss:stacksg,es:datasg
;set up stack for return
 			push 		ds 					;save old data segment
 			sub 		ax,ax 				;put zero in ax
 			push 		ax 					;save it on stack
;set DS register to current data segment
 			mov 		ax,datasg 			;data segment addr
 			mov 		ds,ax 				; into DS register
 			mov 		es,ax 				; into ES register
;MAIN PART OF PROGRAM GOES HERE
 			mov 		ax,0600h
 			call 		q10scr 				;clear screen
 			call 		q20curs 			;set cursor
a20loop:
 			call 		b10inpt 			;Accept hours & rate
 			cmp 		acthlen,0 			;End of input?
 			je 			a30 
 			call 		d10hour 			;Convert hours to binary
 			call 		e10rate 			;Convert rate to binary
 			call 		f10mult 			;Calc wage,round
 			call 		g10wage 			;Convert wage to ASCII
 			call 		k10disp 			;Display wage
 			jmp 		a20loop
a30:
 			mov 		ax,0600h
 			call 		q10scr 				;clear screen
 			ret 							;return to DOS
begin 		endp 							;end of main part of program
;---------------------------------------------------
; 				Input hours & rate:
; 					                        -----------------
b10inpt 	proc 		near 
 			lea 		dx,messg1 			;Prompt for hours
 			mov 		ah,09h
 			int 		21h
 			lea 		dx,hrspar 			;Accept hours
 			mov 		ah,0ah
 			int 		21h
 			cmp 		acthlen,0 			;No hours?(indicates end)
 			jne 		b20
 			ret 							;If so,return to a20loop
b20:
 			mov 		col,25 				;Set column
 			call 		q20curs
 			lea 		dx,messg2 			;Prompt for rate
 			mov 		ah,09h
 			int 		21h
 			lea 		dx,ratepar 			;Accept rate
 			mov 		ah,0ah
 			int 		21h
 			ret
b10inpt 	endp
;--------------------------------------------------------------
; 						Process hours:
; 						--------------------
d10hour 	proc 		near
 			mov 		nodec,0
 			mov 		cl,acthlen
 			sub 		ch,ch
 			lea 		si,hrsfld-1 		;Set right pos'n
 			add 		si,cx 				; of hours
 			call 		m10asbi 			;Convert to binary
 			mov 		ax,binval
 			mov 		binhrs,ax
 			ret
d10hour  	endp
;--------------------------------------------------------------
; 						Process rate:
;                       ----------------
e10rate 	proc 	 	near
 			mov 		cl,actrlen
 			sub 		ch,ch
 			lea 		si,ratefld-1 		;Set right pos'n
 			add 		si,cx 				; of rate
 			call 		m10asbi 			;Convert to binary
 			mov 		ax,binval
 			mov 		binrate,ax
 			ret
e10rate 	endp
;----------------------------------------------------------------
; 						Multiply,round, & shift:
; 						--------------------------
f10mult 	proc 		near
 			mov 		cx,07
 			lea 		di,ascwage 			;Set ASCII wage
 			mov 		ax,3030h 			; to 30's
 			cld
 			rep 		stosw
 			mov 		shift,10
 			mov 		adjust,0
 			mov 		cx,nodec
 			cmp 		cl,06 				;If more than 6
 			ja 			f40 				; decimals,error
 			dec 		cx
 			dec 		cx
 			jle 		f30 				;Bypass if 0,1,2 decs
 			mov 		nodec,02
 			mov 		ax,01
f20:
 			mul 		tenwd 				;Calculate shift factor
 			loop 		f20
 			mov 		shift,ax
 			shr 		ax,1 				;Calculate round value
 			mov 		adjust,ax
f30:
 			mov 		ax,binhrs
 			mul 		binrate 			;Calcute wage
 			add 		ax,adjust 			;Round wage
 			adc 		dx,0
 			mov 		tempdx,dx 			;Save DX:AX
 			mov 		tempax,ax
;
 			cmp 		adjust,0 			;No shift required?
 			jz 			f50
;
 			mov 		ax,dx 				;shift use double-precision
 			mov 		dx,0 				; DIV,
 			div 		shift 				;  quotient into DX:AX
 			mov 		tempdx,ax 
 			mov  		ax,tempax
 			div	 		shift
 			mov 		dx,tempdx
 			mov 		tempax,ax
 			jmp 		f50
;
f40:
 			mov 		ax,0 				;Overflow
 			mov 		dx,0
f50:
 			ret 							;Return
f10mult 	endp
;----------------------------------------------------------
; 						Convert to ASCII:
; 						----------------------
g10wage 	proc 		near 
 			lea 		si,ascwage+11 		;Set decimal pt.
 			mov 		byte ptr[si],'.'
 			add 		si,nodec 			;Set right start pos'n
g30:
 			cmp 		byte ptr[si],'.'
 			jne 		g35 				;Bypass if at dec pos'n
 			dec 		si
g35:
 			cmp 		dx,0 				;If DX:AX < 10,
 			jnz 		g40
 			cmp 		ax,0010 			;operation finished
 			jb 			g50
g40:
 			mov 		ax,dx
 			mov 		dx,0
 			div 		tenwd
 			mov 		tempdx,ax
 			mov 		ax,tempax
 			div 		tenwd 				;Remainder is ASCII digit
 			mov 		tempax,ax
 			or 			dl,30h
 			mov 		[si],dl 			;Store ASCII character
 			dec 		si
 			mov 		dx,tempdx
 			jmp 		g30
g50:
 			or 			al,30h 				;Store last ASCII
 			mov 		[si],al 			; character
 			ret
g10wage 	endp
;--------------------------------------------------------------
; 						Display wage:
; 						---------------
k10disp 	proc 		near
 			mov 		col,50 				;Set column
 			call 		q20curs
 			mov 		cx,10
 			lea 		si,ascwage
k20:
 			cmp 		byte ptr[si],30h
 			jne 		k30 				; to blanks
 			mov 		byte ptr[si],20h
 			inc 		si
 			loop 		k20
k30:
 			lea 		dx,messg3 			;Display
 			mov 		ah,09
 			int 		21h
;++++++++++++++++++++++++++++++
 			xor 		dx,dx
 			lea 		dx,ascwage
 			mov 		ah,09
 			int 		21h
;+++++++++++++++++++++++++++++++++++
 			cmp 		row,20 				;Bottom of screen?
 			jae 		k80
 			inc 		row 				; no -- increment row
 			jmp 		k90
k80:
 			mov 		ax,0601h 			; yes --
 			call 		q10scr 				; scroll &
 			mov 		col,0 				; set cursor
 			call 		q20curs
k90: 		ret
k10disp 	endp
;--------------------------------------------------------------
; 						Convert ASCII to binary:
; 						------------------------
m10asbi 	proc 		near
 			mov 		mult10,01
 			mov 		binval,0
 			mov 		decind,0
 			sub 		bx,bx
m20: 
 			mov 		al,[si] 			; Get ASCII character
 			cmp 		al,'.' 				;Bypass if dec pt.
 			jne 		m40
 			mov 		decind,01
 			jmp 		m90
m40:
 			and 		ax,000fh
 			mul 		mult10 				;Multiply by factor
 			jc 			overflow
 			add 		binval,ax 			;add to binary
 			jc 			overflow
 			mov 		ax,mult10 			;Calculate next
 			mul 		tenwd 				; factor * 10
 			mov 		mult10,ax
 			cmp 		decind,0 			;Reached decimal py?
 			jnz 		m90
 			inc 		bx 					;yes -- add to count
m90:
 			dec 		si
 			loop 		m20
 			cmp 		decind,0 			;End of loop
 			jz 			m100 				;And decimal pt?
 			add 		nodec,bx 			;yes -- add to total
 			jmp 		m100
overflow:
 			mov 		binval,0
m100: 		ret
m10asbi 	endp
;-------------------------------------------------------------
; 						Scroll screen:
; 						-----------------
q10scr 		proc 		near 				;AX set on entry
 			mov 		bh,07 				;Color(07 for BW)
 			sub 		cx,cx
 			mov 		dx,184fh
 			int 		10h
 			ret
q10scr 		endp
;--------------------------------------------------------------
; 						Set cursor:
; 						--------------
q20curs 	proc 		near
 			mov 		ah,2
 			sub 		bh,bh
 			mov 		dh,row
 			mov 		dl,col
 			int 		10h
 			ret
q20curs 	endp
;--------------------------------------------------------------
codesg 		ends 							;end of code segment
;**************************************************************
 			end 		begin 				;end assembly