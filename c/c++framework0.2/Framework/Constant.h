#pragma once
// Constant

// DWORD : unsigned long
// 00000000 00000000 00000000 00000000



const DWORD KEY_UP		= 1;
const DWORD KEY_DOWN	= 2;
const DWORD KEY_LEFT	= 4;
const DWORD KEY_RIGHT	= 8;
const DWORD KEY_SPACE	= 16;
const DWORD KEY_RETURN	= 32;
const DWORD KEY_ESCAPE	= 64;


// 1024 * 1024 까지 2의 배수로 지정가능
// 
// 00000001 = UP	 = 1
// 00000010 = DOWN	 = 2
// 00000100 = LEFT	 = 4
// 00001000 = RIGHT	 = 8
// 00010000 = SPACE	 = 16
// 00100000 = ENTER	 = 32
// 01000000 = ESCAPE = 64
// 10000000          = 128
// 00000001 00000000 = 256
// 00000010 00000000 = 512
// 00000100 00000000 = 1024      

// 00000111 = 3개 동시에 누른거 (1, 2, 4)






