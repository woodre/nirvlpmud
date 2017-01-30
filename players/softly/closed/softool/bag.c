/*Monster created to show damage done.
CREATED by snow and implemente by mythos
modified by Softly 1/4/01 for her use */
#include "/players/softly/closed/ansi.h"
inherit "/obj/monster.c";

int thp,rcount;
int armorclass;
int totalac;
int player_damage;
int total_damage, hit_damage;

reset(arg) {
   ::reset(arg);
   if (!arg) {
      
set_name("bag");
set_short("Punching Bag");
      set_race("demon");
      set_alias("testmob");
      set_long("Punching Bag .... kill me if you can.\n");
set_level(100000);
set_hp(600);
set_ac(14);
set_wc(0);
      set_heal(0,100);
      set_al(0);
      set_aggressive(0);
      thp = 600;
      rcount = 1;
   }
}

init() {
   ::init();
if(!environment()) return;
   if(this_player()->query_level() > 21) {
      add_action("mon_attack","doomer");
   }
}

mon_attack(arg) {
   object meat;
   string name,meatname,moname;
   meat = present(arg,environment(this_object()));
   name = capitalize(this_player()->query_real_name());
   meatname = capitalize(arg);
   moname = this_object()->query_real_name();
   if(!meat) { say(meatname+" is not here!\n"); return 1; }
   if(living(meat)) {
      call_other(meat,"attack_object",this_object());
   } 
   test_show();
   return 1;
}

test_show() {
   int chp,diff,average;
   chp = this_object()->query_hp();
   diff = ( thp - chp );
   average = ( (600 - chp) / rcount );
   say(MAG+
      "Bag HP: "+NORM+chp+MAG+" Damage done: "+NORM+diff+MAG+" Average damage: "+NORM+average+"\n");
   totalac += armorclass;
   average = (totalac / rcount);
   say(MAG+"Attacker AC "+NORM+armorclass+MAG+" Average AC: "+NORM+average+"\n");
   total_damage += player_damage;
   average = (total_damage / rcount);
   say(MAG+"Attacker damage: "+NORM+player_damage+MAG+" Av damage "+NORM+average+MAG+" Total "+NORM+total_damage+"\n");
   say(MAG+"Completed rounds: "+NORM+rcount+"\n");
   thp = chp;
   rcount = ( rcount + 1 );
   return 1;
}

heart_beat() {
   ::heart_beat();
   if(attacker_ob){
      hit_damage = random(30);
      player_damage = attacker_ob->hit_player(hit_damage);
      attacker_ob->add_hit_point(player_damage);
      armorclass = hit_damage-player_damage;
   }
   if(attacker_ob) test_show();
   return 1;
}
