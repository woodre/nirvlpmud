/* Library 2, Created <6/19/01> by Jara */

#include "defs.h"
#include "/players/jara/area1/castle/misc/ansi.h"
inherit "room/room";
int SIT;

reset(arg) {
SIT = 0;
  if(arg) return;
  set_light(1);
  short_desc="Zercher Castle- Library";
  long_desc=
    "  This room is bordered by rows of wooden shelves, each one holding\n"+
    "books, both ancient and new. A gentle fire is burning within the stone\n"+
    "fireplace that has been built into the east wall, and a stack of logs\n"+
    "stand beside the fireplace. A sofa, upholstered with a thick velvet\n"+
    "cloth is directly in front of the fireplace. There is a door in the\n"+
    "western wall, and the library continues to the north.\n";
  items=({
    "shelves",
    "The bookshelves are made of a strong, dark wood, possibly fir",
    "books",
    "Most of these books, bound by leather, are worn and tattered. The\n"+
    "books can be"+HIW+" search"+NORM+"ed",
    "fire",
    "The fire is fueld by a dwindling pile of logs. It brings a warmth to\n"+
    "the library",
    "fireplace",
    "A modest fireplace, built with mortar and a dull, white stone. It is\n"+
    "approximately three feet high",
    "logs",
    "The logs are small, and round, with enough supplied to last through\n"+
    "the evening hours",
    "wall",
    "The walls of this room are covered with rows of shelves, stacked with\n"+      "books of various subjects",
    "sofa",
    "A plush, velvet sofa, dark green in color. You could"+HIW+" sit"+NORM+" in it",
    "cloth",
    "The velvet cloth is thick and richly textured",
    "door",
    "A door made of a dark oak wood and marked with the royal insignia",
    "insignia",
    "A unicorn and a lion facing each other in peace" });
  dest_dir=({
    PATH+"library1","north",
    PATH+"hall1","west" });
}

init(){
    ::init();
  add_action("sit","sit");
  add_action("stand","stand");
  add_action("search","search");
}
sit(arg){
  if(SIT == 1){
    write("Someone is already on the sofa.\n");
return 1; }

  if(arg == "sofa" || arg ==  "on sofa"){ 
    write("You sit down on the plush, comfortable sofa.\n");
    say(TPN+" sits on the sofa.\n");
SIT +=1;
return 1; }
write("Sit on what?\n"); 
return 1; }

stand(arg){ 
  if(SIT == 0){
    write("You're not on the sofa.\n");
return 1; }
  if(arg == "up"){ 
    write("You get up from the sofa.\n");
    say(TPN+" stands up from the sofa.\n");
SIT -=1; 
return 1; }
    write("Stand"+HIW+" up"+NORM+" to get off the sofa.\n");
return 1; }

search(arg){
  if(arg == "books"){
    write("You search through the titles and find none of interest.\n");
    say(TPN+" searches through the books on the shelves.\n");
return 1; }
    write("Search what?\n");
return 1; }
