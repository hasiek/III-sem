#include <allegro.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <list>
#include <iterator>

#define OBSTSIZE 31

using namespace std;

BITMAP* prepareBitmap (char* path); 
void destroyAllBitmaps(BITMAP* name1, BITMAP* name2, BITMAP* name3, BITMAP* name4, BITMAP* name5);
vector <struct Coordinates> drawMap(BITMAP* background, BITMAP* obstacles, BITMAP* buff, BITMAP* obj, int numObst);
void buffering (BITMAP* background, BITMAP* obstacle, BITMAP* buff, BITMAP* snake, BITMAP* bonus, struct Coordinates bonuses, vector <struct Coordinates> obstCoor, int numObst, list <struct Coordinates> snakeBody, int end, bool eaten, int points);
char detectCollision (list <struct Coordinates> snakeBody, vector <struct Coordinates> obstCoor);
bool detectIfAte (list <struct Coordinates> snakeBody, struct Coordinates bonus);
struct Coordinates generateBonuses (vector <struct Coordinates> obstCoor, list <struct Coordinates> snakeBody);
void playGame(BITMAP* backgr, BITMAP* buffer, BITMAP* obst, BITMAP* snake, BITMAP* bonus, vector <struct Coordinates> obstCoor);
void endGame(BITMAP* buffer);

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

void buffering (BITMAP* backgr, BITMAP* buff, BITMAP* obst, BITMAP* snake, BITMAP* bonus, struct Coordinates bonuses, vector <struct Coordinates> obstCoor, int numObst, list <struct Coordinates> snakeBody, int end, bool eaten, int points) {
     
     list <struct Coordinates>::iterator it;
     
     clear_to_color(buff, makecol(128,128,128));      
     blit(backgr, buff, 0, 0, 0, 0, backgr->w, backgr->h);
     for (int i = 0; i < obstCoor.size(); i++) {
             
             blit (obst, buff, 0, 0, obstCoor[i].x, obstCoor[i].y, obst->w, obst->h);    
                 
     }
     textprintf(buff,font,20,20,makecol(255,255,255),"Points: %d", points);
     if (eaten == false) blit (bonus, buff, 0, 0, bonuses.x, bonuses.y, bonus->w, bonus->h);
     for (it = snakeBody.begin(); it != snakeBody.end(); it++) blit (snake, buff, 0, 0, (*it).x, (*it).y, snake->w, snake->h);
     blit(buff, screen, 0, 0, 0, 0, 800, 600);

};

// function which detects a collision

char detectCollision (list <struct Coordinates> snakeBody, vector <struct Coordinates> obstCoor) {
     
         struct Coordinates snake;
         snake = snakeBody.front();
         char end; 
         list <struct Coordinates>::iterator it;
         
         for (int i = 0; i < obstCoor.size(); i++) {
                 
                 if ((snake.x + 31 >= obstCoor[i].x && snake.x <= obstCoor[i].x + 31) && (snake.y+31 >= obstCoor[i].y && snake.y <= obstCoor[i].y + 31)) {
                      end = 'x';
                      break;
                 }
                 else if ((snake.y + 31 >= obstCoor[i].y && snake.y <= obstCoor[i].y + 31) && (snake.x+31 >= obstCoor[i].x && snake.x <= obstCoor[i].x + 31)) {
                      end = 'x';
                      break;
                 }
                 else if ((snake.x <= obstCoor[i].x + 31 && snake.x >= obstCoor[i].x) && (snake.y+31 >= obstCoor[i].y && snake.y <= obstCoor[i].y + 31)) {
                      end = 'x';
                      break;
                 }
                 else if ((snake.y >= obstCoor[i].y && snake.y <= obstCoor[i].y + 31) && (snake.x+31 >= obstCoor[i].x && snake.x <= obstCoor[i].x + 31)) {
                      end = 'x';     
                      break;
                 }
                 else if (snake.x <= 0 || snake.y <= 0 || snake.x + 31 >= 800 || snake.y + 31 >= 600) {
                      end = 'x';
                      break;
                 }
         }
         
        return end;
};

// function which checks whether a bonus was eaten

bool detectIfAte (list <struct Coordinates> snakeBody, struct Coordinates bonus) {
     
     bool eaten;
     struct Coordinates snake;
     
     snake = snakeBody.front();
     
     if ((snake.x + 31 >= bonus.x && snake.x <= bonus.x + 31) && (snake.y+31 >= bonus.y && snake.y <= bonus.y + 31)) eaten = true; 
     else if ((snake.x <= bonus.x + 31 && snake.x >= bonus.x) && (snake.y+31 >= bonus.y && snake.y <= bonus.y + 31)) eaten = true;
     else if ((snake.y + 31 >= bonus.y && snake.y <= bonus.y + 31) && (snake.x+31 >= bonus.x && snake.x <= bonus.x + 31)) eaten = true;
     else if ((snake.y >= bonus.y && snake.y <= bonus.y + 31) && (snake.x+31 >= bonus.x && snake.x <= bonus.x + 31)) eaten = true;
     
     return eaten;
};

// function which generates bonuses

struct Coordinates generateBonuses (vector <struct Coordinates> obstCoor, list <struct Coordinates> snakeBody) {
  
      struct Coordinates bonuses;
      bool free = true;
      int x,y;
      int block = 0;
      list <struct Coordinates>::iterator it;
      
      while (1) {
            
         block++;
         if (block > 1000) break;
         
         srand (time(NULL));
         x = rand() % 800;
         y = rand() % 600;
         
         for (int k = 0; k < obstCoor.size(); k++) {
         
             if ((x + 31 >= obstCoor[k].x && x + 31 <= obstCoor[k].x + 31) && (y + 31 >= obstCoor[k].y && y + 31 <= obstCoor[k].y + 31)) {
                      free = false;
                      break;
             }
             else if ((y + 31 >= obstCoor[k].y && y + 31 <= obstCoor[k].y + 31) && (x >= obstCoor[k].x && x <= obstCoor[k].x + 31)) {
                      free = false;
                      break;
             }
             else if ((x >= obstCoor[k].x && x <= obstCoor[k].x + 31) && (y >= obstCoor[k].y && y <= obstCoor[k].y + 31)) {
                      free = false;
                      break;
             }
             else if ((y >= obstCoor[k].y && y <= obstCoor[k].y + 31) && (x + 31 >= obstCoor[k].x && x + 31 <= obstCoor[k].x + 31)) {
                      free = false;     
                      break;
             }
         }
         if (x + 31 >= 800 || y + 31 >= 600) free = false;
             
         if (free == true) {
         
             for (it = snakeBody.begin(); it != snakeBody.end(); it++) {
             
                  if ((x >= (*it).x && x <= (*it).x + 31) && (y >= (*it).y && y <= (*it).y + 31)) {
                  
                     free = false;
                     break;       
                         
                  }  
             }       
         }
         
         if (free == true) break;
          
      } 
      
      bonuses.x = x;
      bonuses.y = y;
      
      return bonuses;
       
};

// function which draws 'Game Over' screen

void endGame(BITMAP* buffer) {
     
         while (!key[KEY_ESC]) {
    
         clear_to_color(buffer, makecol(0,0,0));
         textout_ex(buffer,font,"Game Over",400,300 ,makecol(255,0,255),-1);
         blit (buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);   
         readkey();     
          
    }
};
// function which moves a snake

void playGame (BITMAP* backgr, BITMAP* buffer, BITMAP* obst, BITMAP* snake, BITMAP* bonus, vector <struct Coordinates> obstCoor) {
    
    struct Coordinates snakePart; 
    char before, end;
    bool eaten = false;
    struct Coordinates bonuses;
    list <struct Coordinates> snakeBody;
    bool started = false;
    bonuses.x = 200;
    bonuses.y = 150;
    snakePart.x = 100;
    snakePart.y = 100;
    snakeBody.push_front(snakePart);
    int points = 0;
    
    list <struct Coordinates>::iterator it;
    
    while(!key[KEY_ESC]) {
                  
         buffering (backgr, buffer, obst, snake, bonus, bonuses, obstCoor, 25, snakeBody, end, eaten, points);
         
         while (speed > 0) {                
                
             if (key[KEY_LEFT]) {
                     
                if (before != 'r') {  
                                     
                    snakePart.x = snakeBody.front().x - 1;
                    snakePart.y = snakeBody.front().y;
                    snakeBody.push_front(snakePart);
                    if (eaten == false) snakeBody.pop_back();
                    before = 'l';
                    
                }
                
             }
             else if (key[KEY_RIGHT]) {
                 
                if (before != 'l') {
                                            
                    snakePart.x = snakeBody.front().x + 1;
                    snakePart.y = snakeBody.front().y;
                    snakeBody.push_front(snakePart);
                    if (eaten == false) snakeBody.pop_back();
                    before = 'r';
                    
                }
                
             }
             else if (key[KEY_UP]) {
                  
                  if (before != 'd') {
                                         
                    snakePart.x = snakeBody.front().x;
                    snakePart.y = snakeBody.front().y - 1;
                    snakeBody.push_front(snakePart);
                    if (eaten == false) snakeBody.pop_back();
                    before = 'u';
                  
                  }
                
             }
             else if (key[KEY_DOWN]) {
                   
                   if (before != 'u') {
                                           
                        snakePart.x = snakeBody.front().x;
                        snakePart.y = snakeBody.front().y + 1;
                        snakeBody.push_front(snakePart);
                        if (eaten == false) snakeBody.pop_back();
                        before = 'd';
                        
                   }
                
             }
             else {
                  
                  if (before == 'l') {
                             
                             snakePart.x = snakeBody.front().x - 1;
                             snakePart.y = snakeBody.front().y;
                             snakeBody.push_front(snakePart);
                             if (eaten == false) snakeBody.pop_back();
                             
                  }
                  if (before == 'r') {
                             
                             snakePart.x = snakeBody.front().x + 1;
                             snakePart.y = snakeBody.front().y;
                             snakeBody.push_front(snakePart);
                             if (eaten == false) snakeBody.pop_back();
                             
                  }
                  if (before == 'u') {
                             
                             snakePart.x = snakeBody.front().x;
                             snakePart.y = snakeBody.front().y - 1;
                             snakeBody.push_front(snakePart);
                             if (eaten == false) snakeBody.pop_back();
                             
                  }
                                
                  if (before == 'd') {
                             
                             snakePart.x = snakeBody.front().x;
                             snakePart.y = snakeBody.front().y + 1;
                             snakeBody.push_front(snakePart);
                             if (eaten == false) snakeBody.pop_back(); 
                             
                  }    
                  
             }
                speed--;
         }
      
      if (started == false && detectIfAte(snakeBody, bonuses) == true) {
                  
         started = true;
         points = points + 10;
      
      }
      
      eaten = detectIfAte(snakeBody, bonuses); 
        
      if (started == true && eaten == false) {
                  
         started = false;
         bonuses = generateBonuses(obstCoor, snakeBody);
      
      }
      end = detectCollision (snakeBody, obstCoor); 
      if (end == 'x') break;

    }
    
    endGame(buffer);
};
