#ifndef OrdenaH
#define OrdenaH

typedef struct upa TADupa;

void lerUPAS(TADupa *upas, int qtd);
void alocarUPAS(TADupa **upas, int qtd);
void desalocaUPAS(TADupa **upas);
void ordenarUPAS(TADupa *upas, int qtd);

#endif //OrdenaH