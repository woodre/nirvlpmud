#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
"  The cavern smells of sulfur and death.  Many of the durkor\n"+
"have travelled to the depths of the cavern to never come back. \n"+
"The area is void of all light making travel somewhat trecherous. \n"+
"A grate is placed in the ceiling allowing access to the higher\n"+
"levels of the cavern. \n");

items = ({
  "grate",
  "The grate in the ceiling allows passage up into the upper levels",
  "ceiling",
  "The ceiling has a grate embedded in it"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_2.c","west",
  "/players/catacomb/Cavern/rooms/lvl3_20.c","climb"
 
});
}


