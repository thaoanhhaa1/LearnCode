.MODEL SMALL
.STACK 100H
.DATA
    WR1 DB "Nhap N: $"
    WR2 DB 10,13,"Nhap mang: $"  
    WR3 DB 10,13,"Tong le: $" 
    N DW ?
    TAM DW ?
    Y DW ?
    A DW ?
    KQ DW ?
.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    LEA DX,WR1
    MOV AH,9
    INT 21H    
    
    CALL NHAP
    MOV AX,TAM 
    MOV N,AX
    
    LEA DX,WR2
    MOV AH,9
    INT 21H
    
WHILE_:
    CMP N,0
    JE THOATWHILE 
    CALL NHAP 
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    DEC N 
    MOV AX,TAM
    MOV DX,0
    MOV BX,2
    DIV BX
    MUL BX 
    CMP AX,TAM
    JE WHILE_ 
    MOV CX,TAM
    ADD KQ,CX
    JMP WHILE_
    
THOATWHILE:        
    
    LEA DX,WR3
    MOV AH,9
    INT 21H
    
    MOV AX,KQ
    CALL XUAT
    
    MOV AH,4CH
    INT 21H
    
MAIN ENDP

NHAP PROC
    
    MOV TAM,0
NHAPA:    
    MOV AH,1
    INT 21H
    CMP AL,13
    JE THOATNHAP 
    SUB AL,30H
    MOV AH,0
    MOV Y,AX
    MOV AX,TAM
    MOV BX,10
    MUL BX
    ADD AX,Y
    MOV TAM,AX
    JMP NHAPA
    
THOATNHAP:

    RET     
     
NHAP ENDP

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