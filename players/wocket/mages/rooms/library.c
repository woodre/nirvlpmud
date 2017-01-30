#include "../defs.h"
#define PATH ROOMDIR
inherit ROOM;

reset(arg){
  if(!present("bookcase",this_object()))
    move_object(OBJDIR+"bookcase.c");
  if(!present("ganof",this_object()))
    move_object(NPCDIR+"ganof.c");
  if(arg) return;
  short_desc = MAG+"A Secret Hall"+NORM;
  long_desc = "   "+
             "A quaint little library with bookshelves that reach to \n"+
             "the ceiling.  The floor is made of a dark marble while the\n"+
             "walls and ceilings of wood panels.  Candles light the area\n"+
             "casting forboding shadows everywhere.\n";
  set_light(1);
  items = ({
    "ceiling","It is low and made of a dark oak",
    "floor","Black marble spreads in every direction",
    "walls","They are made with dark oak pannels and are covered with bookcases",
    "candles","Their soft white wax has melted down as they cast light and shadow",
  });
  listens = ({
    "You hear soft chanting in the background.\nYou can't find a source",
  });
  smells = ({
    "default","You smell dust and age",
  });
  dest_dir = ({ 
    PATH+"guildhall.c","east",
  });
}

init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){
  this_player()->clear_fight_area();
  return 1;
}

realm(){ return "NT"; }
GUILD_PK(){ return 1; }
