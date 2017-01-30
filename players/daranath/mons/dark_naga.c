/*
 *   The Dark Naga of the Dark Myre.   (by Saber and Daranath)
 *   5/12/95
 *
 */

inherit "players/mythos/amon/forest/monster1";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob, ob2, ob3, ob4, gold;
  object hammer;

ob2 = clone_object("/players/daranath/qualtor/newstuff/heals/eggs.c");
ob  = clone_object("/players/daranath/items/chest.c");
ob3 = clone_object("/players/daranath/items/goblet.c");
ob4 = clone_object("/players/saber/gems/ruby.c");
hammer = clone_object("/players/daranath/weps/giant_killer.c");
gold = clone_object("obj/money");
gold->set_money(1000);
move_object(ob3,ob);
move_object(ob4,ob);
move_object(gold,ob);
move_object(ob,this_object());
move_object(ob2,this_object());
move_object(hammer,ob);

     set_name( "dark naga" );
     set_short("A dark naga");
     set_alias("naga");
     set_race( "serpent");
     set_gender("creature");
     set_long("A snake-like creature with a human face.  It's leathery, blacked\n"+
              "body coils within the room, ending in a long, slender stinger.\n"+
              "Poison glistens on both its stinger and its fangs.\n");
     set_level(22);
     set_ac(17);
     set_wc(30);
     set_hp(1300 + random(100));
     set_al(-1000);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(20);
     set_a_chat_chance(15);
     load_chat("Naga hisses and spits at you.\n");
     load_chat("Dark Naga shimmers and seems to be more powerful.\n");
     load_chat("Dark Naga hisses: Do not be foolish.\n");
     load_chat("Dark Naga hisses: Go after the renagade drow elf, not me.\n");
     load_chat("Naga waves its stinger in your face.\n");
     load_a_chat("Naga strikes at you with its stinger.\n");
     load_a_chat("Naga lunges at you with its fangs.\n");

     set_spell_mess2("Naga thrusts its stinger deep into your chest.");
     set_spell_mess1("Naga thrusts its stinger deep into the chest of its foe.");
     set_chance(10);
     set_spell_dam(25);
     call_out("use_spell",10);
   }
  }


monster_died()  {
object ob;
  tell_room(environment(this_object()),
  "\nDark Naga falls to the ground, mortally wounded.\n"+
  "Dark Naga hisses: You have doomed the surface world.\n");
  tell_room(environment(this_object()),
  "\nDark Naga curses, and is forever still...\n\n"+
  "You hope...\n\n");
  return 0;
        }


use_spell()  {
object target, HERE;
int a;

if(!environment(this_object())) return 1;
HERE = first_inventory(environment(this_object()));

if(this_object()->query_attack())  {
tell_room(environment(this_object()),
  "\nDark Naga invokes a spell.\n\n"+
  "       [-"+HIB+"WORD OF POWER"+NORM+"-]\n\n");


while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_name() != "Dark naga")  {
  if(living(HERE))  {
  if(call_other(HERE, "query_attrib", "pie") < random(32))  {
  tell_room(environment(this_object()),
  "\n"+HERE->query_name()+" staggers from the power of the spell.\n");
  HERE->heal_self(-(random(40)));
        }
        }
        }
        }
HERE = next_inventory(HERE);
        }
        }
call_out("use_spell",random(45));
  return 1;
        }
