#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
object ghat, gclub;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("gnoll");
set_alt_name("shaman");
set_race("creature");
set_short("The gnoll shaman");
set_long(
  "  The gnoll mixes various components to makes a "+BLU+"blue"+NORM+"\n"+
  "potion.  Being the wisest, if you can call gnolls wise,\n"+
  "it has become the leader and shaman of the pack.  Its\n"+
  "crude headdress signifies its position within the tribe.\n");
 
set_level(14);
set_hp(220);
set_al(-400 + random(100));
set_aggressive(0);
set_chance(20);
set_spell_dam(15);
set_spell_mess1(
  "The shaman throws a "+RED+"mul"+HIY+"tic"+BLU+"olo"+HIG+"red"+NORM+
  " potion at its foe.\n");
set_spell_mess2(
  "The shaman throws a "+RED+"mul"+HIY+"tic"+BLU+"olo"+HIG+"red"+NORM+
  " potion at you, consuming you in "+HIR+"flames"+NORM+".\n");
 
ghat = clone_object("players/catacomb/barbtribe/gnollcap.c");
gclub = clone_object("players/catacomb/barbtribe/shamanclub.c");
move_object(ghat, this_object());
command("wear headdress", this_object());
move_object(gclub, this_object());
command("wield club", this_object());
set_ac(11);
set_wc(18);
}   