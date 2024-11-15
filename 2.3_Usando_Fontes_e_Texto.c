#include <allegro5/allegro.h>
//biblioteca para usar fontes
#include <allegro5/allegro_font.h>

int main(){
    
    al_init();
    if (!al_init()){
        return -1;
    }

    ALLEGRO_DISPLAY* janela = NULL;
    janela = al_create_display(640, 480);
    if(!janela){
        return -1;
    }

    al_clear_to_color(al_map_rgb(0,0,0)); //--> para escolher a cor do fundo da janela

    //variaveis para decidir o tamanho da janela
    int janela_w = al_get_display_width(janela);
    int janela_h = al_get_display_height(janela);

    al_init_font_addon();       //--> comando para iniciar a fonte 

    //função para cria o texto e o ponteiro para ele
    ALLEGRO_FONT* texto1 = al_create_builtin_font();
    ALLEGRO_FONT* texto2 = al_create_builtin_font();
    ALLEGRO_FONT* texto3 = al_create_builtin_font();
    //para printar o texto na janela(x, y, flag)
    al_draw_text(texto1, al_map_rgb(255,255,255), 640/2, 480/2, ALLEGRO_ALIGN_CENTRE, "SETA HERO");
    al_draw_text(texto2, al_map_rgb(100, 100, 100), janela_w/2, 270, 0, "AAAAAAAHHHHHH");
    al_draw_textf(texto3, al_map_rgb(200, 0, 0), janela_w/2, 230, ALLEGRO_ALIGN_CENTER, "teste teste");
    
    al_flip_display();      //--> comando para flipar a tela e deixar legivel
    al_rest(5.0);

    //aquele esquema
    al_destroy_font(texto1);
    al_destroy_font(texto2);
    al_destroy_font(texto3);
    al_destroy_display(janela);
    return 0;
}
