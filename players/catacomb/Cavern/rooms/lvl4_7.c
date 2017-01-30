#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
" The cavern leads to the south and northwest.  The area seems to be \n"+
"closing in on all that walk the area.  The walls are filled with \n"+
"rocks jutting out of them causing all who walk by to carefully avoid\n"+
"them.\n");

items = ({
  "cavern",
  "The cavern leads to the south and northeast",
  "walls",
  "The walls are covered in sharp jutting rocks",
  "rocks",
  "Sharp rocks protrude from the walls",
  "rock",
  "The rock is stained in red"
});

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_6.c","northeast",
  "/players/catacomb/Cavern/rooms/lvl4_8.c","south"
 
});
}


