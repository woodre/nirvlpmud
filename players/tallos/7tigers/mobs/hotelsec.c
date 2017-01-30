#include "/players/tallos/ansi.h"
inherit "obj/monster.c";
object attacked;
#define attacked (this_object()->query_attack())
#define tpn this_player()->query_name()
#define tpo this_player()->query_objective()

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

  gold = clone_object("obj/money");
  gold->set_money(random(200) + 900);
  move_object(gold,this_object());

set_name("guard");
set_alias("guard_id");
set_race("human");
set_short(BOLD+""+HIG+"Hotel Security Guard"+NORM);
set_long(
  " Oh my you seem to be in the wrong place, this is \n"+
  "a hotel security guard he doesn't look to happy!\n");
 
set_level(15);
set_hp(300);
set_al(0);
set_ac(12);
set_wc(20);
set_dead_ob(this_object());
set_aggressive(1);
set_chat_chance(6);
  load_chat("The guard says, \"You're not to be here, "+HIR+"ALARM ALARM!"+NORM+"\"\n");
  load_chat("The guard says, \"I'll stop you!\"\n");
}
init(){
  ::init();
    add_action("block_dir","east",1);
    add_action("block_dir","west",1);
    add_action("block_dir","enter",1);
}

block_dir(){
  if(present("guard", environment(this_player()))){
  write("The guard stops you. \"You cannot go further!\"\n");
  say(tpn+" tries to move further but the guard stops them.\n");
  return 1;  } 
}  

monster_died(){
   tell_object(attacked,
   "\nThe guard falls with a terrible cry of death.\n");

}



