#pragma once

#include <stdio.h>
#include "ball.h"
#include "racket.h"
#include "dimension.h"

// отрисовка поля
void fieldDraw (struct Ball b, struct Racket r1, struct Racket r2, int CntFirst, int CntSecond) {
    
    for (int i = 1; i <= FieldHeight; ++i) {
        for (int j = 1; j <= FieldWidth; ++j) {
            
            // отрисовка боковых стен поля
            if ((j == 1 || j == FieldWidth) && i != 1) {
                printf("|");
            }

            // отрисовка сетки
            else if (j == FieldWidth / 2 && i != 1) {
                printf("┆");
            }

            // отрисовка верхей и нижней стен поляы
            else if (i == 1 || i == FieldHeight) {
                printf("_");
            }

            // отрисовка мяча
            else if (i == b.x && j == b.y) {
                printf("*");
            }
            
            // отрисовка ракеток
            else if (j == r1.p1.x && (i >= r1.p1.y && i <= r1.p2.y) 
                || j == r2.p1.x && (i >= r2.p1.y && i <= r2.p2.y)) {
                    printf("┃");
            }

            else if (j == FieldWidth / 2 - 1 && i == 2) {
                printf("%d", CntFirst);
            }

            else if (j == FieldWidth / 2 + 1 && i == 2) {
                printf("%d", CntSecond);
            }

            else {
                printf(" ");
            }

        }
        printf("\n");
    }
}

// проверка, что мяч улетел за ракетку,
// значит игрок никогда его не поймает
int ballIsBehindRacket (struct Ball b, struct Racket r) {

    // если это левая ракетка
    if (r.p1.x < FieldWidth / 2) {

        // мяч улетел за ракетку?
        return b.y < r.p1.x;
    }
    
    // если это правая ракетка
    else {

        // мяч улетел за ракетку?
        return b.y > r.p1.x;
    }

}

// возвращает 1, если мяч коснулся стены
// иначе - 0
int BallIsOnWall (struct Ball b) {
    return b.x <= 1 || b.x >= FieldHeight;
}

void BounceFromWall (struct Ball *b) {

    if (!BallIsOnWall(*b)) {
        return;
    }

    b->kx = -b->kx;

    if (b->x > FieldWidth / 2) {
        b->ky = -b->ky;
    }

}
