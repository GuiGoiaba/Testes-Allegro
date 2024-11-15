//biblioteca principal do allegro
#include <allegro5/allegro.h>

int main(){
    
    
    al_init();      //-->a funcao al_init é a que chama o inicio da aplicacao
    if (!al_init()){    
        return -1;
    }

    ALLEGRO_DISPLAY* display = NULL;        //--> funcao para comecar o programa criando um janela para as funcoes
    display = al_create_display(640, 480);      //--> define o tamanho da janela
    if(!display){
        return -1;
    }
    
    al_rest(5.0);       //--> para definir o tempo em que a janela vai ficar aberta
    al_destroy_display(display);        //--> é para fechar o programa, é sempre necessario chamar essa função

    return 0;
}
