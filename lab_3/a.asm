   global _f
_f:
        push    ebp     
		push 	edx
		xor 	edx, edx
		mov 	ebx, 3
		idiv 	ebx
		pop     edx
		shr	edx, 3
		mov 	ebx, eax
		imul	ecx, edx
		add	eax, ecx		
		pop 	ebp    
  
        ret                  
