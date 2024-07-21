#pragma once

#include <stdio.h>
#include "ball.h"
#include "racket.h"
#include "dimension.h"

struct Point {

    int x;
    int y;

};

struct Racket {

    // точки начала и конца ракетки

    struct Point p1;
    struct Point p2;

};  

// движение ракетки вниз, принимает 
// указатель на ракетку и двигает ее, если 
// ракетка не находится на границе поля
void MoveDown (struct Racket *r) {
    if (r->p1.y < FieldHeight - 3) {
        ++r->p1.y;
        ++r->p2.y;
    }
}

// движение ракетки вверх, принимает 
// указатель на ракетку и двигает ее, если 
// ракетка не находится на границе поля
void MoveUp (struct Racket *r) {
    if (r->p2.y > 5) {
        --r->p1.y;
        --r->p2.y;
    }
}

// возвращает 1, если мяч попал на ракетку, иначе - 0
int BallInRacket (struct Racket r, struct Ball b) {
    return b.y == r.p1.x && b.x >= r.p1.y && b.x <= r.p2.y;
}

// меняет положения мяча, если он отскакивает от ракетки
void BounceFromRacket (struct Ball *b, struct Racket r) {

    // проверка, что мяч попал на ракетку
    if (!BallInRacket(r, *b)) {
        return;
    }

    // изменение коэффициента движения мяча
    // после отскока
    b->ky = -b->ky;

}
