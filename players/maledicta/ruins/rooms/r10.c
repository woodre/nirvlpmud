#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/fireangel2.c"), this_object()); }
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   The hallway here has been seriously damaged. Looking out past the\n"+
"crumbled walls you see that what remains of the ruins on this side\n"+
"has been leveled.  Looking down you see a huge gaping hole, the stones\n"+
"around it scorched and blackened.  The hallway leads back to the south.\n";

items = ({
  "ruins",
  "The building would have continued out for quite some\n"+
  "distance, but instead nothing stands. Large piles of\n"+
  "rocks dot the landscape, with an occassional wall\n"+
  "standing only about waist high",
  "hole",
  "You inspect the hole closer and see that it wasn't dug\n"+
  "but was melted into the floor",
  "walls",
  "You see that the walls here were torn apart and scattered outside",
  "hallway",
  "Looking about you can barely tell that this once was a long"+
  "hallway. Its walls are crumbled and fallen, exposing the"+
  "interior of the ruins to the elements"
  
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r8.c","south",
  "/players/maledicta/ruins/rooms/r11.c","down",
});

}
