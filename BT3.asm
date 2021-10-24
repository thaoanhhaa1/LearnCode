.MODEL SMALL
.STACK 100h
.DATA
    WR1 DB "Nhap N: $"
    SO1 DB 0
    GT1 DB 0
.CODE
MAIN PROC

    ;Nhan 2 so
    MOV AX,@DATA
    MOV DS,AX
    
    ;Nhap so thu nhat
    LEA DX,WR1
    MOV AH,9
    INT 21h
    
    MOV SO1,0
    OR SO1,'0'
NHAP:
    MOV AH,1
    INT 21h
    CMP AL,13;So sanh ki tu vua nhap voi Enter
    JE THOATNHAP1
    ;ADD AL,30H;Chuyen ki tu thanh so
    OR AL,'0'
    MOV DL,AL
    MOV CL,SO1
    MOV BL,10
WHILE_:
    ADD SO1,CL
    DEC BL
    CMP BL,0
    JNE WHILE_
    ADD SO1,DL
    
    MOV AH,2
    MOV DL,SO1
    INT 21H
    
    JMP NHAP
    
THOATNHAP1:

    MOV DL,SO1
    MOV BL,0
    MOV CL,10
    MOV AL,DL
    ;MOV SO1,AL
    
A1:
    MOV DX,0
    DIV CX
    ADD DL,30h
    PUSH DX
    INC BL
    CMP AL,0
    JNE A1
    
A2:
    POP DX
    MOV AH,2
    INT 21h
    DEC BL
    CMP BL,0
    JNE A2  

THOAT:

    MOV AH,4CH
    INT 21h

MAIN ENDP
END MAIN