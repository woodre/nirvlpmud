#include "../defs.h"
#define PATH TOWERDIR

inherit ROOM;
reset(arg){
  if(!present("journal",this_object()))
    move_object(clone_object(OBJDIR+"guildboard.c"),this_object());
  if(!present("hatheo",this_object()))
    move_object(clone_object(NPCDIR+"hatheo.c"),this_object());
  if(arg) return;

  short_desc = MAG+"A Secret Hall"+NORM;
  long_desc = "   "+
              "The walls are made from ancient sandstone blocks.  There are a\n"+
              "couple of torches that flicker in the darkness, resting upon the\n"+
              "wall.  A small green fire glows in the center of the room and around\n"+
              "that are mystical sigils that seem to glow with knowledge.  Some\n"+
              "small bookshelves line the walls while a small library is to the\n"+
              "west. Through the south exit a yellow orb glimmers, while north leads\n"+
              "through a maze of hallways.  East leads to a small tunnel.\n";
  set_light(1);
  items = ({
    "walls","They are made from ancient sandstone blocks",
    "blocks","They are made from ancient sandstone and are very smooth",
    "torches","Wooden sticks resting with cast iron rings.  Fire blazes from them",
    "fire","It glows an unusual green",
    "sigils","They are strange markings around the fire that glow with knowledge",
    "bookshelves","They are made from a very dark oak",
    "orb","A round sphere of light that glimmers from the south",
  });
  listens = ({
    "You hear soft chanting in the background.\nYou can't find a source",
  });
  smells = ({
    "default","You smell dust and age",
  });
  dest_dir = ({
    "/room/lanceroad4.c","leave",
    PATH+"stairway1.c","stairs",
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
