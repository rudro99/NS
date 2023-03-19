#include<stdio.h>
#include<string.h>

char a[20], b[20];
 
void encrypt(char p[], int k1)
{
    int k[30];
    k[0] = k1;
    for(int i=1; i<strlen(p); i++)
         k[i] = p[i-1] - 'a';
    for(int i=0; i<strlen(p); i++)
    {
        a[i] = ((p[i]-'a'+ k[i]) % 26) + 'A';
    }
}

void decrypt(char c[], int k1)
{
    int k[30];
    k[0] = k1;
    for(int i=1; i<strlen(c); i++)
         k[i] = (c[i-1] + 'A' - k[i-1] ) % 26;

    for(int i=0; i<strlen(c); i++)
    {
        b[i] = ((c[i] + 'A' - k[i]) % 26) + 'a';
    }
}

int main(){

    char p[20], c[20], d[20];
    int k1;

    freopen("autokeyInput.txt", "r", stdin);
    scanf("%s %d", p, &k1);

    encrypt(p, k1);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c, k1);
    strcpy(d, b);
    printf("Deciphertext: %s\n", d);

    return 0;
}


