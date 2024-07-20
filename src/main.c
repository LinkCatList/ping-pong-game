#include <stdio.h>

#include "ball.h"
#include "field.h"
#include "racket.h"

#define GAME 1

int main () {

    struct Ball b = {FieldHeight / 2 - 2, FieldWidth / 2, 1, 1};
    struct Racket r1 = {{5, 5}, {5, 7}};
    struct Racket r2 = {{76, 10}, {76, 12}};

    int cntFirst = 0;
    int cntSecond = 0;

    while (GAME) {
        char key;

        key = getchar();

        switch (key) {
        case 'a':
            MoveUp(&r1);
            break;
        case 'z':
            MoveDown(&r1);
            break;
        case 'k':
            MoveUp(&r2);
            break;
        case 'm':
            MoveDown(&r2);
            break;
        }

        fieldDraw(b, r1, r2);
        BounceFromWall(&b);
        UpdBallCoords(&b);
        BounceFromRacket(&b, r1);
        BounceFromRacket(&b, r2);
        
        if (ballIsBehindRacket(b, r1)) {
            ++cntSecond;

            if ((cntFirst + cntSecond) % 2 == 0) {
                b.kx = -1;
            }

            b.x = FieldHeight / 2;
            b.y = FieldWidth / 2;
        }
        
        if (ballIsBehindRacket(b, r2)) {
            ++cntFirst;

            if ((cntFirst + cntSecond) % 2 == 0) {
                b.kx = -1;
            }

            b.x = FieldHeight / 2;
            b.y = FieldWidth / 2;
        }

        if (cntSecond == 21) {
            printf(" _______  _______  _______  _______  _        ______             _________ _        _ \n"
                "(  ____ \(  ____ \(  ____ \(  ___  )( (    /|(  __  \\   |\\     /|\\__   __/( (    /|( )\n"
                "| (    \\/| (    \\/| (    \\/| (   ) ||  \\  ( || (  \\  )  | )   ( |   ) (   |  \\  ( || |\n"
                "| (_____ | (__    | |      | |   | ||   \\ | || |   ) |  | | _ | |   | |   |   \\ | || |\n"
                "(_____  )|  __)   | |      | |   | || (\\ \\) || |   | |  | |( )| |   | |   | (\\ \\) || |\n"
                "    ) || (      | |      | |   | || | \\   || |   ) |  | || || |   | |   | | \\   |(_)\n"
                "/\\____) || (____/\\| (____/\\| (___) || )  \\  || (__/  )  | () () |___) (___| )  \\  | _\n" 
                "\\_______)(_______/(_______/(_______)|/    )_)(______/   (_______)\\_______/|/    )_)(_)\n");
            return 0;
        }
        
        if (cntFirst == 21) {
            printf(" _______ _________ _______  _______ _________           _________ _  _\n"
                "(  ____ \\\\__   __/(  ____ )(  ____ \\__   __/  |\\     /|\\__   __/( (    /|( )\n"
                "| (    \\/   ) (   | (    )|| (    \\/   ) (     | )   ( |   ) (   |  \\  ( || |\n"
                "| (__       | |   | (____)|| (_____    | |     | | _ | |   | |   |   \\ | || |\n"
                "|  __)      | |   |     __)(_____  )   | |     | |( )| |   | |   | (\\ \\) || |\n"
                "| (         | |   | (\\ (         ) |   | |     | || || |   | |   | | \\   |(_)\n"
                "| )      ___) (___| ) \\ \\__/\\____) |   | |     | () () |___) (___| )  \\  | _ \n"
                "|/       \\_______/|/   \\__/\\_______)   )_(     (_______)\\_______/|/    )_)(_)\n");
            return 0;
        }
        
    }

    return 0;
}
