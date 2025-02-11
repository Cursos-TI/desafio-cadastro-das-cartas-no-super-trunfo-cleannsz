#include <stdio.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para armazenar as informações de cada cidade
typedef struct {
    char codigo[4];
    int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    double pib_per_capita;
} Cidade;

void cadastrar_cidades(Cidade cidades[NUM_ESTADOS * CIDADES_POR_ESTADO]) {
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;
    
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 1; j <= CIDADES_POR_ESTADO; j++) {
            sprintf(cidades[index].codigo, "%c%02d", estados[i], j);
            printf("Cadastro da cidade %s:\n", cidades[index].codigo);
            printf("Populacao: ");
            scanf("%d", &cidades[index].populacao);
            printf("Area (km²): ");
            scanf("%f", &cidades[index].area);
            printf("PIB (em bilhões): ");
            scanf("%lf", &cidades[index].pib);
            printf("Numero de pontos turisticos: ");
            scanf("%d", &cidades[index].pontos_turisticos);
            
            // Cálculos das propriedades
            if (cidades[index].area > 0) {
                cidades[index].densidade_populacional = cidades[index].populacao / cidades[index].area;
            } else {
                cidades[index].densidade_populacional = 0;
            }
            
            if (cidades[index].populacao > 0) {
                cidades[index].pib_per_capita = cidades[index].pib / cidades[index].populacao;
            } else {
                cidades[index].pib_per_capita = 0;
            }
            index++;
        }
    }
}

void exibir_cidades(Cidade cidades[NUM_ESTADOS * CIDADES_POR_ESTADO]) {
    printf("\nCIDADES CADASTRADAS:\n");
    for (int i = 0; i < NUM_ESTADOS * CIDADES_POR_ESTADO; i++) {
        printf("Codigo: %s\n", cidades[i].codigo);
        printf("Populacao: %d\n", cidades[i].populacao);
        printf("Area: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2lf bilhões\n", cidades[i].pib);
        printf("Pontos turisticos: %d\n", cidades[i].pontos_turisticos);
        printf("Densidade Populacional: %.2f hab/km²\n", cidades[i].densidade_populacional);
        printf("PIB per Capita: %.2lf\n", cidades[i].pib_per_capita);
        printf("-------------------------\n");
    }
}

int main() {
    Cidade cidades[NUM_ESTADOS * CIDADES_POR_ESTADO];
    
    cadastrar_cidades(cidades);
    exibir_cidades(cidades);
    
    return 0;
}
