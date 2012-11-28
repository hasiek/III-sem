#include <allegro.h>
#include <cstdlib>
#include <time.h>
#include <vector>

#define OBSTSIZE 31

using namespace std;

BITMAP* prepareBitmap (char* path); 
void destroyAllBitmaps(BITMAP* name1, BITMAP* name2, BITMAP* name3, BITMAP* name4, BITMAP* name5);
vector <struct Coordinates> drawMap(BITMAP* background, BITMAP* obstacles, BITMAP* buff, BITMAP* obj, int numObst);
void buffering (BITMAP* background, BITMAP* obstacle, BITMAP* buff, BITMAP* snake, BITMAP* bonus, vector <struct Coordinates> obstCoor, int numObst, int snake_x, int snake_y, int end);
char detectCollision (int snake_x, int snake_y, vector <struct Coordinates> obstCoor);
bool detectIfAte (int snake_x, int snake_y, struct Coordinates bonus);
void playGame(BITMAP* backgr, BITMAP* buffer, BITMAP* obst, BITMAP* snake, BITMAP* bonus, vector <struct Coordinates> obstCoor);

struct Coordinates {
       
       int x;
       int y;       
       
};

volatile long speed = 0;
void increment_speed() {
      speed++;
}
END_OF_FUNCTION(increment_speed); 
LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);   

int main() {
    	
	allegro_init();
	install_keyboard();
    set_color_depth(16);
    install_timer();
    install_int_ex(increment_speed, BPS_TO_TIMER(100));  
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);
    BITMAP* backgr = NULL;
    BITMAP* obst = NULL;
    BITMAP* buffer = NULL;
    BITMAP* snake = NULL;
    BITMAP* bonus = NULL;
    vector <struct Coordinates> obstCoor;
    
    buffer = create_bitmap(800,600);
    backgr = prepareBitmap("tlo.bmp");
    obst = prepareBitmap("obst.bmp");
    snake = prepareBitmap("snake.bmp");
    bonus = prepareBitmap("bonus.bmp");
    
    obstCoor = drawMap (backgr, obst, buffer, snake, 25);
    playGame(backgr, buffer, obst, snake, bonus, obstCoor);
    
    remove_int(increment_speed);
    destroyAllBitmaps(backgr, obst, buffer, snake, bonus);
    allegro_exit();
	
	return 0;
}
END_OF_MAIN();

// function which aim is to load bitmap, check whether loading was successful and return loaded bitmap

BITMAP* prepareBitmap (char* path) {
       
    BITMAP *loaded = load_bitmap(path, default_palette);
    if (!loaded) {
                 
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("nie mogê za³adowaæ obrazka %s!", path);
        allegro_exit();
        return 0;           
    }
    else return loaded;  
};

// function which destroys all bitmaps created in program

void destroyAllBitmaps(BITMAP* name1, BITMAP* name2, BITMAP* name3, BITMAP* name4, BITMAP* name5) {
     
     destroy_bitmap(name1);
     destroy_bitmap(name2); 
     destroy_bitmap(name3);   
     destroy_bitmap(name4);
     destroy_bitmap(name5);
     
};

// function which draws a map

vector <struct Coordinates> drawMap(BITMAP* background, BITMAP* obstacles, BITMAP* buff, BITMAP* obj, int numObst) {
    
    vector <struct Coordinates> obstCoor;
    struct Coordinates temp;
    int randomX = 0;
    int randomY = 0;
    bool paint = true;
    blit(background, buff, 0, 0, 0, 0, background->w, background->h);
    blit(obj, buff, 0, 0, 100, 100, obj->w, obj->h);
    for (int i = 0; i < numObst; i++) {
        
        paint = true;
        randomX = 0;
        randomY = 0;
        srand(time(NULL)+i*i);
        randomX = (rand() % 32) + (i*32);
        randomY = rand() % 600;
        if (131 >= randomX && 100 <= randomX + 31) paint = false;
        else if (131 >= randomY && 100 <= randomY + 31)paint = false;
        else if (100 <= randomX + 31 && 100 >= randomX) paint = false;
        else if (100 >= randomY && 100 <= randomY + 31) paint = false; 
        else if ((randomX >= 200 && randomX <= 231) && (randomY >= 150 && randomY <= 181)) paint = false; 
        else if ((200 >= randomX && 200 <= randomX + 31) && (150 >= randomY && 150 <= randomY + 31)) paint = false;        
        if (paint == true) {
                  
                  blit (obstacles, buff, 0, 0, randomX, randomY, OBSTSIZE, OBSTSIZE);
                  temp.x = randomX;
                  temp.y = randomY;
                  obstCoor.push_back(temp);
        }
        
    }
    
    blit (buff, screen, 0, 0, 0, 0, 800, 600);  
    return obstCoor;
     
};

// function which makes double buffering

void buffering (BITMAP* backgr, BITMAP* buff, BITMAP* obst, BITMAP* snake, BITMAP* bonus, vector <struct Coordinates> obstCoor, int numObst, int snake_x, int snake_y, int end) {
     
     if (end == 'x') {
              
         clear_to_color(buff, makecol(0,0,0));
         textout_ex(buff,font,"Game Over",400,300 ,makecol(255,0,255),-1);
         blit (buff, screen, 0, 0, 0, 0, buff->w, buff->h);   
         readkey();    
     }
     clear_to_color(buff, makecol(128,128,128));      
     blit(backgr, buff, 0, 0, 0, 0, backgr->w, backgr->h);
     for (int i = 0; i < numObst; i++) {
         
         blit (obst, buff, 0, 0, obstCoor[i].x, obstCoor[i].y, obst->w, obst->h);    
             
     }
     blit(snake, buff, 0, 0, snake_x, snake_y, snake->w, snake->h);
     blit (bonus, buff, 0, 0, 200, 150, bonus->w, bonus->h);
     blit(buff, screen, 0, 0, 0, 0, 800, 600);
};

// function which detects a collision

char detectCollision (int snake_x, int snake_y, vector <struct Coordinates> obstCoor) {
         char end; 
         for (int i = 0; i < obstCoor.size(); i++) {
                 
                 if ((snake_x + 31 >= obstCoor[i].x && snake_x <= obstCoor[i].x + 31) && (snake_y+31 >= obstCoor[i].y && snake_y <= obstCoor[i].y + 31)) {
                      end = 'x';
                      break;
                 }
                 else if ((snake_y + 31 >= obstCoor[i].y && snake_y <= obstCoor[i].y + 31) && (snake_x+31 >= obstCoor[i].x && snake_x <= obstCoor[i].x + 31)) {
                      end = 'x';
                      break;
                 }
                 else if ((snake_x <= obstCoor[i].x + 31 && snake_x >= obstCoor[i].x) && (snake_y+31 >= obstCoor[i].y && snake_y <= obstCoor[i].y + 31)) {
                      end = 'x';
                      break;
                 }
                 else if ((snake_y >= obstCoor[i].y && snake_y <= obstCoor[i].y + 31) && (snake_x+31 >= obstCoor[i].x && snake_x <= obstCoor[i].x + 31)) {
                      end = 'x';     
                      break;
                 }
                 else if (snake_x <= 0 || snake_y <= 0 || snake_x + 31 >= 800 || snake_y + 31 >= 600) {
                 
                      end = 'x';
                      break;
                      
                 }
             
         }
         
        return end;
};

// function which checks whether a bonus were eaten

bool detectIfAte (int snake_x, int snake_y, struct Coordinates bonus) {
     
     bool eaten;
     
     if ((snake_x + 31 >= bonus.x && snake_x <= bonus.x + 31) && (snake_y+31 >= bonus.y && snake_y <= bonus.y + 31)) eaten = true; 
     
};

// function which moves a snake

void playGame (BITMAP* backgr, BITMAP* buffer, BITMAP* obst, BITMAP* snake, BITMAP* bonus, vector <struct Coordinates> obstCoor) {
     
    char before, end;
    struct Coordinates bonus;
    bonus.x = 200;
    bonus.y = 150;
    int snake_x = 100;
    int snake_y = 100;
    while(!key[KEY_ESC]) {
                  
         buffering (backgr, buffer, obst, snake, bonus, obstCoor, 25, snake_x, snake_y, end); 
         while (speed > 0) {                
                
             if (key[KEY_LEFT]) {
                snake_x--;
                before = 'l';
             }
             if (key[KEY_RIGHT]) {
                snake_x++;
                before = 'r';
             }
             if (key[KEY_UP]) {
                snake_y--;
                before = 'u';
             }
             if (key[KEY_DOWN]) {
                snake_y++;
                before = 'd';
             }
             else {
                  
                  if (before == 'l') snake_x--;
                  if (before == 'r') snake_x++;
                  if (before == 'u') snake_y--;
                  if (before == 'd') snake_y++;     
                  
             }
                speed--;
         }
         
      end = detectCollision (snake_x, snake_y, obstCoor, buffer); 
    }
};
