#include "/players/mythos/closed/ansi.h"
#define tp this_player()
inherit "room/room";
int z;
object ob, ob2, ob3;
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle3.c"),this_object()); }
  if(!present("dancer")) {
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object()); 
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Juliana's Tokyo- Dance Floor>> ";
    long_desc =
    HIR+"                     DANCE FLOOR\n\n"+NORM+
        "The lights are flashing, the music is HOT, and laser light\n"+
        "plays across the mass of bodies that dance together- moving\n"+
        "to the wild beat of the RAVE.\n"+
        "Just let yourself go... let the music fill you... let yourself dance!\n" ;
  items = ({
    "front","Head out of Juliana's",
    "bar","Go get a cool drink and refresh youself.....",
    "stage","Step up onto the stage and feel the music",
    "DJ","See who's in the consol dealing the music ....",
  });

  dest_dir = ({
  "/players/mythos/mroom/juliana1.c","front",
  "/players/mythos/mroom/juliana4.c","bar",
  "/players/mythos/mroom/juliana5.c","stage",
  "/players/mythos/mroom/juliana2.c","DJ",
  });
} }

init() {
  ::init();
  if(!(tp->query_npc())) {
  z = random(10);
  if(z == 0 || z == 3 || z == 4) { 
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());
  ob = clone_object("/players/mythos/mmon/dance.c");
  if(random(5) == 0) { ob->set_aggressive(1); }
  move_object(ob,this_object());
  }
  if(z == 1) { 
  ob2 = clone_object("/players/mythos/mmon/dance.c");
  if(random(3) == 0) { ob2->set_aggressive(1); }
  move_object(ob2,this_object());
  ob3 = clone_object("/players/mythos/mmon/dance.c");
  if(random(5) == 0) { ob3->set_aggressive(1); }
  move_object(ob3,this_object());
  }
  if(z == 2) { 
  if(!present("dancer")) {
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object()); 
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object()); }
  move_object(clone_object("/players/mythos/mmon/dance.c"),this_object());} 
}}
