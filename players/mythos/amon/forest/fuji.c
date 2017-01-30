#include "/players/mythos/closed/ansi.h"
inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("fujin");
  set_race("avatar");
  set_gender("male");
  set_alias("wind");
  set_short("Fujin- The Wind");
  set_long("The avatar of wind- Fujin- stands before you.\n"+
           "With his famous bag of wind over his shoulder\n"+
           "and two sharp horns on his head, he is a foe to\n"+
           "be reckoned with.\n");
  set_hp(900);
  set_level(25);
  move_object(clone_object("/players/mythos/amisc/forest/bag.c"),this_object());
  move_object(clone_object("/players/mythos/aarmor/forest/horns.c"),this_object());
  init_command("wear horns");
  set_al(0);
  set_wc(40);
  set_ac(16);
  set_heal(3,25);
  set_aggressive(0);
  set_chat_chance(20);
  set_chat_chance(30);
  set_a_chat_chance(15);
  load_chat(CYN+"The wind blows..\n"+NORM);
  load_chat("Fujin glares at everything.\n");
  load_a_chat("Fujin smiles evily at you.\n");
  load_a_chat("You cry out in pain as Fujin hits you hard.\n");
  set_chance(15);
  set_spell_dam(40);
  set_spell_mess1("You involuntarily flinch as you see Fujin's foe impaled upon the"+
                   " horns!\n");
  set_spell_mess2("You feel great pain as the horns go right through you!\n");
  call_out("check",3);
}

check() {
if(!environment(this_object())) return 1;
  if(present("raiden",environment(this_object()))) {
     if(present("raiden",environment(this_object()))->query_attack()) {
this_object()->attack_object(present("raiden",environment(this_object()))->query_attack());}}
     call_out("check",3);
  return 1;}
#include "/players/mythos/amon/hb_ag.h"
