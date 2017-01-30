#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  You stand on a large stone ledge high above the room below.\n"+ 
      "This is where the leader of the ferrets presides. The floor is\n"+
      "padded with soft leaves and other brush collected from the forest.\n");
   add_item("den","A large den of unknown origin");
   add_item("leaves","Leaves are scattered on the floor making a soft cushion like floor");
   add_item("brush","Small twigs and other things from the forest");
   add_item("ledge","The ledge is high above the ground below");
   add_item("floor","The floor is covered with nest like materials");
   add_listen("main","Strange rustling noises fill the room.");
   add_exit("/players/fred/forest/Rooms/forest36.c","descend");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
   add_object("/players/fred/forest/Mon/ferret.c");
   add_object("/players/fred/forest/Mon/ferret.c");
   add_object("/players/fred/forest/Mon/ferretov.c");
   add_property("NT");
}

init(){
 ::init();
  add_action("movem","descend");
 }

movem(){
  if(present("overlord", environment(this_player()))){
  write("The Overlord stops you from climbing down!\n");
  say(tpn+" is blocked from leaving by the Overlord.\n");
  return 1; }
 
}
