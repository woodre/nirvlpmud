#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("demon");
  set_race("demon");
  set_short("Demon at the Threshold");
  set_long("This is the demon you must defeat to enter the realm of life again.\n");
  set_hp(475);
  set_level(19);
  set_al(-100);
  set_wc(28);
  set_ac(16);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(10);
  set_a_chat_chance(5);
  load_chat("The demon laughs at you.\n");
  load_chat("Demon says: Kill....kill...\n");
  load_a_chat("Demon screams: Give up now! There is no use in fighting!\n");
  load_a_chat("The demon grins evilly.\n");
  load_a_chat("Demon screams: You may as well kill yourself!\n");
  set_chance(10);
  set_spell_dam(25);
  set_spell_mess1("The DEMON rips its claws through "+capitalize(this_player()->query_name())+"!\n");
  set_spell_mess2("The DEMON rips its claws through you!\n");
  call_out("check",3);
}

check() {
  if(!environment(this_object())) return 1;
  if(!present(owner,environment(this_object()))) {
  destruct(this_object());
  return 1;}
  call_out("check",6);}

monster_died() {
destruct(present("deathmark",find_player(owner)));
call_other(find_player(owner),"set_home","/players/mythos/closed/guild/assembly.c");
  move_object(find_player(owner),"/players/mythos/closed/guild/assembly.c");
  tell_object(find_player(owner),"You have defeated the demon!");
  find_player(owner)->heal_self(500);
  command("look",find_player(owner));
  present(fear,find_player(owner))->set_ggt(0);
  find_player(owner)->save_me();
  return 0;}
