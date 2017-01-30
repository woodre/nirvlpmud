#include "/players/fred/ansi.h"
inherit "obj/monster.c";
object attacked;
#define attacked (this_object()->query_attack())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("hunter");
set_race("human");
set_short(BRED+BOLD+"Insane Hunter"+NORM);
set_long(
  " An older gentleman that looks like he's been lost\n"+
  "in the forest for quite some time. Mud and leaves are\n"+
  "stuck in his scraggly beard.\n");

add_money(800+random(400)); 
set_level(18);
set_hp(450);
set_al(-random(700));
set_ac(15);
set_wc(26);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(7);
  load_chat("The hunter screams: HELP ME!! The animals in here are crazy!\n");
  load_chat("The hunter whispers: I'm being hunted by woodchucks.\n");
  load_chat("The hunter tells you: Leave the forest now before it's too late!\n");
}

monster_died(){
   tell_object(attacked,
   "\nThe hunter starts to laugh as he falls to the ground.\n"+
   "  Fools! all of you, you'll see, trust me.\n");
   }



