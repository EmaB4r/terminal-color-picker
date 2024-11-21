#include "terminal-graphics/Graphics.h"

#define H 8
#define W 10


int main(){
    color_t color={0};
    char key;
    canvas_t screen = canvas_init(H, W);
    SCREEN_LOOP(80, {
        key = getkey(stdin);
        switch(key){
            case 'q': color.r++;  break;
            case 'a': color.r--;  break;
            case 'w': color.g++;  break;
            case 's': color.g--;  break;
            case 'e': color.b++;  break;
            case 'd': color.b--;  break;
        }
        canvas_draw_grectangle(&screen, (v2i_t) {0,0}, (v2i_t) {W-1, H-1}, color, 1);
        canvas_gshow(screen);
        printf("R: %3d  G: %3d  B: %3d   ", color.r, color.g, color.b);
    })
    return 0;
}