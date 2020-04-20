/*
    Soluciones al Laboratorio de Algoritmia 2020-1 - Pregunta 2
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
 * Estrategia: menor distancia entre 2 puntos
 */

#include <stdio.h>
#include <math.h>


int main(int argc, char** argv)
{
    // Ingreso de datos
    int num_static, num_moves;
    double radius;
    printf("Personas en cuarentena: ");
    scanf("%d", &num_static);
    printf("Radio de contagio: ");
    scanf("%lf", &radius);
    int static_info[num_static][3];
    for (int i = 0; i < num_static; ++i) {
        printf("=== Persona %d ===\n", i + 1);
        printf("Estado (0=sano, 1=contagiado): ");
        scanf("%d", &static_info[i][0]);
        printf("Posicion X: ");
        scanf("%d", &static_info[i][1]);
        printf("Posicion Y: ");
        scanf("%d", &static_info[i][2]);
    }
    printf("\nCantidad de movimientos: ");
    scanf("%d", &num_moves);
    int moves[num_moves][2];
    for (int i = 0; i < num_moves; ++i) {
        printf("=== Movimiento %d ===\n", i + 1);
        printf("X: ");
        scanf("%d", &moves[i][0]);
        printf("Y: ");
        scanf("%d", &moves[i][1]);
    }
    printf("\n");
    // proceso de datos
    for (int i = 0; i < num_moves; ++i) {
        int xmove = moves[i][0], ymove = moves[i][1];
        for (int j = 0; j < num_static; ++j) {
            int xstatic = static_info[j][1], ystatic = static_info[j][2];
            double distance = sqrt(pow(xmove - xstatic, 2) + pow(ymove - ystatic, 2));
            if (distance <= radius && static_info[j][0]) {
                printf("Persona podria haberse contagiado en su movimiento %d por la persona %d con nivel de"
                       " cercania %.2lf.\n", i + 1, j + 1, distance);
            }
        }
    }
    return 0;
}