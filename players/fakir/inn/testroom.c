#include "/players/fakir/color.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";
int x;
reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Winespring Inn";
long_desc =
   "The wine cellar is not nearly as large as you expected.  Bottles of wine and\n"+
   "ale are neatly stored in honeycomb like racks built against two of the four\n"+
   "walls of the cellar.  The east wall has the stairwell in the center.  The west\n"+
   "wall has a single large barrel against it.  The walls all appear to be built of\n"+
   "the selfsame interlocking stone that you have seen in other places of the inn.\n"+
   "There is something odd about the west wall.\n";

items = ({
   "carvings", "As you look closer, you notice intricate leaves carved upon the\n"+
               "entire face of the west wall.  There is a depression in the upper\n"+
               "corner of the wall where a leaf seems to be missing",
   "cellar",   "Though it is built below the main level of the inn, it undoubtedly\n"+
               "predates the inn itself.  The working  of the stone here is of an\n"+
               "ancient and superior style",
   "wall",     "Made of the same ancient rock as the foundation of the inn, but having\n"+
               "no mortar to secure it in place.  Instead, each stone is so closely set\n"+
               "to the other that it is almost as if the craftsman had put together some\n"+
               "puzzel pieces, and invoked some magic to join them.  Only one race has the\n"+
               "ability and skill to join rock in such a fashion.  The Ogier.  There are\n"+
               "some carvings on the wall",
   "walls",    "Made of the same ancient rock as the foundation of the inn, but having\n"+
               "no mortar to secure it in place.  Instead, each stone is so closely set\n"+
               "to the other that it is almost as if the craftsman had put together some\n"+
               "puzzel pieces, and invoked some magic to join them.  Only one race has the\n"+
               "ability and skill to join rock in such a fashion.  The Ogier.  There seems\n"+
               "to be something odd about the west wall",
   "stone",    "Stone such as this has only one place of origin...the Misty Mountains",
   "bottles",  "Of odd shapes and sizes, all are corked tight and laid on a side in a rack",
   "wine",     "Those of the Two Rivers vintage are dark red and robust. The imports are pale\n"+
               "and lack the body and flavor preferred by the village folk",
   "ale",      "The ale bottles are of a dark brown color, and stand out from the lighter\n"+
               "bottles of wine",
   "racks",    "Wooden slats cross cut and jointed to form a type of honeycomb in which the\n"+
               "wine and ale bottles can rest on a side to age",
   "stairwell","The stairs and walls are all built of the same stone as this room.  There\n"+
               "is just the faintest trace of light comming from the top of the stairs",
   "benches",  "Plain wooden benches where one might sit and rest a spell. They look to\n"+
               "be poorly made.  It would be unwise to sit upon them",
   "barrel",   "An old empty ale cask with the top missing. It is empty.  You could 'roll'\n"+
               "the barrel if you tried",
   "leaf",     "Looking closely, you notice this entire wall of rock has a soft pattern of\n"+
               "strange shaped leaves etched upon it.  The leaf which caught your eye after\n"+
               "moving the barrel is larger then the rest, and stands out a bit from the wall.\n"+
               "It would appear you could 'grab' the leaf",
   "depression","Looking closer you see it is a carved depression in the shape of a strange leaf",            
                   
   });


dest_dir = ({
   "/players/fakir/inn/room19.c", "climb",
   
   
});

}
init()  {
  ::init();
  add_action("roll","roll");
  add_action("place","place");
  add_action("grab","grab");
}
grab(arg) {
  write(CYAN+"You grab the Avendesora Leaf from the wall!\n"+OFF);
  say  (TPN+" grabs the Avendesora Leaf from the wall!\n");
  move_object(clone_object("/players/fakir/ways/OBJ/leaf.c"),this_player());
  return 1;
}
roll(arg) {
  write(CYAN+"You roll the barrel aside and notice an odd looking leaf!\n"+OFF);
  say  (TPN+" rolls the barrel aside and notices  an odd looking leaf!\n");
  return 1;
}
place(arg) {
  write(CYAN+"You place the leaf into the depression.  The waygate envelopes you.\n"+OFF);
  say  (TPN+" places a leaf on the wall and disapears into the waygate.\n");
  x = present("leaf",this_player());
  destruct(x);
  return 1;
}