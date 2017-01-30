/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define TO this_object()
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("histachii");
set_short(HIY+"histachii"+NORM);
set_long(
  "Once human, this histachii is now a mindless abomination who has\n"+
  "been transformed into a reptilian humanoid.  He is hairless with\n"+
  "an emaciated body.  His yellow-green skin is tough and scaly, and\n"+
  "he smells faintly of rotting meat.  He has bloodshot eyes and a\n"+
  "forked tongue that constantly darts in and out of his mouth.  His\n"+
  "fingernails are black and twisted, resembling the claws of lizard.\n");

set_race("creature");
set_level(20);
set_hp(496 + random(150));
set_al(-random(200));
if(!present("tadji")) {
  move_object(clone_object("/players/eurale/Lab/OBJ/tadji.c"),TO); }
  init_command("wield tadji");
set_wc(30 + random(4));
set_ac(17);
set_aggressive(1);

set_chat_chance(3);
load_chat("Your skin prickles as the histachii looks you over...\n");

set_chance(20);
set_spell_dam(random(30));

set_spell_mess1(
  HIR+"The histachii's eyes glow a brilliant red...\n"+NORM);
set_spell_mess2(
  HIR+"You feel an intense pain as the histachii's eyes glow.\n"+NORM);

}

init() {
  ::init();
  add_action("Search","search");
}

Search() {
  write("The histachii pushes you hard...\n");
  return 1; }
