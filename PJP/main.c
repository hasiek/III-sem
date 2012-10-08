#include <allegro.h>

int main()

{
    
    int klaw = 0;

 allegro_init();

 install_keyboard();

 set_color_depth(16);

 set_gfx_mode(GFX_AUTODETECT,640,480,0,0);

 clear_to_color(screen,makecol(10,10,10));
    
 while( !key[KEY_ESC])

 {
 
 /* klaw = readkey();
 clear_to_color(screen,makecol(10,10,10));
 switch (klaw) {
        case 7217: 
             textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : 1");
             break;
        case 7474:
             textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : 2");
             break;
        case 7731:
             textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : 3");
             break;
        case 7988:
             textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : 4");
             break; 
        case 8245:
             textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : 5");
             break;
 }

 if( key[KEY_LEFT]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_LEFT]");
 
 if( key[KEY_RIGHT]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_RIGHT]");
 
 if( key[KEY_UP]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_UP]");

 if( key[KEY_DOWN]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_DOWN]");
 
 if( key[KEY_0]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_0]");
 
 if( key[KEY_1]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_1]");
 
 if( key[KEY_2]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_2]");
 
 if( key[KEY_3]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_3]");
 
 if( key[KEY_4]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_4]");
 
 if( key[KEY_5]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_5]");
 
 if( key[KEY_6]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_6]");
 
 if( key[KEY_7]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_7]");
 
 if( key[KEY_8]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_8]");
 
 if( key[KEY_9]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_9]");
 
 if( key[KEY_SPACE]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_SPACE]");
 
 if( key[KEY_ENTER]) textprintf(screen,font,20,20,makecol(255,255,128),"Klawisz to : [KEY_ENTER]"); */
 
 BITMAP *plik = NULL;
 
 plik = load_bmp("bmp.bmp",default_palette);
 
 if (!plik)
 {
  set_gfx_mode(GFX_TEXT,0,0,0,0);

  allegro_message("nie mogê za³adowaæ obrazka Plik!");

  allegro_exit();

  return 0;

 }
 
 blit( plik, screen, 0,0, 100,100, plik->w, plik->h);
 readkey(); 
 destroy_bitmap(plik); 
 allegro_exit();
  


}

 

allegro_exit();

return 0;

}

END_OF_MAIN();
