/* Lord of the Ashen Hole within Qual'tor ...  high level nasty
   Big Spell Attack, Area Effect Attack, Regens, Multi Attacks and oh yeah,
   He eats pets ....  yum yum!     -Dar
   Total gold value of 15000 or so, should be worth every coin  */

#define ROOT "/players/daranath/qualtor/newstuff/"
#define ROOT2 "/players/daranath/closed/market/obj/"
inherit "/players/daranath/closed/monster1.c";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object ob, ob2, ob3, ob4, ob5, ob6, gold;
   ::reset(arg);
   if (!arg) {

 ob = clone_object(ROOT+"obj/skin_sack.c");
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"weps/dmace_maj.c");
  move_object(ob2, ob);
 ob3 = clone_object(ROOT+"obj/skull_helm.c");
  move_object(ob3, ob);
 ob4 = clone_object(ROOT2+"flesh.c");
  move_object(ob4, ob);
 ob5 = clone_object(ROOT2+"bone.c");
  move_object(ob5, ob);
 ob6 = clone_object(ROOT2+"innocent.c");
  move_object(ob6, ob);
 gold = clone_object("obj/money.c");
  gold->set_money(7500+random(3000));
  move_object(gold, this_object());

set_name("Lord of the Pit");
set_short("A Demon towers above you");
set_alias("lord");
set_race("demon");
set_gender("creature");
set_long("The Lord of the Pit towers above you, standing nearly 12 feet tall\n"+
         "here within his lair. His dark red skin seems almost black in places\n"+
         "a result of the dark ash about his demonic hole. Two powerful\n"+
         "arms ends in massive talons, while another set ends in pair of\n"+
         "pinchers that drip with a sickly disease. His horned head glares\n"+
         "at you through canine eyes, not a foe to be taken lightly.\n");
set_level(26);
set_ac(24);
set_wc(50 + random(8));
set_hp(1000+random(200));
set_heal(5,10);
set_wc_bonus(9);
set_al(-1000);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(20);
set_a_chat_chance(15);
load_chat("The demon tears a large chunk of meat from another former pet.\n");
load_chat("The Demon tears a huge chunk of meat from a previous victim.\n");
load_chat("The demon tears a large chunk of meat from another former pet.\n");
load_chat("The Demon throws a corpse into the corner and turns torwards you.\n");
load_chat("The Demon runs his claws along the stone of the wall...\n");
load_chat("The Demon enjoys playing with adventurors like yourself.\n");
load_chat("The Demon growls: Bring on my next meal...\n");
load_a_chat("Lord of the Pit slashes at you with his talons.\n");
load_a_chat("Lord of the Pit snaps at you with his pinchers.\n");

set_chance(15);
set_spell_dam(30+random(65));
set_spell_mess1("Lord of the Pit throws back his canine head and roars loudly.\n");
set_spell_mess2("Lord of the Pit catches you in one of the pinchers and tears at your flesh.\n");

call_out("use_spell",15);

set_mult(2);
set_mult_chance(20);
set_mult_dam1(12);
set_mult_dam2(10);
   }
  }

monster_died()  {
write_file("/players/daranath/closed/log/pitlord_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
  tell_room(environment(this_object()),
  "\nThe Lord of the Pit screams loudly, causing part of the roof to collapse.\n");
  tell_room(environment(this_object()),
  "\nThe demon's body falls to the floor, causing ash to rise up and \n"+
   "choke everyone in the room. The Lord of the Pit has been vanquished!\n");
  return 0;
        }

use_spell()  {
object target, HERE;
int a;

if(!environment(this_object())) {return 1; }
if(environment(this_object())) {
HERE = first_inventory(environment(this_object()));

if(this_object()->query_attack())  {
tell_room(environment(this_object()),
  "\nThe Lord of the Pit steps back from fighting for a moment and summons:\n\n"+
  "         "+HIR+"DEMONIC FLAMES"+NORM+"\n\n"+
  "Lord of the Pit roars triumphantly and wades back into the combat!\n\n");

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_name() != "Lord of the Pit")  {
  if(living(HERE))  {
    if(HERE->is_pet()) {
  tell_room(environment(this_object()),
    "\nLord of the Pit reaches down and swallows charred corpse of pet.\n\n");
    destruct(HERE); }
    if(HERE->is_player())
  if(call_other(HERE, "query_attrib", "ste") < random(35))  {
  tell_room(environment(this_object()),
  "\n"+HERE->query_name()+" burns within the fury of the flames.\n");
  HERE->heal_self(-(40+random(125)));
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

