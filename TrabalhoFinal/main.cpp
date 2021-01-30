#include "./Include/Game.h"

int main(){
    Position limit;
    limit.x = TAM_LIN + TAM_BORDER;
    limit.y = TAM_COL + TAM_BORDER;

    Game g1(limit, 2);
    g1.run_game();

    return 0;
}
