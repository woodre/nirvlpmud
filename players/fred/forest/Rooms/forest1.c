#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"CRaZed FoReSt"+NORM;
long_desc =
"  As you begin to enter the forest the light grows dimmer, the\n"+
"trees grow larger and tower above you.  Strange sounds can be\n"+ 
"heard from every direction.  There is something eerie about this\n"+
"place.\n";

items = ({
  "forest",
  "A large forest filled with trees and shrubs", 
  "shrubs",
  "Small shrubs blanket the forest floor", 
  "trees",
  "Huge trees that have been growing over the centuries",
  "light",
  "Translucent beams illuminate your surroundings",
  });

dest_dir = ({
  "/players/fred/forest/Rooms/vill_1.c","east",
  "/players/fred/forest/Rooms/forest2.c","north",
  "/players/fred/forest/Rooms/forest3.c","west",
  "/players/fred/forest/Rooms/forest4.c","south", 
  });
  }

init(){
  ::init();
      if(this_player() && !random(15)){
      if(!present("squirrel_id", this_object())){
      move_object(clone_object("/players/fred/forest/Mon/psquirrel.c"), this_object()); } } 
      add_action("smellem", "smell");
      add_action("searchem", "search");
      add_action("listenem","listen");  
  }

smellem(str){
  write("The forest smells musty and dank.\n");
  say(tpn+" smells the air.\n");
  return 1; }

searchem(str){
  write("You find nothing of interest.\n");
  say(tpn+" searches the room.\n");
  return 1;  }

listenem(str){
  write("Strange sounds float through the air, making you feel uneasy.\n");
  say(tpn+" grows still and listens intently.\n");
  return 1;  }