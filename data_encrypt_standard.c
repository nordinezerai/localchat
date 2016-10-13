#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char table_permut_ini[64] = {58,50,42,34,26,18,10,2,
							 60,52,44,36,28,20,12,4,
							 62,54,46,38,30,22,14,6,
							 64,56,48,40,32,24,16,8,
							 57,49,41,33,25,17,9,1,
							 59,51,43,35,27,19,11,3,
							 61,53,45,37,29,21,13,5,
							 63,55,47,39,31,23,15,7};

char table_exp[48] = {32,1,2,3,4,5,
		 	 	 	  4,5,6,7,8,9,
		 	 	 	  8,9,10,11,12,13,
		 	 	 	  12,13,14,15,16,17,
		 	 	 	  16,17,18,19,20,21,
		 	 	 	  20,21,22,23,24,25,
		 	 	 	  24,25,26,27,28,29,
		 	 	 	  28,29,30,31,32,1};

char key[64] = {58,50,42,34,26,18,10,2,
				 60,52,44,36,28,20,12,4,
				 62,54,46,38,30,22,14,6,
				 64,56,48,40,32,24,16,8,
				 57,49,41,33,25,17,9,1,
				 59,51,43,35,27,19,11,3,
				 61,53,45,37,29,21,13,5,
				 63,55,47,39,31,23,15,7};

char table_keyG_permut[28] = {57,49,41,33,25,17,9,
							1,58,50,42,34,26,18,
							10,2,59,51,43,35,27,
							19,11,3,60,52,44,36};

char table_keyD_permut[28] = {63,55,47,39,31,23,15,
			   	   	   	    7,62,54,46,38,30,22,
			   	   	   	   	14,6,61,53,45,37,29,
			   	   	   	   	21,13,5,28,20,12,4};

char tabG_ini[32];
char tabD_ini[32];
char tabG_exp[48];
char tabD_exp[48];
char keyG[28];
char keyD[28];
char key56[56];

char* crypt(char* message){

	int block = ceil(sizeof(message)/64.0);

	char message_crypte[block*64];

	for(int i = 1; i<=block;i++){ // on commence à parcourir par numero de block

		for(int j=(i-1)*64; j<64*i && j<sizeof(message);j++){  // on parcours les 64 valeurs de chaques blocks

			message_crypte[table_permut_ini[j]-1]=message[j];  // permutation initial

		}

		for(int k=0;k<32;k++){	// 	on scinde le tableau obtenu en 2 blocks de 32 bits ( partie gauche et droite)
			tabG_ini[k]=message_crypte[k];
			tabD_ini[k]=message_crypte[k+32];
		}

		for(int l=0;l<48;l++){			// expansion du tableau de la partie droite en block de 48 bits
			tabD_exp[l]=tabD_ini[table_exp[l]-1];
		}

		for(int m=0;m<28;m++){			// transformation de la clé de 64 bits en 2 tableaux de 28 bits (partie gauche et droite)
			keyG[m]=key[table_keyG_permut[m]-1];
			keyD[m]=key[table_keyD_permut[m]-1];
		}

	}

	return message_crypte;
}

char* decrypt(char* message_crypte){

	char message[sizeof(message_crypte)];

	for(int i = 0; i<64;i++){

	}

	return message;
}
