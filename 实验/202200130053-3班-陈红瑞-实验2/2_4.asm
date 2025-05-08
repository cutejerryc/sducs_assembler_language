; PROGRAM TITLE GOES HEAR -- DIRECT
; direct(com) Direct table access
;************************************
datasg		segment		para		'data'
three		db		 	3 			
mess 		db 			'month?',13,10,'$'
monin 		label 		byte
	max 	db 			3
	act 	db 			?
	mon  	db 			3 dup(?)
;
alfmon 		db 			'???',13,10,'$'
montab 		db 			'JAN','FEB','MAR','APR','MAY','JUN'
			DB 			'JUL','AUG','SEP','OCT','NOV','DEC'
;
datasg 		ends
;*************************************
codesg 		segment 	para 		'code'
;*************************************
			assume cs:codesg, ds:datasg, es:datasg
main 		proc 		far
			push 		ds
			sub 		ax, ax
			push 		ax
;
			mov 		ax, datasg
			mov 		ds, ax
			mov 		es, ax
;						Input month:
; 						-----------
start:
			lea 		dx, mess
			mov 		ah, 09
			int 		21h
			lea 		dx, monin
			mov 		ah, 0ah
			int 		21h
			mov 		dl, 13
			mov 		ah, 02
			int 		21h
			mov 		dl, 10
			mov 		ah, 02
			int 		21h
			cmp 		act, 0
			je 			exit
;						Convert ASCII to binary:
;						-----------------------
			mov 		ah, 30h	 		;Set up month
			cmp 		act, 2
			je 			two
			mov 		al, mon
			jmp 		conv
two:
			mov 		al, mon + 1
			mov 		ah, mon
conv: 
			xor 		ax, 3030h 	;Clear ASCII 3's
			cmp 		ah, 0 		;Month 01-09?
			jz 			loc			;  yes -- bypass
			sub 		ah, ah		;  no -- clear ah
			add 		al, 10 		;  correct for binary
; 						locate month in table:
; 						-------------
loc: 		
			lea 		si, montab
			dec 		al 			;Correct for table
			mul			three		;Mult AL by 3
			add 		si, ax
			mov 		cx, 03		;Init'ze 3 - char move
			cld
			lea 		di, alfmon
			rep 		movsb 		;Move 3 chars
; 						Display alpha month:
; 						-------------
			lea 		dx, alfmon
			mov 		ah, 09
			int 		21h
			jmp 		start
;
exit: 
			ret
main 		endp
;--------------------------------------------
codesg 		ends
;**********************************************
			end 		main