/* controller for virtual rooms.  creates new ones, and moves players
   between them
*/
#include "/players/illarion/dfns.h"
#define WIDTH 5
#define HEIGHT 5
#define VROOM "/players/illarion/poke/room/vroom"

object *rooms;

void reset(int arg) {
  if(arg) return;
  rooms=allocate(HEIGHT*WIDTH);
}
object make_room(int row,int column) {
  object newroom;
  string *exits;
  string long;
  newroom=clone_object(VROOM);
  newroom->set_short("A "+HIY+"Pokemon"+NORM+" field");
  long=
"You stand amidst of a field of healthy, approximately waist height grass.  A "+
"mild breeze brushes by, making the grass wave, and caressing your face.  "+
"Despite the peacefulness of the scene, the grass could hide almost anything, "+
"and something tells you that it might well be hiding something.  ";
  switch(row) {
    case 1: long+="A fence blocks the way to the north, ";
      if(column==1) long+="and west, ";
      if(column==5) long+="and a river to the east, ";
      long+="while the grass continues in the other directions.";
      break;
    case 5: long+="A fence blocks the way to the south, ";
      if(column==1) long+="and west, ";
      if(column==3) long+="but is broken by a small cabin, ";
      if(column==5) long+="and a river to the east, ";
      long+="while the grass continues in the other directions.";
      break;
    default:
      if(column==1|| column==5) {
        if(column==1)
          long+="A fence blocks the way to the west, ";
        else
          long+="A river blocks the way to the east, ";
        long+="and otherwise the grass continues all around.";
      } 
      else
        long+="The grass continues all around you.";
      break;
  }
  newroom->set_long(long);
  newroom->add_item("grass",
"Long, healthy grass, rising high enough to make walking difficult and "+
"to hide something.  It seems resistant to damage, but you do leave a "+
"a trail behind you as you walk.");
  if(row==1 || row==5 || column==1)
    newroom->add_item("fence",
            "A simple wooden fence that rises to about chest height, "+
            "effectively blocking any progress beyond it.");            
  if(column==5)
    newroom->add_item("river","A broad and slow, but deep river, flowing "+
                              "gently from north to south.  Occasionally, "+
                              "something breaks the surface of the waves, "+
                              "leaving ripples to spread across the surface.");
  if(row==5 && column==3) {
    newroom->add_item("cabin","A sturdy-looking but small structure that "+
                              "seems to exude a sense of rest and refuge.");
    newroom->set_special_exit("south","/players/illarion/poke/room/restarea");
  }
  if(!random(3)) {
    object pokemob;
    pokemob=clone_object(PMON+({"abra","clefairy","koffing","oddish","pidgey",
                                "pikachu","vulpix"})[random(7)]);
    move_object(pokemob,newroom);
  }
  exits= ({});
  if(row>1) exits+= ({"north"});
  if(row<HEIGHT) exits+= ({"south"});
  if(column>1) exits+= ({"west"});
  if(column<WIDTH) exits+= ({"east"});
  newroom->create(column,row,exits);
  return newroom;
}
void move_me(object who,int column,int row,string dir) {
  int index;
  switch(dir) {
    case "north": row--; break;
    case "south": row++; break;
    case "east": column++; break;
    case "west": column--; break;
    default: write("Error.\n"); return;
  }
  index=(row-1)*5+(column-1);
  if(!rooms[index])
    rooms[index]=make_room(row,column);
  who->move_player(dir+"#"+file_name(rooms[index]));
}
void destruct_area() {  /* cleans out the area and EVERYTHING in it */
  int x,y,s;
  object *items;
  for(x=0;x<WIDTH*HEIGHT;x++)
    if(rooms[x]) {
      items=deep_inventory(rooms[x]);
      s=sizeof(items);
      for(y=1;y<s;y++)
        destruct(items[y]);
      destruct(rooms[x]);
    }
}
