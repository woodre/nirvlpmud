#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"A small brook trickles down from the east and ends in a deep pool of crystal\n"+
"clear water.  Lush green ferns border the pool, intermixed with purple lace\n"+
"delphinium and white valerian blossoms.  A few maple and alder trees begin to\n"+
"the east, and a lone willow grows in the moist earth southwest.  There are\n"+
"many small footprints in the wet earth surrounding the pool.\n";

items = ({
"brook",   "Only three or four feet wide at this point, it meanders down from the east",
"pool",    "Crystal clear and very deep, it looks refreshing",
"water",   "Its just the regular kind",
"ferns",   "Deep green and bushy, they border the pool of crystal clear water\n"+
           "They look like someplace good to search through",
"delphinium", "A tall flowering bulb.  It grows well in the muted sunlight here",
"crocus",  "Usually only blooming in early spring, these seem to show no sign of wilt",
"blossoms","They bloom in abundance on long slender stalks",
"trees",   "The trees all blend in together from here, but you can tell they are maple and alder",
"willow",  "It is rather short for a willow tree. You can reach it in just a few steps southwest",
"earth",   "Rich dark loam like that found in most wooded areas",
"footprints", "Only the size of your thumb, they must belong to very small creatures",

});
if(!present("valerian",this_object()))
 move_object(clone_object("/players/fakir/woods/OBJ/valerian.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room7.c", "southwest",
   "/players/fakir/woods/room9.c", "east",
   
});
}
init()  {
  ::init();
    add_action("search_ferns","search");
}
search_ferns(arg)  {
if(!arg || arg != "ferns") {
notify_fail("You are searching in the wrong place.\n");
return 0; 
}
if(found) { write("You find nothing there at all.\n"); 
return 1; }
write("You search the ferns and find some fairy folk hiding inside them!\n");
move_object(clone_object("/players/fakir/woods/NPC/pixie.c"),this_object());
move_object(clone_object("/players/fakir/woods/NPC/imp2.c"),this_object());
 found = 1; return 1; 

}

