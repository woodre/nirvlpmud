#include "/players/mythos/closed/guild/def.h"
string follow_name;
inherit "players/mythos/closed/play/monster";

reset(arg) {
  if(arg) return;
  follow_name = RED+"Lilith"+NORM;
  set_name(RED+"Lilith"+NORM);
  set_race("dragon");
  set_alias("lilith");
  set_gender("female");
  set_short(HIR+"Lilith"+NORM+BOLD+"the Dragon"+NORM);
  set_al(-10000);
  set_hp(20000);
  set_level(100);
  set_wc(100);
  set_ac(40);
  set_a_chat_chance(10);
  set_heal(5,1);
  load_a_chat("The dragon roars!\n");
  load_a_chat("Razor sharp claws rip open the earth as the dragon attacks!\n");
  set_chance(69);
  set_spell_dam(200);
  set_spell_mess1(HIR+"Flame blasts down upon the Dragon's enemy!\n"+NORM);
  set_spell_mess2(HIR+"Flame blasts into you!\n"+NORM);
  set_mult(4);
  set_mult_chance(50);
  set_mult_dam1(10);
  set_mult_dam2(100);
  move_object(clone_object("/players/mythos/closed/play/key.c"),this_object());
}

id(str) { return str == "dragon" || str == "lilith" || str == "Lilith" ||
                 str == follow_name; }

query_real_name() { return follow_name; }

query_name() { return follow_name; }

query_prevent_shadow() { return 1;}

query_interactive() { return 1;}

long() {
string mssg;
  if(gender) write(short_desc+" ("+gender+")\n");
  if(hit_point < max_hp/10)  mssg = "in very bad shape.\n";
  if(hit_point < max_hp/5) mssg = "in bad shape.\n";
  if(hit_point < max_hp/2) mssg = "somewhat hurt.\n";
  if(hit_point < max_hp - 200) mssg = "slightly hurt.\n";
  if(hit_point > max_hp - 201) mssg = "in good shape.\n";
  cat("/players/mythos/closed/play/drag_pic");
  write(cap_name+" is "+mssg);
  write(BOLD+"You do not want to anger her.\n"+NORM);
return; }

set_hp(int n) {
  if(n < 20000) n = 20000;
  ::set_hp(n);
}

set_heal(int n,int m) {
  if(n < 5) n = 5;
  if(m != 1) m = 1;
  ::set_heal(n,m);
}

set_chance(int n) {
  if(n < 69) n = 69;
  ::set_chance(n);
}

set_spell_dam(int n) {
  if(n < 200) n = 200;
  ::set_spell_dam(n);
}

set_mult(int n) {
  if(n < 4) n = 4;
  ::set_mult(n);
}

set_mult_chance(int n) {
  if(n < 50) n = 50;
  ::set_mult_chance(n);
}

set_mult_dam1(int n) {
  if(n < 10) n = 10;
  ::set_mult_dam1(n);
}

set_mult_dam2(int n) {
  if(n < 100) n = 100;
  ::set_mult_dam2(n);
}

set_wc(int n) {
  if(n < 100) n = 100;
  ::set_wc(n);
}

set_ac(int n) {
  if(n < 40) n = 40;
  ::set_ac(n);
}

hit_player(arg) {
  int damm;
    damm = arg;
    if(damm > 50) damm = 50;
    ::hit_player(damm);
}

heal_self(arg) {
  int much;
  much = arg;
  if(much < -50) much = -50;
  ::heal_self(much);
}