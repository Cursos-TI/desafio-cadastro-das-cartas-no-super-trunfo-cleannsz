#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void calcularPropriedades(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos;
}

void cadastrarCarta(Carta *carta, char estado, int numero) {
    sprintf(carta->codigo, "%c%02d", estado, numero);
    printf("Cadastro da carta %s:\n", carta->codigo);
    printf("Populacao: ");
    scanf("%d", &carta->populacao);
    printf("Area: ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);
    calcularPropriedades(carta);
}

void exibirCarta(Carta carta) {
    printf("\nCarta %s:\n", carta.codigo);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km^2\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos turisticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km^2\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

void compararCartas(Carta c1, Carta c2) {
    printf("\nComparacao entre %s e %s:\n", c1.codigo, c2.codigo);
    printf("Densidade Populacional: %s vence\n", (c1.densidade_populacional < c2.densidade_populacional) ? c1.codigo : c2.codigo);
    printf("Populacao: %s vence\n", (c1.populacao > c2.populacao) ? c1.codigo : c2.codigo);
    printf("Area: %s vence\n", (c1.area > c2.area) ? c1.codigo : c2.codigo);
    printf("PIB: %s vence\n", (c1.pib > c2.pib) ? c1.codigo : c2.codigo);
    printf("Pontos Turisticos: %s vence\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.codigo : c2.codigo);
    printf("Super Poder: %s vence\n", (c1.super_poder > c2.super_poder) ? c1.codigo : c2.codigo);
}

int main() {
    Carta cartas[NUM_ESTADOS * NUM_CIDADES];
    int total_cartas = 0;
    char estados[NUM_ESTADOS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char continuar;
    
    do {
        if (total_cartas >= NUM_ESTADOS * NUM_CIDADES) {
            printf("Numero maximo de cartas cadastradas!\n");
            break;
        }
        cadastrarCarta(&cartas[total_cartas], estados[total_cartas / NUM_CIDADES], (total_cartas % NUM_CIDADES) + 1);
        total_cartas++;
        printf("Deseja cadastrar outra carta? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's');
    
    for (int i = 0; i < total_cartas; i++) {
        exibirCarta(cartas[i]);
    }
    
    if (total_cartas > 1) {
        int c1, c2;
        printf("\nInforme os indices das duas cartas para comparar (0-%d): ", total_cartas - 1);
        scanf("%d %d", &c1, &c2);
        if (c1 >= 0 && c1 < total_cartas && c2 >= 0 && c2 < total_cartas) {
            compararCartas(cartas[c1], cartas[c2]);
        } else {
            printf("Indices invalidos!\n");
        }
    }
    return 0;
}
