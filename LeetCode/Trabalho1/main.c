#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *longestNiceSubstring(char *s) {
  char chave;
  int cont = 0;
  char letra;
  char *p = NULL;
  for (int i = 0; i < strlen(s); i++) {
    chave = s[i];
    if (chave == s[i]) {
      cont++;
    }
    while (cont > 1) {
      letra = chave;
      p = strstr(s, letra); // retorna um ponteiro para o inicio da substring.
      return p;
    }
  }
 
}
int main(void) {

  char *s = "YazaAay";
  char *resultado = longestNiceSubstring(s);
  if (resultado != NULL) {
    printf("%s\n", resultado);
    free(resultado);
  } else {
    printf("Nenhuma Substring.\n");
  }
}