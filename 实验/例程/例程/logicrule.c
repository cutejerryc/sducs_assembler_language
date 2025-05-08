#include <stdio.h>
typedef unsigned char u8_t;
typedef unsigned short u16_t;

#define LENGTH	10
#define ISB	0
#define ISW	1
#define ADD	0
#define SUB	1
#define MUL	2
#define DIV	3
#define POW	4
#define B(X)	(*((u8_t* restrict)(X)))
#define W(X)	(*((u16_t* restrict)(X)))

u8_t ain[1024], bin[1024], cout[1024];
u16_t din[1024], ein[1024], fout[1024];
u8_t oper[1024];

void calc(void* restrict s1, void* restrict s2, void* restrict d, u8_t o, u8_t t);
int main(void) {
unsigned short port;
unsigned char write;
unsigned char read;

	for (u16_t i = 0; i < 1024; i++) {
		calc(&ain[i],&bin[i],&cout[i],oper[i],ISB);
		calc(&din[i],&ein[i],&fout[i],oper[i],ISW);
	}
    __asm__ __volatile__("outb %[write], %[port]" : : [write]"a"(write), [port]"Nd"(port));
    __asm__ __volatile__("inb %[port], %[read]" : [read]"=a"(read) : [port]"Nd"(port));
	return 0;
}

void calc(void* s1, void* s2, void* d, u8_t o, u8_t t) {
	if (t == ISB) {
		switch (o) {
			case ADD: B(d) = B(s1) + B(s2); break;
			case SUB: B(d) = B(s1) - B(s2); break;
			case MUL: B(d) = B(s1) * B(s2); break;
			case DIV: B(d) = B(s1) / B(s2); break;
			case POW: {
				B(d) = 1;
				for (u8_t i = 0; i < B(s2); i++)
					B(d) *= B(s1);
				break;
			}
		}
	} else {
		switch(o) {
			case ADD: W(d) = W(s1) + W(s2); break;
			case SUB: W(d) = W(s1) - W(s2); break;
			case MUL: W(d) = W(s1) * W(s2); break;
			case DIV: W(d) = W(s1) / W(s2); break;
			case POW: {
				W(d) = 1;
				for(u16_t i = 0; i < W(s2); i++)
					W(d) *= W(s1);
				break;
			}
		}

	}
}
