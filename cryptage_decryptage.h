#ifndef _DES_H_
#define _DES_H_

typedef struct {
	char cle[8];
	char g[4];
	char d[4];
} sous_cle;

void generate_key(char* cle);
void generate_sub_keys(char* cle, sous_cle* sous_cles);
void crypter(char* message);
void decrypter(char* message);

#endif
