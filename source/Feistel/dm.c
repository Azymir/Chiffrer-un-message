#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INT_SIZE sizeof(int)
#define INT_BITS INT_SIZE * 8 - 1 


int binaire_to_decimale(long n){
	int num=0, i=0, rem;
	long v=n;
	while(n>0){
		rem = n%10;
		num = num+rem*pow(2, i);
		i++;
		n = n/10;
	}
	return num;
}

int hexadecimale_decimale(char hex[]){

	int dec=0, len, i=0, novalid=0;
	len = strlen(hex);
	while(i < len){
		switch(hex[i]){
			case '0' :
				dec = dec + (int)pow(16,len-i-1)*0;
				break;
			case '1' :
				dec = dec + (int)pow(16,len-i-1)*1;
				break;
			case '2' :
				dec = dec + (int)pow(16,len-i-1)*2;
				break;
			case '3' :
				dec = dec + (int)pow(16,len-i-1)*3;
				break;
			case '4' :
				dec = dec + (int)pow(16,len-i-1)*4;
				break;
			case '5' :
				dec = dec + (int)pow(16,len-i-1)*5;
				break;
			case '6' :
				dec = dec + (int)pow(16,len-i-1)*6;
				break;
			case '7' :
				dec = dec + (int)pow(16,len-i-1)*7;
				break;
			case '8' :
				dec = dec + (int)pow(16,len-i-1)*8;
				break;
			case '9' :
				dec = dec + (int)pow(16,len-i-1)*9;
				break;
			case 'A' :
				dec = dec + (int)pow(16,len-i-1)*10;
				break;
			case 'B' :
				dec = dec + (int)pow(16,len-i-1)*11;
				break;
			case 'C' :
				dec = dec + (int)pow(16,len-i-1)*12;
				break;
			case 'D' :
				dec = dec + (int)pow(16,len-i-1)*13;
				break;
			case 'E' :
				dec = dec + (int)pow(16,len-i-1)*14;
				break;
			case 'F' :
				dec = dec + (int)pow(16,len-i-1)*15;
				break;
			default :
				novalid = 1;
				break;
		}
		if(novalid == 1)
			break;
		i++;
	}
	if(novalid == 0)
		return dec;
	else
		printf("Inserez un nombre hexadecimale correcte");
}


char* decimale_to_hexadecimale(int num){
	int temp, rem, i=1, j;
	char hexa[50];
	
	temp = num;
	while(temp != 0){
		rem = temp%16;
		if(rem<10)
			rem = rem+48;
		else
			rem = rem+55;
		hexa[i++] = rem;
		temp = temp/16;
	}
	char* tab = (char*)malloc(i);
	for(j=i-1; j>0; j--){
		tab[i-j-1] = hexa[j];
	}
	return tab;
} 


int rotateLeft(int num, unsigned int rotation)
{
    int DROPPED_MSB;

    // The effective rotation
    rotation %= INT_BITS;


    // Loop till rotation becomes 0
    while(rotation--)
    {
        // Get MSB of num before it gets dropped
        DROPPED_MSB = (num >> INT_BITS) & 1; 

        // Left rotate num by 1 and 
        // Set its dropped MSB as new LSB
        num = (num << 1) | DROPPED_MSB;
    }

    return num;
}


int main(){

	char a[255], b[255], k0[255], k1[255];
	

	printf("Donnez le premier mot en héxadécimale : "); // le mot a gauche
	scanf("%s", a);
	int a_dec = hexadecimale_decimale(a);

	printf("Donnez le deuxième mot en héxadécimale : "); // le mot à droite
	scanf("%s", b);
	int b_dec = hexadecimale_decimale(b);

	long a_xor_b = a_dec ^ b_dec ;

	a_dec = rotateLeft(a_xor_b, 7);

	printf("Donnez la première clé en héxadécimale : "); // k0
	scanf("%s", k0);
	int k0_dec = hexadecimale_decimale(k0);

	a_dec = a_dec ^ k0_dec;

	b_dec = b_dec ^ a_dec;

	b_dec = rotateLeft(b_dec, 7);

	printf("Donnez la deuxième clé en héxadécimale : "); // k1
	scanf("%s", k1);
	int k1_dec = hexadecimale_decimale(k1);

	b_dec = b_dec ^ k1_dec;
	

	printf("L1  = %x\n", a_dec);
	printf("R1  = %x\n", b_dec);

	return 0;
}

