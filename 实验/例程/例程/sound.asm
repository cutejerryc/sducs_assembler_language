        CODE    SEGMENT
        ASSUME  CS:CODE

        MAIN    PROC    FAR
        PUSH    DS
        SUB     AX, AX
        PUSH    AX
START:
        MOV     AL, 182
        OUT     43H, AL         ; NOTE.
        MOV     AX, 4560        ; FREQUENCY NUMBER (IN DECIMAL) FOR MIDDLE C.
        OUT     42H, AL         ; OUTPUT LOW BYTE.
        MOV     AL, AH          ; OUTPUT HIGH BYTE.
        OUT     42H, AL 
        IN      AL, 61H         ; TURN ON NOTE (GET VALUE FROM PORT 61H).
        OR      AL, 00000011B   ; SET BITS 1 AND 0.
        OUT     61H, AL         ; SEND NEW VALUE.
        MOV     BX, 25          ; PAUSE FOR DURATION OF NOTE.
.PAUSE1:
        MOV     CX, 65535
.PAUSE2:
        DEC     CX
        JNE     .PAUSE2
        DEC     BX
        JNE     .PAUSE1
        IN      AL, 61H         ; TURN OFF NOTE (GET VALUE FROM
                                ; PORT 61H).
        AND     AL, 11111100B   ; RESET BITS 1 AND 0.
        OUT     61H, AL         ; SEND NEW VALUE.

        RET
        MAIN    ENDP

        CODE    ENDS

        END