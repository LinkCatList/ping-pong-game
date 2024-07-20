#pragma once

struct Ball {

    // координаты мяча
    int x;
    int y;

    // коэффициенты для получения направления
    // движения мяча
    double kx;
    double ky;
};

void UpdBallCoords (struct Ball *b) {
    b->x += b->kx;
    b->y += b->ky;
}
