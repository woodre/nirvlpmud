/*Monster created to show damage done.
CREATED by snow and implemente by mythos*/

inherit "/players/beck/updates/monster.c";

int thp,rcount;
int armorclass;
int totalac;
int player_damage;
int total_damage, hit_damage;

reset(arg) {
   ::reset(arg);
   if (!arg) {
      
      set_name("doom");
      set_short("DOOM");
      set_race("demon");
      set_alias("spirit");
      set_long("DOOM is its name, DOOM is its game.\n");
      set_level(20);
      set_ac(17);
      set_wc(0);
      SHitPoint(600);
      set_heal(0,100);
      set_al(0);
      set_aggressive(0);
      thp = 600;
      rcount = 1;
   }
}

init() {
   ::init();
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
   say(
      "DOOM HP: <"+chp+"> DAMAGE DONE: <"+diff+"> AVERAGE DAMAGE: <"+average+">\n");
   totalac += armorclass;
   average = (totalac / rcount);
   say("ATTACKER AC <"+armorclass+"> AVERAGE AC: <"+average+">\n");
   total_damage += player_damage;
   average = (total_damage / rcount);
   say("ATTACKER DAMAGE <"+player_damage+"> AV DAMAGE <"+average+"> TOTAL <"+total_damage+">\n");
   say("NUMBER OF ROUNDS TILL DEATH <"+rcount+">\n");
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
