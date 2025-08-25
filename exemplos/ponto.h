//tipo opaco Ponto
typedef struct ponto Ponto;

//cria um novo ponto com coordenadas "x" e "y"
Ponto* ponto_cria(float x, float y);

//libera um ponto
void ponto_libera(Ponto* p);

//Acessa os valores de "x" e "y" de um ponto
int ponto_acessa(Ponto* p, float* x, float* y);

//atribui os valores "x" e "y" a um ponto
int ponto_atribui(Ponto* p, float x, float y);

//calcula a distancia entre dois pontos
float ponto_distancia(Ponto* p1, Ponto* p2);