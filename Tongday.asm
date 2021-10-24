.MODEL SMALL
.STACK 100H
.DATA
    WR1 DB "Nhap day: $"  
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
    
NHAP:
    MOV DX,0
    MOV AH,1
    INT 21H
    CMP AL,13
    JE THOATNHAP
    SUB AL,30H
    MOV AH,0 
    MOV TAM,AX
    MOV BL,2
    DIV BL
    MUL BL
    CMP AX,TAM
    JE NHAP
    MOV AX,TAM
    ADD KQ,AX
    JMP NHAP
    
THOATNHAP:
    
    LEA DX,WR3
    MOV AH,9
    INT 21H
    
    MOV AX,KQ
    CALL XUAT
    
    MOV AH,4CH
    INT 21H
    
MAIN ENDP

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