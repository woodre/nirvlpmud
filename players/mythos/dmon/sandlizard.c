#include "/players/mythos/closed/ansi.h"
int base;
inherit "players/mythos/dmon/mon";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("sandlizard");
  set_race("lizard");
  set_short("SandLizard");
  set_long("A rather long but slim brown lizard stads before you.\n"+
           "It hisses at you and its beady eyes stare at you with malice.\n"+
           "The creature's skin seems to glow.....\n");
  set_level(16);
  set_hp(600);
  if(random(2) == 0) set_al(-random(1000));
  else set_al(random(1000));
  set_wc(22);  
  set_ac(13);
  set_heal(10,10);
  set_aggressive(1);
  set_chat_chance(10);
  set_a_chat_chance(2);
  load_chat("The lizard slithers about.\n");
  load_chat("The lizard hisses at you.\n");
  load_a_chat("The Lizard pounces!\n");   
  load_a_chat("The SandLizard bites down hard.\n");
  set_mult(2);
  base = 0;
  set_extra(0);
  set_dead_ob(this_object());
}

query_prevent_shadow() { return 1; }

monster_died() {
object leave;
   switch(random(2)) {
     case 0: leave = clone_object("/obj/money.c");
             leave->set_money(750 + random(1000));  /* look at the monster first */
             break;
     case 1: leave = clone_object("/players/mythos/dmisc/scale.c");
             break;
   }
  move_object(leave,this_object());
}

heart_beat() {
  set_mult(2);
  set_heal(10,10);
  set_extra(base);
  if(attacker_ob) {
    if(base > (random(22) + attacker_ob->query_level() + 
               attacker_ob->query_extra_level() +
               attacker_ob->query_wc() + attacker_ob->query_ac())) {
        if(query_hp() * 100 / query_mhp() > 40) base -= random(100);
        if(query_hp() * 100 / query_mhp() > 80) base = 0;
    }
  }
  ::heart_beat();
}

hit_player(dam,zap) {
int damm;
  damm = dam;
  if(damm - query_ac() > 0) {
    base = base + (damm - query_ac())/4;
  }
  ::hit_player(dam,zap);
}

heal_self(n) {
int damm;
  damm = n;
  if(damm < 0) {
    base = base + (-damm)/7;
  }
  ::heal_self(damm);
}
  