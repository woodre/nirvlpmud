#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
inherit "room/room";
object hunters;

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = BOLD+"CRaZed FoReSt"+NORM;
long_desc =
"  The forest is pitch black now as you trudge even farther into the\n"+
"forest.  Leaves are rustling throughout the tree tops. Sounds fill\n"+ 
"the forest making you a little paranoid. Something is not right about\n"+
"this place.\n";

items = ({
  "forest",
  "A large forest filled with trees and shrubs", 
  "shrubs",
  "Small shrubs blanket the forest floor", 
  "trees",
  "Huge trees that have been growing over the centuries",
  "leaves",
  "Leaves rustle free from the tree and slowly float to the ground",
 });

dest_dir = ({
  "/players/fred/forest/Rooms/forest1.c","east",
  "/players/fred/forest/Rooms/forest11.c","north",
  "/players/fred/forest/Rooms/forest5.c","west",
  "/players/fred/forest/Rooms/forest4.c","south", 
  });
  hunters = clone_object("/players/fred/forest/Mon/hunter.c");
  move_object(hunters, this_object()); 
}

init(){
  ::init();
      if(this_player() && !random(15)){
      if(!present("squirrel_id", this_object())){
      move_object(clone_object("/players/fred/forest/Mon/psquirrel.c"), this_object()); }
      tell_room(this_object(),
      "A Squirrel parachutes into the room!\n"); } 
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

  