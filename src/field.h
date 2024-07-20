#pragma once

#include <stdio.h>
#include "ball.h"
#include "racket.h"
#include "dimension.h"

// отрисовка поля
inline void fieldDraw (struct Ball b, struct Racket r1, struct Racket r2) {
    
    for (int i = 1; i <= FieldHeight; ++i) {
        for (int j = 1; j <= FieldWidth; ++j) {

            if ((j == 1 || j == FieldWidth) && i != 1) {
                printf("|");
            }

            else if (j == FieldWidth / 2 && i != 1) {
                printf("┆");
            }

            else if (i == 1 || i == FieldHeight) {
                printf("_");
            }

            else if (i == b.x && j == b.y) {
                printf("*");
            }
            
            else if (j == r1.p1.x && (i >= r1.p1.y && i <= r1.p2.y) 
                || j == r2.p1.x && (i >= r2.p1.y && i <= r2.p2.y)) {
                    printf("┃");
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
inline int ballIsBehindRacket (struct Ball b, struct Racket r) {

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
inline int BallIsOnWall (struct Ball b) {
    return b.x <= 1 || b.x >= FieldHeight;
}

inline void BounceFromWall (struct Ball *b) {

    if (!BallIsOnWall(*b)) {
        return;
    }

    b->kx = -b->kx;

    if (b->x > FieldWidth / 2) {
        b->ky = -b->ky;
    }

}
