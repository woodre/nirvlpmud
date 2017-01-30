#define TP this_player()
#define TO this_object()
#define TPN capitalize(TP->query_name())
#define MEATN capitalize(attacker_ob->query_name())
#define TR tell_room
#define SK BOLD+"Shadow King"+OFF
 
#include "/players/snow/MONSTERS/color.h"
inherit "/obj/monster";

int gempres, can_heal_damage;

query_gem() { return gempres; }
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(5000);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/shadows/stuff/crown");
move_object(ob,this_object());
 
     set_name("shadow king");
     set_short(SK);
     set_race("shadowcreature");
     set_alias("king");
     set_long(
"A black-bearded figure of shadow about 4 meters tall, the "+SK+"\n"+
"commands respect from all mortals. An impressive crown studded with dark\n"+
"jewels rests on his head. He appears open to questions.\n");
     set_level(30);
init_command("wear crown");
     set_ac(25);
     set_wc(55);
     set_hp(1200);
     set_heal(2,1);
/* NEW CODE */
set_ac_bonus(15);
set_wc_bonus(16);
     set_al(-100);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(7);
     load_chat("The "+SK+" says: I know how you can leave this realm...\n");
     load_chat("The "+SK+" says: Give me a shadow gem and you are free\n"+
               "to use my portal...\n");
     load_a_chat("The "+SK+" says: To your death then, mortals.\n");
     load_a_chat("The "+SK+" moves in a blur!\n");
set_chance(50);
set_spell_mess1("The "+SK+" is wreathed in dark power!\n");
set_spell_mess2("The "+SK+" is wreathed in dark power!\n");
set_spell_dam(25);
set_dead_ob(this_object());
enable_commands();
   }
}

monster_died() {
  write_file("/players/snow/log/bigmon", ctime(time())+" "+
    query_attack()->query_name()+" killed Shadow King.\n");
  return 0; }

heart_beat() {
  ::heart_beat();
  king_heal();
  king_fight();
  king_check();
  checkup();
  set_heal(2,1);
  can_heal_damage = 1;
return 1;
}
 
king_heal() {
  int healnum;
  healnum = random(10)+5;
  if(hit_point < 750) {
    if(random(20) < 14) {
      if(healnum > 8) {
        say(BLUE+"The Shadow King's wounds close rapidly.\n"+OFF);
      }
      hit_point += healnum;
    }
  }
return 1;
}
 
king_check() {
  if(gempres) return;
  if(present("shadow gem",TO)) {
    say(BOLD+"The Shadow King says: You may pass.\n"+OFF);
    gempres = 1;
    }
return 1;
}
king_fight() {
  if(!attacker_ob) return 1;
  if(!present(attacker_ob, environment())) return;
  if(attacker_ob->query_ghost()) return 1;
  if(!random(3)) {
    tell_room(environment(attacker_ob),
      "The "+BOLD+"Shadow King"+OFF+" blasts "+attacker_ob->query_name()+" with a bolt of "+
      BLINK+REV_RED+"~SHADOWFIRE~"+OFF+OFF+"\n");
   tell_object(attacker_ob,BOLD+"__The bolt crashes into you!__\n"+OFF);
      attacker_ob->hit_player(random(50)+25);
  }
return 1;
}

checkup() {
  if(attacker_ob) {
    if(attacker_ob == TO) pissed(1);
  }
  if(attacker_ob)
    if(attacker_ob->query_race() == "shadowcreature") pissed();
  if(TO->query_wc() < 40) pissed();
  return 1;
}

pissed(arg) {
  if(!arg) {
    attacker_ob->stop_fight(); attacker_ob->stop_fight();
    attacker_ob->stop_hunter(); }
    stop_fight(); stop_fight(); stop_hunter();
  TO->set_wc(80);
  TO->heal_self(1000);
  return 1;
}

heal_self(int num) {
  if(num < 0) {
    if(!can_heal_damage) return 1;
    can_heal_damage = 0; }
  ::heal_self(num);
  return 1; }

query_limited_shadow() { return 1; }
