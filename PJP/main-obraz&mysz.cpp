#include <allegro.h>
#include <vector>

using namespace std;

struct Obraz {
  
    int x;
    int y;
    int numer;     
       
};

int main() {
    
    int i = 0, k = 0;
    int indeks = 0, x = 0, y = 0, j = 0;
    vector <struct Obraz> zapisane;
    struct Obraz temp;

    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);
    install_mouse();
    show_mouse(screen);
    unscare_mouse();
    clear_to_color(screen, makecol(128,128,128));
    
    // wskazniki
    
    BITMAP *tablica[3];
    BITMAP *pierwszy = NULL;
    BITMAP *drugi = NULL;
    BITMAP *trzeci = NULL;
    BITMAP *bufor = NULL;
    
    bufor = create_bitmap(800,600);
    
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
       allegro_message("blad ladownia");
       allegro_exit();
       return 0;
     }
    tablica[2] = trzeci;

    while (!key[KEY_ESC]) {
          
               destroy_bitmap(bufor);
               bufor = create_bitmap(800,600);
               if (mouse_b == 1) {
                           
                  blit(tablica[i],bufor, 0, 0, mouse_x, mouse_y, tablica[i]->w, tablica[i]->h);
                  temp.x = mouse_x;
                  temp.y = mouse_y;
                  temp.numer = i;
                  zapisane.push_back(temp);
                  i++;
                  mouse_b = 0;
                  if (i == 3) i = 0;
               }
               else if (mouse_b == 2) {
                    
                      for (j = 0; j < zapisane.size(); j++) {
                            
                              temp = zapisane[j];   
                              if (mouse_x >= temp.x && mouse_x <= temp.x+201 && mouse_y >= temp.y && mouse_y <= temp.y+177) {
                                           zapisane.erase(zapisane.begin()+j);

                                           }
                              }
                      mouse_b = 0;
                      j = 0;   
                    
               }

               for (k = 0; k < zapisane.size(); k++) {
               
                   indeks = zapisane[k].numer;
                   x = zapisane[k].x;
                   y = zapisane[k].y;
                   blit(tablica[indeks],bufor, 0, 0, x, y, tablica[indeks]->w, tablica[indeks]->h);
                   
               }
               blit(bufor,screen,0,0,0,0,800,600);
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


