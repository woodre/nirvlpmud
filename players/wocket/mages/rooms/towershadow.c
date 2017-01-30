/* sorcerer tower shadow 
   created by wocket 4/99
   modified by wocket 6/2004
*/
#include "../defs.h"
#define SHADOWROOM "/room/farmroad3"
#define TOWERENT "/players/wocket/mages/rooms/guildhall.c"
object room;
string *items;

start_shadow(){
  room = find_object(SHADOWROOM);
  shadow(room,1);
  items = ({ "tower","The tower rised upwards into the sky.  It seems to have a magical\nshimmer surrounding it." });
}

stop_shadow(){
  shadow(room,0);
  destruct(this_object());
  return 1;
}

long(string str){
  if(str == "tower"){
    write("The tower rised upwards into the sky.  It seems to have a magical shimmer\n"+
    "surrounding it.  Your eyes adjust to it and you see a way to '"+BOLD+"enter"+OFF+"' it.\n");
    return 1; 
  }
  if(!str){
    if(BOOK){     
      write("You are on a deeply rutted north-south road used by farmers to tend\n"+
      "the various crops grown to feed the villages.  Seemingly out of place a \n"+
      "giant tower reaches for the sky casting long shadows along\n"+
      "the grass ridden ground.\n"+
      "    There is one obvious exit: north\n");
    }
  } else {
    room->long(str);
  }
  return 1;
}

query_long(){
  return 0;
}

init(){
  if(BOOK){
    write(CYN+"A tower shimmers into view.\n"+OFF);
  }   
  add_action("enter_tower","enter");
  room->init();
}

enter_tower(str){
  if(!BOOK){
    notify_fail("What would you like to enter?\n");
    return 0;
  }
  if(str != "tower"){
    notify_fail("What would you like to enter?\n");
    return 0;
  }
  this_player()->move_player("enters the tower#"+TOWERENT);
  return 1;
}


status id(string str)
{
 if (!items) return 0;
 return (member_array(str, items) > -1);
}


/* makes it so a castle can not be dropped at this location */
status query_drop_castle(){ return 0; }