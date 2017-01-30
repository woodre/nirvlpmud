/* added in a cap on the number of crysmals that can be summoned   Jun-07-2002  */

#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "/players/mythos/amon/forest/monster1.c";
int cap;

reset(arg) {
cap = 0;
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3, gold;
  gold = clone_object("/obj/money");
  gold->set_money(2500);
  move_object(gold,this_object());
  ob3 = clone_object("/players/daranath/qualtor/obj/shard.c");
  move_object(ob3, this_object());
  ob2 = clone_object("/players/daranath/qualtor/obj/shard.c");
  move_object(ob2, this_object());
  ob = clone_object("/players/daranath/qualtor/wep/power.c");
  move_object(ob,this_object());

     set_name("Crystalline Elemental");
     set_alt_name("crystal");
     set_short("Crystalline Elemental");
     set_race("elemental");
     set_alias("element");
     set_gender("creature");
     set_long("The crystalline elemental has been trapped here from the elemental plane of\n"+
              "its home. Made from pure crystal, the elemental moves with a grace\n"+
              "that it shouldn't have. A powerful opponent.\n");
     set_level(21);

     init_command("wield power");

     set_ac(20);
     set_wc(36);
     set_hp(750);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(8);
     load_chat("The Elemental hums with power.\n");
     load_a_chat("The Crystalline Elemental strikes at you with the power of pure crystal.\n");

     call_out("check",15);
   }
}

SUMMON()  {
object shard;
if(!environment(this_object())) {return 1; }
if(cap > 4) {return 1; }
 say("\nA "+HIW+"flash of light"+NORM+" comes from the Crystalline Elemental.\n"+
     "            A crysmal forms in the area!\n\n");
 shard = clone_object("/players/daranath/qualtor/newstuff/mon/crysmal.c");
  move_object(shard, environment(this_object()));
  cap = cap + 1;
        }

check()  {
  if((this_object()->query_attack()) && (random(20) < 12))  {
  SUMMON();
  call_out("check",15);
  return 1;
       }
  call_out("check", 15);
        }
