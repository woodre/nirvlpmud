#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object belt;

reset(arg)  
{
  ::reset(arg);
  if(arg) return;

set_name("spectre");
set_race("undead");
set_short("An undead spectre");
set_long(
  "  The only remains of a poor soul who travelled too far into the\n"+
  "forest.  It is impossible to discern what kind of being this was\n"+
  "in its former life.  Its only goal in the after life is to cause\n"+
  "as much pain and misery as possible.\n");
 
set_level(18);
set_hp(400);
set_al(-500);
set_ac(15);
set_wc(26);
add_money(1500+random(2500));

set_dead_ob(this_object());
set_aggressive(1);
set_chat_chance(2);
  load_chat("The spectre lets out a gutteral moan.\n");

set_chance(20);
set_spell_dam(25);
set_spell_mess1(
  "\nThe spectre reaches out and lays a chilling hand on its foe.\n");
set_spell_mess2(
  "\n"+ATTACKED+" withers in pain after being touched by the spectre.\n");

}
 
