;PROGRAM TITLE GOES HERE -- RANK
;**********************************
datarea 	segment 				;define data segment
	grade 		dw 		50 dup(?)
	rank 		dw 		50 dup(?)
	count 		dw 		?
	mess1 		db 		'Grade? $'
	mess2 		db 		13,10,'Input Error!',13,10,'$'
	mess3 		db 		'Rank: $'
datarea 	ends
;******************************************
program 	segment 				;define code segment
;-----------------------------------------------
main 		proc 		far 		;main part of program
 			assume cs:program,ds:datarea
start:
;set up stack for return
 			push 		ds 			;save old data segment
 			sub 		ax,ax 		;put zero in AX
 			push 		ax 			;save it on stack
;set DS register to current data segment
 			mov 		ax,datarea 	;datarea segment addr
 			mov 		ds,ax 		;into DS register
;MAIN PART OF PROGRAM GOES HERE
			call 		input
			call 		rankp
			call 		output
			ret
main 		endp
;---------------------------------------------------
input 		proc 		near
 			lea 		dx,mess1
 			mov 		ah,09
 			int 		21h
 ;
 			mov 		si,0
 			mov 		count,0
enter:
 			call 		decibin
 			inc 		count
 			cmp 		dl,',' 		;is it ','?
 			je 			store
 			cmp 		dl,13 		;is it 'return'?
 			je 			exit2
 			jne 		error
store:
 			mov 		grade[si],bx ;enter the results
 			add 		si,2 		; of students
 			jmp 		enter
error:
 			lea 		dx,mess2
 			mov 		ah,09
 			int 		21h
exit2:
 			mov 		grade[si],bx
 			call 		crlf
 			ret
input 		endp
;-----------------------------------------------------
rankp 		proc 		near
 			mov 		di,count
 			mov 		bx,0
loop1:
 			mov 		ax,grade[bx]
 			mov 		word ptr rank[bx],0
 			mov 		cx,count
 			lea 		si,grade
next:
 			cmp 		ax,[si]
 			jg 			no_count
 			inc 		word ptr rank[bx]
no_count:
 			add 		si,2
 			loop 		next
 			add 		bx,2
 			dec 		di
 			jne 		loop1
 			ret 					;return to DOS
rankp 		endp
;-----------------------------------------------------
output 		proc 		near
 			lea 		dx,mess3
 			mov 		ah,09
 			int 		21h
;
 			mov 		si,0
 			mov 		di,count
next1:
 			mov 		bx,rank[si]
 			call 		binidec 	;display the rank
 			mov 		dl,',' 		;of students
 			mov 		ah,02
 			int 		21h
 			add 		si,2
 			dec 		di
 			jnz 		next1
 			call 		crlf
 			ret
output 		endp
;----------------------------------------------------
decibin 	proc 		near
;procedure to convert decimal on keybd to binary
;result is left in BX register
 			mov 		bx,0 		;clear BX for number
;get digit from keyboard,convert to binary
newchar:
 			mov 		ah,1 		;keyboard input
 			int 		21h 		;call DOS
 			mov 		dl,al
 			sub 		al,30h 		;ASCII to binary
 			jl 			exit1 		;jump if < 0
 			cmp 		al,9d 		;is it ? 9d?
 			jg 			exit1 		;yes,not dec digit
 			cbw 					;byte in AL to word in AX
;(digit is now in AX)
;multiply number in BX by 10 decimal.
 			xchg 		ax,bx 		;trade digit & number
 			mov 		cx,10d 		;put 10 dec in CX
 			mul 		cx 			;number times 10
 			xchg 		ax,bx 		;trade number & digit
;add digit in AX to number in BX
 			add 		bx,ax 		;add digit to number
 			jmp 		newchar 	;get next digit
exit1: 		ret 					;return from decibin
decibin 	endp 					;end of decibin proc
;-----------------------------------------------------
binidec 	proc 		near
;procedure to convert binary number in BX to decimal
; on sonsole screen
 			push 		bx
 			push 		cx
 			push 		si
 			push 		di
 			mov 		cx,100d 	;divide by 100
 			call 		dec_div
 			mov 		cx,10d 		;divide by 10
 			call 		dec_div
 			mov 		cx,1d 		;divide by 1
 			call 		dec_div
 			pop 		di
 			pop 		si
 			pop 		cx
 			pop 		bx
 			ret 					;return from binidec
binidec 	endp
;---------------------------------------------------------
dec_div 	proc 		near
;sub_subroutine to divide number in BX by number in CX
; print quotient on screen
 			mov  		ax,bx 		;number high half
 			mov 		dx,0 		;zero out low half
 			div 		cx 			;divide by CX
 			mov 		bx,dx 		;remainder into BX
 			mov 		dl,al 		;quotient into DL
;print the contents of DL on screen
 			add 		dl,30h 		;convert to ASCII
 			mov 		ah,02h 		;display function
 			int 		21h 		;call DOS
 			ret 					;return from dec_div
dec_div 	endp
;--------------------------------------------------------
crlf 		proc 		near
;print carriage return and linefeed
 			mov 		dl,0ah 		;linefeed
 			mov 		ah,02h 		;display function
 			int 		21h
;
 			mov 		dl,0dh 		;carriage return
 			mov 		ah,02h 		;display function
 			int 		21h
;
 			ret
crlf 		endp
;-------------------------------------------------------
program 	ends 					;end of code segment
;*******************************************************
 			end 		start 		;end assembly