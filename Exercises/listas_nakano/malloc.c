/* declarando uma matriz e preenchendo elementos */
/* explorando os endereços para entender como m está armazenada */
/* código no main para evitar array to pointer decay. */

#include <stdio.h>
#include <stdlib.h>   // aqui o protótipo da função rand() está definido
                      // ié a função é declarada.
                      // a função está definida em libc.so (glibc)

#define M 5
#define N 11

float m[M][N]; // as dimensões diferentes e de valores específicos vão nos ajudar...

void imprime (float x[M][N]);   // protótipo - define como uma função é usada antes de definir seu funcionamento/comportamento/corpo
                                // útil em projetos maiores onde, habitualmente, as interfaces (protótipos) são definidas em grupo, 
                                // os comportamentos
                                // são combinados em conversas e o trabalho é distribuído definindo quem codifica o quê.

int main() {
  for (int i=0;i<M;i++) {
    for (int j=0;j<N;j++) {
      m[i][j]= rand()/10000.0;
    }
  }
  imprime (m);
  /* análise. Pergunta: como m está armazenado? */
  printf ("Endereço, conteúdo, conteúdo2 e tamanho de m: %p, %p, %p %ld\n", &m, m, *m, sizeof(m));
  printf ("M*N*sizeof float=%ld\n", M*N*sizeof(float));
  printf ("O zero-ésimo elemento de m quanto vale? %p\n", m[0]);
  printf ("m[0][0] quanto vale? %f\n", m[0][0]);
  printf ("m[0][0] em que endereço está? %p\n", &(m[0][0]));
/*
  printf ("O zero-ésimo elemento de M quanto vale? %X\n", m[0]);
fabio@super:~/MeuGithub/IP-Apostila/matrizes$ gcc matriz1-reverso.c 
matriz1-reverso.c: In function ‘main’:
matriz1-reverso.c:30:53: warning: format ‘%X’ expects argument of type ‘unsigned int’, but argument 2 has type ‘float *’ [-Wformat=]
   30 |   printf ("O zero-ésimo elemento de M quanto vale? %X\n", m[0]);
      |                                                    ~^     ~~~~
      |                                                     |      |
      |                                                     |      float *
      |                                                     unsigned int
Agora temos certeza que m[0] é um ponteiro para float.
*/
  printf ("O um-ésimo elemento de m quanto vale? %p\n", m[1]);
  printf ("O um-ésimo elemento de m em que endereço está? %p\n", &(m[1]));
  printf ("m[1][0] quanto vale? %f\n", m[1][0]);
  printf ("m[1][0] em que endereço está? %p\n", &(m[1][0]));
 
  printf ("O tamanho do um-ésimo elemento de m quanto vale? %ld e em hexadecimal? %lX\n", sizeof (m[1]), sizeof (m[1]));
 
}

void imprime (float x[M][N]) {
  for (int i=0;i<M;i++) {
    for (int j=0;j<N;j++) {
      printf ("%f\t", m[i][j]);
    }
    puts("");
  }
}






// /* declarando dinamicamente uma matriz como array de vetores e preenchendo elementos */

// #include <stdio.h>
// #include <stdlib.h>   // aqui o protótipo da função rand() está definido
//                       // ié a função é declarada.
//                       // a função está definida em libc.so (glibc)

// #define M 5
// #define N 11

// float **m; // as dimensões diferentes e de valores específicos vão nos ajudar...

// void imprime (float **x);   // protótipo - define como uma função é usada antes de definir seu funcionamento/comportamento/corpo
//                                 // útil em projetos maiores onde, habitualmente, as interfaces (protótipos) são definidas em grupo, 
//                                 // os comportamentos
//                                 // são combinados em conversas e o trabalho é distribuído definindo quem codifica o quê.

// int main() {
//   m = (float **) malloc (M*sizeof (float *));  // array de ponteiros para linhas
//   for (int i=0;i<M;i++) {
//     m[i]= (float *) malloc (N*sizeof (float));  // array de float (uma linha
//   }

//   for (int i=0;i<M;i++) {
//     for (int j=0;j<N;j++) {
//       m[i][j]= rand()/10000.0;
//     }
//   }

//   imprime (m);


//   /* análise. Pergunta: como m está armazenado? */
//   printf ("Endereço, conteúdo, conteúdo 2 e tamanho de m: %p, %p, %p, %ld\n", &m, m, *m, sizeof(m));
//   printf ("M*N*sizeof float=%ld\n", M*N*sizeof (float));
//   printf ("O zero-ésimo elemento de m quanto vale? %p\n", m[0]);
//   printf ("m[0][0] quanto vale? %f\n", m[0][0]);
//   printf ("m[0][0] em que endereço está? %p\n", &(m[0][0]));
//   printf ("O um-ésimo elemento de m quanto vale? %p\n", m[1]);
//   printf ("O um-ésimo elemento de m em que endereço está? %p\n", &(m[1]));
//   printf ("m[1][0] quanto vale? %f\n", m[1][0]);
//   printf ("m[1][0] em que endereço está? %p\n", &(m[1][0]));
 
//   printf ("O tamanho do um-ésimo elemento de m quanto vale? %ld e em hexadecimal? %lX\n", sizeof (m[1]), sizeof (m[1]));


//   for (int i=0;i<M;i++) {
//     free(m[i]);  // boa prática: liberar memória (como o programa está terminando, isto seria feito automaticamente
//   }
//   free(m);

//   m = NULL;  // boa prática: evitar dangling pointer
// }

// void imprime (float **x) {
//   for (int i=0;i<M;i++) {
//     for (int j=0;j<N;j++) {
//       printf ("%f\t", m[i][j]);
//     }
//     puts("");
//   }
// }





