/* Library 1, Created <6/19/01> by Jara */

#include "/players/jara/misc/ansi.h"
#include "defs.h"
inherit "room/room";
int SIT;

reset(arg) {
SIT = 0;
  if(arg) return;
  set_light(1);
  short_desc="Zercher Castle- Library";
  long_desc=
    "  The northern part of the library holds hundreds of books, as well\n"+
    "as scrolls and a map. A curtained window overlooks a forest to the\n"+
    "north, and a plush, highbacked chair stands nearby. There is a desk\n"+
    "up against the western wall, a few papers placed on the carefully\n"+
    "polished surface. The library continues to the south.\n";
  items=({
    "shelves",
    "The bookshelves are made of a strong, dark wood, possibly fir",
    "books",
    "Most of these books, bound by leather, are worn and tattered. The\n"+
    "books can be"+HIW+" search"+NORM+"ed",
    "window",
    "The window is partially blocked by the delicate green curtains that\n"+
    "drape over it. The glass is clean and the window is made of glass",
    "scrolls",
    "The scrolls have been stacked at the end of the shelves. The papers\n"+
    "appear yellowed with age",
    "papers",
    "The scrolls are made of a yellowed paper pulp. There is writing in an\n"+
    "unfamiliar and ancient language",
    "map",
    "An ancient map of the kingdom of Zercher. The forest that lies to\n"+
    "northeast is uncharted",
    "forest",
    "The edge of the forest appears in the distance. The thick canopy seems\n"+
    "to move with a gentle rhythm",
    "chair",
    "The chair is upholstered with a richly textured, green velvet. You\n"+
    "could"+HIW+" sit"+NORM+" in it",
    "desk",
    "A desk, made of the same woods as the shelves, has several drawers and\n"+
    "a small lamp",
    "drawers",
    "Wooden drawers, each with a small keyhole",
    "keyhole",
    "The keyholes appear to be made of brass" });
  dest_dir=({ PATH+"library2","south" });
}

init(){
    ::init();
  add_action("sit","sit");
  add_action("stand","stand");
  add_action("search","search");
}
sit(arg){
  if(SIT == 1){
    write("Someone is already on the chair.\n");
return 1; }

  if(arg == "chair" || arg ==  "on chair"){ 
    write("You sit down on the plush, comfortable chair.\n");
    say(TPN+" sits on the chair.\n");
SIT +=1;
return 1; }
write("Sit on what?\n"); 
return 1; }

stand(arg){ 
  if(SIT == 0){
    write("You're not on the chair.\n");
return 1; }
  if(arg == "up"){ 
    write("You get up from the chair.\n");
    say(TPN+" stands up from the chair.\n");
SIT -=1; 
return 1; }
    write("Stand"+HIW+" up"+NORM+" to get off the chair.\n");
return 1; }

search(arg){
  if(arg == "books"){
    write("You search through the titles and find none of interest.\n");
    say(TPN+" searches through the books on the shelves.\n");
return 1; }
    write("Search what?\n");
return 1; }
