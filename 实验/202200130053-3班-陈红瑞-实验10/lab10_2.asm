datarea         segment
      crlf     db         13,10,'$'
      space     db         ' ','$'
datarea         ends
;
prognam     segment
      assume cs:prognam,ds:datarea
;
main      proc      far
start:
          push      ds
          sub       ax,ax
          push      ax

          mov      ax,datarea
          mov      ds,ax
          mov      dl,21h
          mov      cx,11

outside:
          push        cx
          mov         cx,20

inside:
          mov         ah,02h
          int         21h
          inc         dl
            
          push        dx            ;����DL���ַ�
          lea         dx,space      ;����ո�
          mov         ah,09h
          int         21h

          pop         dx             ;�ָ�DL���ַ�
          loop        inside

          push        dx             ;����DX
          lea         dx,crlf       ;�������

          mov         ah,09h
          int         21h

          pop         dx              ;�ָ�DX
          pop         cx              ;�ָ�CX���ص����ѭ��

          loop        outside
          ret
main      endp

prognam      ends

end       start