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
          mov      dl,10h
          mov      cx,15

outside:
          push        cx
          mov         cx,16

inside:
          mov         ah,02h
          int         21h
          inc         dl
            
          push        dx            ;保存DL的字符
          lea         dx,space      ;输出空格
          mov         ah,09h
          int         21h

          pop         dx             ;恢复DL的字符
          loop        inside

          push        dx             ;保存DX
          lea         dx,crlf       ;输出换行

          mov         ah,09h
          int         21h

          pop         dx              ;恢复DX
          pop         cx              ;恢复CX，回到外层循环

          loop        outside
          ret
main      endp

prognam      ends

end       start