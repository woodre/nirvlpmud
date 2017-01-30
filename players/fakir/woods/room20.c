#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Clearcut";
long_desc =
"Many trees have been cut down, and all that remains are the foot tall\n"+
"stumps of what once was a beautiful woodland forest.  Most of the bushes\n"+
"have been trampled under horses shod hooves, and wagon tracks lead south,\n"+
"east, and west. It will be some time before this area grows back to its\n"+
"natural beauty.  One stump is hollow in the center.\n";

items = ({
"stump",   "A very old tree once stood here, and this stump is all that is left.\n"+
           "You could try to search the stump if you feel brave enough",
"trees",   "There are no trees here anymore",
"stumps",  "What is left of once tall oak and spruce trees",
"bushes",  "Mostly crushed by horse's hooves and wagon wheels",
"tracks",  "The ruts left in the ground by the wheels of flatbed wagons used to haul logs",
});

dest_dir = ({
   "/players/fakir/woods/room21.c", "west",
   "/players/fakir/woods/room19.c", "east",
   "/players/fakir/woods/room18.c", "south",
});
}
init()  {
  ::init();
    add_action("search_stump","search");
}
search_stump(str)  {
if(str && str != "stump") {
notify_fail("You find nothing when you search that.\n");
return 0; 
}
if(found) { write("You find nothing.\n"); 
return 1; }
write("You search around in the hollow stump and find a skunk hiding there!\n");
move_object(clone_object("/players/fakir/woods/NPC/skunk.c"),this_object());
 found = 1; return 1; 

}



