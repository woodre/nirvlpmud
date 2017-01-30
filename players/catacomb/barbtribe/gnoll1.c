#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
object shield;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("gnoll");
set_race("creature");
set_short("An ugly gnoll");
set_long(
  "  This bipedal monstrosity growls at you.  It is a mixed\n"+
  "breed of dog and human.  It walks like a human, but has\n"+
  "the head of a dog. The gnoll utters something at you under\n"+
  "it's breath, in it's own primitive language.");
 
set_level(10);
set_hp(150);
set_al(-200);
set_wc(14);
set_aggressive(0);
set_chance(10);
set_spell_dam(20);
set_spell_mess1(
  "The gnoll "+HIY+"HOWLS"+NORM+", and charges at it's foe.\n");
set_spell_mess2(
  "The gnoll "+YEL+"HOWLS "+NORM+"to the sky and charges you with\n"+
  "all of its might, knocking you down.\n");
 
shield = clone_object("players/catacomb/barbtribe/leathershield.c");
move_object(shield, this_object());
command("wear shield", this_object());
set_ac(8);
}   