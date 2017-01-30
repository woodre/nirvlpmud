#include "/players/mythos/closed/guild/def.h"
string type;
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("snake");
  set_alias("monster");
  set_alt_name("giant snake");
  set_race("creature");
  set_short("Giant Black Snake");
  set_long("A giant black snake- over 20 feet long and \n"+
           "as think as a tree trunk.  Its mesmerizing eyes\n"+
           "gleam and its fangs flash!\n");
  set_hp(500);
  set_level(20);
  set_al(-1000);
  set_wc(30);
  set_ac(17);
  set_heal(5,20);
  set_dead_ob(this_object());
  set_a_chat_chance(10);
  load_a_chat("A snake lashes out!\n");
  load_a_chat("A Snake strikes with blinding speed!\n"); 
  set_chance(20);
  set_spell_dam(50);
  set_spell_mess1("A snake lashes out!\n");
  set_spell_mess2("A snake lashes out and bites deeply into your flesh!\n"); 
}

set_type(str) { type = str; }

monster_died() {
  if(type == "m1") { environment(this_object())->set_m1(); }
  if(type == "m2") { environment(this_object())->set_m2(); }
  if(type == "m3") { environment(this_object())->set_m3(); }
  if(type == "m4") { environment(this_object())->set_m4(); }
  if(type == "m5") { environment(this_object())->set_m5(); }
return 0; }
