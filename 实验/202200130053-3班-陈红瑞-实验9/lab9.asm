datasg segment para 'data'
	targetStr label byte
		max db 100
		act db ?
		buf db 100 dup(?) ;��׼�����Ӧ�Ļ�����

    
	counter db 0,0,0,0
 	c1 db '0','0',13,10,'$'
 	c2 db '0','0',13,10,'$'
 	c3 db '0','0',13,10,'$'
    
datasg ends

codesg segment para 'code'
	assume cs:codesg,ds:datasg,es:datasg

main	proc	far
	push ds
	sub  ax,ax
	push ax
        ;�ѵ�ǰ���ݶε���ʼ��ַ����ds��es�Ĵ�����
	mov ax,datasg
	mov ds,ax
	mov es,ax

start:
	;lea dx,mess1
	;mov ah,09
	;int 21h
	
	lea dx,targetStr
	mov ah,0ah
	int 21h
	cmp act,0
	;je toExit        ;�������ת
    
	;lea dx,mess2
	;mov ah,09
	;int 21h
	mov si,0
    jmp work

work:
	lea bx,buf       ;��λ�׸��ַ�
	xor cx,cx
	mov cl,act

lop:
	mov al,[bx]
	cmp al,'a'
	jb next1
	cmp al,'z'
	ja next1
	inc counter[si]      ;С��a����z��������һ�����counter[si]+1
	jmp exit

next1:
	cmp al,'A'
	jb next2
	cmp al,'Z'
	ja next2
	inc counter[si+1] ;С��A����Z��������һ�����counter[si+1]+1
	jmp exit

next2:
	cmp al,'0'
	jb next3
	cmp al,'9'
	ja next3
	inc counter[si+2] ;С��0����9��������һ�����counter[si+2]+1
	jmp exit

next3:
	inc counter[si+3] ;ʣ�¾��������ַ��ˣ�counter[si+3]+1
	
exit:
	inc bx
	loop lop ;ѭ��
	
	mov cx,10
	mov bx,0
	xor ax,ax
	
	mov al,counter[si]

	div cl
	
	xor c1[bx],al
	xor bx,1
	xor c1[bx],ah
	xor bx,1
	xor ax,ax


	mov al,counter[si+1]
	div cl
	xor c2[bx],al
	xor bx,1
	xor c2[bx],ah
	xor bx,1
	xor ax,ax
	
	mov al,counter[si+2]
	div cl
	xor c3[bx],al
	xor bx,1
	xor c3[bx],ah
	
	mov ah,09h
	mov bx,0
	cmp c1[bx],'0'  ;��ʮλ��0ʱ�ʹӸ�λ��ʼ���
	je  t1
	lea dx,c1
	jmp t2
t1:	lea dx,c1+1
t2:
	int 21h
	cmp c2[bx],'0'
	je  t3
	lea dx,c2
	jmp t4
t3:	lea dx,c2+1
t4:	int 21h
	cmp c3[bx],'0'
	je  t5
	lea dx,c3
	jmp t6
t5:	lea dx,c3+1
t6:	int 21h
	
	ret

main endp
codesg ends
end main