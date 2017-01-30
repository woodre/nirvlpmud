#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object coupon;
int no_hit;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("carp");
set_alias("fish");
set_race("creature");
set_short(BOLD+"Peanut Butter Carp"+NORM);
set_long(
  " A large brown colored fish that looks like it was\n"+
  "involved in freak science experiments.  It almost\n"+
  "looks like it is covered in, yes, yes it is, it's\n"+
  "covered in Peanut Butter!\n");
 
set_level(13);
set_hp(195);
set_al(-100);
set_ac(10);
set_wc(17);
set_dead_ob(this_object());
set_aggressive(1);
set_chat_chance(7);
  load_chat("For some reason you want to sing:\n"+
            "I love fishes cause they're so delicious!\n");
}

heart_beat(){
  ::heart_beat();
   if(no_hit) {
     set_ac(200000);
     no_hit = 0;
     if(attacker_ob && !random(4)) {
     tell_object(attacker_ob,
     "Your weapon sticks to the fish!!\n"); }
     }
   else{
     set_ac(10);
     no_hit = 1;
     if(attacker_ob && !random(5)) {
     tell_object(attacker_ob,
     "You struggle to free your weapon.\n");  }
   } 
}

monster_died(){ 
   coupon = clone_object("/players/fred/forest/Obj/coupon.c");
   move_object(coupon, this_object());
}



