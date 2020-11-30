#include <stdio.h>

int main(){

//-----------escrever-----------

    int a = 20;

    FILE *arquivo;

    arquivo = fopen("exemplo1.bin","wb");

    fwrite(&a,sizeof(int),1,arquivo);

    fclose(arquivo);

//-----------ler-----------

    int b;

    arquivo = fopen("exemplo1.bin","rb");

    fread(&b,sizeof(int),1,arquivo);

    printf("%d",b);

    fclose(arquivo);

    return 0;
}

