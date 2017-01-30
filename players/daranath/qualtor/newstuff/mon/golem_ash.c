#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "/players/daranath/closed/monster1.c";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

set_name("Ash Golem");
set_short("An Ashen Golem");
set_alias("ash");
set_alt_name("golem");
set_race("construct");
set_gender("creature");
set_long("Blackened and smouldering, the Ash Golem is frightful just to look\n"+
         "just to look at.  Cracks run along the surface of the magical\n"+
         "monstrosity, with molten lava showing through.  It's mouth glows\n"+
         "akin to the hottest furnace, smoke and ash within.\n");
set_level(20);
set_ac(17);
set_wc(28 + random(6));
set_hp(450 + random(125));
set_wc_bonus(9);
set_al(0);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(10);
set_a_chat_chance(10);
load_chat("Ashen Golem burns silently.\n");
load_a_chat("The Ashen Golem spurts molten lava at you.\n");
load_a_chat("Immense heat from Ashen Golem blackens your weapon.\n");
load_a_chat("The black ash around the chamber is kicked up during the fight.\n");

set_spell_mess2("Ash Golem breathes a cone of blackened ash at you!\n");
set_spell_mess1("Ashen Golem breathes blackened ash at its foe.\n");
set_chance(10);
set_spell_dam(25 + random(50));
call_out("use_spell",15);

gold = clone_object("obj/money");
gold->set_money(random(1500)+3500);
/* average of 4250, plus the 750 from the pile, means 5000 per monster guide */
move_object(gold,this_object());
   }
  }


monster_died()  {
move_object(clone_object(ROOT+"obj/ash_pile.c"),environment(this_object()));
  tell_room(environment(this_object()),
  "\nThe Ashen Golem crumbles into bits of charcoal at your feet.\n");
return 0; }

use_spell()  {
object target, HERE;
int a;

if(!environment(this_object())) {return 1; }
if(environment(this_object())) {
HERE = first_inventory(environment(this_object()));

if(this_object()->query_attack())  {
tell_room(environment(this_object()),
  "   "+BOLD+BLK+"Ashen Golem"+NORM+" exhales and fills the area with\n\n"+
   BOLD+BLK+".:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):.\n"+NORM);
tell_room(environment(this_object()),
  BOLD+BLK+"  .:(:..:):..:(:..:):..:(:.. CHOKING ASH ..:):..:(:..:):..:(:..:):..\n"+
  ".:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):..:(:..:):.\n\n"+NORM);

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_name() != "Mourning Coil")  {
  if(living(HERE))  {
    if(HERE->is_player())
  if(call_other(HERE, "query_attrib", "sta") < random(45))  {
  tell_room(environment(this_object()),
  "\n"+HERE->query_name()+" coughs and chokes within the "+BOLD+BLK+"Dark Ash"+NORM+".\n");
  HERE->heal_self(-(20+random(90)));
        }
        }
        }
        }
HERE = next_inventory(HERE);
        }
        }
call_out("use_spell",random(45));
}
  return 1;
        }
