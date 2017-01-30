#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object trident;
object cloak;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("scout");
set_race("human");
set_short();
set_long(
  "  The creature standing before you is one of the Durkor.  They are\n"+
  "trained in the art of stealth.  The scout is second in stealth only\n"+
  "to the assassins.  She stands cloaked in the shadows prepared to strike\n"+
  "only when it is absolutely neccessary.\n");
 
set_level(17);
set_hp(350);
set_al(-500);
set_aggressive(0);
add_money(random(200) + 800);
set_chat_chance(1);
  load_chat("You sense that something is not right.\n");
set_spell_dam(20);
  set_spell_mess1(
    "The Durkor whirls her trident above her head then quickly brings it\n"+
    "down slashing across her foes chest.\n");
  set_spell_mess2(
    "The Durkor elegantly whirls her trident above her head then brings\n"+
    "the mighty trident down across your chest leaving a gaping "+HIR+"gash"+NORM+"\n"+
    "in your chest.\n");

trident = clone_object("/players/catacomb/Cavern/items/trident.c"); 
move_object(trident, this_object());
command("wield sword", this_object());
set_wc(24);

cloak = clone_object("/players/catacomb/Cavern/items/Dcloak.c"); 
move_object(cloak, this_object());
command("wear cloak", this_object());
set_ac(14);

}
