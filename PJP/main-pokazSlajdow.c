#include <allegro.h>

int main() {
    
    int i = 0;
    int index = 0;

    allegro_init();

    install_keyboard();

    set_color_depth(16);

    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

    clear_to_color(screen, makecol(128,128,128));
    
    // wskazniki
    
    BITMAP *tablica[3];
    BITMAP *pierwszy = NULL;
    BITMAP *drugi = NULL;
    BITMAP *trzeci = NULL;
    
    // wczytywanie obrazków
    
    pierwszy = load_bmp("pierwszy.bmp",default_palette);

    if (!pierwszy) {

       set_gfx_mode(GFX_TEXT,0,0,0,0);

       allegro_message("blad ladowania!");

       allegro_exit();

       return 0;

    } 
    
    tablica[0] = pierwszy; 
    
    drugi = load_bmp("drugi.bmp",default_palette);

    if (!drugi) {

       set_gfx_mode(GFX_TEXT,0,0,0,0);

       allegro_message("blad ladowania");

       allegro_exit();

       return 0;

    } 
    
    tablica[1] = drugi;
    
    trzeci = load_bmp("trzeci.bmp",default_palette);

    if (!trzeci) {

       set_gfx_mode(GFX_TEXT,0,0,0,0);

       allegro_message("nie mogê za³adowaæ obrazka Ludek !");

       allegro_exit();

       return 0;

    } 
    
    tablica[2] = trzeci;
    clear_to_color(screen, makecol(0,0,0));
    
    // wyœwietlanie
    
    blit(tablica[0], screen, 0,0, 100,100, tablica[0]->w, tablica[0]->h);
    textprintf_ex(screen, font, 20, 20, makecol(250,250,250), - 1, "%d", i);


    while (!key[KEY_ESC]) {
           
           clear_to_color(screen, makecol(0,0,0));
           if (key[KEY_LEFT]) 
           {
              if (index == 0) 
                 index = 2;          
              else 
                  index--;   
              i--;
              textprintf_ex(screen, font, 20, 20, makecol(250,250,250), - 1, "%d", i);
           }    
           if (key[KEY_RIGHT]) 
           {
               if (index == 2) 
                 index = 0;          
                 
               else
                  index++; 
                      
              i++;
              textprintf_ex(screen, font, 20, 20, makecol(250, 250, 250), - 1, "%d", i);                
           }
           blit(tablica[index], screen, 0,0, 100,100, tablica[index]->w, tablica[index]->h);                     
           readkey();
    }

    // czyszczenie bitmap
    
    readkey();
    destroy_bitmap(pierwszy);
    destroy_bitmap(drugi);
    destroy_bitmap(trzeci);
    allegro_exit();

    return 0;

}

END_OF_MAIN();  
