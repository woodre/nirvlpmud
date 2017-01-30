#include "/players/maledicta/ansi.h"
#define OPP attacker_ob->query_name()
inherit "obj/monster.c";

reset(arg)  {
 ::reset(arg);
  if(arg) return;
set_name("griffin");
set_alt_name("war griffin");
set_race("griffin");
set_short(BOLD+"War "+NORM+YEL+"Griffin"+NORM);
set_long(
"This is a large griffin, a beast trained by the\n"+
"Emerald Dragons to guard the forest home of its\n"+
"master. Its head is that of an eagle, its beak\n"+
"sharp and capable of tearing away flesh with\n"+
"ease. Its forelegs are clawed, with the same\n"+
"eagle-like characteristics as the head. The\n"+
"rear portion of its body is that of a lion, with\n"+
"huge clawed paws and a long tail. This creature\n"+
"is very deadly and ready to defend its home.\n");
set_level(17);
set_hp(450);
set_al(-1000);
set_wc(23);
set_ac(18);
set_heart_beat(1);
set_chance(25);
set_spell_dam(20);
set_spell_mess1(
"The griffin lunges at its opponent, biting at them with a razor sharp beak!\n");
set_spell_mess2(
"The griffins beak pierces deep into your skin!\n");
set_chat_chance(10);
load_chat("The griffin screeches a warning at you!\n");
load_chat("The griffin hisses as it circles slowly.\n");
}

heart_beat(){
 ::heart_beat();
 if(random(100) < 25){
   tell_room(environment(),
   "The griffin "+HIR+"RIPS"+NORM+" "+OPP+" with its front claws!\n");
   attacker_ob->hit_player(random(21));
   }
 if(random(100) < 25){
   tell_room(environment(),
   "The griffin "+HIR+"RIPS"+NORM+" "+OPP+" with its front claws!\n");
   attacker_ob->hit_player(random(21));
   }
 }