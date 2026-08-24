    #include <stdio.h>
    #include <stdlib.h>

    typedef struct{
        int x, y;
        int size;
        int quadrados[];
    } Point;


    void quadrado(Point *arr, int n){
        for(int i = 0; i < n; i++){
            arr->quadrados[i] *= arr->quadrados[i];
        }
    }


    void quadrado_indice(Point *arr, int indice){
        arr->quadrados[indice] *= arr->quadrados[indice];
    }

    void exibir(Point *arr, int n){
        for(int i = 0; i < n; i++){
            printf("%d ", arr->quadrados[i]);
        }
        printf("\n");
    }

    int tamanho(Point *arr, int n){
            arr->size = n;

            return arr->size;
    }

    int main() {

        int n;
        scanf("%d", &n);
        Point *p = malloc(sizeof(Point) + (n * sizeof(int)));

        for(int i = 0; i < n; i++){
            scanf("%d", &(p->quadrados)[i]);
        }

        exibir(p, n);
        printf("Tamanho: %d\n", tamanho(p, n));

        quadrado(p,n);
        exibir(p, n);
        printf("Tamanho: %d \n", tamanho(p, n));
        
        n++; //Incrementa o tamanho do array para receber um novo valor

        Point *temp = realloc(p, sizeof(Point) + n * sizeof(int));
        if(temp == NULL){
            printf("Erro na alocação de memória\n");
            free(temp);
            return -1;
        }

        p = temp;

        printf("Inserindo um novo valor:");
        scanf("%d", &p->quadrados[n-1]);

        exibir(p, n);
        quadrado_indice(p, n-1); 
        exibir(p, n);

        free(p);

        return 0;
    }