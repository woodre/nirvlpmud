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
      "  You have entered the hut of the fabled Archer King. Bones\n"+
      "of previous hunters are scattered around the floor almost\n"+
      "burying the small chest that sits in the corner.\n");
   add_item("bones","Old bones that are starting to rot");
   add_item("floor","A makeshift floor made of old wood");
   add_item("wood","It is warped and rays of light shine through the gaps");
   add_item("light","Beams of light show the dust floating in the air");
   add_smell("main","You almost gag from the stench of rotting bones.");
   add_touch("chest","It is smooth to the touch.");
   add_listen("main","Loud screeches from the monkeys drive you crazy!!");
   add_exit("/players/fred/forest/Rooms/forest14.c","down");
   add_object("/players/fred/forest/Obj/chest.c");
   add_object("/players/fred/forest/Mon/monkey.c");
   add_object("/players/fred/forest/Mon/monkey.c");
   add_object("/players/fred/forest/Mon/monkey.c");
   add_object("/players/fred/forest/Mon/kmonky.c");
   add_property("NT");
}   

init(){
 ::init();
  add_action("movem","down");
  add_action("movem","d");
 }
	
movem(){
   if(present("drablo", environment(this_player()))){
   write("The Archer King cackles and blocks your movement.\n");
   say("Drablo blocks"+tpn+" from leaving.\n");
   return 1; } 
 }
