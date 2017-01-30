/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())
#define TO this_object()
#define TP this_player()

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("yugoloth");
set_alias("guardian");
set_short(GRY+"Yugoloth"+NORM);
set_long(
  "This gigantic, grey, winged bear has been summoned by an evil\n"+
  "wizard to protect the area.  It has ram horns protruding from\n"+
  "its forehead and eagle talons for hands.\n");

set_race("creature");
set_level(20);
set_hp(510 + random(50));
set_al(0);
set_wc(33 + random(5));
set_ac(17);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(4);
  load_chat("The yugoloth grunts.\n");

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  HIR+"The yugoloth breathes and engulfs its prey in flame.\n"+NORM);
set_spell_mess2(
  HIR+"You are engulfed by flame from the yugoloth's breath.\n"+NORM);

}

monster_died() {
move_object(clone_object("/players/eurale/Lab/OBJ/tip.c"),ETO);
tell_room(ETO,
  HIR+"     The yugoloth IGNITES as it falls to the ground.\n"+NORM);
return 0; }

init() {
  ::init();
  add_action("Drop","drop");
}

Drop(str) {
  if(str) 
    return 0;
  TO->attack_object(TP);
return 1;
}
