#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
object fucked, gold;

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   set_name("zombie");
   set_alias("zombie");
   set_race("zombie");
   set_short("A Man "+RED+"("+BLK+BOLD+"zombie"+NORM+RED+")"+NORM);
   set_long("This once lively, dancing guy now looks disgusting.\n"+
      "His skin is peeling from all over his body.  Rotted\n"+
      "flesh and muscle can be seen under hideous gashes\n"+
      "and scars. His eyes glow a blood red and puss\n"+
      "drops from the corners of his mouth.\n");
   set_level(18);
   set_hp(300+random(100));
   set_al(0);
   set_wc(30);
   set_ac(10);
   set_aggro(1, 10, 100);
   set_chance(20);
   set_spell_dam(30+random(16));
   set_chat_chance(20);
   load_chat("The zombie snarls.\n");
   load_chat("The zombie hisses angrilly.\n");
   load_chat("The zombie roars hungrilly at you.\n");
   load_chat("The zombie lashes around.\n");
   set_spell_mess1(
      "\n\nThe Mage summons a storm of "+BLK+BOLD+"ash"+NORM+" and "+RED+"brimstone"+NORM+" over the room!\n");
   set_spell_mess2(
      "\n\nThe Mage summons a storm of "+BLK+BOLD+"ash"+NORM+" and "+RED+"brimstone"+NORM+" over the room!\n"+
      HIR+"\tThe ashen storm burns your body!\n"+NORM);
   set_dead_ob(this_object());
   
   gold = clone_object("obj/money");
   gold->set_money(4500+random(1001));                              
   move_object(gold,this_object());
}


init(){
   ::init();
   if (this_player()->is_player()) fucked = this_player();
}


monster_died() {
   tell_room(environment(this_object()), "The zombie falls to the ground with a heavy THUD.\n");
   return 0; }

heart_beat(){
   object here, there;
   here = environment(this_object());
   there = environment(fucked);
   ::heart_beat();
   if(here != there){
      move_object(this_object(), environment(fucked)); 
      say("A zombie rushes in to the room!\n");
   }
   
}
