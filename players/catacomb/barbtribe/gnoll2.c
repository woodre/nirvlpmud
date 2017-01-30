#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
object cloak, gsword;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("gnoll");
set_alt_name("guard");
set_race("creature");
set_short("A gnoll guard");
set_long(
  "  The guard utters something in it own language.  The\n"+
  "creature appears to be a human with the head of a canine.\n"+
  "The gnoll stands strong warding off any intruders into its\n"+
  "camp.\n");
 
set_level(11);
set_hp(165);
set_al(-300);
set_aggressive(1);
set_chance(15);
set_spell_dam(10 + random(15));
set_spell_mess1(
  "The gnoll charges at its foe, and takes a deep "+HIR+"bite"+NORM+".\n");
set_spell_mess2(
  "The guard charges you and at the last second takes a large\n"+
  RED+"BITE "+NORM+"from your shoulder.\n");
 
cloak = clone_object("players/catacomb/barbtribe/torncloak.c");
gsword = clone_object("players/catacomb/barbtribe/gnollsword.c");
move_object(cloak, this_object());
command("wear cloak", this_object());
move_object(gsword, this_object());
command("wield sword", this_object());
set_ac(9);
set_wc(15);
}   