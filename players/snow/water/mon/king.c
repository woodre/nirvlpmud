#include "/players/snow/MONSTERS/color.h"
#define TK GREEN+BOLD+"Troglodyte King"+OFF+OFF
inherit "/obj/monster";

int can_heal_damage;

reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(5000);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/WEAPONS/tsunami.c");
move_object(ob,this_object());
 
     set_name("troglodyte king");
     set_short(TK);
     set_race("troglodyte");
     set_alias("king");
     set_long(
"\tYou see before you a massive green creature of ferocious mein.\n"+
"Its huge scaled arms ripple with dark muscle and its claws gleam\n"+
"with deadly poison. It does not appear happy to see you.\n");
     set_level(30);
init_command("wield trident");
     set_ac(10);
       set_ac_bonus(12);
      set_wc_bonus(19);
     set_wc(55);
     set_hp(800);
     set_heal(2,1);
     set_al(-1000);
     set_aggressive(1);
set_chance(50);
set_spell_mess2("You feel the "+TK+"'s poison burn into you!\n");
set_spell_mess1("The "+TK+"'s poison burns into its victim!\n");
set_spell_dam(20);
enable_commands();
set_dead_ob(this_object());
   }
}

monster_died() {
  write_file("/players/snow/log/bigmon", ctime(time())+" "+
    attacker_ob->query_name()+" killed Trog King.\n");
  return 0; }

init() {
  ::init();
  add_action("stop_move","north");
  add_action("stop_move","east");
}

stop_move() {
  write("The "+TK+" slaps you back!\n");
  this_player()->hit_player(random(15)+15);
  return 1; }
 
heal_self(arg) {
  if(arg < 0) {
      if(!can_heal_damage) return 1;
    can_heal_damage = 0;
    ::heal_self(arg); return 1; }
  ::heal_self(arg);
  return 1; }

heart_beat() {
  if(!random(6)) { already_fight=0; attack(); }
  king_heal();
  king_fight();
  checkup();
  can_heal_damage = 1;
  :: heart_beat();
}

query_can_heal_damage() { return can_heal_damage; }
 
king_heal() {
  int healnum;
healnum = random(10)+5;
  if(query_hp() < 800) {
    if(random(20) < 14) {
      heal_self(healnum);
    }
  }
return 1;
}
 
king_fight() {
  if(!query_attack()) return;
  if(!present(query_attack(), environment())) return 1;
  if(query_attack()->query_ghost()) return 1;
  if(random(30) > 24) {
    tell_room(environment(query_attack()),
    "\tThe "+TK+" summons a "+BLINK+GREEN+"TIDAL WAVE"+OFF+OFF+"!\n\n");
      query_attack()->hit_player(random(50)+50);
  }
return 1;
}

checkup() {
  if(attacker_ob && attacker_ob->query_race() == "troglodyte") pissed();
  if(query_wc() < 40) pissed();
  return 1;
}

pissed() {
  if(attacker_ob && attacker_ob != this_object()) {
    attacker_ob->stop_fight(); attacker_ob->stop_fight();
    attacker_ob->stop_hunter();
  }
  stop_fight(); stop_fight(); stop_hunter();
  set_wc(80);
  heal_self(1000);
  set_heal(15,1);
  return 1;
}

query_limited_shadow() { return 1; }
