#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(){
    
    al_init();
    if (!al_init()){
        return -1;
    }

    int janela_w = 640;
    int janela_h = 480;

    ALLEGRO_DISPLAY* janela = al_create_display(janela_w, janela_h);
    if(!janela){
        return -1;
    }
    al_clear_to_color(al_map_rgb(0,0,0));

    al_init_primitives_addon();     //--> para iniciar o tipo primitivo

    al_draw_pixel(200, 200, al_map_rgb(255,255,255));       //-->para fazer um pixil(um ponto)

    //comando para criar uma linha
    al_draw_line(100, janela_h/2, janela_w - 100, janela_h/2, al_map_rgb(255,255,255), 5);  //--> para fazer uma linha
    al_draw_line(320, 100, 320, 400, al_map_rgb(255,255,255), 5);       //--> para fazer uma linha na horizontal

    //comando para criar um triangulo
    al_draw_triangle(10, 200, 100, 10, 190, 200, al_map_rgb(255, 255, 255), 5);     //--> para fazer triangulos em linhas
    al_draw_filled_triangle(300, 400, 400, 200, 500, 400, al_map_rgb(255, 255, 255));       //--> para fazer um triangulo cheio

    //comando para criar um quadrado ou retangulo
    al_draw_rectangle(100, 100, 250, 250, al_map_rgb(255, 255, 255), 5); // -->para criar um quadrado ou retangulo dependendo do x e do y
    al_draw_rounded_rectangle(janela_w - 200, 10, janela_h - 10, 50, 5, 5, al_map_rgb(255, 255, 255), 5);       //-->adiciona uma rotacao em graus no retangulo criado
    al_draw_filled_rectangle(10, 280, 250, janela_h - 10, al_map_rgb(255, 255, 255));   //-->para criar um retangulo preenchido

    //comando para criar um circulo
    al_draw_circle(100, 100, 50, al_map_rgb(255, 255, 255), 5);     //--> para criar um circulo
    al_draw_filled_circle(janela_w/2, janela_h/2, 50, al_map_rgb(255, 255, 255));       //--> para criar um circulo preenchido

    //comando para criar uma elipse
    al_draw_ellipse(150, 100, 100, 50, al_map_rgb(255, 255, 255), 5);       //--> cria elipse em linhas
    al_draw_filled_ellipse(400, 250, 100, 200, al_map_rgb(255, 255,255));       //--> cria uma elipse preenchida

    al_flip_display();
    al_rest(5.0);
    al_destroy_display(janela);
}