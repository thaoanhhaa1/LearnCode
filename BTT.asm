MODEL SMALL
.DATA
    S1 DB 0AH,0DH,'Nhap so a:$' 
    S2 DB 0AH,0DH,'Nhap so b:$' 
    S3 DB 0AH,0DH,'Tich axb la:$' 
    S4 DB 0AH,0DH,'Hieu a/b la:$' 
    S5 DB 0AH,0DH,'Tong a+b la:$' 
    S6 DB 0AH,0DH,'Nhan phim bat ki ket thuc..$' 
    S7 DB 0AH,0DH,'NHAP SAI NHAP LAI$'
.CODE
    MOV AX,@DATA
    MOV DS,AX
NHAPSO:
    MOV AH,9
    LEA DX,S1
    INT 21H
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    MOV AH,9
    LEA DX,S2
    INT 21H
    MOV AH,1
    INT 21H
    
CALL KTSO
    SUB BL,30H
    SUB AL,30H
    ADD BL,AL
    ADD BL,30H
    MOV AH,9
    LEA DX,S5
    INT 21H
    MOV DL,BL
    MOV AH,2
    INT 21H
    JMP THOAT
    
KTSO:
    CMP AL,30H
    JL TBLOI
    CMP AL,39H
    JG TBLOI
    
TBLOI:
    MOV AH,9
    LEA DX,S7
    INT 21H
    JMP NHAPSO
    
THOAT:
    MOV AH,9
    LEA DX,S6
    INT 21H
    MOV AH,1
    INT 21H
    MOV AH,4CH
    INT 21H
END