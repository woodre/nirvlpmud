#include "defs.h"

inherit ROOM;

/* Map coordinate */
int x, y;

string short()
{
  string s;
  s=(string)::short();
  if(TP && TP->query_level() > 20)
    s+="("+x+","+y+")";
  return s;
}
void long(string str)
{
  if(TP->query_level() > 20)
    write("X: "+x+" Y: "+y+"\n");
  ::long(str);
}
  
void set_coords(int a, int b)
{
  x=a;
  y=b;
}

int *query_coords() {
  return ({ x, y });
}
 
int cmd_move()
{
  object newloc;
  int newx, newy;
  switch(query_verb())
  {
    case "north": newx=x  ; newy=y+1; break;
    case "west" : newx=x-1; newy=y  ; break;
    case "east" : newx=x+1; newy=y  ; break;
    case "south": newx=x  ; newy=y-1; break;
    default: newx=x; newy=y;
  }
  
/* Chance of getting lost without a map */
  if(!present("jalhab map",this_player()) 
     && random(22) > (int)this_player()->query_attrib("int") ) {
    write("You're lost.\n");
    newx=random(WIDTH);
    newy=random(LENGTH);
  }

  if(newx < 0) newx=0;
  if(newx >= WIDTH) newx=WIDTH-1;
  if(newy < 0) newy=0;
  if(newy >= LENGTH) newy=LENGTH-1;
    if(!newloc) newloc=(object)MAP->query_location(newx,newy);

  say(TPN+" trudges "+query_verb()+" across the desert.\n");
  move_object(this_player(),newloc);
  command("look",this_player());
  say(TPN+" arrives.\n");

  return 1;
}
