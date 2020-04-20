/*
    Soluciones al Laboratorio de Algoritmia 2020-1 - Pregunta 1
    Copyright (C) 2020  Toro Vera Carlos Santos

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
            the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
            but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
 * Estrategia: Manejo de bits, problema de la mochila
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20

void int_to_bin(unsigned int num, int size, int* out)
{
    unsigned int mask = 1U;
    for (int i = 0; i < size; ++i) {
        out[i] = (num & mask) ? 1 : 0;
        num >>= 1U;
    }
}

int main(int argc, char** argv)
{
    // Ingreso de datos
    int num_workers, req_speed;
    printf("t = ");
    scanf("%d", &num_workers);
    if (num_workers > MAX) {
        printf("Error, solo pueden haber como maximo 20 postulantes.\n");
        exit(EXIT_FAILURE);
    }
    printf("MPxH = ");
    scanf("%d", &req_speed);
    int workers[num_workers][4];
    for (int i = 0; i < num_workers; ++i) {
        printf("=== Postulante %d ===\n", i + 1);
        workers[i][0] = i + 1;
        //printf("Postulante: ");
        //scanf("%d", &(workers[i][0]));
        printf("Rol: ");
        scanf("%d", &workers[i][1]);
        printf("Velocidad (mph): ");
        scanf("%d", &workers[i][2]);
        printf("Bonificacion: ");
        scanf("%d", &workers[i][3]);
    }

    // procesar datos
    int rolls[][3] = {
            {1, 2560, 16},
            {2, 3040, 19},
            {3, 3520, 22}
    };
    int chr[num_workers]; // array de bits
    int selected = -1, max_pay = INT_MAX;

    for (int i = 0; i < pow(2, num_workers); ++i) {
        int_to_bin(i, num_workers, chr);
        int partial_speed = 0, partial_pay = 0;
        for (int j = 0; j < num_workers; ++j) {
            if (chr[j]) {
                int* worker = workers[j];
                partial_speed += worker[2];
                partial_pay += rolls[worker[1] - 1][2] + worker[2] * worker[3];
            }
        }
        if (partial_speed >= req_speed && partial_pay <= max_pay) {
            selected = i;
            max_pay = partial_pay;
        }
    }
    printf("=========\n");
    printf("Trabajadores seleccionados: ");
    int_to_bin(selected, num_workers, chr);
    for (int j = 0; j < num_workers; ++j) {
        if (chr[j]) {
            int* worker = workers[j];
            printf("%d ", worker[0]);
        }
    }
    printf("\nCosto minimo: %d\n", max_pay);

    return 0;
}