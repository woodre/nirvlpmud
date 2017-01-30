#include "/players/fred/ansi.h"
inherit "obj/monster.c";
object parachute, helmet;
object attacked;
#define attacked (this_object()->query_attack())
#define tpn this_player()->query_name()
#define tpo this_player()->query_objective()

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("squirrel");
set_alias("squirrel_id");
set_race("creature");
set_short(BOLD+"Paratrooper Squirrel"+NORM);
set_long(
  " This cute loveable squirrel is wearing a green \n"+
  "parachute with a red helmet.  It looks so cute!\n");
 
set_level(10);
set_hp(200);
set_al(-1000);
set_ac(7);
set_wc(24);
set_dead_ob(this_object());
set_aggressive(1);
set_chat_chance(7);
  load_chat("The squirrel looks at you and falls down laughing.\n");
  load_chat("You notice the squirrel running back and forth.\n");
}

init(){
  ::init();
    add_action("block_dir","east",1);
    add_action("block_dir","west",1);
    add_action("block_dir","north",1);
    add_action("block_dir","south");
    add_action("block_dir","s");
    add_action("block_dir","up",1);
    add_action("block_dir","down",1);
    add_action("block_dir","northeast",1);
    add_action("block_dir","northwest",1);
    add_action("block_dir","southwest");
    add_action("block_dir","southeast");
    add_action("block_dir","ne");
    add_action("block_dir","nw");
    add_action("block_dir","se");
    add_action("block_dir","sw");
}

block_dir(){
  if(present("squirrel", environment(this_player()))){
  write("You must fight the squirrel! You can not leave here.\n");
  say(tpn+" tries to run away but the squirrel runs "+tpo+" down.\n");
  return 1;  } 
}  

monster_died(){
  if(attacked)
   tell_object(attacked,
   "\nAs the squirrel lets out one last squeak you see\n"+
   "  the parachute and helmet fall to the ground.\n\n");
   parachute = clone_object("/players/fred/forest/Obj/pchute.c");  
   move_object(parachute, this_object());
   helmet = clone_object("/players/fred/forest/Obj/shelmet.c");
   move_object(helmet, this_object());
}



