/* Same as mourn_coil, but aggressive.  -Dar */

inherit "/obj/monster";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

     set_name("Mourning Coil");
     set_short("A Mourning Coil");
     set_alias("coil");
     set_race("undead");
     set_gender("creature");
     set_long("A Coil is the ghost of a person who died in extreme pain,\n"+
              "so much that their spirit haunts the place of their death,\n"+
              "trying to extract its revenge upon anything living.\n");
     set_level(20);
     set_ac(17);
     set_wc(40 + random(4));
     set_hp(500 + random(100));
set_al(-(250+random(350)));
     set_aggressive(1);
     set_dead_ob(this_object());
     set_chat_chance(20);
     set_a_chat_chance(15);
     load_chat("The Coil wails in grief and pain.\n");
     load_chat("The Coil wails with a soul shaking moan.\n");
     load_a_chat("The Coil tears into your throat, drawing blood.\n");
     load_a_chat("The Coil tries to make you one of the dead.\n");

     set_spell_mess2("The Coil tears into your throat, drawing blood.\n");
     set_spell_mess1("The Coil tears into its foe, howling gleefully.\n");
     set_chance(10);
     set_spell_dam(60);
     call_out("use_spell",15);

     gold = clone_object("obj/money");
     gold->set_money(random(3000)+3500);
  /* Average coins of 5000 per monster guide -Dar */
     move_object(gold,this_object());
   }
  }


monster_died()  {
object ob;
  tell_room(environment(this_object()),
  "\nThe Coil disipates, causing a cool breeze to fill the area.\n");
  tell_room(environment(this_object()),
  "\nA howl is heard in the far off distance....\n");
  return 0;
        }


use_spell()  {
object target, HERE;
int a;

if(environment(this_object())) {
HERE = first_inventory(environment(this_object()));

if(!environment(this_object())) {return 1; }
if(this_object()->query_attack())  {
tell_room(environment(this_object()),
  "\nMourning Coil gives off an ear piercing\n\n"+
  "        "+HIR+"WAIL"+NORM+"      \n\n");


while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_name() != "Mourning Coil")  {
  if(living(HERE))  {
  if(call_other(HERE, "query_attrib", "pie") < random(32))  {
  tell_room(environment(this_object()),
  "\n"+HERE->query_name()+" staggers from the power of the wail.\n");
  HERE->heal_self(-(20+random(90)));
        }
        }
        }
        }
HERE = next_inventory(environment(this_object()));
        }
        }
call_out("use_spell",random(45));
}
  return 1;
        }
