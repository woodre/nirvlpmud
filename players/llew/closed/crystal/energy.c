#include "/players/llew/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
 if(arg || root()) return;
   set_name("energy");
   set_level(5);
   set_alias("red energy");
   set_race("spirit");
   set_hp(50);
   set_al(0);
   set_short(RED+"Red Energy"+NORM);
   set_long("Red pulsing energy.\n");
   set_wc(13);
   set_ac(5);
   set_aggressive(1);
   set_can_kill(1);
   set_chance(10);
   set_spell_mess1("Red light flashed.");
   set_spell_mess2("Red light flashes.");
   set_spell_dam(10);
   set_hbflag("hbstayon");
   set_dead_ob(this_object());
   call_out("des",900);
}

heart_beat() {
   ::heart_beat();
  if(environment(this_object()))
   if(random(5)) random_move();
}

monster_died() {
   destruct(present("corpse of energy"));
   say("The Red Energy explodes in a busrt of light.\n");
   if(!random(4)) {
      object ob1,ob2,ob3;
      ob1=clone_object("/players/llew/closed/crystal/energy.c");
      ob2=clone_object("/players/llew/closed/crystal/energy.c");
      if(!random(4)) {
         say("The light reforms into three!!\n");
         ob3=clone_object("/players/llew/closed/crystal/energy.c");
         transfer(ob3,environment());
         ob3->attack_object(attacker_ob);
      }
      else say("The light reforms into two!\n");
      transfer(ob1,environment());
      transfer(ob2,environment());
      ob1->attack_object(attacker_ob);
      ob2->attack_object(attacker_ob);
   }
   else say("The light dissipates and fades away.\n");
   remove_call_out("des");
}

des() {
  set_heart_beat(0);
  if(environment(this_object()))
   say("The Red Energy fades to nothing.\n");
  destruct(this_object());
return 1; }

random_move() {
   string direc;
   direc=(string)({"north","south","east","west"})[random(4)];
  if(environment(this_object()))
   if(command(direc))
   /* next line by verte ..... bog.
   */
     if(this_object())
  tell_room(environment(this_object()),RED+"Red Energy "+NORM+"leaves "+direc+".\n");
}
