.MODEL SMALL
.DATA
    WR1 DB "NHAP N: $"
    WR2 DB 10,13,"XUAT: $"
    N DW ?
    Y DW ? 
    KQ DW ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    LEA DX,WR1
    MOV AH,9
    INT 21h 
    
    CALL NHAP    
    
    LEA DX,WR2
    MOV AH,9
    INT 21h 
    
    MOV KQ,1
    MOV AX,KQ
    MOV CX,2
    ;SUB CX,30H
    MOV KQ,2
    ;SUB KQ,30H
WHILE_:   
    ;MOV DX,N
    CMP CX,N
    JNBE THOATWHILE 
    MOV BX,CX 
    MUL BX
    ADD CX,KQ
    JMP WHILE_
    
THOATWHILE: 
    CALL XUAT
    
    MOV AH,4CH
    INT 21h
    
MAIN ENDP

NHAP PROC 
    MOV N,0
    NHAPA:
    MOV AH,1
    INT 21H
    CMP AL,13
    JE THOATNHAPA 
    SUB AL,30H 
    XOR AH,AH 
    MOV Y,AX
    MOV AX,N
    MOV BX,10
    MUL BX
    ADD AX,Y
    MOV N,AX
    JMP NHAPA 
    
THOATNHAPA:
    
    RET 
    
NHAP ENDP

;CTC xuat so
XUAT PROC
   MOV CX,0     
    MOV AX,AX
CHIA1:  
    MOV DX,0    
    MOV BX,0AH
    DIV BX          ; AX / BX -> NGUYEN LUU AX, DU LUU DX
    PUSH DX         ; Cat DX vao stack
    INC CX
    CMP AL,0
    JBE THOATCHIA1
    JMP CHIA1
    
THOATCHIA1:                  
    
TOP1:
    POP DX          ;Lay du lieu tu dinh stack dua vao DX
    MOV AH,2  
    ADD DL,30H
    INT 21H
    DEC CX
    CMP CX,0
    JNE TOP1
    RET
XUAT ENDP  
    END MAIN