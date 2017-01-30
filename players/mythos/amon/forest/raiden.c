#include "/players/mythos/closed/ansi.h"
inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("raiden");
  set_race("avatar");
  set_gender("male");
  set_alias("thunderer");
  set_short("Raiden- The Thunderer");
  set_long("A man of great size- Raiden- appears to be ferocious.\n"+
           "He is the avatar of thunder- his drums symbolizing this.\n"+
           "Be careful, for he is a man to be you be frightened of.\n");
  set_hp(900);
  set_level(25);
move_object(clone_object("/players/mythos/amisc/forest/drums.c"),this_object());
move_object(clone_object("/players/mythos/aarmor/forest/light.c"),this_object());
  init_command("wear lightning");
  set_al(0);
  set_wc(40);
  set_ac(16);
  set_heal(3,25);
  set_aggressive(1);
  set_chat_chance(20);
  set_chat_chance(30);
  set_a_chat_chance(15);
  load_chat(BOLD+"Thunder rumbles.\n"+NORM);
  load_chat("Raiden glares at you.\n");
  load_a_chat("You cry out in pain as Raiden hits you hard.\n");
  load_a_chat("Rain starts to fall...\n");
  set_chance(15);
  set_spell_dam(40);
  set_spell_mess1("You stumble back as you see lightning flash and hit Raiden's foe!\n");
  set_spell_mess2("You feel great shock and pain as lightning strikes you!\n");
  call_out("check",3);
}

check() {
if(!environment(this_object())) return 1;
  if(present("fujin",environment(this_object()))) {
     if(present("fujin",environment(this_object()))->query_attack()) {
this_object()->attack_object(present("fujin",environment(this_object()))->query_attack());}}
     call_out("check",3);
  return 1;}
#include "/players/mythos/amon/hb_ag.h"
