#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

struct Point {
       
       int x;
       int y;
       
};

int main ()
{
  struct Point point;
  point.x = 3;
  point.y = 5;
  struct Point point1;
  point1.x = 9;
  point1.y = 0;
  
  list <struct Point> mylist;
  
  mylist.push_front(point);
  mylist.push_front(point1);
  
  cout << mylist.size() << endl;


  list<struct Point>::iterator it;

  cout << "mylist contains:";
  for ( it=mylist.begin() ; it != mylist.end(); it++ )
    cout << " " << (*it).y;

  cout << endl;
  
  system ("pause");

  return 0;
}
