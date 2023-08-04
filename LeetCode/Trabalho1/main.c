 
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
