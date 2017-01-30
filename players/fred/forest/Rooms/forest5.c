#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(0);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  The tall trees grow up all around you. There is a large\n"+
      "ravine to the north. A bank drops off to the south into a\n"+ 
      "free flowing river. The river rushes by carrying away dirt\n"+
      "from the embankment.\n");
   add_item("trees","Large trees that form a canopy over you");
   add_item("ravine","A large ravine is to the north");
   add_item("bank","A slight drop off leading down to the river");
   add_item("embankment","A slight drop off leading down to the river");
   add_item("river","A free flowing river, it looks cold");
   add_item("dirt","Dirt that is being pulled into the river");  
   add_touch("trees","The trees bark is rough...Ouch!");
   add_touch("river","WOW!! That's cold");
   add_listen("main","You hear the water rushing past you");
   add_exit("/players/fred/forest/Rooms/forest3.c","east");
   add_exit("/players/fred/forest/Rooms/forest6.c","west");
   add_exit("/players/fred/forest/Rooms/forest9.c","north");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
}

init(){
 ::init();
  if(this_player() && !random(15)){
    if(!present("squirrel_id", this_object())){
    move_object(clone_object("/players/fred/forest/Mon/psquirrel.c"), this_object()); }
    tell_room(this_object(),
    "A squirrel parachutes into the room!\n"); } 
 }
